#include "controller.h"
#include "tools.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "snake.h"
#include "map.h"
#include <fstream>
#include <vector>
#include <algorithm>

void Controller::start()
{
	SetWindowSize(41, 32);
}

void Controller::select1()
{
	SetColor(FOREGROUND_BLUE);
	SetCursorPosition(1, 21);
	std::cout << "选择游戏难度：";
	SetCursorPosition(1, 22);
	std::cout << "上下键选择 回车键确定";
	SetCursorPosition(27, 22);
	SetBackgroundColor();//第一个选项设置背景色以表示当前选中
	std::cout << "简单模式";
	SetCursorPosition(27, 24);
	SetColor(FOREGROUND_RED);
	std::cout << "普通模式";
	SetCursorPosition(27, 26);
	std::cout << "困难模式";
	SetCursorPosition(27, 28);
	std::cout << "炼狱模式";
	SetCursorPosition(0, 31);
	score = 0;
	/*
	-32
	72:上
	-32
	80：下
	-32
	75：左
	-32
	77：右
	*/
	bool enter = false;
	char ch;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 72://上
			if (option == 1)
			{
				option = 4;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(27, 22);
				std::cout << "简单模式";
				SetBackgroundColor();
				SetCursorPosition(27, 28);
				std::cout << "炼狱模式";
				SetColor(FOREGROUND_RED);
			}
			else
			{
				option--;
				switch (option)
				{
				case 3:
					SetCursorPosition(27, 28);
					SetColor(FOREGROUND_RED);
					std::cout << "炼狱模式";
					SetCursorPosition(27, 26);
					SetBackgroundColor();
					std::cout << "困难模式";
					SetColor(FOREGROUND_RED);
					break;
				case 2:

					SetCursorPosition(27, 26);
					SetColor(FOREGROUND_RED);
					std::cout << "困难模式";
					SetCursorPosition(27, 24);
					SetBackgroundColor();
					std::cout << "普通模式";
					SetColor(FOREGROUND_RED);
					break;
				case 1:
					SetCursorPosition(27, 24);
					SetColor(FOREGROUND_RED);
					std::cout << "普通模式";
					SetCursorPosition(27, 22);
					SetBackgroundColor();
					std::cout << "简单模式";
					SetColor(FOREGROUND_RED);
					break;
				default:
					break;
				}
			}

			break;
		case 80://下
			if (option == 4)
			{
				option = 1;

				SetCursorPosition(27, 28);
				SetColor(FOREGROUND_RED);
				std::cout << "炼狱模式";
				SetCursorPosition(27, 22);
				SetBackgroundColor();
				std::cout << "简单模式";
				SetColor(FOREGROUND_RED);
				break;
			}

			else
			{
				option++;
				switch (option)
				{
				case 4:
					SetCursorPosition(27, 26);
					SetColor(FOREGROUND_RED);
					std::cout << "困难模式";
					SetCursorPosition(27, 28);
					SetBackgroundColor();
					std::cout << "炼狱模式";
					SetColor(FOREGROUND_RED);
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetColor(FOREGROUND_RED);
					std::cout << "普通模式";
					SetCursorPosition(27, 26);
					SetBackgroundColor();
					std::cout << "困难模式";
					SetColor(FOREGROUND_RED);
					break;
				case 2:

					SetCursorPosition(27, 22);
					SetColor(FOREGROUND_RED);
					std::cout << "简单模式";
					SetCursorPosition(27, 24);
					SetBackgroundColor();
					std::cout << "普通模式";
					SetColor(FOREGROUND_RED);
					break;
				default:
					break;
				}
			}
			break;
		case 13://输入enter
			enter = true;
			break;
		default:
			break;
		}
		if (enter)
			break;
	}
	switch (option)
	{
	case 1:
		speed = 120;
		break;
	case 2:
		speed = 100;
		break;
	case 3:
		speed = 80;
		break;
	case 4:
		speed = 60;
		break;
	default:
		break;
	}
}

