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
	//������������
	void Calculation_mouse_click_function_area(int left_x, int left_y,
		int right_x, int right_y,
		int top_x, int top_y,
		int bottom_x, int bottom_y,
		int Function_ID);
	//����������
	void Set_Function_Coor(int top_left_cornor_x, int top_left_cornor_y,
		                   int lower_right_cornor_x, int lower_right_cornor_y,
		                   int Function_ID);
	virtual void initialModel()=0;
	void initialFuntionArea();
	void Insert_Coordinate_in_draw(int x,int y);
	//virtual void Draw_Model_in_the_Picture() = 0;
	void LoadFile(const char* filePath);//�����ļ�
	void OutputModel();//��ӡģ��
	void OutputModelSize();//��ӡģ�ͳߴ�
	void OutputFunction_area();
	char** model_data;
	int model_size_x, model_size_y;//model�ĳߴ�
	std::vector <Coor> Coordinate_in_draw;
	int** Function_area;
	//std::unordered_map<int, int**>FunctionID_and_FunctionArea;
	//std::unordered_map<int, Coor>FunctionID_and_CoorinModel;
	//��Ⱦ���ȼ� Խ�߼�Խ����Ⱦ �����ڵͼ�������
	int priority_z;  //�������Ϊ�Կ���̨����ΪXOYƽ�棬��ֱXOYָ�������Ļ��ΪZ��

};

class DisplayMoney :public AbstrastModel {
public:
	DisplayMoney();
	DisplayMoney(const char* model_data_filePath);
	//void dispalyMoneyinscreen();
	virtual void initialModel();
	
	//void SetMoneyValue();
	void SetMoneyValue(int num);//������ʾ��Ǯ����

	char** Number[10];
	//�����model���������Ͻǵ�����
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


	//���������ܰ���������Χ  �����model������
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

	int is_in_big_or_small_desk=0;//1��ʾ��С���ӣ�2��ʾ�ڴ�����
	int in_big_desk_index = -1;
	int in_samll_desk_index = -1;
	

};
class DisplayText_Num :public AbstrastModel {
public:
	DisplayText_Num();
	
	//void dispalyMoneyinscreen();
   void initialModel();

    static void SetNumber();   //setһ�ξͺ�
	//void SetMoneyValue();
	void SetMoneyValue(int num);//������ʾ��Ǯ����

	static char** Number[10];
	//�����model���������Ͻǵ�����
	Coor position[4];
	int Money[4];
	static char** loadNumber(const char* model_data_filePath);

};