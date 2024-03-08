#include"Dishes.h"
#include<cmath>


void Dishes::initialModel() {



}
Dishes::Dishes(int grade,int basic_price, int basic_popularity, int basic_raw_material_cost,int id, const char* model_data_filePath) 
	                 :AbstrastModel(model_data_filePath)
{
	this->Basic_Price = basic_price;
	this->Basic_Popularity = basic_popularity;
	this->Basic_Raw_material_cost = basic_raw_material_cost;
	this->ID = id;
	this->Grade = grade;

	for (int i = 0; i < 3; i++) {
		this->Price[i] = Basic_Price * (i+1);
		//this->Popularity[i] = Basic_Popularity * Stars;
		this->Raw_material_cost[i] = Basic_Raw_material_cost * pow(0.75, i - 1);
        this->profit[i] = this->Price[i] - this->Raw_material_cost[i];
	}
	




}

//void Dishes::Rising_star() {
//	this->Stars++;
//	this->Price = Basic_Price * Stars;
//	this->Popularity = Basic_Popularity * Stars;
//	this->Raw_material_cost = Basic_Raw_material_cost * pow(0.75, Stars - 1);
//
//}

//int Bag::dishes_one_star
//int Bag::dishes_two_star[number_of_Kind_of_dishes] = { 0 };
//int Bag::dishes_three_star[number_of_Kind_of_dishes] = { 0 };
extern Dishes Rice;
extern Dishes Dongpo_braised_pork;
extern Dishes Beijing_Roast_Duck;
extern Dishes Lafite;
extern Dishes Royal_Palace_Banquet;
int Bag::ALL_dishes[3][number_of_Kind_of_dishes] = { 0 };
std::map<int, Index> Bag::dishesMAp;
std::vector<Dishes> Bag::Dishes_vector;
void Bag::InitialBag() {
	Dishes_vector.push_back(Rice);//0
	Dishes_vector.push_back(Dongpo_braised_pork);//1
	Dishes_vector.push_back(Beijing_Roast_Duck); //2
    Dishes_vector.push_back(Lafite);// 3
	Dishes_vector.push_back(Royal_Palace_Banquet); //4
	ALL_dishes[0][0] = 1;
	ALL_dishes[1][1] = 1;
	SetdishesMap();
}
void Bag::SetdishesMap() {
	dishesMAp.clear();
	int begin = 31;
	for (int j = 0; j < 3; j++) {
		for(int i =0;i< number_of_Kind_of_dishes;i++)
			if (ALL_dishes[j][i] != 0) {
				Index temp = { j,i };
				dishesMAp.emplace(begin++, temp);
			}
	}

}
extern Dishes Rice;
extern Dishes Dongpo_braised_pork;
extern Dishes Beijing_Roast_Duck;
extern Dishes Lafite;
extern Dishes Royal_Palace_Banquet;
extern StaticModel ID_24_ThreeStars;
extern StaticModel ID_25_TwoStars;
extern StaticModel ID_26_OneStar;
void Bag::PrintBag() {
	SetdishesMap();
	for (auto it : dishesMAp) {
		switch (it.second.ID) {
		case 0:
			Rice.Insert_Coordinate_in_draw(988 + ((it.first - 31) % 8) * 82, 134 + ((it.first - 31) / 8) * 48);
			break;
		case 1:
			Dongpo_braised_pork.Insert_Coordinate_in_draw(988 + ((it.first - 31) % 8) * 82, 134 + ((it.first - 31) / 8) * 48);
			break;
		case 2:
			Beijing_Roast_Duck.Insert_Coordinate_in_draw(988 + ((it.first - 31) % 8) * 82, 134 + ((it.first - 31) / 8) * 48);
			break;
		case 3:
			Lafite.Insert_Coordinate_in_draw(988 + ((it.first - 31) % 8) * 82, 134 + ((it.first - 31) / 8) * 48);
			break;
		case 4:
			Royal_Palace_Banquet.Insert_Coordinate_in_draw(988 + ((it.first - 31) % 8) * 82, 134 + ((it.first - 31) / 8) * 48);
			break;
		default:break;
		}

		switch (it.second.stars) {
		case 0://1ÐÇ
			ID_26_OneStar.Insert_Coordinate_in_draw(1025 + ((it.first - 31) % 8) * 82, 157+((it.first - 31) / 8) * 48);
			break;
		case 1://1ÐÇ
			ID_25_TwoStars.Insert_Coordinate_in_draw(1025 + ((it.first - 31) % 8) * 82, 157+((it.first - 31) / 8) * 48);
		break; case 2://1ÐÇ
			ID_24_ThreeStars.Insert_Coordinate_in_draw(1025 + ((it.first - 31) % 8) * 82, 157+((it.first - 31) / 8) * 48);
			break;
		default:break;
		}
	}
	UI::Insert_ModelandFunctionArea(Rice);
	UI::Insert_ModelandFunctionArea(Dongpo_braised_pork);
	UI::Insert_ModelandFunctionArea(Beijing_Roast_Duck);
	UI::Insert_ModelandFunctionArea(Lafite);
	UI::Insert_ModelandFunctionArea(Royal_Palace_Banquet);

	UI::Insert_ModelandFunctionArea_superposition(ID_24_ThreeStars);
	UI::Insert_ModelandFunctionArea_superposition(ID_25_TwoStars);
	UI::Insert_ModelandFunctionArea_superposition(ID_26_OneStar);
}

//void Bag::Display_dishes_one_star() {
//	for (int i = 0; i < number_of_Kind_of_dishes; i++) {
//
//
//
//	}
//
//
//}
//Bag::Bag() {
//	dishes_one_star_model.push_back(new StaticModel());
//
//
//
//
//}