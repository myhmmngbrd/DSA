#include <iostream>
#include <windows.h>
#include "View.h"

View::View() {

}
void View::gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void View::drawbox(int x, int y, int w, int h) {
	/*
	* 좌상: ┌
	* 좌하: └
	* 우상: ┐
	* 우하: ┘
	* 가로: ─
	* 세로: │
	* 박스: □ ■
	*
	*/
	for (int i = 1; i < w; i++) {
		gotoxy(x + i, y);
		printf("─");
		gotoxy(x + i, y + h);
		printf("─");
	}
	for (int i = 1; i < h; i++) {
		gotoxy(x, y + i);
		printf("│");
		gotoxy(x + w, y + i);
		printf("│");
	}
	gotoxy(x, y);
	printf("┌");
	gotoxy(x + w, y);
	printf("┐");
	gotoxy(x, y + h);
	printf("└");
	gotoxy(x + w, y + h);
	printf("┘");
}