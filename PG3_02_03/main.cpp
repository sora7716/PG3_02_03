#include <stdio.h>
#include <Windows.h>

typedef void (*PFunc)(int*);

void DispResult(int* s) {
	printf("%d�b��҂��Ď��s���ꂽ��\n", *s);
}

void setTimeout(PFunc p, int second) {
	Sleep(second * 1000);

	p(&second);
}

int main() {
	printf("start\n");
	PFunc p;
	p = DispResult;
	setTimeout(p,5);
	return 0;
}