//选择地图
void Controller::select2()
{
	option2 = 1;
	system("cls");//清屏
	SetColor(FOREGROUND_RED);
	SetCursorPosition(20, 26);
	std::cout << "地图2（穿墙）";
	SetBackgroundColor();
	SetCursorPosition(10, 26);
	std::cout << "地图1（不穿墙）";
	SetColor(FOREGROUND_RED);
	bool enter = false;
	char ch;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 75://左
			if (option2 == 1)
			{
				option2 = 2;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(10, 26);
				std::cout << "地图1（不穿墙）";
				SetBackgroundColor();
				SetCursorPosition(20, 26);
				std::cout << "地图2（穿墙）";
				SetColor(FOREGROUND_RED);
				break;
			}
			else
			{
				option2 = 1;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(20, 26);
				std::cout << "地图2（穿墙）";
				SetBackgroundColor();
				SetCursorPosition(10, 26);
				std::cout << "地图1（不穿墙）";
				SetColor(FOREGROUND_RED);
				break;
			}

		case 77://右
			if (option2 == 1)
			{
				option2 = 2;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(10, 26);
				std::cout << "地图1（不穿墙）";
				SetBackgroundColor();
				SetCursorPosition(20, 26);
				std::cout << "地图2（穿墙）";
				SetColor(FOREGROUND_RED);
				break;
			}
			else
			{
				option2 = 1;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(20, 26);
				std::cout << "地图2（穿墙）";
				SetBackgroundColor();
				SetCursorPosition(10, 26);
				std::cout << "地图1（不穿墙）";
				SetColor(FOREGROUND_RED);
				break;
			}

		case 13://输入enter
			enter = true;
			break;
		default:
			break;
		}

		if (enter)
			break;
	}
}

//选择模式
void Controller::select3()
{
	option3 = 1;
	system("cls");//清屏
	SetColor(FOREGROUND_RED);
	SetCursorPosition(15, 26);
	std::cout << "双人";
	SetBackgroundColor();
	SetCursorPosition(10, 26);
	std::cout << "单人";
	SetColor(FOREGROUND_RED);
	bool enter = false;
	char ch;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 75://左
			if (option3 == 1)
			{
				option3 = 2;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(10, 26);
				std::cout << "单人";
				SetBackgroundColor();
				SetCursorPosition(15, 26);
				std::cout << "双人";
				SetColor(FOREGROUND_RED);
				break;
			}
			else
			{
				option3 = 1;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(15, 26);
				std::cout << "双人";
				SetBackgroundColor();
				SetCursorPosition(10, 26);
				std::cout << "单人";
				SetColor(FOREGROUND_RED);
				break;
			}

		case 77://右
			if (option3 == 1)
			{
				option3 = 2;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(10, 26);
				std::cout << "单人";
				SetBackgroundColor();
				SetCursorPosition(15, 26);
				std::cout << "双人";
				SetColor(FOREGROUND_RED);
				break;
			}
			else
			{
				option3 = 1;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(15, 26);
				std::cout << "双人";
				SetBackgroundColor();
				SetCursorPosition(10, 26);
				std::cout << "单人";
				SetColor(FOREGROUND_RED);
				break;
			}

		case 13://输入enter
			enter = true;
			break;
		default:
			break;
		}

		if (enter)
			break;
	}
}

void Controller::drawgame(int _option2)
{
	system("cls");//清屏
	SetColor(FOREGROUND_BLUE);
	Map* ptr = new Map();
	ptr->PrintInitmap(_option2);
	delete ptr;
	SetColor(FOREGROUND_GREEN);
	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(34, 2);
	std::cout << "贪吃蛇";
	SetCursorPosition(31, 4);
	std::cout << "难度：";
	SetCursorPosition(36, 5);
	switch (option)
	{
	case 1:
		std::cout << "简单模式";
		break;
	case 2:
		std::cout << "普通模式";
		break;
	case 3:
		std::cout << "困难模式";
		break;
	case 4:
		std::cout << "炼狱模式";
		break;
	default:
		break;
	}
	SetCursorPosition(31, 7);
	std::cout << "得分：";
	SetCursorPosition(37, 8);
	std::cout << "     0";
	SetCursorPosition(33, 13);
	std::cout << " 方向键移动";
	SetCursorPosition(33, 15);
	std::cout << " ESC键暂停";
}

