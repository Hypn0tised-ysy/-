#include "food.h"
#include "tools.h"
#include <ctime>//���ڻ�ȡϵͳʱ���������
#include <cstdlib>//���ڲ��������
#include <iostream>
#include <windows.h>
Food::Food(Snake& rsnake)
{
	int x0, y0;
	while (true) 
	{
		srand(time(NULL));
		int a = 2, b = 29;
		x0 = a + rand() % (b - a + 1);//ȡģ�����ټ�a����x�ķ�Χλ��a��b֮��
		y0 = a + rand() % (b - a );
		bool overlap = false;//overlap �ص�
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
	


