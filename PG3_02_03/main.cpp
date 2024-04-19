#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
typedef void (*PFunc)();//�֐��|�C���^

int DiceRoll() {
	srand((unsigned int)time(nullptr));
	int dice = rand() % 6 + 1;//�T�C�R���̖�
	return dice;
}

void Correct() {
	printf("����\n");
}

void Incorrect() {
	printf("�s����\n");
}

void Mistake() {
	printf("���͂��ꂽ�������Ⴂ�܂�");
}

//�R�[���o�b�N�֐�
void SetTimeout(PFunc p, int second) {
	Sleep(second);
	p();
}

int main() {
	PFunc text;//�֐��|�C���^

	int dice = DiceRoll();
	int num  = 0;//�\�z����鐔

	printf("�\�z�����l����͂��Ă������� : \n����:0,�:1\n");
	scanf_s("%d", &num);

	//�T�C�R���̖ڂƗ\�z����鐔����������
	if (num == 0 || num == 1) {
		if (num == 0 && dice % 2 == 0) {
			text = Correct;
		}
		else if (num == 1 && dice % 2 == 1) {
			text = Correct;
		}
		else {
			text = Incorrect;
		}
	}
	else {
		text = Mistake;
	}
	//�T�C�R���̖ڂƗ\�z����鐔����������

	SetTimeout(text, 3000);//3�~���b��Ɍ��ʂ�\��
	return 0;
}