void Controller::updatescore()
{
	score += option;
	//为保持分数尾部对齐，将最大分数设置为6位，计算当前分数位数，将剩余位数用空格补全，再输出分数
	SetCursorPosition(37, 8);
	SetColor(FOREGROUND_RED);
	int bit = 0;
	int score_bits = score;
	while (score_bits != 0)
	{
		++bit;
		score_bits /= 10;
	}
	for (int i = 0; i < (6 - bit); ++i)
	{
		std::cout << " ";
	}
	std::cout << score;
}

void Controller::writescoretofile(int s)
{
	std::ofstream file("scores.txt", std::ios::app);  // 打开文件以进行追加写入

	if (file.is_open())
	{
		file << s << std::endl;  // 写入分数并换行
		file.close();
	}
	else
	{
		std::cout << "Unable to open file" << std::endl;
	}
}

void Controller::sortscoresinfile()
{
	std::ifstream file("scores.txt");
	std::vector<int> scores;

	int score;
	while (file >> score)
	{
		scores.push_back(score);
	}

	file.close();

	std::sort(scores.begin(), scores.end(), std::greater<int>());  // 按照从大到小排序

	std::ofstream outFile("sorted_scores.txt");
	int rank = 1;
	if (outFile.is_open())
	{
		for (int s : scores)
		{
			outFile << rank << ":" << s << std::endl;
			rank++;
		}
		outFile.close();
	}
	else
	{
		std::cout << "Unable to open output file" << std::endl;
	}
}

int Controller::menu()
{
	SetColor(FOREGROUND_BLUE);
	SetCursorPosition(32, 19);
	std::cout << "菜单：";
	Sleep(100);
	SetCursorPosition(34, 21);
	SetBackgroundColor();
	std::cout << "继续游戏";
	Sleep(100);
	SetCursorPosition(34, 23);
	SetColor(FOREGROUND_GREEN);
	std::cout << "重新开始";
	Sleep(100);
	SetCursorPosition(34, 25);
	std::cout << "退出游戏";
	SetCursorPosition(0, 31);

	/*选择部分*/
	char ch;
	int menuoption = 1;
	bool enter = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 72://上
			if (menuoption == 1)
			{
				menuoption = 3;
				SetCursorPosition(34, 21);
				SetColor(FOREGROUND_GREEN);
				std::cout << "继续游戏";
				SetCursorPosition(34, 25);
				SetBackgroundColor();
				std::cout << "退出游戏";
				break;
			}
			else
			{
				switch (menuoption)
				{
				case 2:
					SetCursorPosition(34, 21);
					SetBackgroundColor();
					std::cout << "继续游戏";
					SetCursorPosition(34, 23);
					SetColor(FOREGROUND_GREEN);
					std::cout << "重新开始";
					--menuoption;
					break;
				case 3:
					SetCursorPosition(34, 23);
					SetBackgroundColor();
					std::cout << "重新开始";
					SetCursorPosition(34, 25);
					SetColor(FOREGROUND_GREEN);
					std::cout << "退出游戏";
					--menuoption;
					break;
				}
			}
			break;
		case 80://DOWN
			if (menuoption == 3)
			{
				menuoption = 1;
				SetCursorPosition(34, 25);
				SetColor(FOREGROUND_GREEN);;
				std::cout << "退出游戏";
				SetCursorPosition(34, 21);
				SetBackgroundColor();
				std::cout << "继续游戏";
				break;
			}
			else
			{
				switch (menuoption)
				{
				case 1:
					SetCursorPosition(34, 23);
					SetBackgroundColor();
					std::cout << "重新开始";
					SetCursorPosition(34, 21);
					SetColor(FOREGROUND_GREEN);
					std::cout << "继续游戏";
					++menuoption;
					break;
				case 2:
					SetCursorPosition(34, 25);
					SetBackgroundColor();
					std::cout << "退出游戏";
					SetCursorPosition(34, 23);
					SetColor(FOREGROUND_GREEN);
					std::cout << "重新开始";
					++menuoption;
					break;
				}
			}
			break;
		case 13://Enter
			enter = true;
			break;
		default:
			break;
		}
		if (enter)
		{
			break;
		}
		SetCursorPosition(0, 31);
	}
	if (menuoption == 1) //选择继续游戏，则将菜单擦除
	{
		SetCursorPosition(32, 19);
		std::cout << "      ";
		SetCursorPosition(34, 21);
		std::cout << "        ";
		SetCursorPosition(34, 23);
		std::cout << "        ";
		SetCursorPosition(34, 25);
		std::cout << "        ";
	}

	return menuoption;
}

