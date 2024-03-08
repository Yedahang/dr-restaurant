#pragma once
#include"ScreenUnit.h"
#include "Model.h"
#include"InputUnit.h"
#include"UI.h"
#include"PlayerInformation.h"
#include"Dishes.h"


static class GAMESYSTEM {
public:
	static void InitialGamesystem();
	static void Beginmenu();
	static void MainGame();
	static void Research_interface();
	static void Restaurant_menu();
	static void Rising_star_menu();
	static void BuySmallDesk(int Fun_ID);
	static void update();
	static void BuyBigDesk(int Fun_ID);
	static void Bag_display();
	static void  Bag_clear();
	
	static void LoadGameFile();

	static int HaveSelect_Function_ID;
	static int HaveSelect_in_RaisingFunction;
};
extern StaticModel ID_1_StartButton;
extern StaticModel ID_2;
extern StaticModel ID_3_MainViewOfRestaurant;
extern StaticModel ID_5_FunctionMenu;
extern StaticModel ID_6_BackgroundofResearch;
extern StaticModel ID_7_BackgroundofResearch_1;
extern StaticModel ID_8_Menu;
extern StaticModel ID_9_FunctionMenu_1;
extern StaticModel ID_10_Frame_1;
extern StaticModel ID_11_Frame_2;
extern StaticModel ID_12_FunctionMenu_2;
extern StaticModel ID_13_FunctionMenu_3;
extern StaticModel ID_14_SynthesisUI;
extern StaticModel ID_15_SmallDesk;
extern StaticModel ID_16_BigDesk;

extern  BagModel ID_17_Bag;
extern StaticModel ID_18_CheckBox;
extern StaticModel ID_24_ThreeStars;
extern StaticModel ID_25_TwoStars;
extern StaticModel ID_26_OneStar;
extern StaticModel ID_27_FunctionInRaisingStar;
extern StaticModel ID_28_FunctionInRaisingStar_1;
extern StaticModel ID_29_Selectframe;
extern  StaticModel ID_30_BeginBackground;
extern StaticModel  ID_31_Title_1;
extern StaticModel BeginText;
extern DisplayMoney displaymoney;
extern Customer ID_4_Customer;

extern  StaticModel Chinese_Rice;
extern  StaticModel Chinese_Dongpo_braised_pork;
extern  StaticModel Chinese_Beijing_Roast_Duck;
extern StaticModel Chinese_Lafite;
extern StaticModel Chinese_Royal_Palace_Banquet;

extern StaticModel  Chinese_Price;
extern StaticModel Chinese_Profit;
extern StaticModel  Chinese_Quality;
extern StaticModel Chinese_RowCost;
extern StaticModel Chinese_Quantityowned;

extern Dishes Rice;
extern Dishes Dongpo_braised_pork;
extern Dishes Beijing_Roast_Duck;
extern Dishes Lafite ;
extern Dishes Royal_Palace_Banquet;

