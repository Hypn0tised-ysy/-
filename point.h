#pragma once
class Point
{
private:
	int x;
	int y;
public:
	Point() {};
	Point(int a, int b) :x(a), y(b) {};
	void print();
	void printcircle();
	void printstar();
	void printclear();
	void changeposition(int a,int b);
	int getx() { return x; };
	int gety() { return y; };
	bool operator==(Point& point) { return (point.x == this->x) && (point.y == this->y);};
};