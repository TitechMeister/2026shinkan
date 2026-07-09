#include <Arduino.h>
#include <Wire.h>
#include <string.h>

#if defined(ARDUINO_ARCH_RP2040) && __has_include("pico/bootrom.h")
#include "pico/bootrom.h"
#define XIAO_HAS_RP2040_USB_BOOT 1
#else
#define XIAO_HAS_RP2040_USB_BOOT 0
#endif

#ifndef SERIAL_MONITOR_SPEED
#define SERIAL_MONITOR_SPEED 115200
#endif

#ifndef D0
#define D0 26
#endif
#ifndef D1
#define D1 27
#endif
#ifndef D2
#define D2 28
#endif
#ifndef D3
#define D3 29
#endif
#ifndef D4
#define D4 6
#endif
#ifndef D5
#define D5 7
#endif
#ifndef D6
#define D6 0
#endif
#ifndef D7
#define D7 1
#endif
#ifndef D8
#define D8 2
#endif
#ifndef D9
#define D9 4
#endif
#ifndef D10
#define D10 3
#endif

#ifndef PIN_LED_R
#define PIN_LED_R 17
#endif
#ifndef PIN_LED_G
#define PIN_LED_G 16
#endif
#ifndef PIN_LED_B
#define PIN_LED_B 25
#endif

const uint8_t kPracticeLeds[] = {D0, D1, D2};
const uint8_t kPracticeLedCount = sizeof(kPracticeLeds) / sizeof(kPracticeLeds[0]);
const uint8_t kAnalogPin = D3;
const uint8_t kButtonPin = D9;
const uint8_t kUserLedR = PIN_LED_R;
const uint8_t kUserLedG = PIN_LED_G;
const uint8_t kUserLedB = PIN_LED_B;

const unsigned long kPracticeLedIntervalMs = 350;
const unsigned long kUserLedIntervalMs = 700;
const unsigned long kReportIntervalMs = 3000;
const float kAdcReferenceVoltage = 3.3f;
const float kAdcMaxValue = 4095.0f;

unsigned long lastPracticeLedMs = 0;
unsigned long lastUserLedMs = 0;
unsigned long lastReportMs = 0;
uint8_t practiceLedIndex = 0;
uint8_t userLedPhase = 0;
bool periodicReportEnabled = true;
uint32_t serial1RxCount = 0;
int lastSerial1Byte = -1;

String commandBuffer;

void setUserLed(bool red, bool green, bool blue) {
  digitalWrite(kUserLedR, red ? LOW : HIGH);
  digitalWrite(kUserLedG, green ? LOW : HIGH);
  digitalWrite(kUserLedB, blue ? LOW : HIGH);
}

void setPracticeLedsLow() {
  for (uint8_t i = 0; i < kPracticeLedCount; i++) {
    digitalWrite(kPracticeLeds[i], LOW);
  }
}

void printI2cAddress(uint8_t address) {
  Serial.print(F("0x"));
  if (address < 16) {
    Serial.print('0');
  }
  Serial.print(address, HEX);
}

uint8_t scanI2c(bool verbose) {
  uint8_t found = 0;

  if (verbose) {
    Serial.println(F("I2C scan on D4(SDA) / D5(SCL):"));
  }

  for (uint8_t address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    uint8_t error = Wire.endTransmission();

    if (error == 0) {
      if (found > 0) {
        Serial.print(F(", "));
      }
      printI2cAddress(address);
      found++;
    }
  }

  if (found == 0) {
    Serial.print(F("none"));
  }
  Serial.println();

  return found;
}

void printHelp() {
  Serial.println(F("Commands:"));
  Serial.println(F("  ? or help  : show this help"));
  Serial.println(F("  report     : print one report and enable periodic reports"));
  Serial.println(F("  quiet      : stop periodic reports"));
  Serial.println(F("  scan       : scan I2C on D4/D5"));
  Serial.println(F("  uart       : loopback check, jumper D6(TX) to D7(RX) first"));
  Serial.println(F("  led        : flash D0-D2 together"));
  Serial.println(F("  boot or b  : reboot to BOOTSEL for upload without BOOT button"));
}

void printBanner() {
  Serial.println();
  Serial.println(F("XIAO RP2040 health check"));
  Serial.println(F("Built-in USER LED cycles R/G/B. Practice board LEDs use D0-D2."));
  Serial.println(F("D3 is analog input, D4/D5 are I2C, D6/D7 are UART, D9 is button input."));
  Serial.println(F("Send 'boot' before upload if the BOOT button is missing but this sketch runs."));
  printHelp();
}

void printReport() {
  int analogRaw = analogRead(kAnalogPin);
  float voltage = (float)analogRaw * kAdcReferenceVoltage / kAdcMaxValue;

  Serial.println();
  Serial.print(F("uptime_ms="));
  Serial.print(millis());
  Serial.print(F("  D9_button="));
  if (digitalRead(kButtonPin) == LOW) {
    Serial.print(F("PRESSED"));
  } else {
    Serial.print(F("released"));
  }
  Serial.print(F("  D3_raw="));
  Serial.print(analogRaw);
  Serial.print(F("  D3_voltage="));
  Serial.print(voltage, 3);
  Serial.print(F("V  Serial1_RX_count="));
  Serial.print(serial1RxCount);
  Serial.print(F("  last_RX="));
  if (lastSerial1Byte < 0) {
    Serial.println(F("none"));
  } else {
    Serial.print(F("0x"));
    if (lastSerial1Byte < 16) {
      Serial.print('0');
    }
    Serial.println(lastSerial1Byte, HEX);
  }

  Serial.print(F("I2C_found="));
  scanI2c(false);
}

