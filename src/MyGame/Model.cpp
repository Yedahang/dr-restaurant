#include"Model.h"
using namespace std;
extern int line(double k, double b, int x);
AbstrastModel::AbstrastModel() {
	this->initialFuntionArea();
};
AbstrastModel::AbstrastModel(const char* model_data_filePath) {
	LoadFile(model_data_filePath);
	this->initialFuntionArea();
}
void AbstrastModel::Calculation_mouse_click_function_area(int left_x, int left_y,
	int right_x, int right_y,
	int top_x, int top_y,
	int bottom_x, int bottom_y,
	int Function_ID) {
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
		int ymin = max(line(k2, b2, i), line(k1, b1, i));
		int ymax = min(line(k2, b3, i), line(k1, b4, i));
		for (int j = 0; j < height; j++) {
			if (j > ymin && j < ymax)
				this->Function_area[j+ top_y][i+ left_x] = Function_ID;
		}
	}
	//Coor temp = { right_x ,top_y };
	//this->FunctionID_and_FunctionArea.emplace(Function_ID, Function_area);
	//this->FunctionID_and_CoorinModel.emplace(Function_ID, temp);

	


	/*for (int i = 0; i < height; i++) {
		delete[] Function_area[i];
	}
	delete[]Function_area;*/

	return ;
}
//设置矩形鼠标点击响应区域
void AbstrastModel::Set_Function_Coor(int top_left_cornor_x, int top_left_cornor_y,//左上角顶点坐标
	                                  int lower_right_cornor_x, int lower_right_cornor_y,//右下角顶点坐标
                                      int Function_ID)//响应事件的ID
{
	                                     
	for (int i = top_left_cornor_x; i < lower_right_cornor_x+1; i++) {
		for (int j = top_left_cornor_y; j < lower_right_cornor_y+1; j++) {
				this->Function_area[j ][i ] = Function_ID;
		}
	}
}
void AbstrastModel::initialFuntionArea() {
	//this->Function_area= new 
		this->Function_area = new int* [this->model_size_y];
	for (int i = 0; i < this->model_size_y; i++) {
		Function_area[i] = new int[this->model_size_x] {0};
	}
	/*for (auto& it1 : FunctionID_and_CoorinModel) {
		auto it2 = FunctionID_and_FunctionArea.find(it1.first);
		if (it2 == FunctionID_and_FunctionArea.end()) {
			cout << "void AbstrastModel::InsertFuntionArea()出现错误" << endl;
			system("pause");
		}
		int** temp = (*it2).second;
		int temp_col_size = sizeof(temp);
		int temp_row_size = sizeof(temp[0]);
			for (int i = 0; i < temp_col_size; i++) {
				for(int j=0;j< temp_row_size;j++)
					
			}
	}*/
}
void AbstrastModel::Insert_Coordinate_in_draw(int x, int y) {
	Coor temp = { x,y };
	this->Coordinate_in_draw.push_back(temp);
}
void AbstrastModel::LoadFile(const char* filePath) {
	std::ifstream ifs;
	ifs.open(filePath, ios::in);
	//检测文件是否打开成功
	if (!ifs.is_open()) {
		system("cls");
		cout << "路径：" << filePath << " 打开文件失败" << endl;
		system("pause");
		return;
	}
	string buf;
	vector<string>ch;
	while (getline(ifs, buf)) {
		buf += '\0';
		ch.push_back(buf);
	}
	int ch_size = ch.size();
	this->model_data = new char* [ch_size];
	//将string转化成char*
	for (int i = 0; i < ch_size; i++) {
		//fileName.data[i] = (char*)ch[i].c_str();
		this->model_data[i] = new char[ch[i].length()];
		//		cout << strlen(model_data[i]);
		ch[i].copy(this->model_data[i], string::npos);
		//fileName.data[i] += '\0';
	}
	(this->model_size_y) = ch_size;
	(this->model_size_x) = strlen(this->model_data[0]);
	ifs.close();

}
void AbstrastModel::OutputModel() {
	for (int i = 0; i < this->model_size_y; i++)
		cout << this->model_data[i] << endl;
}
void AbstrastModel::OutputModelSize() {
	char ch[15];
	sprintf(ch, "model_size_x=%d,model_size_y=%d", this->model_size_x, this->model_size_y);
	extern void Pop_up_message_box(const char* content, const char* title);
	Pop_up_message_box(ch, ch);

}
void AbstrastModel::OutputFunction_area() {
	for (int i = 0; i < this->model_size_y; i++) {
		for (int j = 0; j < this->model_size_x; j++)
			cout << this->Function_area[i][j];
		cout << endl;
	}
}
DisplayMoney::DisplayMoney(){}
DisplayMoney::DisplayMoney(const char* model_data_filePath) :AbstrastModel(model_data_filePath) {
	initialModel();
}
void DisplayMoney::initialModel() {
	//初始化文件
	this->Number[0] = this->loadNumber("../Sources/Number/ASCII-0.txt");
	this->Number[1] = this->loadNumber("../Sources/Number/ASCII-1.txt");
	this->Number[2] = this->loadNumber("../Sources/Number/ASCII-2.txt");
	this->Number[3] = this->loadNumber("../Sources/Number/ASCII-3.txt");
	this->Number[4] = this->loadNumber("../Sources/Number/ASCII-4.txt");
	this->Number[5] = this->loadNumber("../Sources/Number/ASCII-5.txt");
	this->Number[6] = this->loadNumber("../Sources/Number/ASCII-6.txt");
	this->Number[7] = this->loadNumber("../Sources/Number/ASCII-7.txt");
	this->Number[8] = this->loadNumber("../Sources/Number/ASCII-8.txt");
	this->Number[9] = this->loadNumber("../Sources/Number/ASCII-9.txt");
	//初始化各个数字的坐标位置
	for (int i = 0; i < 9; i++) {
		position[i] = { 430 - i * 37,6 };
	}
	//初始化Money数组
	for (int i = 0; i < 9; i++)
		this->Money[i] = 0;
}

