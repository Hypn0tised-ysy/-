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
	std::cout << "ѡ����Ϸ�Ѷȣ�";
	SetCursorPosition(1, 22);
	std::cout << "���¼�ѡ�� �س���ȷ��";
	SetCursorPosition(27, 22);
	SetBackgroundColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	std::cout << "��ģʽ";
	SetCursorPosition(27, 24);
	SetColor(FOREGROUND_RED);
	std::cout << "��ͨģʽ";
	SetCursorPosition(27, 26);
	std::cout << "����ģʽ";
	SetCursorPosition(27, 28);
	std::cout << "����ģʽ";
	SetCursorPosition(0, 31);
	score = 0;
	/*
	-32
	72:��
	-32
	80����
	-32
	75����
	-32
	77����
	*/
	bool enter = false;
	char ch;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 72://��
			if (option == 1)
			{
				option = 4;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(27, 22);
				std::cout << "��ģʽ";
				SetBackgroundColor();
				SetCursorPosition(27, 28);
				std::cout << "����ģʽ";
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
					std::cout << "����ģʽ";
					SetCursorPosition(27, 26);
					SetBackgroundColor();
					std::cout << "����ģʽ";
					SetColor(FOREGROUND_RED);
					break;
				case 2:

					SetCursorPosition(27, 26);
					SetColor(FOREGROUND_RED);
					std::cout << "����ģʽ";
					SetCursorPosition(27, 24);
					SetBackgroundColor();
					std::cout << "��ͨģʽ";
					SetColor(FOREGROUND_RED);
					break;
				case 1:
					SetCursorPosition(27, 24);
					SetColor(FOREGROUND_RED);
					std::cout << "��ͨģʽ";
					SetCursorPosition(27, 22);
					SetBackgroundColor();
					std::cout << "��ģʽ";
					SetColor(FOREGROUND_RED);
					break;
				default:
					break;
				}
			}

			break;
		case 80://��
			if (option == 4)
			{
				option = 1;

				SetCursorPosition(27, 28);
				SetColor(FOREGROUND_RED);
				std::cout << "����ģʽ";
				SetCursorPosition(27, 22);
				SetBackgroundColor();
				std::cout << "��ģʽ";
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
					std::cout << "����ģʽ";
					SetCursorPosition(27, 28);
					SetBackgroundColor();
					std::cout << "����ģʽ";
					SetColor(FOREGROUND_RED);
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetColor(FOREGROUND_RED);
					std::cout << "��ͨģʽ";
					SetCursorPosition(27, 26);
					SetBackgroundColor();
					std::cout << "����ģʽ";
					SetColor(FOREGROUND_RED);
					break;
				case 2:

					SetCursorPosition(27, 22);
					SetColor(FOREGROUND_RED);
					std::cout << "��ģʽ";
					SetCursorPosition(27, 24);
					SetBackgroundColor();
					std::cout << "��ͨģʽ";
					SetColor(FOREGROUND_RED);
					break;
				default:
					break;
				}
			}
			break;
		case 13://����enter
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

//ѡ���ͼ
void Controller::select2()
{
	option2 = 1;
	system("cls");//����
	SetColor(FOREGROUND_RED);
	SetCursorPosition(20, 26);
	std::cout << "��ͼ2����ǽ��";
	SetBackgroundColor();
	SetCursorPosition(10, 26);
	std::cout << "��ͼ1������ǽ��";
	SetColor(FOREGROUND_RED);
	bool enter = false;
	char ch;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 75://��
			if (option2 == 1)
			{
				option2 = 2;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(10, 26);
				std::cout << "��ͼ1������ǽ��";
				SetBackgroundColor();
				SetCursorPosition(20, 26);
				std::cout << "��ͼ2����ǽ��";
				SetColor(FOREGROUND_RED);
				break;
			}
			else
			{
				option2 = 1;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(20, 26);
				std::cout << "��ͼ2����ǽ��";
				SetBackgroundColor();
				SetCursorPosition(10, 26);
				std::cout << "��ͼ1������ǽ��";
				SetColor(FOREGROUND_RED);
				break;
			}

		case 77://��
			if (option2 == 1)
			{
				option2 = 2;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(10, 26);
				std::cout << "��ͼ1������ǽ��";
				SetBackgroundColor();
				SetCursorPosition(20, 26);
				std::cout << "��ͼ2����ǽ��";
				SetColor(FOREGROUND_RED);
				break;
			}
			else
			{
				option2 = 1;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(20, 26);
				std::cout << "��ͼ2����ǽ��";
				SetBackgroundColor();
				SetCursorPosition(10, 26);
				std::cout << "��ͼ1������ǽ��";
				SetColor(FOREGROUND_RED);
				break;
			}

		case 13://����enter
			enter = true;
			break;
		default:
			break;
		}

		if (enter)
			break;
	}
}

