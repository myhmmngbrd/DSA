#pragma once
class View
{
	void gotoxy(int x, int y);
public:
	View();
	void drawbox(int startx, int starty, int width, int height);
};

