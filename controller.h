#pragma once
class Controller
{
private:
	int option;//��Ϸ�Ѷȵ�ѡ��
	int option2;//��ͼ��ѡ��
	int option3;//ģʽ��ѡ��
	int speed;//��Ϸ���е��ٶȣ�������Ϸ���Ѷ�
	int score;
public:
	Controller() :option(1), score(0) {};
	void start();//���ƿ�ʼ����
	void select1();//ѡ���Ѷ�
	void select2();//ѡ���ͼ
	void select3();//ѡ��ģʽ������/˫�ˣ�
	void drawgame(int _option2);//������Ϸҳ�棬�Ե÷֡������Ƚ���˵��
	void updatescore();//���·���
	void writescoretofile(int s);//������д��txt�ļ�
	void sortscoresinfile();//�Է�����������
	int menu();//������esc֮���ѡ��˵���ѡ���˳���Ϸ��������Ϸ�����¿�ʼ�����ؿ�ʼ����
	int gameover();//��Ϸ�����������ѡ������һ�λ����˳�
	int playgame(int _option);//������Ϸ,������Ϸ��������ҵ�ѡ�񷵻ز�ͬ������ֵ
	void game();//����playgame�������ص���������������Ϸ�����˳���Ϸ
};