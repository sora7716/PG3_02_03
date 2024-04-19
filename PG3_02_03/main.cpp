#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
typedef void (*PFunc)();//�֐��|�C���^

void Correct() {
	printf("����\n");
}

void Incorrect() {
	printf("�s����\n");
}

//�R�[���o�b�N�֐�
void SetTimeout(PFunc p, int second) {
	Sleep(second * 1000);
	p();
}

int main() {
	PFunc text;//�֐��|�C���^

	srand((unsigned int)time(nullptr));
	int dice = rand() % 6 + 1;//�T�C�R���̖�
	int num  = 0;//�\�z����鐔

	printf("�\�z�����l����͂��Ă�������(1~6) : ");
	scanf_s("%d", &num);
	printf("%d\n", num);

	//�T�C�R���̖ڂƗ\�z����鐔����������
	if (num == dice) {
		text = Correct;
	}
	else {
		text = Incorrect;
	}
	//�T�C�R���̖ڂƗ\�z����鐔����������

	SetTimeout(text, 3);//3�b��Ɍ��ʂ�\��
	return 0;
}

