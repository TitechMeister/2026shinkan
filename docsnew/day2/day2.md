[�O��](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day0/)�̑����ł��B�����LED���`�J�`�J�����܂��B

---

# �ڎ�

* [�͂��߂�(�n�[�h�E�F�A��)](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day0/)
* [�͂��߂�(�\�t�g�E�F�A��)](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day0.5/)
* [��1�� L�`�J](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day1/)
* [��2�� 7�Z�O�����gLED](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day2/)
* [��3�� �_�C�i�~�b�N�_��](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day3/)
* [��4�� �^�C�}���荞��](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day4/)
* [��5�� �T�[�~�X�^��AD�ϊ�](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day5/)

---

## ����̖ڕW
## 7�Z�O�ŃJ�E���g�A�b�v����v���O����

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

����