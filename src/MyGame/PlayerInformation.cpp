#include"PlayerInformation.h"

extern Dishes Rice;
extern Dishes Dongpo_braised_pork;
extern Dishes Beijing_Roast_Duck;
extern Dishes Lafite;
extern Dishes Royal_Palace_Banquet;

int PlayerInformation::Money;
int PlayerInformation::Popularity;
bool PlayerInformation::Havesmalldesk[7] = { true, true, true, false,false, false, false };
bool PlayerInformation::Havebigdesk[5] = { true, false,false, false, false };
//std::vector<int> PlayerInformation::Menu;
std::map<int, Index> PlayerInformation::Menu;

void PlayerInformation::InitialPlayerInformation() {
	Money = 10000;
	Popularity = 150;
	//Menu.push_back(1);
	Index temp_index = { 0,0 };
	Menu.emplace(17,temp_index );//插入米饭 1星
	InitialBag();
}

std::vector<Customer*> CPU::Customers_vector_reserve;
 Coor  CPU::BEGIN[]= { {1618, 300}, { 404,242 }, { 848,358 }, { 479,276 }, { 1096,451 }, { 1375,377 } };
 Coor  CPU::END_smalldesk[] = { {715,155},{793,177},{870,198},{1261,169},{1343,187},{1420,210},{1503,228} };
 Coor  CPU::END_bigdesk[] = { {852,283},{925,262},
							 { 950,311},{1047,291},
							 {1077,346},{1175,330},
							 {1158,256},{1260,233},
							 {1273,288},{1388,260} };


 bool CPU::is_samlldeak_available[7] = { true, true, true, false,false, false , false };
 int CPU::is_bigdeak_available[5] = {2,0,0,0,0};
bool CPU::is_NewCustomer_going =false;
//int CPU::dishes_profit[] = {Rice.profit,Dongpo_braised_pork.profit ,Beijing_Roast_Duck.profit,Lafite.profit ,Royal_Palace_Banquet.profit};

std::vector<Customer> CPU::Customers_vector_doing;

void CPU::initialCPU() {
	Customers_vector_reserve.push_back(new Customer(1618,300,715,155));//smalldesk0   0
	Customers_vector_reserve.push_back(new Customer(404,242,793,177));//smalldesk1   1
	Customers_vector_reserve.push_back(new Customer(848,358, 870, 198));//smalldesk2  2
	Customers_vector_reserve.push_back(new Customer(479, 276, 1261, 169));//smalldesk3  3
	Customers_vector_reserve.push_back(new Customer(1096, 451, 1343, 187));//smalldesk4  4
	Customers_vector_reserve.push_back(new Customer(1375, 377, 1420, 210));//smalldesk5  5
	Customers_vector_reserve.push_back(new Customer(1618, 300, 1503, 228));//smalldesk6  6

	Customers_vector_reserve.push_back(new Customer(1618, 300, END_bigdesk[0].x, END_bigdesk[0].y));//Bigdesk0_1   7
	Customers_vector_reserve.push_back(new Customer(1618, 300, END_bigdesk[1].x, END_bigdesk[1].y));//Bigdesk0_2   8

	Customers_vector_reserve.push_back(new Customer(404, 242, END_bigdesk[2].x, END_bigdesk[2].y));//Bigdesk1_1   9
	Customers_vector_reserve.push_back(new Customer(404, 242, END_bigdesk[3].x, END_bigdesk[3].y));//Bigdesk1_2   10

	Customers_vector_reserve.push_back(new Customer(404, 242, END_bigdesk[4].x, END_bigdesk[4].y));//Bigdesk2_1   11
	Customers_vector_reserve.push_back(new Customer(404, 242, END_bigdesk[5].x, END_bigdesk[5].y));//Bigdesk2_2   12

	Customers_vector_reserve.push_back(new Customer(404, 242, END_bigdesk[6].x, END_bigdesk[6].y));//Bigdesk3_1   13
	Customers_vector_reserve.push_back(new Customer(404, 242, END_bigdesk[7].x, END_bigdesk[7].y));//Bigdesk3_2   14


	Customers_vector_reserve.push_back(new Customer(404, 242, END_bigdesk[8].x, END_bigdesk[8].y));//Bigdesk4_1   15
	Customers_vector_reserve.push_back(new Customer(404, 242, END_bigdesk[9].x, END_bigdesk[9].y));//Bigdesk4_2   16
}

