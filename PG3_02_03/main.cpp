#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
typedef void (*PFunc)(int *);//�֐��|�C���^

void Correct(int *num) {
	printf("%d�Ő���\n",*num);
}

void Incorrect(int *num) {
	printf("%d�ŕs����\n",*num);
}

//�R�[���o�b�N�֐�
void SetTimeout(PFunc p, int second,int num) {
	Sleep(second * 1000);
	p(&num);
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

	SetTimeout(text, 3,num);//3�b��Ɍ��ʂ�\��
	return 0;
}

