#include "snake.h"//snake.back()得到蛇头对应的点，snake.front（）得到蛇尾对应的点
#include "tools.h"
#include <windows.h>
#include <conio.h>//上下左右方向键的字符值分别对应72 80 75 77
/*w:119
a:97
s:115
d:100*/
void Snake::initsnake()//绘制蛇
{
	for (auto& point : snake)
	{
		point.printcircle();
	}
}
void Snake::increase(int _option)//蛇吃到食物之后获得增长
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

//蛇正常移动
void Snake::move(int _option)
{
	snake.front().printclear();
	snake.pop_front();
	increase(_option);
}

//用来判断蛇有没有越出边界
bool Snake::notoutofedge(int _option)
{
	if (_option == 1)
		return snake.back().getx() < 30 && snake.back().getx() > 1 && snake.back().gety() > 1 && snake.back().gety() < 29;
	else
		return true;
}

//用来判断蛇有没有撞到自身
bool Snake::notbiteitself()
{
	{
		int cnt = 0;
		for (Point& point : snake)
		{
			if (point == snake.back())
				cnt++;//cnt用来计算和蛇头重合的点的个数，只要cnt超过了一，就说明蛇头撞到了蛇身
		}
		if (cnt == 1)
			return true;
		else
			return false;
	}
}

//用来判断玩家是否相撞
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

//用来判断蛇有没有转向
bool Snake::changedirection()
{

	char ch;
	if (_kbhit())
	{
		ch = _getch();
		switch (ch)
		{
		case -32://-32是方向键的特殊编码
			ch = _getch();
			switch (ch)
			{
			case 72://上
				if (direction != Direction::DOWN)
					direction = Direction::UP;
				break;
			case 80://下
				if (direction != Direction::UP)
					direction = Direction::DOWN;
				break;
			case 75://左
				if (direction != Direction::RIGHT)
					direction = Direction::LEFT;
				break;
			case 77://右
				if (direction != Direction::LEFT)
					direction = Direction::RIGHT;
				break;
			}
			return true;
		case 27://27对应esc键的字符值，此时函数应该返回false
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
		case 119://上
			if (snake2->direction != Direction::DOWN)
				snake2->direction = Direction::UP;
			break;
		case 115://下
			if (snake2->direction != Direction::UP)
				snake2->direction = Direction::DOWN;
			break;
		case 97://左
			if (snake2->direction != Direction::RIGHT)
				snake2->direction = Direction::LEFT;
			break;
		case 100://右
			if (snake2->direction != Direction::LEFT)
				snake2->direction = Direction::RIGHT;
			break;
		case -32://-32是方向键的特殊编码
			ch = _getch();
			switch (ch)
			{
			case 72://上
				if (direction != Direction::DOWN)
					direction = Direction::UP;
				break;
			case 80://下
				if (direction != Direction::UP)
					direction = Direction::DOWN;
				break;
			case 75://左
				if (direction != Direction::RIGHT)
					direction = Direction::LEFT;
				break;
			case 77://右
				if (direction != Direction::LEFT)
					direction = Direction::RIGHT;
				break;
			}
			return true;
		case 27://27对应esc键的字符值，此时函数应该返回false
			return false;
		default:
			return true;
		}
	}
	return true;
}


//判断蛇有没有吃到食物
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
