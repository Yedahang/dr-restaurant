#include <math.h>

#include "Astar.h"
#include<algorithm>
#include<iostream>

void Astar::InitAstar(std::vector<std::vector<int>>& _maze)
{
	maze = _maze;
}

int Astar::calcG(Point* temp_start, Point* point)
{
	int extraG = (abs(point->x - temp_start->x) + abs(point->y - temp_start->y)) == 1 ? kCost1 : kCost2;
	int parentG = point->parent == NULL ? 0 : point->parent->G; //如果是初始节点，则其父节点是空
	return parentG + extraG;
}

int Astar::calcH(Point* point, Point* end)
{
	//用简单的欧几里得距离计算H，这个H的计算是关键，还有很多算法，没深入研究^_^
	return sqrt((double)(end->x - point->x) * (double)(end->x - point->x) + (double)(end->y - point->y) * (double)(end->y - point->y)) * kCost1;
}

int Astar::calcF(Point* point)
{
	return point->G + point->H;
}

Point* Astar::getLeastFpoint()
{
	if (!openList.empty())
	{
		auto resPoint = openList.front();
		for (auto& point : openList)
			if (point->F < resPoint->F)
				resPoint = point;
		return resPoint;
	}
	return NULL;
}

Point* Astar::findPath(Point& startPoint, Point& endPoint, bool isIgnoreCorner)
{
	openList.push_back(new Point(startPoint.x, startPoint.y)); //置入起点,拷贝开辟一个节点，内外隔离
	while (!openList.empty())
	{
		auto curPoint = getLeastFpoint(); //找到F值最小的点
		openList.remove(curPoint); //从开启列表中删除
		closeList.push_back(curPoint); //放到关闭列表
		//1,找到当前周围八个格中可以通过的格子
		auto surroundPoints = getSurroundPoints(curPoint, isIgnoreCorner);
		for (auto& target : surroundPoints)
		{
			//2,对某一个格子，如果它不在开启列表中，加入到开启列表，设置当前格为其父节点，计算F G H
			if (!isInList(openList, target))
			{
				target->parent = curPoint;

				target->G = calcG(curPoint, target);
				target->H = calcH(target, &endPoint);
				target->F = calcF(target);

				openList.push_back(target);
			}
			//3，对某一个格子，它在开启列表中，计算G值, 如果比原来的大, 就什么都不做, 否则设置它的父节点为当前点,并更新G和F
			else
			{
				int tempG = calcG(curPoint, target);
				if (tempG < target->G)
				{
					target->parent = curPoint;

					target->G = tempG;
					target->F = calcF(target);
				}
			}
			Point* resPoint = isInList(openList, &endPoint);
			if (resPoint)
				return resPoint; //返回列表里的节点指针，不要用原来传入的endpoint指针，因为发生了深拷贝
		}
	}

	return NULL;
}

std::list<Point*> Astar::GetPath(Point& startPoint, Point& endPoint, bool isIgnoreCorner)
{
	Point* result = findPath(startPoint, endPoint, isIgnoreCorner);
	std::list<Point*> path;
	//返回路径，如果没找到路径，返回空链表
	while (result)
	{
		path.push_front(result);
		result = result->parent;
	}

	// 清空临时开闭列表，防止重复执行GetPath导致结果异常
	openList.clear();
	closeList.clear();

	return path;
}

Point* Astar::isInList(const std::list<Point*>& list, const Point* point) const
{
	//判断某个节点是否在列表中，这里不能比较指针，因为每次加入列表是新开辟的节点，只能比较坐标
	for (auto p : list)
		if (p->x == point->x && p->y == point->y)
			return p;
	return NULL;
}

bool Astar::isCanreach(const Point* point, const Point* target, bool isIgnoreCorner) const
{
	if (target->x<0 || target->x>maze.size() - 1
		|| target->y<0 || target->y>maze[0].size() - 1
		|| maze[target->x][target->y] == 1
		|| target->x == point->x && target->y == point->y
		|| isInList(closeList, target)) //如果点与当前节点重合、超出地图、是障碍物、或者在关闭列表中，返回false
		return false;
	else
	{
		if (abs(point->x - target->x) + abs(point->y - target->y) == 1) //非斜角可以
			return true;
		else
		{
			//斜对角要判断是否绊住
			if (maze[point->x][target->y] == 0 && maze[target->x][point->y] == 0)
				return true;
			else
				return isIgnoreCorner;
		}
	}
}

