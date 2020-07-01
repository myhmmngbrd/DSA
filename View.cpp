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
void View::drawwindow(int x, int y, int w, int h) {
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
	for (int i = 1; i <= w; i++) {
		gotoxy(x + i, y);
		printf("─");
		gotoxy(x + i, y + h + 1);
		printf("─");
	}
	for (int i = 1; i <= h; i++) {
		gotoxy(x, y + i);
		printf("│");
		gotoxy(x + w + 2, y + i);
		printf("│");
	}
	for (int i = 1; i <= w/2; i++) {
		gotoxy(x + i * 2, y+1);
		printf("□");
	}
	for (int i = 1; i <= h; i++) {
		gotoxy(x + 2, y + i);
		printf("■");
	}
	gotoxy(x, y);
	printf("┏");
	gotoxy(x + w + 2, y);
	printf("┓");
	gotoxy(x, y + h + 1);
	printf("┗");
	gotoxy(x + w + 2, y + h + 1);
	printf("┛");
}