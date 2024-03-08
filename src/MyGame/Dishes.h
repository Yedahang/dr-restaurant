#pragma once
#include"Model.h"

#include<vector>
#include<map>
#include"UI.h"
class Dishes:public AbstrastModel {
public:
	int Grade;//等级  1~5级

	//int Stars;//星级   1~3星
	

	int Basic_Price;
	int Basic_Popularity;
	int Basic_Raw_material_cost;

	int Price[3];
	int Popularity;
	int Raw_material_cost[3];
	int profit[3];
	int ID;
	void initialModel();
	Dishes();
	Dishes(int grade,int basic_price, int basic_popularity, int basic_raw_material_cost,int id, const char* model_data_filePath);
	//int GetPrice(int star);
	//int GetRaw_material_cost(int star);
	//int Getprofit(int star);
	//int Get
	void Rising_star();
};


const int number_of_Kind_of_dishes = 5;

struct Index {
	int stars;
	int ID;
};
static class Bag {
public:
	
	static int ALL_dishes[3][number_of_Kind_of_dishes]; //ID为索引  数值为数量  星 种类
	static std::vector<Dishes> Dishes_vector;
	static std::map<int ,Index> dishesMAp;
	static void SetdishesMap();
	static void PrintBag();
	//std::vector<StaticModel*> dishes_one_star_model;
	//std::vector<StaticModel*> dishes_two_star_model;
	//std::vector<StaticModel*> dishes_three_star_model;
	static void InitialBag();
};