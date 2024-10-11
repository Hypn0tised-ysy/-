#pragma once
#include <deque>
#include "food.h"
#include "point.h"
class Food;
class Snake
{
private:
    //将Food类置为友元，以便访问其私有元素
    friend class Food;
    
public:
    //用point实例化模板deque类
    int eatfood;
    std::deque<Point> snake;
    enum Direction{UP,DOWN,RIGHT,LEFT};//枚举变量来做常量使用
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
    //绘制蛇
    void initsnake();
    //蛇吃到食物之后获得增长
    void increase(int _option);
    //蛇正常移动
    void move(int _option);
    //用来判断蛇有没有越出边界
    bool notoutofedge(int _option);
    //用来判断蛇有没有撞到自身
    bool notbiteitself();
    //用来判断蛇有没有转向
    bool changedirection();
    //双人模式下用来判断蛇有没有转向
    bool changedirection2(Snake* snake2);
    //用来判断玩家是否相撞
    bool notbiteeachother(Snake* snake2);
    //判断有没有吃到食物
    bool getfood(Food& food);

};