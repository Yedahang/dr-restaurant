#pragma once

/*
//A*�㷨������
*/
#include <vector>
#include <list>

const int kCost1 = 10; //ֱ��һ������
const int kCost2 = 14; //б��һ������

struct Point
{
	int x, y; //�����꣬����Ϊ�˷��㰴��C++�����������㣬x������ţ�y��������
	int F, G, H; //F=G+H
	Point* parent; //parent�����꣬����û����ָ�룬�Ӷ��򻯴���
	Point(int _x, int _y) :x(_x), y(_y), F(0), G(0), H(0), parent(NULL)  //������ʼ��
	{
	}
};

class Astar
{
public:
	void InitAstar(std::vector<std::vector<int>>& _maze);
	std::list<Point*> GetPath(Point& startPoint, Point& endPoint, bool isIgnoreCorner);

private:
	Point* findPath(Point& startPoint, Point& endPoint, bool isIgnoreCorner);
	std::vector<Point*> getSurroundPoints(const Point* point, bool isIgnoreCorner) const;
	bool isCanreach(const Point* point, const Point* target, bool isIgnoreCorner) const; //�ж�ĳ���Ƿ����������һ���ж�
	Point* isInList(const std::list<Point*>& list, const Point* point) const; //�жϿ���/�ر��б����Ƿ����ĳ��
	Point* getLeastFpoint(); //�ӿ����б��з���Fֵ��С�Ľڵ�
	//����FGHֵ
	int calcG(Point* temp_start, Point* point);
	int calcH(Point* point, Point* end);
	int calcF(Point* point);
private:
	std::vector<std::vector<int>> maze;
	std::list<Point*> openList;  //�����б�
	std::list<Point*> closeList; //�ر��б�
};


static class Movablemap {
	public:
		static std::vector<std::vector<int>>MAP;
		static int** temp_MAP;
		static int multiple_X; 
		static int multiple_Y; 
		static void InitialMovablemap();
		static void SetMAP();
		static void SetMoveablePlace(int left_x, int left_y,
			int right_x, int right_y,
			int top_x, int top_y,
			int bottom_x, int bottom_y);
		static void Set_UN_MoveablePlace(int left_x, int left_y,
			int right_x, int right_y,
			int top_x, int top_y,
			int bottom_x, int bottom_y);
		static void SetStartandEnd_for_tset(int start_x, int start_y, int end_x, int end_y);
		static void SetStartandEnd(int start_x, int start_y, int end_x, int end_y, std::list<Point*>& path);

};