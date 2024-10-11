#pragma once
#include "snake.h"
#include "point.h"
class Snake;
class Food
{
private:
	int x, y;
	Point* ptr;
public:
	Food(Snake& rsnake);
	~Food() 
	{
		delete ptr; 
	};
	int getx() { return x; };
	int gety() { return y; };
	void drawfood(bool superfood);
	friend class Point;
	friend class Snake;
};