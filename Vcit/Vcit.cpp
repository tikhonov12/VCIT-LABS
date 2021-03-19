#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
void lab4() {
	int counter = 100001;
	int count = 100000;
	int y = 2;
	int x = 0;
	int q = 500;
	int r;
	int out = 0;

	int outnum;

	_asm {
		mov eax, x			// переменая для сравнивания предыдущего х
		mov ebx, y			// делитель на проверку простого числа
		mov ecx, 1
		start:
		mov x, eax
			cmp ecx, counter
				je en
			mov eax, ecx
			add eax, ecx	//|
			dec eax			//|
			mov edx, 0		//|
			div q			//(x-x-1)/500
			inc ecx
			mov ebx, y
			cmp eax, 0		//|
				je dcntr	//|
			cmp eax, 1		//|если x=1||0 || x[i-1]
				je dcntr	//|
			cmp eax, x		//|
				je dcntr	//|
			jmp rnd
dcntr :
		dec count
			jmp start
rnd :						// проверка на простоту числа
		cmp eax, 2			// если 2, то простое
				je m6
			cmp ebx, eax
				jge m6
			mov edx, 0
			mov r, eax
			div ebx
			mov eax, r
			cmp edx, 0
				je dcntr
			inc ebx
				jmp rnd

	m6:
		cmp out, 52
			je start
			inc out
			mov outnum, ecx
			jmp start
	en:
	} 
	cout << endl << count << endl;
	cout << "CountNum[51] = " << outnum;
}

void lab3() {
	signed char a = 20; //1 байт
	signed char b = 30; //1 байт
	short q3, q4, c = 10; //2 байта
	int q1, q2;

	signed char q;
	//d=(a^2)*b/c
	_asm {
		mov al, a
		imul al
		cwde
		mov ebx, eax
		mov al, b
		cbw
		cwde
		imul ebx
		movsx ecx, c
		idiv ecx
		mov q1, eax //вывод
		mov q2, edx //остаток
	}
	cout << dec << "10 :\n\t" << q1 << "\%" << q2 << "\n" << "\n16 :\n\t" << hex << q1 << "\ % " << q2 << "\n" << endl;
	//e=(a-b)/(a-c)
	_asm {
		mov al, a
		sub al, b
		mov b, al
		mov al, a
		cbw
		sub ax, c
		mov c, ax
		mov al, b
		cbw
		cwd
		idiv c
		mov q3, ax //вывод
		mov q4, dx //остаток
	}
	cout << dec << "10 :\n\t" << q3 << "\%" << q4 << "\n" << "\n16 :\n\t" << hex << q3 << "\ % " << q4 << endl;
}
template <typename T>
void to_binary(unsigned char* link, T x)
{
	for (int i = sizeof(x) - 1; i >= 0; i--)
	{
		for (int j = 7; j > 0; j--)
		{
			switch ((link[i]<< j) & 1)
			{
			case 1: cout << 1; break;
			case 0: cout << 0; break;
			}
		}
	}
	cout << endl;
}
void lab1()
{
	signed char scx;
	char16_t c16x;
	int inx;
	double dx;
	float fx;
	cout << typeid(scx).name() << " Byte:" << sizeof(scx) << endl; to_binary((unsigned char*)&scx, scx = 10); to_binary((unsigned char*)&scx, scx = -10); cout << endl;
	cout <<  typeid(c16x).name() << " Byte:" << sizeof(c16x) << endl; to_binary((unsigned char*)&c16x, c16x = 10); to_binary((unsigned char*)&c16x, c16x = -10); cout << endl;
	cout <<  typeid(inx).name() << " Byte:" << sizeof(inx) << endl; to_binary((unsigned char*)&inx, inx = 10); to_binary((unsigned char*)&inx, inx = -10); cout << endl;
	cout <<  typeid(fx).name() << " Byte:" << sizeof(fx) << endl; to_binary((unsigned char*)&fx, fx = 1152.12); to_binary((unsigned char*)&fx, fx = -1152.12); cout << endl;
	cout <<  typeid(dx).name() << " Byte:" << sizeof(dx) << endl; to_binary((unsigned char*)&dx, dx = 1032.12); to_binary((unsigned char*)&dx, dx = -1032.12); cout << endl;
}
int main()
{
	lab4();
}