int Controller::gameover()
{
	Sleep(500);
	SetColor(FOREGROUND_RED);
	SetCursorPosition(5, 8);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	Sleep(30);
	SetCursorPosition(4, 9);
	std::cout << " ┃               Game Over !!!              ┃";
	Sleep(30);
	SetCursorPosition(4, 10);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(4, 11);
	std::cout << " ┃              很遗憾！你挂了              ┃";
	Sleep(30);
	SetCursorPosition(4, 12);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(4, 13);
	std::cout << " ┃             你的分数为：                 ┃";
	SetCursorPosition(19, 13);
	std::cout << score;
	Sleep(30);
	SetCursorPosition(4, 14);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(4, 15);
	std::cout << " ┃   是否再来一局？                         ┃";
	Sleep(30);
	SetCursorPosition(4, 16);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(4, 17);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(4, 18);
	std::cout << " ┃    嗯，好的        不了，还是学习有意思  ┃";
	Sleep(30);
	SetCursorPosition(4, 19);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(4, 20);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(5, 21);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

	Sleep(100);
	SetCursorPosition(7, 18);
	SetBackgroundColor();
	std::cout << "嗯，好的";
	SetCursorPosition(0, 31);

	/*选择部分*/
	char ch;
	int overoption = 1;
	bool enter = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 75://左
			if ((overoption == 1))
			{
				overoption = 2;
				SetCursorPosition(7, 18);
				SetColor(FOREGROUND_RED);
				std::cout << "嗯，好的";
				SetCursorPosition(15, 18);
				SetBackgroundColor();
				std::cout << "不了，还是学习有意思";
				break;
			}
			else
			{
				SetCursorPosition(7, 18);
				SetBackgroundColor();
				std::cout << "嗯，好的";
				SetCursorPosition(15, 18);
				SetColor(FOREGROUND_RED);
				std::cout << "不了，还是学习有意思";
				--overoption;
			}
			break;

		case 77://右
			if (overoption == 2)
			{
				overoption = 1;
				SetCursorPosition(15, 18);
				SetColor(FOREGROUND_RED);
				std::cout << "不了，还是学习有意思";
				SetCursorPosition(7, 18);
				SetBackgroundColor();
				std::cout << "嗯，好的";
				break;
			}
			else
			{
				SetCursorPosition(15, 18);
				SetBackgroundColor();
				std::cout << "不了，还是学习有意思";
				SetCursorPosition(7, 18);
				SetColor(FOREGROUND_RED);
				std::cout << "嗯，好的";
				++overoption;
			}
			break;

		case 13://输入enter
			enter = true;
			break;

		default:
			break;
		}

		SetCursorPosition(0, 31);
		if (enter) {
			break;
		}
	}

	SetColor(FOREGROUND_RED);
	switch (overoption)
	{
	case 1:
		return 1;//重新开始
	case 2:
		return 2;//退出游戏
	default:
		return 1;
	}
}

