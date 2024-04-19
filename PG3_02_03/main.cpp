#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
typedef void (*PFunc)(int *);//関数ポインタ

void Correct(int *num) {
	printf("%dで正解\n",*num);
}

void Incorrect(int *num) {
	printf("%dで不正解\n",*num);
}

//コールバック関数
void SetTimeout(PFunc p, int second,int num) {
	Sleep(second * 1000);
	p(&num);
}

int main() {
	PFunc text;//関数ポインタ

	srand((unsigned int)time(nullptr));
	int dice = rand() % 6 + 1;//サイコロの目
	int num  = 0;//予想される数

	printf("予想される値を入力してください(1~6) : ");
	scanf_s("%d", &num);
	printf("%d\n", num);

	//サイコロの目と予想される数が同じか↓
	if (num == dice) {
		text = Correct;
	}
	else {
		text = Incorrect;
	}
	//サイコロの目と予想される数が同じか↑

	SetTimeout(text, 3,num);//3秒後に結果を表示
	return 0;
}

