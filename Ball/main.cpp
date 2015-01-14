#include <iostream>
#include <Windows.h>
#include "graphics.h"
using namespace std;

struct Walls
{
	int x1Wall = 250, y1Wall = 150, x2Wall = 550, y2Wall = 550;

	void DrawWalls()
	{
		SgSelectPen(2, SgRGB(0, 0, 0));
		SgSelectBrush(HS_DIAGCROSS, SgRGB(0, 0, 0));
		SgRectangle(x1Wall - 20, y1Wall - 20, x2Wall + 20, y2Wall + 20);
		SgSelectBrush(-1, SgRGB(220, 220, 220));
		SgRectangle(x1Wall, y1Wall, x2Wall, y2Wall);
	}
};

class Ball : public Walls
{
private:
	int x, y, xSpeed = 1, ySpeed = 1;
public:
	Ball()
	{
		x = x1Wall + (x2Wall - x1Wall)*0.5;
		y = y1Wall + (y2Wall - y1Wall)*0.5;
	}

	void Render()
	{
		SgSelectPen(1, SgRGB(0, 0, 0));
		SgSelectBrush(-1, SgRGB(255, 0, 0));
		SgCircle(x, y, 20);
	}

	void Update()
	{
		UpdateSpeed();
		x += xSpeed;
		y += ySpeed;
	}

	void UpdateSpeed()
	{
		if (xSpeed == 1 && x + 21 == x2Wall)
			xSpeed = -1;
		else if (xSpeed == -1 && x - 21 == x1Wall)
			xSpeed = 1;
		if (ySpeed == 1 && y + 21 == y2Wall)
			ySpeed = -1;
		else if (ySpeed == -1 && y - 21 == y1Wall)
			ySpeed = 1;
	}
};

void main()
{
	HWND hConsole = GetConsoleWindow();
	ShowWindow(hConsole, 0);
	Walls W;
	Ball B;
	SgCreate(800, 800, "Ball");
	while (SgIsActive()) {
		SgClearScreen(sgRGB(220, 220, 220));
		W.DrawWalls();
		B.Render();
		B.Update();
		SgFlipPages();
		SgPause(15);
	}
	SgDestroy();
}