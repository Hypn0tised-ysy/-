#include "map.h"
#include "tools.h"
#include <Windows.h>
void Map::PrintInitmap(int option)
{
	if (option == 1)
	{
		for (Point& point : initmap)//遍历initmap数组中的每个元素，来打印出地图的边界
		{
			point.print();
			Sleep(1);//每次打印地图边界之后停顿1ms来营造动画的效果
		}
	}
	else
		for (Point& point : initmap)//遍历initmap数组中的每个元素，来打印出地图的边界
		{
			point.printcircle();
			Sleep(1);//每次打印地图边界之后停顿1ms来营造动画的效果
		}
	
}