//ѡ��ģʽ
void Controller::select3()
{
	option3 = 1;
	system("cls");//����
	SetColor(FOREGROUND_RED);
	SetCursorPosition(15, 26);
	std::cout << "˫��";
	SetBackgroundColor();
	SetCursorPosition(10, 26);
	std::cout << "����";
	SetColor(FOREGROUND_RED);
	bool enter = false;
	char ch;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 75://��
			if (option3 == 1)
			{
				option3 = 2;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(10, 26);
				std::cout << "����";
				SetBackgroundColor();
				SetCursorPosition(15, 26);
				std::cout << "˫��";
				SetColor(FOREGROUND_RED);
				break;
			}
			else
			{
				option3 = 1;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(15, 26);
				std::cout << "˫��";
				SetBackgroundColor();
				SetCursorPosition(10, 26);
				std::cout << "����";
				SetColor(FOREGROUND_RED);
				break;
			}

		case 77://��
			if (option3 == 1)
			{
				option3 = 2;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(10, 26);
				std::cout << "����";
				SetBackgroundColor();
				SetCursorPosition(15, 26);
				std::cout << "˫��";
				SetColor(FOREGROUND_RED);
				break;
			}
			else
			{
				option3 = 1;
				SetColor(FOREGROUND_RED);
				SetCursorPosition(15, 26);
				std::cout << "˫��";
				SetBackgroundColor();
				SetCursorPosition(10, 26);
				std::cout << "����";
				SetColor(FOREGROUND_RED);
				break;
			}

		case 13://����enter
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
	system("cls");//����
	SetColor(FOREGROUND_BLUE);
	Map* ptr = new Map();
	ptr->PrintInitmap(_option2);
	delete ptr;
	SetColor(FOREGROUND_GREEN);
	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(34, 2);
	std::cout << "̰����";
	SetCursorPosition(31, 4);
	std::cout << "�Ѷȣ�";
	SetCursorPosition(36, 5);
	switch (option)
	{
	case 1:
		std::cout << "��ģʽ";
		break;
	case 2:
		std::cout << "��ͨģʽ";
		break;
	case 3:
		std::cout << "����ģʽ";
		break;
	case 4:
		std::cout << "����ģʽ";
		break;
	default:
		break;
	}
	SetCursorPosition(31, 7);
	std::cout << "�÷֣�";
	SetCursorPosition(37, 8);
	std::cout << "     0";
	SetCursorPosition(33, 13);
	std::cout << " ������ƶ�";
	SetCursorPosition(33, 15);
	std::cout << " ESC����ͣ";
}