int Controller::playgame(int _option)
{
	if (_option == 1)
	{
		bool superfood = false;
		Snake* snake = new Snake();
		Food* food = new Food(*snake);
		SetColor(FOREGROUND_RED);
		snake->initsnake();
		food->drawfood(superfood);
		while (snake->notbiteitself() && snake->notoutofedge(option2))
		{
			if (!snake->changedirection())//输入esc
			{
				int status = menu();//继续游戏status=1，重新游戏status=2，退出游戏status=3
				switch (status)
				{
				case 1://继续游戏
					break;
				case 2://重新开始
					delete snake;
					delete food;
					return 1;//将1作为返回值返回到game函数中，表示重新开始
				case 3:
					return 2;
				default:
					break;
				}
			}
			if (snake->getfood(*food))
			{
				updatescore();
				if (snake->eatfood == 0)
					updatescore();
				snake->increase(option2);
				delete food;
				if (snake->eatfood == 3)
					superfood = true;
				else
					superfood = false;
				food = new Food(*snake);
				food->drawfood(superfood);
			}
			else
			{
				snake->move(option2);
			}
			Sleep(speed);
		}
		delete snake;
		delete food;
		int status = gameover();
		writescoretofile(score);
		sortscoresinfile();
		return status;

	}
	else
	{
		bool superfood = false;
		Snake* snake = new Snake();
		Snake* snake2 = new Snake(1);//这里参数的意义仅仅在于不调用默认构造函数
		Food* food = new Food(*snake);
		SetColor(FOREGROUND_RED);
		snake->initsnake();
		snake2->initsnake();
		food->drawfood(superfood);
		while (snake->notbiteitself() && snake->notoutofedge(option2) && snake2->notbiteitself() && snake->notoutofedge(option2) && snake->notbiteeachother(snake2) && snake2->notbiteeachother(snake))
		{
			if (!snake->changedirection2(snake2))//输入esc
			{
				int status = menu();//继续游戏status=1，退出游戏status=3
				switch (status)
				{
				case 1://继续游戏
					break;
				case 3:
					return 2;
				case 2://重新开始
					delete snake;
					delete snake2;
					delete food;
					return 1;//将1作为返回值返回到game函数中，表示重新开始

				default:
					break;
				}
			}
			if (snake->getfood(*food) || snake2->getfood(*food))
			{
				updatescore();
				if (snake->eatfood + snake2->eatfood == 0)
					updatescore();
				if (snake->getfood(*food))
					snake->increase(option2);
				else
					snake2->increase(option2);
				delete food;
				food = new Food(*snake);
				if (snake->eatfood + snake2->eatfood == 3)
					superfood = true;
				else
					superfood = false;
				food->drawfood(superfood);
			}
			else
			{
				snake->move(option2);
				snake2->move(option2);
			}
			Sleep(speed);
		}
		delete snake;
		delete food;
		int status = gameover();
		writescoretofile(score);
		sortscoresinfile();
		return status;
	}

}


void Controller::game()
{
	start();//开始界面,设置控制台窗口大小
	while (true)//游戏可视为一个死循环，直到退出游戏时循环结束
	{
		select1();//选择界面,选择游戏难度
		select2();//选择界面，选择地图（是否穿墙）
		select3();//选择界面，选择模式（单人或双人）

		drawgame(option2);//绘制游戏界面
		int status = playgame(option3);//开启游戏循环，当重新开始或退出游戏时，结束循环并返回值给status
		if (status == 1) //返回值为1时重新开始游戏
		{
			system("cls");
			continue;
		}
		else if (status == 2) //返回值为2时退出游戏
		{
			break;
		}
		else
		{
			break;
		}
	}
}

