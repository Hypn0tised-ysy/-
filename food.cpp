#include "food.h"
#include "tools.h"
#include <ctime>//用于获取系统时间产生种子
#include <cstdlib>//用于产生随机数
#include <iostream>
#include <windows.h>
Food::Food(Snake& rsnake)
{
	int x0, y0;
	while (true) 
	{
		srand(time(NULL));
		int a = 2, b = 29;
		x0 = a + rand() % (b - a + 1);//取模运算再加a能让x的范围位于a到b之间
		y0 = a + rand() % (b - a );
		bool overlap = false;//overlap 重叠
		for (Point& point : rsnake.snake)
		{
			if (x0 == point.getx() && y0 == point.gety())
			{
				overlap = true;
				break;
			}
		}
		if (!overlap)
			break;
	}
	this->x = x0;
	this->y = y0;

}

void Food::drawfood(bool superfood)
{
	if (!superfood)
	{
		ptr = new Point(x, y);
		SetColor(FOREGROUND_GREEN);
		ptr->printstar();
		
	}
	else
	{
		ptr = new Point(x, y);
		SetBackgroundColor();
		ptr->printstar();
		SetColor(FOREGROUND_GREEN);
	}

}
	


