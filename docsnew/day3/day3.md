[�O��](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day2/day2.md)�̑����ł��B

---

# �ڎ�

* [�͂��߂�(�n�[�h�E�F�A��)](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day0/day0.md)
* [�͂��߂�(�\�t�g�E�F�A��)](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day0.5/day0.5.md)
* [��1�� L�`�J](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day1/day1.md)
* [��2�� 7�Z�O�����gLED](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day2/day2.md)
* [��3�� �_�C�i�~�b�N�_��](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day3/day3.md)

---

## ����̖ڕW
## 7�Z�O�ł��ꂼ��̌��ɈႤ������\������

---

##  �_�C�i�~�b�N�_��

7�Z�O��4���ɕʁX�̐�����\����������@��**�_�C�i�~�b�N�_��**�ł��I

1. 1����**����**��_�����܂��B���̏�Ԃ�5ms���x�҂��܂��B
2. 2����**����**��_�����܂��B���̏�Ԃ�5ms���x�҂��܂��B
3. 3����**����**��_�����܂��B���̏�Ԃ�5ms���x�҂��܂��B
4. 4����**����**��_�����܂��B���̏�Ԃ�5ms���x�҂��܂��B

1.~4.���J��Ԃ����s���܂��B����ƁA�e���̎c���������邽�߁A4���S�Ă��_�����Ă���悤�Ɍ����܂��B

---

## �g�����W�X�^

n���ڂ����\������v���O�����������Ă����܂��B
�ȒP�̂��߂ɍ�����e���v���[�g���g���Ă����܂��B

```cpp
#include<avr/io.h>
#include<util/delay.h>

int main(void){
    
    DDRD=0b11111111;
    DDRB=0b00001111;

    //LED(i)����������
    int LED[10]=(0b00111111,0b00000110,0b01011011,0100111111,0b01100110,0b00101101,0b01111100,0b00100111,0b01111111,0b01101111);
    #define LED(i) PORTD=led[i]

    //DIGIT(i)����������
    int digit[4]=(0b00000001,0b00000010,0b00000100,0b00001000);
    #define DITGIT(i) PORTB=digit[i+1]

    //�����̉��ɏ�������

}
```
�ȉ��̃R�[�h�����s���Ă݂Ă��������B
```cpp
    while(1){
    DIGIT(n);
    LED(0);
    }
    
```
n���ڂ���0���\������Ă���̂��킩��Ǝv���܂��B

##�@���
7�Z�O��1234�ƕ\�����Ă݂Ă��������B

�y�q���g�z
4���ڂ�1��5ms�\������
�@��
3���ڂ�2��5ms�\������
�@��
2���ڂ�3��5ms�\������
�@��
1���ڂ�4��5ms�\������
�@��
�`�`�`
�@���������[�v

�y���K�z
�������[�v
while(1){
    �v���O����
}

n��J��Ԃ�
for(int i=0:i<n:i++){
    �v���O����
}

7�Z�O��n��\������
LED(n);

7�Z�O��n���ڂɕ\������
DIGIT(n);

---

## �ŏI�ۑ�@0~9999�܂ŃJ�E���g�A�b�v����^�C�}�[����낤�I

�y�q���g�z
for����2�d3�d�Ɏg���ƁH

```cpp
for(int i=0:i<9:i++){
    for(int j=0:j<9:j++){

    }
}
```

�����܂ł����l�ł����I
����ɂēd����Ƒ̌��͏I���ł��I
Meister�ł͂��Ђ���ȂǐV���C�x���g�����ɂ�����̂ł��ЎQ�����Ă݂Ă��������I


