#include "map.h"
#include "tools.h"
#include <Windows.h>
void Map::PrintInitmap(int option)
{
	if (option == 1)
	{
		for (Point& point : initmap)//����initmap�����е�ÿ��Ԫ�أ�����ӡ����ͼ�ı߽�
		{
			point.print();
			Sleep(1);//ÿ�δ�ӡ��ͼ�߽�֮��ͣ��1ms��Ӫ�춯����Ч��
		}
	}
	else
		for (Point& point : initmap)//����initmap�����е�ÿ��Ԫ�أ�����ӡ����ͼ�ı߽�
		{
			point.printcircle();
			Sleep(1);//ÿ�δ�ӡ��ͼ�߽�֮��ͣ��1ms��Ӫ�춯����Ч��
		}
	
}