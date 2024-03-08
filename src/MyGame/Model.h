#pragma once
#include<fstream>
#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
#include"InputUnit.h"
#include"Astar.h"
#include<queue>

struct Coor {int x; int y;};
class AbstrastModel {
public:
	AbstrastModel();
	AbstrastModel(const char* model_data_filePath);
	//非正方形区域
	void Calculation_mouse_click_function_area(int left_x, int left_y,
		int right_x, int right_y,
		int top_x, int top_y,
		int bottom_x, int bottom_y,
		int Function_ID);
	//正方形区域
	void Set_Function_Coor(int top_left_cornor_x, int top_left_cornor_y,
		                   int lower_right_cornor_x, int lower_right_cornor_y,
		                   int Function_ID);
	virtual void initialModel()=0;
	void initialFuntionArea();
	void Insert_Coordinate_in_draw(int x,int y);
	//virtual void Draw_Model_in_the_Picture() = 0;
	void LoadFile(const char* filePath);//载入文件
	void OutputModel();//打印模型
	void OutputModelSize();//打印模型尺寸
	void OutputFunction_area();
	char** model_data;
	int model_size_x, model_size_y;//model的尺寸
	std::vector <Coor> Coordinate_in_draw;
	int** Function_area;
	//std::unordered_map<int, int**>FunctionID_and_FunctionArea;
	//std::unordered_map<int, Coor>FunctionID_and_CoorinModel;
	//渲染优先级 越高级越迟渲染 覆盖在低级画面上
	int priority_z;  //可以理解为以控制台窗口为XOY平面，垂直XOY指向电脑屏幕外为Z轴

};

class DisplayMoney :public AbstrastModel {
public:
	DisplayMoney();
	DisplayMoney(const char* model_data_filePath);
	//void dispalyMoneyinscreen();
	virtual void initialModel();
	
	//void SetMoneyValue();
	void SetMoneyValue(int num);//设置显示金钱数字

	char** Number[10];
	//相对于model的坐标左上角的坐标
	Coor position[9];
	int Money[9];
	char** loadNumber(const char* model_data_filePath);
	
};

class StaticModel :public AbstrastModel {
public:
	StaticModel();
	StaticModel(const char* model_data_filePath, int FunctionNum);
	void initialModel();
	//static StaticModel* NewStaticModel(const char* model_data_filePath);
	//void Load_Coor_top_left(const char* filePath);
	//void Set_Function_Coor(int top_left_cornor_x, int top_left_cornor_y, int lower_right_cornor_x, int lower_right_cornor_y);
	//void Set_LowerRightCorner(int x, int y);


	//鼠标操作功能按键的区域范围  相对于model的坐标
	//Coor* Function_TopLeftCorner;
	//Coor* Function_LowerRightCorner;
	//int haveInsert;
	//int FunctionNum;
};

class BagModel : public AbstrastModel {
public:
	BagModel();
	BagModel(const char* model_data_filePath, int FunctionNum);
	void initialModel();
	int Det_x = 81;
	int Det_y = 46;
	void SetBagFunction(int top_left_cornor_x, int top_left_cornor_y,
		int lower_right_cornor_x, int lower_right_cornor_y,
		int Function_ID);


};
class Customer :public AbstrastModel {
public:
	Customer();
	Customer(int begin_x,int begin_y,int end_x, int end_y);
	Customer(const char* model_data_filePath);
	char** theCustomer_data;
	void initialModel();
	void SetActionto_modeldata();
	void SetPath(int start_x, int start_y, int end_x, int end_y);
	void PrintPath();
	void Load_Customer_data(const char* model_data_filePath);
	void load_every_tAction();
	void PrintAction(int col, int row);
	bool  CustomerMove();
	void MoveAction();
	//void CustomerBuy();
	int the_customer_size_x;
	int the_customer_size_y;
	static  char*** theAction[4];
	std::list<Point*> Movepath;
	std::queue<char**> moveaction;

	//bool Top_Right = true;
	int Action_row = 0;
	int Action_col = 0;
	int previous_x;
	int previous_y;

	int Customer_eat_time = 0;

	int is_in_big_or_small_desk=0;//1表示在小桌子，2表示在大桌子
	int in_big_desk_index = -1;
	int in_samll_desk_index = -1;
	

};
class DisplayText_Num :public AbstrastModel {
public:
	DisplayText_Num();
	
	//void dispalyMoneyinscreen();
   void initialModel();

    static void SetNumber();   //set一次就好
	//void SetMoneyValue();
	void SetMoneyValue(int num);//设置显示金钱数字

	static char** Number[10];
	//相对于model的坐标左上角的坐标
	Coor position[4];
	int Money[4];
	static char** loadNumber(const char* model_data_filePath);

};