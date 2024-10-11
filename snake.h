#pragma once
#include <deque>
#include "food.h"
#include "point.h"
class Food;
class Snake
{
private:
    //��Food����Ϊ��Ԫ���Ա������˽��Ԫ��
    friend class Food;
    
public:
    //��pointʵ����ģ��deque��
    int eatfood;
    std::deque<Point> snake;
    enum Direction{UP,DOWN,RIGHT,LEFT};//ö�ٱ�����������ʹ��
    Direction direction;
    Snake()
    {
        snake.emplace_back(14, 8);
        snake.emplace_back(15, 8);
        snake.emplace_back(16, 8);
        direction = Direction::DOWN;
        eatfood = 0;
    }
    Snake(int player)
    {
        snake.emplace_back(14, 28);
        snake.emplace_back(15, 28);
        snake.emplace_back(16, 28);
        direction = Direction::UP;
        eatfood = 0;
    }
    //������
    void initsnake();
    //�߳Ե�ʳ��֮��������
    void increase(int _option);
    //�������ƶ�
    void move(int _option);
    //�����ж�����û��Խ���߽�
    bool notoutofedge(int _option);
    //�����ж�����û��ײ������
    bool notbiteitself();
    //�����ж�����û��ת��
    bool changedirection();
    //˫��ģʽ�������ж�����û��ת��
    bool changedirection2(Snake* snake2);
    //�����ж�����Ƿ���ײ
    bool notbiteeachother(Snake* snake2);
    //�ж���û�гԵ�ʳ��
    bool getfood(Food& food);

};