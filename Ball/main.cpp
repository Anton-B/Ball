#include <iostream>
#include <Windows.h>
#include "graphics.h"
using namespace std;

class Ball
{
private:
	int x, y;
public:
	void setXY(const int &x1, const int &y1, const int &x2, const int &y2)
	{
		x = x1 + (x2 - x1)*0.5;
		y = y1 + (y2 - y1)*0.5;
	}
	void DrawBall()
	{
		SgSelectPen(1, SgRGB(0, 0, 0));
		SgSelectBrush(-1, SgRGB(255, 0, 0));
		SgCircle(x, y, 20);
		
	}

	void Direction(const int &x1, const int &y1, const int &x2, const int &y2, char &xD, char &yD)
	{
		if (xD == '+' && yD == '+')
		{
			x = (x + 21 == x2) ? x - 1 : x + 1;
			xD = (x + 21 == x2) ? '-' : '+';
			y = (y + 21 == y2) ? y - 1 : y + 1;
			yD = (y + 21 == y2) ? '-' : '+';
		}
		else if (xD == '+' && yD == '-')
		{
			x = (x + 21 == x2) ? x - 1 : x + 1;
			xD = (x + 21 == x2) ? '-' : '+';
			y = (y - 21 == y1) ? y + 1 : y - 1;
			yD = (y - 21 == y1) ? '+' : '-';
		}
		else if (xD == '-' && yD == '+')
		{
			x = (x - 21 == x1) ? x + 1 : x - 1;
			xD = (x - 21 == x1) ? '+' : '-';
			y = (y + 21 == y2) ? y - 1 : y + 1;
			yD = (y + 21 == y2) ? '-' : '+';
		}
		else if (xD == '-' && yD == '-')
		{
			x = (x - 21 == x1) ? x + 1 : x - 1;
			xD = (x - 21 == x1) ? '+' : '-';
			y = (y - 21 == y1) ? y + 1 : y - 1;
			yD = (y - 21 == y1) ? '+' : '-';
		}
	}
};

void Walls(const int &x1, const int &y1, const int &x2, const int &y2)
{
	SgSelectPen(2, SgRGB(0, 0, 0));
	SgSelectBrush(HS_DIAGCROSS, SgRGB(0, 0, 0));
	SgRectangle(x1-20, y1-20, x2+20, y2+20);
	SgSelectBrush(-1, SgRGB(220, 220, 220));
	SgRectangle(x1, y1, x2, y2);
}

void main()
{
	HWND hConsole = GetConsoleWindow();
	ShowWindow(hConsole, 0);
	int x1Wall = 250, y1Wall = 150, x2Wall = 550, y2Wall = 550;
	char xDirection = '+', yDirection = '+';
	Ball B;
	B.setXY(x1Wall, y1Wall, x2Wall, y2Wall);
	SgCreate(800, 800, "Ball");
	while (SgIsActive()) {
		SgClearScreen(sgRGB(220, 220, 220));
		Walls(x1Wall, y1Wall, x2Wall, y2Wall);
		B.DrawBall();
		B.Direction(x1Wall, y1Wall, x2Wall, y2Wall, xDirection, yDirection);
		SgFlipPages();
		SgPause(10);
	}
}