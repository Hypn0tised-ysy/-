#include "point.h"
#include "tools.h"
#include <iostream>
void Point::print()
{
	SetCursorPosition(x,y);
	std::cout << "��";//

}
void Point::printcircle()
{
	SetCursorPosition(x,y);
	std::cout << "��";

}
void Point::printstar()
{
	SetCursorPosition(x, y);
	std::cout << "��";
}
void Point::printclear()
{
	SetCursorPosition(x, y);
	std::cout << " ";

}
void Point::changeposition(int a,int b)
{
	this->x = a;
	this->y = b;
}