void CPU::NewCustomer() {
	
	if (rand() % 200 < PlayerInformation::Popularity)
	{
		//小桌子
		if (rand() % 100 < 60) {
			for (int i = 0; i < 7; i++) {
				if (is_samlldeak_available[i]) {
					Customers_vector_doing.push_back(*Customers_vector_reserve[i]);/////////////////////////////////////////
					Customers_vector_doing.back().is_in_big_or_small_desk = 1;
					Customers_vector_doing.back().in_samll_desk_index = i;
				/*	Coor temp = BEGIN[rand() % 6];
					Customers_vector_reserve.push_back(new Customer(temp.x,temp.y, END_smalldesk[i].x, END_smalldesk[i].y));
					is_samlldeak_available[i] = !is_samlldeak_available[i];*/
					is_samlldeak_available[i] = false;
					break;
				}
			}

		}
		//大桌子
		else {
			for (int i = 0; i < 5; i++) {
				if (is_bigdeak_available[i]==2) {
					Customers_vector_doing.push_back(*Customers_vector_reserve[i*2+7]);
					Customers_vector_doing.back().is_in_big_or_small_desk = 2;
					Customers_vector_doing.back().in_big_desk_index = i;

					Customers_vector_doing.push_back(*Customers_vector_reserve[i*2+8]);
					Customers_vector_doing.back().is_in_big_or_small_desk = 2;
					Customers_vector_doing.back().in_big_desk_index = i;
					is_bigdeak_available[i] = 0;
					/*	Coor temp = BEGIN[rand() % 6];
						Customers_vector_reserve.push_back(new Customer(temp.x,temp.y, END_smalldesk[i].x, END_smalldesk[i].y));
						is_samlldeak_available[i] = !is_samlldeak_available[i];*/

					break;
				}
			}
		}
		
	}
	//is_NewCustomer_going = !is_NewCustomer_going;
	return;
}
void CPU::Customer_Unit() {
	/*if (!is_NewCustomer_going) {
		is_NewCustomer_going = !is_NewCustomer_going;
		std::thread t(CPU::NewCustomer);
		
	}*/
	NewCustomer();


	//for (auto it : Customers_vector_doing) {
	for (auto it = Customers_vector_doing.begin(); it != Customers_vector_doing.end();) {
		UI::Insert_Customer((*it));


		if (!(*it).CustomerMove()) {
			
			if ((*it).Customer_eat_time++==70) {
				//顾客吃东西
			/*	switch (rand() % PlayerInformation::Menu.size() + 1) {
				case 1:
					PlayerInformation::Money += PlayerInformation::Dishes_vector[PlayerInformation::Menu[17].ID].profit[PlayerInformation::Menu[17].stars];
					break;
				case 2:
					PlayerInformation::Money += PlayerInformation::Dishes_vector[PlayerInformation::Menu[18].ID].profit[PlayerInformation::Menu[18].stars];
					break;
				case 3:
					PlayerInformation::Money += PlayerInformation::Dishes_vector[PlayerInformation::Menu[19].ID].profit[PlayerInformation::Menu[19].stars];
					break;
				default:
					break;
				}*/

				int times = 0;
				for (auto itMenu = PlayerInformation::Menu.begin(); times < rand() % PlayerInformation::Menu.size() + 1; itMenu++) {
					PlayerInformation::Money += PlayerInformation::Dishes_vector[itMenu->second.ID].profit[itMenu->second.stars];
					times++;
				}
				if ((*it).is_in_big_or_small_desk == 1) {
					//在小桌子上
					is_samlldeak_available[(*it).in_samll_desk_index] = true;

				}
				else  {
					//在大桌子上
					is_bigdeak_available[(*it).in_big_desk_index]++;
				}
				it = Customers_vector_doing.erase(it);
				continue;
	       	}
			
		}
		it++;
	}

}