#include <iostream>
#include <windows.h>
#include "Tetris.h"


int main() {
	_COORD coord;
	coord.X = 200;
	coord.Y = 50;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Right = 200-1;
	Rect.Bottom = 50-1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);


	View window;
	window.drawwindow(0, 0, 20, 20);


	return 0;
}