void DisplayMoney::SetMoneyValue(int num) {
	for (int i = 0; i < 9; i++)
		this->Money[i] = 0;
	for (int i = 0; i < 9; i++) {
		Money[i] = num % 10;
		num = num / 10;
		if (num == 0)
			break;
	}
	//数字显示设置了9位 比如num=1000时，那么显示 -----1000 “-”表示为空
	int index = 8;
	for (; index > -1; index--) {
		if (Money[index] == 0) {
			for (int i = 0; i < 25; i++) {
				for (int j = 0; j < 50; j++) {
					this->model_data[i + this->position[index].y][j + this->position[index].x] = ' ';
				}
			}
			continue;
		}
		break;
	}
	for (; index > -1; index--) {
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 50; j++) {
				this->model_data[i + this->position[index].y][j + this->position[index].x] = this->Number[Money[index]][i][j];
			}
		}
	}
}
char** DisplayMoney::loadNumber(const char* model_data_filePath) {
	std::ifstream ifs;
	ifs.open(model_data_filePath, ios::in);
	//检测文件是否打开成功
	if (!ifs.is_open()) {
		system("cls");
		cout << "路径：" << model_data_filePath << " 打开文件失败" << endl;
		system("pause");
		return nullptr;
	}
	string buf;
	vector<string>ch;
	while (getline(ifs, buf)) {
		buf += '\0';
		ch.push_back(buf);
	}
	int ch_size = ch.size();
	char** Number = new char* [ch_size];

	for (int i = 0; i < ch_size; i++) {
		Number[i] = new char[ch[i].length()];
		ch[i].copy(Number[i], string::npos);
	}
	ifs.close();
	return Number;
}
StaticModel::StaticModel(const char* model_data_filePath, int FunctionNum) : AbstrastModel(model_data_filePath) 
{

}
void StaticModel::initialModel() {

}


BagModel::BagModel() {

};
BagModel::BagModel(const char* model_data_filePath, int FunctionNum) :AbstrastModel(model_data_filePath) {

}

void  BagModel::initialModel() {

}
void  BagModel::SetBagFunction(int top_left_cornor_x, int top_left_cornor_y,
	int lower_right_cornor_x, int lower_right_cornor_y,
	int Function_ID) {


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {

			this->Set_Function_Coor(top_left_cornor_x + j * Det_x, top_left_cornor_y + i * Det_y,
				lower_right_cornor_x + j * Det_x, lower_right_cornor_y + i * Det_y,
				Function_ID+i*8+j);

		}


	}
}