void Controller::updatescore()
{
	score += option;
	//Ϊ���ַ���β�����룬������������Ϊ6λ�����㵱ǰ����λ������ʣ��λ���ÿո�ȫ�����������
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
	std::ofstream file("scores.txt", std::ios::app);  // ���ļ��Խ���׷��д��

	if (file.is_open())
	{
		file << s << std::endl;  // д�����������
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

	std::sort(scores.begin(), scores.end(), std::greater<int>());  // ���մӴ�С����

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
	std::cout << "�˵���";
	Sleep(100);
	SetCursorPosition(34, 21);
	SetBackgroundColor();
	std::cout << "������Ϸ";
	Sleep(100);
	SetCursorPosition(34, 23);
	SetColor(FOREGROUND_GREEN);
	std::cout << "���¿�ʼ";
	Sleep(100);
	SetCursorPosition(34, 25);
	std::cout << "�˳���Ϸ";
	SetCursorPosition(0, 31);

	/*ѡ�񲿷�*/
	char ch;
	int menuoption = 1;
	bool enter = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 72://��
			if (menuoption == 1)
			{
				menuoption = 3;
				SetCursorPosition(34, 21);
				SetColor(FOREGROUND_GREEN);
				std::cout << "������Ϸ";
				SetCursorPosition(34, 25);
				SetBackgroundColor();
				std::cout << "�˳���Ϸ";
				break;
			}
			else
			{
				switch (menuoption)
				{
				case 2:
					SetCursorPosition(34, 21);
					SetBackgroundColor();
					std::cout << "������Ϸ";
					SetCursorPosition(34, 23);
					SetColor(FOREGROUND_GREEN);
					std::cout << "���¿�ʼ";
					--menuoption;
					break;
				case 3:
					SetCursorPosition(34, 23);
					SetBackgroundColor();
					std::cout << "���¿�ʼ";
					SetCursorPosition(34, 25);
					SetColor(FOREGROUND_GREEN);
					std::cout << "�˳���Ϸ";
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
				std::cout << "�˳���Ϸ";
				SetCursorPosition(34, 21);
				SetBackgroundColor();
				std::cout << "������Ϸ";
				break;
			}
			else
			{
				switch (menuoption)
				{
				case 1:
					SetCursorPosition(34, 23);
					SetBackgroundColor();
					std::cout << "���¿�ʼ";
					SetCursorPosition(34, 21);
					SetColor(FOREGROUND_GREEN);
					std::cout << "������Ϸ";
					++menuoption;
					break;
				case 2:
					SetCursorPosition(34, 25);
					SetBackgroundColor();
					std::cout << "�˳���Ϸ";
					SetCursorPosition(34, 23);
					SetColor(FOREGROUND_GREEN);
					std::cout << "���¿�ʼ";
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
	if (menuoption == 1) //ѡ�������Ϸ���򽫲˵�����
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
	std::cout << "������������������������������������������������������������������������������������";
	Sleep(30);
	SetCursorPosition(4, 9);
	std::cout << " ��               Game Over !!!              ��";
	Sleep(30);
	SetCursorPosition(4, 10);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(4, 11);
	std::cout << " ��              ���ź��������              ��";
	Sleep(30);
	SetCursorPosition(4, 12);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(4, 13);
	std::cout << " ��             ��ķ���Ϊ��                 ��";
	SetCursorPosition(19, 13);
	std::cout << score;
	Sleep(30);
	SetCursorPosition(4, 14);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(4, 15);
	std::cout << " ��   �Ƿ�����һ�֣�                         ��";
	Sleep(30);
	SetCursorPosition(4, 16);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(4, 17);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(4, 18);
	std::cout << " ��    �ţ��õ�        ���ˣ�����ѧϰ����˼  ��";
	Sleep(30);
	SetCursorPosition(4, 19);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(4, 20);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(5, 21);
	std::cout << "������������������������������������������������������������������������������������";

	Sleep(100);
	SetCursorPosition(7, 18);
	SetBackgroundColor();
	std::cout << "�ţ��õ�";
	SetCursorPosition(0, 31);

	/*ѡ�񲿷�*/
	char ch;
	int overoption = 1;
	bool enter = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 75://��
			if ((overoption == 1))
			{
				overoption = 2;
				SetCursorPosition(7, 18);
				SetColor(FOREGROUND_RED);
				std::cout << "�ţ��õ�";
				SetCursorPosition(15, 18);
				SetBackgroundColor();
				std::cout << "���ˣ�����ѧϰ����˼";
				break;
			}
			else
			{
				SetCursorPosition(7, 18);
				SetBackgroundColor();
				std::cout << "�ţ��õ�";
				SetCursorPosition(15, 18);
				SetColor(FOREGROUND_RED);
				std::cout << "���ˣ�����ѧϰ����˼";
				--overoption;
			}
			break;

		case 77://��
			if (overoption == 2)
			{
				overoption = 1;
				SetCursorPosition(15, 18);
				SetColor(FOREGROUND_RED);
				std::cout << "���ˣ�����ѧϰ����˼";
				SetCursorPosition(7, 18);
				SetBackgroundColor();
				std::cout << "�ţ��õ�";
				break;
			}
			else
			{
				SetCursorPosition(15, 18);
				SetBackgroundColor();
				std::cout << "���ˣ�����ѧϰ����˼";
				SetCursorPosition(7, 18);
				SetColor(FOREGROUND_RED);
				std::cout << "�ţ��õ�";
				++overoption;
			}
			break;

		case 13://����enter
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
		return 1;//���¿�ʼ
	case 2:
		return 2;//�˳���Ϸ
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
			if (!snake->changedirection())//����esc
			{
				int status = menu();//������Ϸstatus=1��������Ϸstatus=2���˳���Ϸstatus=3
				switch (status)
				{
				case 1://������Ϸ
					break;
				case 2://���¿�ʼ
					delete snake;
					delete food;
					return 1;//��1��Ϊ����ֵ���ص�game�����У���ʾ���¿�ʼ
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
		Snake* snake2 = new Snake(1);//�������������������ڲ�����Ĭ�Ϲ��캯��
		Food* food = new Food(*snake);
		SetColor(FOREGROUND_RED);
		snake->initsnake();
		snake2->initsnake();
		food->drawfood(superfood);
		while (snake->notbiteitself() && snake->notoutofedge(option2) && snake2->notbiteitself() && snake->notoutofedge(option2) && snake->notbiteeachother(snake2) && snake2->notbiteeachother(snake))
		{
			if (!snake->changedirection2(snake2))//����esc
			{
				int status = menu();//������Ϸstatus=1���˳���Ϸstatus=3
				switch (status)
				{
				case 1://������Ϸ
					break;
				case 3:
					return 2;
				case 2://���¿�ʼ
					delete snake;
					delete snake2;
					delete food;
					return 1;//��1��Ϊ����ֵ���ص�game�����У���ʾ���¿�ʼ

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
	start();//��ʼ����,���ÿ���̨���ڴ�С
	while (true)//��Ϸ����Ϊһ����ѭ����ֱ���˳���Ϸʱѭ������
	{
		select1();//ѡ�����,ѡ����Ϸ�Ѷ�
		select2();//ѡ����棬ѡ���ͼ���Ƿ�ǽ��
		select3();//ѡ����棬ѡ��ģʽ�����˻�˫�ˣ�

		drawgame(option2);//������Ϸ����
		int status = playgame(option3);//������Ϸѭ���������¿�ʼ���˳���Ϸʱ������ѭ��������ֵ��status
		if (status == 1) //����ֵΪ1ʱ���¿�ʼ��Ϸ
		{
			system("cls");
			continue;
		}
		else if (status == 2) //����ֵΪ2ʱ�˳���Ϸ
		{
			break;
		}
		else
		{
			break;
		}
	}
}

