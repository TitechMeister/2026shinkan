[�O��](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day0.5/day0.5.md)�̑����ł��B�����LED���`�J�`�J�����܂��B

---

# �ڎ�

* [�͂��߂�(�n�[�h�E�F�A��)](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day0/day0.md)
* [�͂��߂�(�\�t�g�E�F�A��)](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day0.5/day0.5.md)
* [��1�� L�`�J](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day1/day1.md)
* [��2�� 7�Z�O�����gLED](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day2/day2.md)
* [��3�� �_�C�i�~�b�N�_��](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day3/day3.md)


---

## ����̖ڕW
## �v���O�������}�C�R���ɏ��������L�`�J������I�I�I

---

## 6. �v���O���~���O����ɂ���

�����C������g���ĊJ�����܂��B

C����̕׋��̂������߃T�C�g��
[�ꂵ��Ŋo����C����](https://9cguide.appspot.com/)

---
## 7.�v���O����

### 7.1 �v���O����������
�Ƃ肠�����A�v���O�����������Ă݂܂��傤�B����͈̂ȉ��̂悤�ɂȂ�܂��B

```cpp
#include<avr/io.h>
#include<util/delay.h>

int main(void){
	DDRC=0b00000001;//���o�̓��[�h��ݒ�
	while(1){
		PORTC=0b00000001;//�_��
		_delay_ms(1000);//��b�҂�
		PORTC=0b00000000;//����
		_delay_ms(1000);//��b�҂�
	}
	return 0;
}
```
### �y�⑫�z�������[�v
```cpp
while(1){
	�v���O����
}
```
���̂悤�ɏ������v���O�����͖����Ƀ��[�v�����s���ꑱ����

### 7.2�v���O�������}�C�R���ɏ�������

step1.[�O��](https://github.com/TitechMeister/Device-ATmega88_Board/tree/main/docs/day0/)�̒ʂ��ArduinoIDE��ݒ肷��

step2.�Ԙg�����Ƀv���O�������R�s�y
<img width="512" src="./img/sinkan1.png"></img>

step3.�Ԙg�̕������v�b�V���I

<img width ='512' src="./img/sinkan2.png"></img>

�v���O�����̏������݂��I���܂����B
�����LED�_�ŁiL�`�J�j���ł����͂��ł��I�I�I

---

##�@�������G���[���ł���H
<img width ='512' src="./img/sinkan3.png"></img>

����g���Ă���atmega88V�Ƃ����}�C�R���͏�������ŏ�̎ʐ^�̂悤�ȃG���[���o�邩������܂���B
~~�q�ɂɗ]���Ă����}�C�R����K���ɑI�񂾂����ł��B���߂�Ȃ���~~

���̎��́AArduinoIDE�Ƃ͕ʂ̕��@�Ń}�C�R���ɏ������݂����܂��傤�I

###�@�������ݕ��@

step1.[Winavr](https://sourceforge.net/projects/winavr/)���_�E�����[�h
<img width ='512' src="./img/sinkan4.png"></img>
step2.ArduinoIDE��.hex�t�@�C�������

�@�v���O������ۑ�����B
<img width ='512' src="./img/sinkan5.png"></img>

�A.hex�t�@�C�������
<img width ='512' src="./img/sinkan6.png"></img>

�B.hex�t�@�C�����ł���
<img width ='512' src="./img/sinkan7.png"></img>

step3.�R�}���h�v�����v�g����winavr���N����.hex�t�@�C�����}�C�R���ɏ�������

.hex�̃A�h���X���R�s�y���Ĉȉ��̎��������������悤�I
```
avrdude -c usbtiny -p m88 -U flash:w:{.hex�̃A�h���X�ɕς���}

```
�ȉ��̎������R�}���h�v�����v�g�ɑł��������I

�ȏ�Ń}�C�R���ɏ������߂��͂��ł��B


---
[����:DAY2_7�Z�OLED](https://github.com/TitechMeister/2026shinkan/blob/main/docsnew/day2/day2.md)