char*** Customer::theAction[4];
Customer::Customer() {
	this->model_size_y = 43;//
	this->model_size_x = 40;//
	this->initialFuntionArea();
}
Customer::Customer(int begin_x, int begin_y, int end_x, int end_y) {
	this->model_size_y = 43;//
	this->model_size_x = 40;//
	this->initialFuntionArea();
	this->SetPath(begin_x, begin_y, end_x, end_y);
}
Customer::Customer(const char* model_data_filePath) {
	Load_Customer_data(model_data_filePath);
	//this->model_data = this->theCustomer_data;
	//this->model_size_x = this->the_customer_size_x;
	//this->model_size_y = this->the_customer_size_y;
	initialModel();
}
void Customer::initialModel() {
	this->model_size_y = 43;//
	this->model_size_x = 40;//
	load_every_tAction();
	this->initialFuntionArea();
}
void Customer::SetActionto_modeldata() {
	int row = 1, col = 3;

	this->model_data = this->theAction[col][row];
	/*for (int i = 0; i < 3; i++) {

	///*}*/
	//this->OutputModel();
	//system("pause");*/
}
void Customer::SetPath(int start_x, int start_y, int end_x, int end_y) {
	previous_x = start_x;
	previous_y = start_y;
	Movablemap::SetStartandEnd(start_x, start_y, end_x, end_y, this->Movepath);

}
void Customer::PrintPath() {
	for (auto& p : this->Movepath)
		std::cout << '(' << p->x << ',' << p->y << ')' << std::endl;

	system("pause");

}
void Customer::Load_Customer_data(const char* model_data_filePath) {
	std::ifstream ifs;
	ifs.open(model_data_filePath, ios::in);
	//检测文件是否打开成功
	if (!ifs.is_open()) {
		system("cls");
		cout << "路径：" << model_data_filePath << " 打开文件失败" << endl;
		system("pause");
		return;
	}
	string buf;
	vector<string>ch;
	while (getline(ifs, buf)) {
		buf += '\0';
		ch.push_back(buf);
	}
	int ch_size = ch.size();
	theCustomer_data = new char* [ch_size];
	//将string转化成char*
	for (int i = 0; i < ch_size; i++) {
		//fileName.data[i] = (char*)ch[i].c_str();
		theCustomer_data[i] = new char[ch[i].length()];
		//		cout << strlen(model_data[i]);
		ch[i].copy(theCustomer_data[i], string::npos);
		//fileName.data[i] += '\0';
	}
	(this->the_customer_size_y) = ch_size;
	(this->the_customer_size_y) = strlen(theCustomer_data[0]);
	ifs.close();
}
void Customer::load_every_tAction() {
	for (int col = 0; col < 4; col++) {
		this->theAction[col] = new char** [3];
		for (int row = 0; row < 3; row++) {
			this->theAction[col][row] = new char* [43];
			for (int j = 0; j < 43; j++) {
				this->theAction[col][row][j] = new char[41];
				for (int i = 0; i < 41; i++) {
					if (i == 40)
						this->theAction[col][row][j][40] = '\0';
					else
						this->theAction[col][row][j][i] = this->theCustomer_data[col * 43 + j][row * 40 + i];
				}
			}

		}
	}

}
void Customer::PrintAction(int col, int row) {
	for (int j = 0; j < this->model_size_y; j++) {
		cout << this->theAction[col][row][j] << endl;
	}

}
bool Customer::CustomerMove(){
	MoveAction();
	if (this->Movepath.begin() != this->Movepath.end()) {
		this->Coordinate_in_draw.clear();
		Coor temp = { this->Movepath.front()->x,this->Movepath.front()->y };
		this->Coordinate_in_draw.push_back(temp);
		this->Movepath.pop_front();
		return true;
	}
	else  //顾客到达桌子
	{
		return false;
	}
}
void Customer::MoveAction() {
	//for (auto it : this->Movepath) {
		
	//if (Top_Right)
	//	//this->moveaction.push(this->theAction[3][0]);
	//	this->model_data = this->theAction[3][0];
	//else
	//	//this->moveaction.push(this->theAction[3][2]);
	//	this->model_data = this->theAction[3][2];
	//	Top_Right = !Top_Right;
	////}
	if (Movepath.begin() == Movepath.end())
		return;

	int det_X = this->Movepath.front()->x - previous_x;
	int det_Y = this->Movepath.front()->y - previous_y;
	if (this->Movepath.front()->x == previous_x) {
		if (det_Y > 0)
			Action_col = 0;
		if (det_Y < 0)
			Action_col = 3;
	}
	else {
		int k = det_Y / det_X;
		if (k > 0) {
			if(det_X>0)
				Action_col = 3;
			if (det_X < 0)
				Action_col = 0;
		}
		else {
			if (det_X > 0)
				Action_col = 2;
			if (det_X < 0)
				Action_col = 1;
		}
			
	}
	previous_x = this->Movepath.front()->x;
	previous_y = this->Movepath.front()->y;
	switch (Action_row++) {
	case 0:
		this->model_data = this->theAction[Action_col][0]; break;
	case 1:
		this->model_data = this->theAction[Action_col][1]; break;
	case 2:
		this->model_data = this->theAction[Action_col][2];
		Action_row = 0;
		break;
	}
}

