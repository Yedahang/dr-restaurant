#pragma once
#include"Model.h"
#include"Dishes.h"
#include"UI.h"
#include<vector>

static class PlayerInformation :public Bag{
public:
	static bool Havesmalldesk[7];
	static bool Havebigdesk[5];

	//static 

	static int Money;
	static int Popularity;
	static std::map<int, Index>Menu;

	static void InitialPlayerInformation();
};


static class CPU {
public:
	static Coor BEGIN[]; 
	static Coor END_smalldesk[];
	static Coor END_bigdesk[];
	static bool is_samlldeak_available[7];
	static int is_bigdeak_available[5];
	static int dishes_profit[];
	static std::vector<Customer*> Customers_vector_reserve;
	static std::vector<Customer> Customers_vector_doing;
	static void initialCPU();
	static void NewCustomer();
	static bool is_NewCustomer_going;
	static void Customer_Unit();

};


