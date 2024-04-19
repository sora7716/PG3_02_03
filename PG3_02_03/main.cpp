#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
typedef void (*PFunc)();//関数ポインタ

int DiceRoll() {
	srand((unsigned int)time(nullptr));
	int dice = rand() % 6 + 1;//サイコロの目
	return dice;
}

void Correct() {
	printf("正解\n");
}

void Incorrect() {
	printf("不正解\n");
}

void Mistake() {
	printf("入力された数字が違います");
}

//コールバック関数
void SetTimeout(PFunc p, int second) {
	Sleep(second);
	p();
}

int main() {
	PFunc text;//関数ポインタ

	int dice = DiceRoll();
	int num  = 0;//予想される数

	printf("予想される値を入力してください : \n偶数:0,奇数:1\n");
	scanf_s("%d", &num);

	//サイコロの目と予想される数が同じか↓
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
	//サイコロの目と予想される数が同じか↑

	SetTimeout(text, 3000);//3ミリ秒後に結果を表示
	return 0;
}