void rebootToBootsel() {
  Serial.println(F("Entering BOOTSEL. Wait for the RPI-RP2 drive, then upload with PlatformIO."));
  Serial.flush();
  delay(200);

#if XIAO_HAS_RP2040_USB_BOOT
  reset_usb_boot(0, 0);
#else
  Serial.println(F("This Arduino core does not expose reset_usb_boot()."));
  Serial.println(F("Use the BOOT pad/button or SWD for the next upload."));
#endif
}

void runUartLoopbackCheck() {
  const char pattern[] = "UART";
  char received[sizeof(pattern)] = {};
  uint8_t receivedCount = 0;

  while (Serial1.available()) {
    Serial1.read();
  }

  Serial.println(F("UART loopback check: connect D6(TX) to D7(RX)."));
  Serial1.write((const uint8_t *)pattern, sizeof(pattern) - 1);
  Serial1.flush();

  unsigned long startMs = millis();
  while (millis() - startMs < 200 && receivedCount < sizeof(pattern) - 1) {
    if (Serial1.available()) {
      received[receivedCount++] = (char)Serial1.read();
    }
  }

  if (strncmp(received, pattern, sizeof(pattern) - 1) == 0) {
    Serial.println(F("UART loopback: PASS"));
  } else {
    Serial.print(F("UART loopback: no match, received "));
    Serial.print(receivedCount);
    Serial.println(F(" byte(s)"));
  }
}

void flashPracticeLedsTogether() {
  Serial.println(F("Flashing D0-D2 together."));
  for (uint8_t repeat = 0; repeat < 3; repeat++) {
    for (uint8_t i = 0; i < kPracticeLedCount; i++) {
      digitalWrite(kPracticeLeds[i], HIGH);
    }
    delay(120);
    setPracticeLedsLow();
    delay(120);
  }
}

void handleCommand(String command) {
  command.trim();
  command.toLowerCase();

  if (command.length() == 0) {
    return;
  }

  if (command == "?" || command == "help") {
    printHelp();
  } else if (command == "report") {
    periodicReportEnabled = true;
    printReport();
  } else if (command == "quiet") {
    periodicReportEnabled = false;
    Serial.println(F("Periodic reports disabled. Send 'report' to enable them."));
  } else if (command == "scan" || command == "i2c") {
    scanI2c(true);
  } else if (command == "uart") {
    runUartLoopbackCheck();
  } else if (command == "led") {
    flashPracticeLedsTogether();
  } else if (command == "boot" || command == "b") {
    rebootToBootsel();
  } else {
    Serial.print(F("Unknown command: "));
    Serial.println(command);
    printHelp();
  }
}

void readSerialCommands() {
  while (Serial.available()) {
    char c = (char)Serial.read();

    if (c == '\r' || c == '\n') {
      handleCommand(commandBuffer);
      commandBuffer = "";
    } else if (commandBuffer.length() < 32) {
      commandBuffer += c;
    }
  }
}

void readSerial1Bytes() {
  while (Serial1.available()) {
    lastSerial1Byte = Serial1.read();
    serial1RxCount++;
  }
}

void updatePracticeLedSequence() {
  unsigned long now = millis();
  if (now - lastPracticeLedMs < kPracticeLedIntervalMs) {
    return;
  }

  lastPracticeLedMs = now;
  setPracticeLedsLow();
  digitalWrite(kPracticeLeds[practiceLedIndex], HIGH);
  practiceLedIndex = (practiceLedIndex + 1) % kPracticeLedCount;
}

void updateUserLedSequence() {
  unsigned long now = millis();
  if (now - lastUserLedMs < kUserLedIntervalMs) {
    return;
  }

  lastUserLedMs = now;
  switch (userLedPhase) {
    case 0:
      setUserLed(true, false, false);
      break;
    case 1:
      setUserLed(false, true, false);
      break;
    case 2:
      setUserLed(false, false, true);
      break;
    case 3:
      setUserLed(true, true, true);
      break;
    default:
      setUserLed(false, false, false);
      break;
  }

  userLedPhase = (userLedPhase + 1) % 5;
}

void setup() {
  Serial.begin(SERIAL_MONITOR_SPEED);
  Serial1.begin(9600);
  Wire.begin();

#if defined(ARDUINO_ARCH_RP2040)
  analogReadResolution(12);
#endif

  for (uint8_t i = 0; i < kPracticeLedCount; i++) {
    pinMode(kPracticeLeds[i], OUTPUT);
    digitalWrite(kPracticeLeds[i], LOW);
  }

  pinMode(kAnalogPin, INPUT);
  pinMode(kButtonPin, INPUT_PULLUP);
  pinMode(kUserLedR, OUTPUT);
  pinMode(kUserLedG, OUTPUT);
  pinMode(kUserLedB, OUTPUT);
  setUserLed(false, false, false);

  delay(300);
  printBanner();
}

void loop() {
  readSerialCommands();
  readSerial1Bytes();
  updatePracticeLedSequence();
  updateUserLedSequence();

  if (periodicReportEnabled && millis() - lastReportMs >= kReportIntervalMs) {
    lastReportMs = millis();
    printReport();
  }
}
