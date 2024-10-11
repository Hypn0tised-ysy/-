#pragma once
class Controller
{
private:
	int option;//游戏难度的选择
	int option2;//地图的选择
	int option3;//模式的选择
	int speed;//游戏进行的速度，决定游戏的难度
	int score;
public:
	Controller() :option(1), score(0) {};
	void start();//绘制开始界面
	void select1();//选择难度
	void select2();//选择地图
	void select3();//选择模式（单人/双人）
	void drawgame(int _option2);//绘制游戏页面，对得分、操作等进行说明
	void updatescore();//更新分数
	void writescoretofile(int s);//将分数写入txt文件
	void sortscoresinfile();//对分数进行排序
	int menu();//当输入esc之后打开选择菜单，选择退出游戏、继续游戏、重新开始、返回开始界面
	int gameover();//游戏结束后让玩家选择再玩一次或是退出
	int playgame(int _option);//进行游戏,根据游戏结束后玩家的选择返回不同的整数值
	void game();//根据playgame（）返回的整数决定继续游戏还是退出游戏
};