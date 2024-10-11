#include "snake.h"//snake.back()�õ���ͷ��Ӧ�ĵ㣬snake.front�����õ���β��Ӧ�ĵ�
#include "tools.h"
#include <windows.h>
#include <conio.h>//�������ҷ�������ַ�ֵ�ֱ��Ӧ72 80 75 77
/*w:119
a:97
s:115
d:100*/
void Snake::initsnake()//������
{
	for (auto& point : snake)
	{
		point.printcircle();
	}
}
void Snake::increase(int _option)//�߳Ե�ʳ��֮��������
{
	if (_option == 1)
	{
		switch (direction)
		{
		case Snake::UP:
			snake.emplace_back(snake.back().getx(), snake.back().gety() - 1);
			break;
		case Snake::DOWN:
			snake.emplace_back(snake.back().getx(), snake.back().gety() + 1);
			break;
		case Snake::RIGHT:
			snake.emplace_back(snake.back().getx() + 1, snake.back().gety());
			break;
		case Snake::LEFT:
			snake.emplace_back(snake.back().getx() - 1, snake.back().gety());
			break;
		default:
			break;
		}
		SetColor(FOREGROUND_RED);
		snake.back().printcircle();
	}
	else
	{
		switch (direction)
		{
		case Snake::UP:
			if (snake.back().gety() == 1)
				snake.emplace_back(snake.back().getx(), 30 - snake.back().gety());
			else
				snake.emplace_back(snake.back().getx(), snake.back().gety() - 1);
			break;
		case Snake::DOWN:
			if (snake.back().gety() == 29)
				snake.emplace_back(snake.back().getx(), 30 - snake.back().gety());
			else
				snake.emplace_back(snake.back().getx(), snake.back().gety() + 1);
			break;
		case Snake::RIGHT:
			if (snake.back().getx() == 30)
				snake.emplace_back(31 - snake.back().getx(), snake.back().gety());
			else
				snake.emplace_back(snake.back().getx() + 1, snake.back().gety());
			break;
		case Snake::LEFT:
			if (snake.back().getx() == 1)
				snake.emplace_back(31 - snake.back().getx(), snake.back().gety());
			else
				snake.emplace_back(snake.back().getx() - 1, snake.back().gety());
			break;
		default:
			break;
		}
		SetColor(FOREGROUND_RED);
		snake.back().printcircle();
	}
}

//�������ƶ�
void Snake::move(int _option)
{
	snake.front().printclear();
	snake.pop_front();
	increase(_option);
}

//�����ж�����û��Խ���߽�
bool Snake::notoutofedge(int _option)
{
	if (_option == 1)
		return snake.back().getx() < 30 && snake.back().getx() > 1 && snake.back().gety() > 1 && snake.back().gety() < 29;
	else
		return true;
}

//�����ж�����û��ײ������
bool Snake::notbiteitself()
{
	{
		int cnt = 0;
		for (Point& point : snake)
		{
			if (point == snake.back())
				cnt++;//cnt�����������ͷ�غϵĵ�ĸ�����ֻҪcnt������һ����˵����ͷײ��������
		}
		if (cnt == 1)
			return true;
		else
			return false;
	}
}

//�����ж�����Ƿ���ײ
bool Snake::notbiteeachother(Snake* snake2)
{
	bool notbite = true;
	for (Point& point : snake2->snake)
	{
		if (snake.back().getx() == point.getx() && snake.back().gety() == point.gety())
			notbite = false;
	}
	return notbite;

}

//�����ж�����û��ת��
bool Snake::changedirection()
{

	char ch;
	if (_kbhit())
	{
		ch = _getch();
		switch (ch)
		{
		case -32://-32�Ƿ�������������
			ch = _getch();
			switch (ch)
			{
			case 72://��
				if (direction != Direction::DOWN)
					direction = Direction::UP;
				break;
			case 80://��
				if (direction != Direction::UP)
					direction = Direction::DOWN;
				break;
			case 75://��
				if (direction != Direction::RIGHT)
					direction = Direction::LEFT;
				break;
			case 77://��
				if (direction != Direction::LEFT)
					direction = Direction::RIGHT;
				break;
			}
			return true;
		case 27://27��Ӧesc�����ַ�ֵ����ʱ����Ӧ�÷���false
			return false;
		default:
			return true;
		}
	}
	return true;
}

bool Snake::changedirection2(Snake* snake2)
{
	char ch;
	if (_kbhit())
	{
		ch = _getch();
		switch (ch)
		{
		case 119://��
			if (snake2->direction != Direction::DOWN)
				snake2->direction = Direction::UP;
			break;
		case 115://��
			if (snake2->direction != Direction::UP)
				snake2->direction = Direction::DOWN;
			break;
		case 97://��
			if (snake2->direction != Direction::RIGHT)
				snake2->direction = Direction::LEFT;
			break;
		case 100://��
			if (snake2->direction != Direction::LEFT)
				snake2->direction = Direction::RIGHT;
			break;
		case -32://-32�Ƿ�������������
			ch = _getch();
			switch (ch)
			{
			case 72://��
				if (direction != Direction::DOWN)
					direction = Direction::UP;
				break;
			case 80://��
				if (direction != Direction::UP)
					direction = Direction::DOWN;
				break;
			case 75://��
				if (direction != Direction::RIGHT)
					direction = Direction::LEFT;
				break;
			case 77://��
				if (direction != Direction::LEFT)
					direction = Direction::RIGHT;
				break;
			}
			return true;
		case 27://27��Ӧesc�����ַ�ֵ����ʱ����Ӧ�÷���false
			return false;
		default:
			return true;
		}
	}
	return true;
}


//�ж�����û�гԵ�ʳ��
bool Snake::getfood(Food& food)
{
	if (snake.back().getx() == food.x && snake.back().gety() == food.y)
	{
		eatfood++;
		eatfood %= 4;
		return true;
	}

	else
		return false;
}
