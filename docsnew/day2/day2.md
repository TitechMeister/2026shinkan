[�O��](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day1/day1.md)�̑����ł��B

---

# �ڎ�

* [�͂��߂�(�n�[�h�E�F�A��)](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day0/day0.md)
* [�͂��߂�(�\�t�g�E�F�A��)](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day0.5/day0.5.md)
* [��1�� L�`�J](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day1/day1.md)
* [��2�� 7�Z�O�����gLED](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day2/day2.md)
* [��3�� �_�C�i�~�b�N�_��](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day3/day3.md)

---

## ����̖ڕW
## 7�Z�O�ŃJ�E���g�A�b�v����v���O����������

---

�����7�Z�O���g����0~9�܂łŃJ�E���g�A�b�v����v���O�����������Ă݂܂��傤�I

�ȒP�̂��߂Ƀe���v���[�g��p���܂��B�R�[�h�𖄂߂ăe���v���[�g�����������悤�I

```cpp
#include<avr/io.h>
#include<util/delay.h>

int main(void){
    DDRD=0b11111111;
    DDRB=0b00001111;
    PORTB=0b00001111;

    int led[10]=(0b00111111,0b00000110,0b01011011,0100111111,0b01100110,0b00101101,0b01111100,0b00100111,0b01111111,0b01101111)
    #define LED(i) PORTD=led[i]
    

    //�����̉��ɏ�������
}
```
������LED[n]��n��0~9�������ď������ނƁH

---


## �ł́A�����ŃJ�E���g�A�b�v����v���O�����������Ă݂܂��傤�I

�y�q���g�z
for����delay��LED(n)���g���΃J�E���g�A�b�v���ł����I

Q.for���Ƃ�
A.
������

```cpp
for(int i=0:i<n:i++){
    �v���O����
}
```
����
i=0�ɂȂ�
�@��
�v���O���������s�����
�@��
�v���O�������I���
�@��
i=1�ɂȂ�
�@��
�v���O���������s�����
�@��
�`�`�`
�@��
i=n�ɂȂ�����I��

[����ŏI��:DAY3_�_�C�i�~�b�N�_��](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day3/day3.md)