//void Customer::CustomerBuy() {
//	
//
//
//}

char** DisplayText_Num::Number[10];
DisplayText_Num::DisplayText_Num() {
	//初始化各个数字的坐标位置
	for (int i = 0; i < 4; i++) {
		position[i] = { 90- i * 30,0 };
	}
	//初始化Money数组
	//for (int i = 0; i < 4; i++)
	//	this->Money[i] = 0;
	this->model_data = new char* [20];
	for (int i = 0; i < 20; i++) {
		this->model_data[i] = new char[120];
		for (int j = 0; j < 120; j++)
			this->model_data[i][j] = ' ';
	}
	this->model_size_x =120 ;
	this->model_size_y = 20;
	this->initialFuntionArea();
}
void DisplayText_Num::initialModel() {
	
}
void DisplayText_Num::SetMoneyValue(int num) {
	if (num > 9999) {
		system("cls");
		cout << "void DisplayText_Num::SetMoneyValue(int num)出现错误" << endl;
		system("pause");
	}
	for (int i = 0; i < 4; i++)
		this->Money[i] = 0;

	for (int i = 0; i < 4; i++) {
		Money[i] = num % 10;
		num = num / 10;
		if (num == 0)
			break;
	}
	//数字显示设置了4位 比如num=90时，那么显示 --90 “-”表示为空
	int index = 3;
	for (; index > -1; index--) {
		if (Money[index] == 0) {
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 30; j++) {
					this->model_data[i + this->position[index].y][j + this->position[index].x] = ' ';
				}
			}
			continue;
		}
		break;
	}
	for (; index > -1; index--) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 30; j++) {
				this->model_data[i + this->position[index].y][j + this->position[index].x] = this->Number[Money[index]][i][j];
			}
		}
	}
}
void DisplayText_Num::SetNumber() {
	//初始化文件
	Number[0] = loadNumber("../Sources/Text/ASCII-0.txt");
	Number[1] = loadNumber("../Sources/Text/ASCII-1.txt");
	Number[2] = loadNumber("../Sources/Text/ASCII-2.txt");
	Number[3] = loadNumber("../Sources/Text/ASCII-3.txt");
	Number[4] = loadNumber("../Sources/Text/ASCII-4.txt");
	Number[5] = loadNumber("../Sources/Text/ASCII-5.txt");
	Number[6] = loadNumber("../Sources/Text/ASCII-6.txt");
	Number[7] = loadNumber("../Sources/Text/ASCII-7.txt");
	Number[8] = loadNumber("../Sources/Text/ASCII-8.txt");
	Number[9] = loadNumber("../Sources/Text/ASCII-9.txt");

 }
char** DisplayText_Num::loadNumber(const char* model_data_filePath) {
	std::ifstream ifs;
	ifs.open(model_data_filePath, ios::in);
	//检测文件是否打开成功
	if (!ifs.is_open()) {
		system("cls");
		cout << "路径：" << model_data_filePath << " 打开文件失败" << endl;
		system("pause");
		return nullptr;
	}
	string buf;
	vector<string>ch;
	while (getline(ifs, buf)) {
		buf += '\0';
		ch.push_back(buf);
	}
	int ch_size = ch.size();
	char** Number = new char* [ch_size];

	for (int i = 0; i < ch_size; i++) {
		Number[i] = new char[ch[i].length()];
		ch[i].copy(Number[i], string::npos);
	}
	ifs.close();
	return Number;
}