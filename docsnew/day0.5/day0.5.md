[�O��](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day0)�̑����ł��B

---

# �ڎ�


* [�͂��߂�(�n�[�h�E�F�A��)](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day0/)
* [�͂��߂�(�\�t�g�E�F�A��)](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day0.5/)
* [��1�� ���W�X�^��L�`�J](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day1/)
* [��2�� 7�Z�O�����gLED](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day2/)
* [��3�� �_�C�i�~�b�N�_��](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day3/)
* [��4�� �^�C�}���荞��](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day4/)
* [��5�� �T�[�~�X�^��AD�ϊ�](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day5/)
---
## 4. �J�����̍\�z

### 4.1. Arduino���C���X�g�[��

https://www.arduino.cc/en/software ����Arduino IDE���_�E�����[�h&�C���X�g�[�����Ă��������B


### 4.2. Board Manager���Ǘ�����

Arduino IDE���J����Preferences���J���Ă��������B�ȉ��̂悤�ȉ�ʂɂȂ�Ǝv���܂��B
![](img/fig2.png)

�ʐ^�̂悤�ɁA`Additional board manager URLs:`�̗���```https://mcudude.github.io/MiniCore/package_MCUdude_MiniCore_index.json```��ǉ����Ă��������B
�I�������`OK`�������܂��B

![](img/fig3.png)

���ɉE�̃{�[�h�̃A�C�R�����N���b�N���Ă݂܂��傤�B��̂悤�Ȃ��̂��o��͂��ł��B`BOARD MANAGER`�̗���`MiniCore`�Ɠ��͂���Ɖ摜�̂悤�ɕ\�������ł��傤�B
�I�������`INSTALL`�������Ă��������B

### 4.3. �R���p�C���A���C�^�[�̐ݒ�


�܂��ATools > Board > MiniCore > ATmega88 �ƑI�����Ă����Ă��������B

![](img/fig4.png)

���ɁA�摜�̂悤�ɁATools > Clock > Internal 1MHz�@�ƑI�сA�N���b�N���g����ݒ肵�܂��B

![](img/fig5.png)

�Ō�ɁA Tools > Programmer > Arduino as ISP �ƑI�����Ă��������B

![](img/fig6.png)



�ȏ�Ŋ��\�z�͏I���ł��B[����](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day1/)��L�`�J���܂��B

---

## 5. AVR���C�^�[��p�ӂ��� (���܂�)

AVR�}�C�R���ɏ������ނ��߂ɂ́AAVR���C�^�[�Ƃ������̂��K�v�ł��B�����ł́AArduino���g����AVR���C�^�[������Ă݂܂��B

### 5.1. �t�@�[���E�F�A����������

�܂��AArduino IDE���N�����Ă��������B

�N���o������A�ȉ��̉摜�̂悤�� File > Examples > 11 ArduinoISP > ArduinoISP �ƑI��ł��������B

![](img/fig7.png)

��������ƁAArduinoISP�̃X�P�b�`���J�����Ǝv���܂��B���x��Arduino��ڑ����A���̃X�P�b�`��Arduino�ɏ������݂܂��傤�BCtrl+U�Ɖ����Ώ������܂�܂��B

### 5.2. �z������

�t�@�[���E�F�A����������Arduino�ƃ^�[�Q�b�g����IC���ȒP�ɐڑ��ł���悤�ɁA�z�����܂��B

|�s���̖��O|Arduino��|ICSP�[�q��|
|-|-|-|
|GND|GND|4|
|VCC|5V|6|
|RST|D10|3|
|MISO|D11|1|
|MOSI|D12|5|
|SCK|D13|2|
---

## �i�Q�l�j�g���}�C�R��IC�ɂ���

2023�N��Meister�̍�Ƒ̌��ł�ATmega88�Ƃ����}�C�R��IC���g���܂��BArduino UNO�Ɏg���Ă���ATmega328p�̒핪�݂����Ȃ�ł��ˁB

�f�[�^�V�[�g�F[https://ww1.microchip.com/downloads/en/DeviceDoc/ATmega48_88_168_megaAVR-Data-Sheet-40002074.pdf](https://ww1.microchip.com/downloads/en/DeviceDoc/ATmega48_88_168_megaAVR-Data-Sheet-40002074.pdf)

�����̕s���̍��ł�250�~���x�ƂƂĂ������ł��B