std::vector<Point*> Astar::getSurroundPoints(const Point* point, bool isIgnoreCorner) const
{
	std::vector<Point*> surroundPoints;

	for (int x = point->x - 1; x <= point->x + 1; x++)
		for (int y = point->y - 1; y <= point->y + 1; y++)
			if (isCanreach(point, new Point(x, y), isIgnoreCorner))
				surroundPoints.push_back(new Point(x, y));

	return surroundPoints;
}
std::vector<std::vector<int>> Movablemap::MAP;
int** Movablemap::temp_MAP;
int Movablemap::multiple_X = 10;
int Movablemap::multiple_Y = 3;
extern int line(double k, double b, int x);
void Movablemap::InitialMovablemap() {
	int MAX_X = 1917, MAX_Y = 497;
	temp_MAP = new int* [MAX_Y];
	for (int i = 0; i < MAX_Y; i++) {
		temp_MAP[i] = new int[MAX_X]{ 1 };
	}
	for (int i = 0; i < MAX_Y; i++) {
		for (int j = 0; j < MAX_X; j++)
			 temp_MAP[i][j]=1;
		
	}

	SetMoveablePlace(400, 201, 1691, 250, 962, 12, 1122, 400);//

	SetMoveablePlace(1040,470,1741,285,1665,269,1106,466);

	SetMoveablePlace(297,240,1199,465,371,200,1108,473);
	SetMoveablePlace(555,276,726,251,660,227,617,297);

	Set_UN_MoveablePlace(647, 100, 1250, 115, 952, 4, 960, 200);
	Set_UN_MoveablePlace(690,295,926,235,864,214,794,300);
	Set_UN_MoveablePlace(988,239,1200,201,1184,160,1022,260);
	SetMAP();


	//for (int i = 0; i < MAX_Y; i++) {
	//	for (int j = 0; j < MAX_X; j++)
	//		std::cout << temp_MAP[i][j];
	//	std::cout << std::endl;
	//}

	//system("pause");

}
void Movablemap::SetMAP() {
	int MAX_X = 1917, MAX_Y = 497;


	int Reduce_x = MAX_X/ multiple_X;
	int Reduce_y = MAX_Y/ multiple_Y;
	
	
	MAP.reserve(Reduce_y);
	for (int i = 0; i < Reduce_y; i++) {
		std::vector<int>tempvector;
		tempvector.reserve(Reduce_x);
		for (int j = 0; j < Reduce_x; j++)
			tempvector.push_back(temp_MAP[i* multiple_Y][j* multiple_X]);
		MAP.push_back(tempvector);
	}
	
	////测试
	//for (int i = 0; i < Reduce_y; i++) {
	//	for (int j = 0; j < Reduce_x; j++)
	//		std::cout << MAP[i][j];
	//	std::cout << std::endl;
	//}
	//system("pause");
}
void Movablemap::SetMoveablePlace(int left_x, int left_y,
	int right_x, int right_y,
	int top_x, int top_y,
	int bottom_x, int bottom_y) {
	int height = bottom_y - top_y;
	int width = right_x - left_x;


	double k1 = (right_y - top_y) / (double)(right_x - top_x);
	double k2 = (top_y - left_y) / (double)(top_x - left_x);
	double b1 = 0 - k1 * (top_x - left_x);
	double b2 = 0 - k2 * (top_x - left_x);
	double b3 = (right_y - top_y) - k2 * (right_x - left_x);
	double b4 = (left_y - top_y) - 0;

	// line(k1,b1,x)  L1
	//line(k2,b2,x)  L2
	//line(k2,b3,x)  L3
	//line(k1,b4,x)  L4
	int det_x = right_x - left_x;
	for (int i = 0; i < det_x; i++) {
		int ymin = std::max(line(k2, b2, i), line(k1, b1, i));
		int ymax = std::min(line(k2, b3, i), line(k1, b4, i));
		for (int j = 0; j < height; j++) {
			if (j > ymin && j < ymax)
				temp_MAP[j + top_y][i + left_x] = 0;
		}
	}
}
void Movablemap::Set_UN_MoveablePlace(int left_x, int left_y,
	int right_x, int right_y,
	int top_x, int top_y,
	int bottom_x, int bottom_y) {
	int height = bottom_y - top_y;
	int width = right_x - left_x;


	double k1 = (right_y - top_y) / (double)(right_x - top_x);
	double k2 = (top_y - left_y) / (double)(top_x - left_x);
	double b1 = 0 - k1 * (top_x - left_x);
	double b2 = 0 - k2 * (top_x - left_x);
	double b3 = (right_y - top_y) - k2 * (right_x - left_x);
	double b4 = (left_y - top_y) - 0;

	// line(k1,b1,x)  L1
	//line(k2,b2,x)  L2
	//line(k2,b3,x)  L3
	//line(k1,b4,x)  L4
	int det_x = right_x - left_x;
	for (int i = 0; i < det_x; i++) {
		int ymin = std::max(line(k2, b2, i), line(k1, b1, i));
		int ymax = std::min(line(k2, b3, i), line(k1, b4, i));
		for (int j = 0; j < height; j++) {
			if (j > ymin && j < ymax)
				temp_MAP[j + top_y][i + left_x] = 1;
		}
	}
}

void Movablemap::SetStartandEnd_for_tset(int start_x, int start_y, int end_x, int end_y) {
	//a星算法
	Astar astar;
	astar.InitAstar(MAP);
	//设置起始和结束点
	Point start(start_y/multiple_Y, start_x/multiple_X);
	Point end(end_y / multiple_Y, end_x / multiple_X);
	//A*算法找寻路径
	std::list<Point*> path = astar.GetPath(start, end, false);
	//打印
	for (auto& p : path)
		std::cout << '(' << p->x << ',' << p->y << ')' << std::endl;

	system("pause");
}
void Movablemap::SetStartandEnd(int start_x, int start_y, int end_x, int end_y, std::list<Point*>& path) {
	//a星算法
	Astar astar;
	astar.InitAstar(MAP);
	//设置起始和结束点
	Point start(start_y / multiple_Y, start_x / multiple_X);
	Point end(end_y / multiple_Y, end_x / multiple_X);
	//A*算法找寻路径
	std::list<Point*>temp= astar.GetPath(start, end, false);
	for (auto it : temp) {
		/*it->x *= multiple_Y;
		it->y *= multiple_X;*/
		Point* p = new Point(it->y * multiple_X, it->x * multiple_Y);
		/*p->x= it->y * multiple_X;
		p->y= it->x * multiple_Y;*/
      	path.push_back(p);
	}
}