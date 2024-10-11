#include "tools.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>

void SetWindowSize(int cols, int lines) 
{
    system("title 贪吃蛇");//设置窗口标题
    char cmd[30];
    sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//一个图形■占两个字符，故宽度乘以2
    system(cmd);//system(mode con cols=88 lines=88)设置窗口宽度和高度
}

void SetCursorPosition(const int x, const int y)
{
    COORD position;
    position.X = x * 2;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);//将光标位置移至创建的坐标处
}

void SetColor(int colorid)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorid);//用于设置文本的颜色
}

void SetBackgroundColor()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        FOREGROUND_BLUE |
        BACKGROUND_BLUE |
        BACKGROUND_GREEN |
        BACKGROUND_RED);
}