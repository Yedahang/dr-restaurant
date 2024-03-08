#include"Database.h"
#include<stdlib.h>
#include<string>
extern void Pop_up_message_box(const char* content, const char* title);
extern int Pop_up_message_box_MB_YESNO(const char* content, const char* title);

//加载资源文件
StaticModel ID_1_StartButton("../Sources/Model/ASCII-ID1-StartButton.txt", 3);
StaticModel ID_2("../Sources/Model/ASCII-ID2.txt", 0);
StaticModel ID_3_MainViewOfRestaurant("../Sources/Model/ASCII-ID3_MainViewOfRestaurant.txt", 0);
StaticModel ID_5_FunctionMenu("../Sources/Model/ASCII-ID5_FunctionMenu.txt", 0);
StaticModel ID_6_BackgroundofResearch("../Sources/Model/ASCII-ID6_BackgroundofResearch.txt", 0);
StaticModel ID_7_BackgroundofResearch_1("../Sources/Model/ASCII-ID7_BackgroundofResearch_1.txt", 0);
StaticModel ID_8_Menu("../Sources/Model/ASCII-ID8_Menu.txt", 0);
StaticModel ID_9_FunctionMenu_1("../Sources/Model/ASCII-ID9_FunctionMenu_1.txt", 0);
StaticModel ID_10_Frame_1("../Sources/Frame/Frame_1.txt", 0);
StaticModel ID_11_Frame_2("../Sources/Frame/Frame_2.txt", 0);
StaticModel ID_12_FunctionMenu_2("../Sources/Model/ASCII-ID12_FunctionMenu_2.txt", 0);
StaticModel ID_13_FunctionMenu_3("../Sources/Model/ASCII-ID13_FunctionMenu_3.txt", 0);
StaticModel ID_14_SynthesisUI("../Sources/Model/ASCII-ID14_SynthesisUI.txt", 0);
StaticModel ID_15_SmallDesk("../Sources/Model/ASCII-ID15_SmallDesk.txt", 0);
StaticModel ID_16_BigDesk("../Sources/Model/ASCII-ID16_BigDesk.txt", 0);	

StaticModel Chinese_Rice("../Sources/Text/Chinese_Rice.txt", 0);
StaticModel Chinese_Dongpo_braised_pork("../Sources/Text/Chinese_Dongpo_braised_pork.txt", 0);
StaticModel Chinese_Beijing_Roast_Duck("../Sources/Text/Chinese_Beijing_Roast_Duck.txt", 0);
StaticModel Chinese_Lafite("../Sources/Text/Chinese_Lafite.txt", 0);
StaticModel Chinese_Royal_Palace_Banquet("../Sources/Text/Chinese_Royal_Palace_Banquet.txt", 0);

StaticModel Chinese_Price("../Sources/Text/Chinese_Price.txt", 0);
StaticModel Chinese_Profit("../Sources/Text/Chinese_Profit.txt", 0);
StaticModel  Chinese_Quality("../Sources/Text/Chinese_Quality.txt", 0);
StaticModel Chinese_RowCost("../Sources/Text/Chinese_RowCost.txt", 0);
StaticModel Chinese_Quantityowned("../Sources/Text/Chinese_Quantityowned.txt", 0);

BagModel ID_17_Bag("../Sources/Model/ASCII-ID17_Bag.txt", 0);
StaticModel ID_18_CheckBox("../Sources/Model/ASCII-ID18_CheckBox.txt", 0);


StaticModel ID_24_ThreeStars("../Sources/Model/ASCII-ID24_Three_stars.txt", 0);
 StaticModel ID_25_TwoStars("../Sources/Model/ASCII-ID25_Two_stars.txt", 0);
StaticModel ID_26_OneStar("../Sources/Model/ASCII-ID26_one_star.txt", 0);

StaticModel ID_27_FunctionInRaisingStar("../Sources/Model/ASCII-ID27_FunctionMenuinRaisingStar.txt", 0);
StaticModel ID_28_FunctionInRaisingStar_1("../Sources/Model/ASCII-ID28_FunctionMenuinRaisingStar_1.txt", 0);
StaticModel ID_29_Selectframe("../Sources/Model/ASCII-ID29_Select_frame.txt", 0);

StaticModel ID_30_BeginBackground("../Sources/Model/ASCII-ID30_Beginbackground.txt", 0);
StaticModel  ID_31_Title_1("../Sources/Text/Title_1.txt", 0);
//StaticModel ID_19_Rice("../Sources/Model/ASCII-ID19_Rice.txt", 0);

StaticModel BeginText("../Sources/Text/BeginText.txt", 0);;
DisplayText_Num Textdisplay_1;
DisplayText_Num Textdisplay_2;
DisplayText_Num Textdisplay_3;
DisplayText_Num Textdisplay_4;
DisplayText_Num Textdisplay_5;
StaticModel TEMP("../Sources/Text/ASCII-7.txt", 0);


DisplayMoney displaymoney("../Sources/Frame/MoneyFrame.txt");


Dishes Rice(1, 20, 4, 2, 0, "../Sources/Model/ASCII-ID19_Rice.txt");//米饭 1级
Dishes Dongpo_braised_pork(2, 40, 6, 10, 1, "../Sources/Model/ASCII-ID20_Dongpo_braised_pork.txt");//东坡肉 2级
Dishes Beijing_Roast_Duck(3, 100, 15, 12, 2,"../Sources/Model/ASCII-ID21_Beijing_Roast_Duck.txt");//北京烤鸭 3级
Dishes Lafite(4, 300, 20, 50, 3, "../Sources/Model/ASCII-ID22_Lafite.txt");           //82年拉菲 4级
Dishes Royal_Palace_Banquet(5, 700, 30, 100, 4, "../Sources/Model/ASCII-ID23_Royal_Palace_Banquet.txt");//皇家宫廷宴 5级



Customer ID_4_Customer("../Sources/Model/ASCII-ID4_CharacterModel1.txt");//初始化一次，后面用无参构造

int GAMESYSTEM::HaveSelect_Function_ID = 0;
void InitialScreenUnit() {
	ScreenUnit::InitialScreenUnit();
	
}
void initialInputUnit() {
	MouseInputUnit::initialMouseInputUnit();

}
void InitialUI() {
	UI::initialUI();
}
void InitialData() {
	PlayerInformation::InitialPlayerInformation(); 
	DisplayText_Num::SetNumber();

	ID_1_StartButton.Set_Function_Coor(22, 18, 331, 65, 1);
	ID_1_StartButton.Set_Function_Coor(22, 99, 331, 148, 2);
	ID_1_StartButton.Set_Function_Coor(22, 183, 331, 231, 3);
	//UI::Insert_ModelandFunctionArea(1300, 170, ID_1_StartButton);
	ID_1_StartButton.Insert_Coordinate_in_draw(760, 220);
    // UI::Insert_ModelandFunctionArea(ID_1_StartButton);

	ID_3_MainViewOfRestaurant.Calculation_mouse_click_function_area(987,151,1108,151,1055,135,1040,166,4);
	ID_3_MainViewOfRestaurant.Calculation_mouse_click_function_area(1066,172,1185,171,1126,156,1124,188,5);
	ID_3_MainViewOfRestaurant.Calculation_mouse_click_function_area(1145,195,1264,192,1204,176,1207,210,6);
	ID_3_MainViewOfRestaurant.Calculation_mouse_click_function_area(1222,216,1345,216,1281,198,1283,231,7);
	ID_3_MainViewOfRestaurant.Calculation_mouse_click_function_area(700,295,890,279,822,261,747,316 ,23);
	ID_3_MainViewOfRestaurant.Calculation_mouse_click_function_area(812,332,1011,313,934,293,893,350, 24);
	ID_3_MainViewOfRestaurant.Calculation_mouse_click_function_area(898,244,1108,221,1036,205,970,260,25);
	ID_3_MainViewOfRestaurant.Calculation_mouse_click_function_area(1022,277,1224,254,1158,221,1080,294,26);
	ID_3_MainViewOfRestaurant.Insert_Coordinate_in_draw(230, 10);

	ID_5_FunctionMenu.Calculation_mouse_click_function_area(10,30,193,2,13,1,188,33,8);
	ID_5_FunctionMenu.Calculation_mouse_click_function_area(10,70,191,49,15,47,189,72, 9);
	ID_5_FunctionMenu.Calculation_mouse_click_function_area(8,119,192,99,15,94,189,121,10);
	ID_5_FunctionMenu.Insert_Coordinate_in_draw(33, 330);

	ID_6_BackgroundofResearch.Insert_Coordinate_in_draw(370, 25);

	ID_7_BackgroundofResearch_1.Insert_Coordinate_in_draw(500, 100);

	ID_8_Menu.Insert_Coordinate_in_draw(664, 197);




	ID_9_FunctionMenu_1.Calculation_mouse_click_function_area(18, 48, 280, 14, 27, 10, 274, 50, 11);
	ID_9_FunctionMenu_1.Calculation_mouse_click_function_area(20,116,278,84,28,78,276,117,12);
	ID_9_FunctionMenu_1.Calculation_mouse_click_function_area(20,182,283,150,30,145,279,183,13);
	ID_9_FunctionMenu_1.Insert_Coordinate_in_draw(1230, 197);


	ID_10_Frame_1.Set_Function_Coor(64, 69, 427, 111, 17);
	ID_10_Frame_1.Set_Function_Coor(64, 146, 427, 187, 18);
	ID_10_Frame_1.Set_Function_Coor(64, 226, 427, 268, 19);
	ID_10_Frame_1.Insert_Coordinate_in_draw(150, 59);

	ID_11_Frame_2.Insert_Coordinate_in_draw(828, 59);

	ID_12_FunctionMenu_2.Calculation_mouse_click_function_area(215, 27, 385, 6, 218, 1, 380, 28, 14);
	ID_12_FunctionMenu_2.Calculation_mouse_click_function_area(11, 27, 181, 3, 18, 1, 177, 28, 15);
	ID_12_FunctionMenu_2.Insert_Coordinate_in_draw(831, 425);

	ID_13_FunctionMenu_3.Calculation_mouse_click_function_area(1, 33, 194, 10, 11, 2, 191, 35, 16);
	ID_13_FunctionMenu_3.Insert_Coordinate_in_draw(450, 425);

	ID_14_SynthesisUI.Insert_Coordinate_in_draw(200, 100);

	//ID_15_SmallDesk.Insert_Coordinate_in_draw(1230, 126);
	//ID_15_SmallDesk.Insert_Coordinate_in_draw(1310,148);
	//ID_15_SmallDesk.Insert_Coordinate_in_draw(1390, 170);
	//ID_15_SmallDesk.Insert_Coordinate_in_draw(1470, 192);

	//ID_16_BigDesk.Insert_Coordinate_in_draw(1140, 205);
	//ID_16_BigDesk.Insert_Coordinate_in_draw(1260, 238);
	//ID_16_BigDesk.Insert_Coordinate_in_draw(929, 266);
	//ID_16_BigDesk.Insert_Coordinate_in_draw(1049, 299);

	ID_17_Bag.Insert_Coordinate_in_draw(959, 114);
	ID_17_Bag.SetBagFunction(30, 19, 95, 56,31);    //Function 31~62

	ID_27_FunctionInRaisingStar.Set_Function_Coor(9, 5, 193, 31, 20);//添加
	ID_27_FunctionInRaisingStar.Set_Function_Coor(212,5,397,33,21);//返回
	ID_27_FunctionInRaisingStar.Insert_Coordinate_in_draw(831, 425);

	ID_28_FunctionInRaisingStar_1.Set_Function_Coor(5, 2, 164, 25, 22);//升星
	ID_28_FunctionInRaisingStar_1.Insert_Coordinate_in_draw(369, 390);

	ID_30_BeginBackground.Insert_Coordinate_in_draw(0, 0);
	//ID_4_Customer.Insert_Coordinate_in_draw(870, 198);
	//ID_4_Customer.SetPath( 559,298,1160,161 );
	//ID_4_Customer.SetPath(479,276,715,155);
	//ID_4_Customer.PrintPath();
	//system("pause");
	ID_4_Customer.SetActionto_modeldata();

	BeginText.Insert_Coordinate_in_draw(350, 100);
	displaymoney.Insert_Coordinate_in_draw(1380, 10);
	/*UI::Insert_ModelandFunctionArea(ID_3_MainViewOfRestaurant);
	UI::Insert_ModelandFunctionArea(displaymoney);


	UI::PaintthePicture();
	MouseInputUnit::mouse_for_test();*/


	//ID_3_MainViewOfRestaurant.OutputModel();
	//MouseInputUnit::Get_mouse_click_coordinates();


}
void InitialMovablemap() {
	Movablemap::InitialMovablemap();
}
void InitialPlayerInformation() {
	PlayerInformation::InitialPlayerInformation();
}
void DisplayBegintext() {
	UI::Insert_ModelandFunctionArea(BeginText);
	ScreenUnit::Double_Buffershow(UI::thePicturedata);
	Sleep(3000);

}
void GAMESYSTEM::InitialGamesystem() {
	InitialScreenUnit();
	initialInputUnit();
	InitialUI();
	InitialMovablemap();
	InitialData();
	InitialPlayerInformation();
	//DisplayBegintext();
//	CPU::initialCPU();
}
void GAMESYSTEM::Beginmenu() {
	UI::ClearthePicture();
    UI::Insert_ModelandFunctionArea(ID_30_BeginBackground);
	ID_31_Title_1.Insert_Coordinate_in_draw(391, 45);
	UI::Insert_ModelandFunctionArea_superposition(ID_31_Title_1);
	UI::Insert_ModelandFunctionArea_superposition(ID_1_StartButton);

	while (true) {
		ScreenUnit::Double_Buffershow(UI::thePicturedata);
		switch (MouseInputUnit::mouse()) {
		case 1: 
			GAMESYSTEM::MainGame(); break;
		case 2:
			
			GAMESYSTEM::LoadGameFile();
			break;
		case 3:
		//	char* title[]="提示";
			//char* content = "您已成功退出游戏，请关闭控制台窗口";
			
			//Pop_up_message_box(content, title);
			system("cls");
			Pop_up_message_box("您已成功退出游戏，请关闭控制台窗口", "提示");
			exit(0); break;
		default:
			break;

		}

	}

}
void GAMESYSTEM::MainGame() {
	
	
	while (1) {
		UI::Insert_ModelandFunctionArea(ID_3_MainViewOfRestaurant);
		UI::Insert_ModelandFunctionArea(displaymoney);
		UI::Insert_ModelandFunctionArea(ID_5_FunctionMenu);
		UI::Insert_ModelandFunctionArea_superposition(ID_15_SmallDesk);
		UI::Insert_ModelandFunctionArea_superposition(ID_16_BigDesk);
		CPU::Customer_Unit();

		ScreenUnit::Double_Buffershow(UI::thePicturedata);
		
	   //MouseInputUnit::Get_mouse_click_coordinates();
         //MouseInputUnit::mouse_for_test();
		int temp = MouseInputUnit::mouse();
		if (temp > 3 && temp < 8) {


			GAMESYSTEM::BuySmallDesk(temp);

		}
		else if (temp > 22 && temp < 27) {
			GAMESYSTEM::BuyBigDesk(temp);

		}
		else {
			switch (temp) {
			case 8:
				Restaurant_menu();
				break;
			case 9:
				Research_interface();
				break;
			case 10:
				Rising_star_menu();
			default:
				break;

			}
			update();
		}
	}
};
void GAMESYSTEM::update() {
	displaymoney.SetMoneyValue(PlayerInformation::Money);
	UI::ClearthePicture();
	
}
//研究 “抽卡”
void Luck_draw(int times) {
	std::string Temp_string;
	for (int i = 0; i < times; i++) {
		int get = rand() % 150;
		
		if (get < 40) {
			Temp_string += "   米饭     品质：1  星级：1\n";
			PlayerInformation::ALL_dishes[0][0]++;
		}
		else if (get > 39 && get < 80) {
			Temp_string += "  东坡肉    品质：2  星级：1\n";
			PlayerInformation::ALL_dishes[0][1]++;
		}
		else if (get > 79 && get < 110) {
			Temp_string += " 北京烤鸭   品质：3  星级：1\n";
			PlayerInformation::ALL_dishes[0][2]++;
		}
		else if (get > 109 && get < 130) {
			Temp_string += " 82年拉菲   品质：4  星级：1\n";
			PlayerInformation::ALL_dishes[0][3]++;
		}
		else if (get > 129 && get < 150) {
			Temp_string += "皇家宫廷宴  品质：5  星级：1\n";
			PlayerInformation::ALL_dishes[0][4]++;
		}
	}
	char* temp_char = new char[Temp_string.length()];
	Temp_string.copy(temp_char, std::string::npos);
	temp_char [Temp_string.length()]='\0';
	Pop_up_message_box(temp_char, "恭喜您，您获得了：");

}

void  GAMESYSTEM::Research_interface() {
	UI::ClearFunctionArea();
	while (1) {

		UI::Insert_ModelandFunctionArea(ID_6_BackgroundofResearch);
		UI::Insert_ModelandFunctionArea_superposition(ID_7_BackgroundofResearch_1);
		UI::Insert_ModelandFunctionArea(ID_8_Menu);
		UI::Insert_ModelandFunctionArea_superposition(ID_9_FunctionMenu_1);
		ScreenUnit::Double_Buffershow(UI::thePicturedata);
		switch (MouseInputUnit::mouse()) {
		case 11://研究一次
			if (Pop_up_message_box_MB_YESNO("研究一次将消耗1000元,是否继续?", "注意") == 6) {
				if (PlayerInformation::Money > 999) {
					PlayerInformation::Money -= 1000;
					Luck_draw(1);
				}
				else
					Pop_up_message_box("您当前余额不够，等钱够了再来吧!", "研究失败");
            
			}
			break;
		case 12://研究十次
			if (Pop_up_message_box_MB_YESNO("研究十次将消耗10000元,是否继续?", "注意") == 6) {
				if (PlayerInformation::Money > 9999) {
					PlayerInformation::Money -= 10000;
					Luck_draw(10);
				}
				else
					Pop_up_message_box("您当前余额不够，等钱够了再来吧!", "研究失败");
			     
			}
			break;

		case 13://返回键
			return;
		default:break;
		}
	}
}


void GAMESYSTEM::Restaurant_menu() {
	UI::ClearFunctionArea();
	bool Is_Removemenu = false;
	while (1) {
		UI::Insert_ModelandFunctionArea(ID_10_Frame_1);
		UI::Insert_ModelandFunctionArea(ID_11_Frame_2);
		UI::Insert_ModelandFunctionArea_superposition(ID_12_FunctionMenu_2);
		UI::Insert_ModelandFunctionArea_superposition(ID_13_FunctionMenu_3);

		UI::Insert_ModelandFunctionArea(ID_17_Bag);

		ID_26_OneStar.Coordinate_in_draw.clear();
		ID_25_TwoStars.Coordinate_in_draw.clear();
		ID_24_ThreeStars.Coordinate_in_draw.clear();
		//菜单
		for (auto& it : PlayerInformation::Menu) {
			switch (it.second.ID) {
			case 0:
				Rice.Insert_Coordinate_in_draw(360, 130 + (it.first - 17) * 80);
				break;
			case 1:
				Dongpo_braised_pork.Insert_Coordinate_in_draw(360, 130 + (it.first - 17) * 80);
				break;
			case 2:
				Beijing_Roast_Duck.Insert_Coordinate_in_draw(360, 130 + (it.first - 17) * 80);
				break;
			case 3:
				Lafite.Insert_Coordinate_in_draw(360, 130 + (it.first - 17) * 80);
				break;
			case 4:
				Royal_Palace_Banquet.Insert_Coordinate_in_draw(360, 130 + (it.first - 17) * 80);
				break;
			default:break;
			}
			switch (it.second.stars) {
			case 0://1星
				ID_26_OneStar.Insert_Coordinate_in_draw(397, 153 + (it.first - 17) * 80);
				break;
			case 1://1星
				ID_25_TwoStars.Insert_Coordinate_in_draw(397, 153 + (it.first - 17) * 80);
			break; case 2://1星
				ID_24_ThreeStars.Insert_Coordinate_in_draw(397, 153 + (it.first - 17) * 80);
				break;
			default:break;
			}

		}
		GAMESYSTEM::Bag_display();

		UI::Insert_ModelandFunctionArea_superposition(ID_29_Selectframe);
		UI::Insert_ModelandFunctionArea_superposition(ID_18_CheckBox);

		ScreenUnit::Double_Buffershow(UI::thePicturedata);

		//MouseInputUnit::Get_mouse_click_coordinates();

		//MouseInputUnit::Get_mouse_click_coordinates();
		//MouseInputUnit::mouse_for_test();
		int temp = 0;
		if (Is_Removemenu){
			temp = 31;
			Is_Removemenu = false;
	     }
		else
		temp = MouseInputUnit::mouse();
		
		if (temp > 30 && temp < 63) {
			GAMESYSTEM::HaveSelect_Function_ID = temp;
			ID_29_Selectframe.Coordinate_in_draw.clear();
			ID_18_CheckBox.Coordinate_in_draw.clear();
			ID_18_CheckBox.Insert_Coordinate_in_draw(988 + ((temp - 31) % 8) * 82, 134 + ((temp - 31) / 8) * 48);//设置选中框
			auto temp_it = PlayerInformation::dishesMAp.find(temp);

			GAMESYSTEM::Bag_clear();
			

			if (temp_it != PlayerInformation::dishesMAp.end()) {
				int temp_star = (*temp_it).second.stars;
				switch ((*temp_it).second.ID) {
				case 0:
					Rice.Insert_Coordinate_in_draw(914, 337);
					Chinese_Rice.Insert_Coordinate_in_draw(975, 337);
					Textdisplay_1.SetMoneyValue(Rice.Price[temp_star]);
					Textdisplay_2.SetMoneyValue(Rice.Raw_material_cost[temp_star]);
					Textdisplay_3.SetMoneyValue(Rice.profit[temp_star]);
					break;
				case 1:
					Dongpo_braised_pork.Insert_Coordinate_in_draw(914, 337);
					Chinese_Dongpo_braised_pork.Insert_Coordinate_in_draw(975, 337);
					Textdisplay_1.SetMoneyValue(Dongpo_braised_pork.Price[temp_star]);
					Textdisplay_2.SetMoneyValue(Dongpo_braised_pork.Raw_material_cost[temp_star]);
					Textdisplay_3.SetMoneyValue(Dongpo_braised_pork.profit[temp_star]);
					break;
				case 2:
					Beijing_Roast_Duck.Insert_Coordinate_in_draw(914, 337);
					Chinese_Beijing_Roast_Duck.Insert_Coordinate_in_draw(975, 337);
					Textdisplay_1.SetMoneyValue(Beijing_Roast_Duck.Price[temp_star]);
					Textdisplay_2.SetMoneyValue(Beijing_Roast_Duck.Raw_material_cost[temp_star]);
					Textdisplay_3.SetMoneyValue(Beijing_Roast_Duck.profit[temp_star]);
					break;
				case 3:
					Lafite.Insert_Coordinate_in_draw(914, 337);
					Chinese_Lafite.Insert_Coordinate_in_draw(975, 337);
					Textdisplay_1.SetMoneyValue(Lafite.Price[temp_star]);
					Textdisplay_2.SetMoneyValue(Lafite.Raw_material_cost[temp_star]);
					Textdisplay_3.SetMoneyValue(Lafite.profit[temp_star]);
					break;
				case 4:
					Royal_Palace_Banquet.Insert_Coordinate_in_draw(914, 337);
					Chinese_Royal_Palace_Banquet.Insert_Coordinate_in_draw(975, 337);
					Textdisplay_1.SetMoneyValue(Royal_Palace_Banquet.Price[temp_star]);
					Textdisplay_2.SetMoneyValue(Royal_Palace_Banquet.Raw_material_cost[temp_star]);
					Textdisplay_3.SetMoneyValue(Royal_Palace_Banquet.profit[temp_star]);
					break;
				default:
					break;
				}
				Chinese_Price.Insert_Coordinate_in_draw(916, 370);
				Chinese_RowCost.Insert_Coordinate_in_draw(1178, 372);
				Chinese_Profit.Insert_Coordinate_in_draw(1441, 372);
				Chinese_Quantityowned.Insert_Coordinate_in_draw(1400, 345);
				Chinese_Quality.Insert_Coordinate_in_draw(1242, 345);

				Textdisplay_1.Insert_Coordinate_in_draw(995, 374);
				Textdisplay_2.Insert_Coordinate_in_draw(1260, 374);
				Textdisplay_3.Insert_Coordinate_in_draw(1530, 374);
				Textdisplay_4.Insert_Coordinate_in_draw(1552, 348);
				Textdisplay_5.Insert_Coordinate_in_draw(1245, 350);

				Textdisplay_4.SetMoneyValue(PlayerInformation::ALL_dishes[(*temp_it).second.stars][(*temp_it).second.ID]);
				Textdisplay_5.SetMoneyValue((*temp_it).second.ID+1);
			}
			
		    
		}
		else if (temp > 16 && temp < 20) {
			GAMESYSTEM::HaveSelect_Function_ID = temp;
			ID_29_Selectframe.Coordinate_in_draw.clear();
			ID_18_CheckBox.Coordinate_in_draw.clear();
			ID_29_Selectframe.Insert_Coordinate_in_draw(215, 127+ (temp - 17)* 79);//设置选中框

		}
		else {
		switch (temp) {
			case 14://返回键
				//UI::ClearthePicture();
				GAMESYSTEM::HaveSelect_Function_ID = 0;
				return;
			case 15://加入菜单
				if (GAMESYSTEM::HaveSelect_Function_ID>30&& GAMESYSTEM::HaveSelect_Function_ID < 63) {
					int temp_size = PlayerInformation::Menu.size();
					if (temp_size == 3) {
						Pop_up_message_box("菜单已满，加入失败。", "提示");
						break;
					}
					auto it = PlayerInformation::dishesMAp.find(HaveSelect_Function_ID);
					if (it != PlayerInformation::dishesMAp.end()) {
						//可以添&加
						for (int i = 17; i < 20;i++) {
							if (PlayerInformation::Menu.find(i) == PlayerInformation::Menu.end()) {
								PlayerInformation::Menu.emplace(i, (*it).second);
								break;
							}
						}
						
						//	Pop_up_message_box("添加。", "提示");
					}
					else {
						Pop_up_message_box("请在右边栏目中选择你要添加的菜品，再添加。", "提示");
					}
				}
				else {
					Pop_up_message_box("请选择好要添加的菜品后再进行添加。", "提示");

				}
				break;
			case 16://移出菜单
				if (GAMESYSTEM::HaveSelect_Function_ID > 16 && GAMESYSTEM::HaveSelect_Function_ID < 20) {
					auto it = PlayerInformation::Menu.find(HaveSelect_Function_ID);
					if (it == PlayerInformation::Menu.end()) {
						Pop_up_message_box("移出失败，当前选中框处无可移出内容。", "提示");
						break;
					}
					PlayerInformation::Menu.erase(it);
					Is_Removemenu = true;
					Pop_up_message_box("移出成功。", "提示");
				}
				break;
			default:
				break;

		}
		
		}
	}



 }


 //***********************************************************************************************分界线 便于coding时定位*****************
 //升星功能
 void DisplayModelinRaisingFunction(AbstrastModel& model) {
	 for (int i = 0; i < 2; i++) {
		 for(int j=0;j<2;j++)
			 model.Insert_Coordinate_in_draw(319+201*j, 175 + i * 113);
	 }
 }
 void DisplayStarsinRaisingFunction(AbstrastModel& model) {
	 for (int i = 0; i < 2; i++) {
		 for (int j = 0; j < 2; j++)
			 model.Insert_Coordinate_in_draw(353 + 201 * j, 200 + i * 113);
	 }


 }
 void DisplayModelinRaisingFunction_center(AbstrastModel& model) {
	
	 model.Insert_Coordinate_in_draw(418, 231);

 }
 void DisplayStarsinRaisingFunction_center(AbstrastModel& model) {
			 model.Insert_Coordinate_in_draw(455, 254);
	
 }
int GAMESYSTEM::HaveSelect_in_RaisingFunction=0;
void GAMESYSTEM::Rising_star_menu() {
	//UI::ClearFunctionArea();
	UI::ClearFunctionArea();
	GAMESYSTEM::Bag_clear();
	int Temp_ID = -1;
	int Temp_Star = -1;
	bool is_Succeed_raising = false;
	while (1) {
		UI::Insert_ModelandFunctionArea(ID_14_SynthesisUI);
		UI::Insert_ModelandFunctionArea(ID_11_Frame_2);
		UI::Insert_ModelandFunctionArea(ID_17_Bag);
		UI::Insert_ModelandFunctionArea_superposition(ID_27_FunctionInRaisingStar);
		UI::Insert_ModelandFunctionArea_superposition(ID_28_FunctionInRaisingStar_1);
	//	UI::Insert_ModelandFunctionArea_superposition(Temp_staticmodel);
		//将菜品图标插入进升星四角的四个框里
		if(GAMESYSTEM::HaveSelect_in_RaisingFunction != 0) {
			switch (PlayerInformation::dishesMAp.find(HaveSelect_in_RaisingFunction)->second.ID) {
			case 0:
				DisplayModelinRaisingFunction(Rice);
				break;
			case 1:
				DisplayModelinRaisingFunction(Dongpo_braised_pork);
				break;
			case 2:
				DisplayModelinRaisingFunction(Beijing_Roast_Duck);
				break;
			case 3:
				DisplayModelinRaisingFunction(Lafite);
				break;
			case 4:
				DisplayModelinRaisingFunction(Royal_Palace_Banquet);
				break;
			default:break;
			}
			switch (PlayerInformation::dishesMAp.find(HaveSelect_in_RaisingFunction)->second.stars) {
			case 0://1星
				DisplayStarsinRaisingFunction(ID_26_OneStar); 
				break;
			case 1://1星
				DisplayStarsinRaisingFunction(ID_25_TwoStars);
			break; case 2://1星
				DisplayStarsinRaisingFunction(ID_24_ThreeStars); 
				break;
			default:break;
			}

		}
		if (Temp_ID != -1) {
			switch (Temp_ID) {
			case 0:
				DisplayModelinRaisingFunction_center(Rice);
				break;
			case 1:
				DisplayModelinRaisingFunction_center(Dongpo_braised_pork);
				break;
			case 2:
				DisplayModelinRaisingFunction_center(Beijing_Roast_Duck);
				break;
			case 3:
				DisplayModelinRaisingFunction_center(Lafite);
				break;
			case 4:
				DisplayModelinRaisingFunction_center(Royal_Palace_Banquet);
				break;
			default:break;
			}
			switch (Temp_Star) {
			case 0://1星
				DisplayStarsinRaisingFunction_center(ID_26_OneStar);
				break;
			case 1://1星
				DisplayStarsinRaisingFunction_center(ID_25_TwoStars);
			break; case 2://1星
				DisplayStarsinRaisingFunction_center(ID_24_ThreeStars);
				break;
			default:break;
			}


		}
		
		PlayerInformation::PrintBag();
		GAMESYSTEM::Bag_display();
		UI::Insert_ModelandFunctionArea_superposition(ID_18_CheckBox);
		ScreenUnit::Double_Buffershow(UI::thePicturedata);
		//MouseInputUnit::Get_mouse_click_coordinates();
		int temp = 0;
		if (!is_Succeed_raising)
			temp = MouseInputUnit::mouse();
		else {
			temp = 31;
			is_Succeed_raising = false;
		}
		if (temp > 30 && temp < 63) {
			GAMESYSTEM::HaveSelect_in_RaisingFunction = 0;

			GAMESYSTEM::HaveSelect_Function_ID = temp;
			ID_18_CheckBox.Coordinate_in_draw.clear();
			ID_18_CheckBox.Insert_Coordinate_in_draw(988 + ((temp - 31) % 8) * 82, 134 + ((temp - 31) / 8) * 48);//设置选中框
			auto temp_it = PlayerInformation::dishesMAp.find(temp);

			GAMESYSTEM::Bag_clear();

			if (temp_it != PlayerInformation::dishesMAp.end()) {
				int temp_star = (*temp_it).second.stars;
				switch ((*temp_it).second.ID) {
				case 0:
					Rice.Insert_Coordinate_in_draw(914, 337);
					Chinese_Rice.Insert_Coordinate_in_draw(975, 337);
					Textdisplay_1.SetMoneyValue(Rice.Price[temp_star]);
					Textdisplay_2.SetMoneyValue(Rice.Raw_material_cost[temp_star]);
					Textdisplay_3.SetMoneyValue(Rice.profit[temp_star]);
					break;
				case 1:
					Dongpo_braised_pork.Insert_Coordinate_in_draw(914, 337);
					Chinese_Dongpo_braised_pork.Insert_Coordinate_in_draw(975, 337);
					Textdisplay_1.SetMoneyValue(Dongpo_braised_pork.Price[temp_star]);
					Textdisplay_2.SetMoneyValue(Dongpo_braised_pork.Raw_material_cost[temp_star]);
					Textdisplay_3.SetMoneyValue(Dongpo_braised_pork.profit[temp_star]);
					break;
				case 2:
					Beijing_Roast_Duck.Insert_Coordinate_in_draw(914, 337);
					Chinese_Beijing_Roast_Duck.Insert_Coordinate_in_draw(975, 337);
					Textdisplay_1.SetMoneyValue(Beijing_Roast_Duck.Price[temp_star]);
					Textdisplay_2.SetMoneyValue(Beijing_Roast_Duck.Raw_material_cost[temp_star]);
					Textdisplay_3.SetMoneyValue(Beijing_Roast_Duck.profit[temp_star]);
					break;
				case 3:
					Lafite.Insert_Coordinate_in_draw(914, 337);
					Chinese_Lafite.Insert_Coordinate_in_draw(975, 337);
					Textdisplay_1.SetMoneyValue(Lafite.Price[temp_star]);
					Textdisplay_2.SetMoneyValue(Lafite.Raw_material_cost[temp_star]);
					Textdisplay_3.SetMoneyValue(Lafite.profit[temp_star]);
					break;
				case 4:
					Royal_Palace_Banquet.Insert_Coordinate_in_draw(914, 337);
					Chinese_Royal_Palace_Banquet.Insert_Coordinate_in_draw(975, 337);
					Textdisplay_1.SetMoneyValue(Royal_Palace_Banquet.Price[temp_star]);
					Textdisplay_2.SetMoneyValue(Royal_Palace_Banquet.Raw_material_cost[temp_star]);
					Textdisplay_3.SetMoneyValue(Royal_Palace_Banquet.profit[temp_star]);
					break;
				default:
					break;
				}
				Chinese_Price.Insert_Coordinate_in_draw(916, 370);
				Chinese_RowCost.Insert_Coordinate_in_draw(1178, 372);
				Chinese_Profit.Insert_Coordinate_in_draw(1441, 372);
				Chinese_Quantityowned.Insert_Coordinate_in_draw(1400, 345);
				Chinese_Quality.Insert_Coordinate_in_draw(1242, 345);

				Textdisplay_1.Insert_Coordinate_in_draw(995, 374);
				Textdisplay_2.Insert_Coordinate_in_draw(1260, 374);
				Textdisplay_3.Insert_Coordinate_in_draw(1530, 374);
				Textdisplay_4.Insert_Coordinate_in_draw(1552, 348);
				Textdisplay_5.Insert_Coordinate_in_draw(1245, 350);

				Textdisplay_4.SetMoneyValue(PlayerInformation::ALL_dishes[(*temp_it).second.stars][(*temp_it).second.ID]);
				Textdisplay_5.SetMoneyValue((*temp_it).second.ID + 1);
			}


		}
		else {
				switch (temp) {
				case 20://添加
					if (GAMESYSTEM::HaveSelect_Function_ID != 0) {
						auto it = PlayerInformation::dishesMAp.find(HaveSelect_Function_ID);

						if (it == PlayerInformation::dishesMAp.end()) {
							
							//	int temp_size = PlayerInformation::Menu.size();
						}
						else {
							if (PlayerInformation::ALL_dishes[it->second.stars][it->second.ID] < 4) {
								Pop_up_message_box("数量不足4个，不能进行升星。", "提示");
								break;
							}
							else {//可以添加

								//ID_26_OneStar.Coordinate_in_draw.clear();
								//ID_25_TwoStars.Coordinate_in_draw.clear();
								//ID_24_ThreeStars.Coordinate_in_draw.clear();

								GAMESYSTEM::HaveSelect_in_RaisingFunction = HaveSelect_Function_ID;
								
								//Temp_staticmodel = PlayerInformation::Dishes_vector[it->second.ID];
								//DisplayModelinRaisingFunction(Temp_staticmodel);

								//PlayerInformation::Dishes_vector[it->second.ID];
								//Index temp_index={}
								//PlayerInformation::Menu.emplace(17 + temp_size, (*it).second);
								//	Pop_up_message_box("添加。", "提示");
							}
						}
					}
					break;

				case 21://返回键
					//UI::ClearthePicture();
					GAMESYSTEM::HaveSelect_in_RaisingFunction = 0;
					GAMESYSTEM::HaveSelect_Function_ID = 0;
					return;
					break;
				case 22://升星
					if (HaveSelect_in_RaisingFunction != 0) {
						if (PlayerInformation::dishesMAp.find(HaveSelect_in_RaisingFunction)->second.stars == 2)
						{
							Pop_up_message_box("已达三星，无法继续升星。", "提示");
						}
						else {
							//可以升星
							Temp_ID = PlayerInformation::dishesMAp.find(HaveSelect_in_RaisingFunction)->second.ID;
							Temp_Star = PlayerInformation::dishesMAp.find(HaveSelect_in_RaisingFunction)->second.stars;
							PlayerInformation::ALL_dishes[Temp_Star++][Temp_ID] -= 4;
							is_Succeed_raising = true;
							PlayerInformation::ALL_dishes[Temp_Star][Temp_ID] ++;
							Pop_up_message_box("升星成功。", "提示");
						}
					}

					break;
				default:
					break;

				}

			
		}
	}
}


void GAMESYSTEM::BuySmallDesk(int Fun_ID) {
	if (Pop_up_message_box_MB_YESNO("是否增加小桌，将消耗1000元?", "注意") == 6) {
		if (PlayerInformation::Money < 1000) {
			Pop_up_message_box("您当前余额不够，等钱够了再来吧!", "提示");
			return;
		}
		PlayerInformation::Money -= 1000;

	}
	else return;
	switch (Fun_ID) {
	case 4:
		PlayerInformation::Havesmalldesk[3] = true;
		CPU::is_samlldeak_available[3] = true;
		ID_15_SmallDesk.Insert_Coordinate_in_draw(1230, 126);
		//ID_3_MainViewOfRestaurant.Calculation_mouse_click_function_area(987, 151, 1108, 151, 1055, 135, 1040, 166, 0);
		break;
	case 5:
		PlayerInformation::Havesmalldesk[4] = true;
		CPU::is_samlldeak_available[4] = true;
		ID_15_SmallDesk.Insert_Coordinate_in_draw(1310, 148);
		//ID_3_MainViewOfRestaurant.Calculation_mouse_click_function_area(1066, 172, 1185, 171, 1126, 156, 1124, 188, 0);
		break;
	case 6:
		PlayerInformation::Havesmalldesk[5] = true;
		CPU::is_samlldeak_available[5] = true;
		ID_15_SmallDesk.Insert_Coordinate_in_draw(1390, 170);
		//ID_3_MainViewOfRestaurant.Calculation_mouse_click_function_area(1145, 195, 1264, 192, 1204, 176, 1207, 210, 0);
		break;
	case 7:
		PlayerInformation::Havesmalldesk[6] = true;
		CPU::is_samlldeak_available[6] = true;
		ID_15_SmallDesk.Insert_Coordinate_in_draw(1470, 192);
		//ID_3_MainViewOfRestaurant.Calculation_mouse_click_function_area(1222, 216, 1345, 216, 1281, 198, 1283, 231, 0);
		break;
	default:
		break;
	}


}
void GAMESYSTEM::BuyBigDesk(int Fun_ID) {
	if (Pop_up_message_box_MB_YESNO("是否增加大桌，将消耗2000元?", "注意") == 6) {
		if (PlayerInformation::Money < 2000) {
			Pop_up_message_box("您当前余额不够，等钱够了再来吧!", "提示");
			return;
		}
		PlayerInformation::Money -= 2000;

	}
	else return;
	switch (Fun_ID) {
	case 23:
		PlayerInformation::Havebigdesk[1] = true;
		CPU::is_bigdeak_available[1] = 2;
		ID_16_BigDesk.Insert_Coordinate_in_draw(929, 266);
		
		//ID_3_MainViewOfRestaurant.Calculation_mouse_click_function_area(987, 151, 1108, 151, 1055, 135, 1040, 166, 0);
		break;
	case 24:
		PlayerInformation::Havebigdesk[2] = true;
		CPU::is_bigdeak_available[2] = 2;
		ID_16_BigDesk.Insert_Coordinate_in_draw(1049, 299);
		//ID_3_MainViewOfRestaurant.Calculation_mouse_click_function_area(1066, 172, 1185, 171, 1126, 156, 1124, 188, 0);
		break;
	case 25:
		PlayerInformation::Havebigdesk[3] = true;
		CPU::is_bigdeak_available[3] = 2;
		ID_16_BigDesk.Insert_Coordinate_in_draw(1140, 205);
		//ID_3_MainViewOfRestaurant.Calculation_mouse_click_function_area(1145, 195, 1264, 192, 1204, 176, 1207, 210, 0);
		break;
	case 26:
		PlayerInformation::Havebigdesk[4] = true;
		CPU::is_bigdeak_available[4] = 2;
		ID_16_BigDesk.Insert_Coordinate_in_draw(1260, 238);
		//ID_3_MainViewOfRestaurant.Calculation_mouse_click_function_area(1222, 216, 1345, 216, 1281, 198, 1283, 231, 0);
		break;
	default:
		break;
	}


}
void GAMESYSTEM::Bag_display() {
	PlayerInformation::PrintBag();

	//背包
   //详情内容 -名字
	UI::Insert_ModelandFunctionArea_superposition(Chinese_Rice);
	UI::Insert_ModelandFunctionArea_superposition(Chinese_Dongpo_braised_pork);
	UI::Insert_ModelandFunctionArea_superposition(Chinese_Beijing_Roast_Duck);
	UI::Insert_ModelandFunctionArea_superposition(Chinese_Lafite);
	UI::Insert_ModelandFunctionArea_superposition(Chinese_Royal_Palace_Banquet);


	//详情内容- 价格 成本 利润 拥有数量
	UI::Insert_ModelandFunctionArea_superposition(Chinese_Price);
	UI::Insert_ModelandFunctionArea_superposition(Chinese_RowCost);
	UI::Insert_ModelandFunctionArea_superposition(Chinese_Profit);
	UI::Insert_ModelandFunctionArea_superposition(Chinese_Quantityowned);
	UI::Insert_ModelandFunctionArea_superposition(Chinese_Quality);
	//详情内容 - 数字
	UI::Insert_ModelandFunctionArea_superposition(Textdisplay_1);
	UI::Insert_ModelandFunctionArea_superposition(Textdisplay_2);
	UI::Insert_ModelandFunctionArea_superposition(Textdisplay_3);
	UI::Insert_ModelandFunctionArea_superposition(Textdisplay_4);
	UI::Insert_ModelandFunctionArea_superposition(Textdisplay_5);

}
void  GAMESYSTEM::Bag_clear() {
	Rice.Coordinate_in_draw.clear();
	Dongpo_braised_pork.Coordinate_in_draw.clear();
	Beijing_Roast_Duck.Coordinate_in_draw.clear();
	Lafite.Coordinate_in_draw.clear();
	Royal_Palace_Banquet.Coordinate_in_draw.clear();

	Chinese_Rice.Coordinate_in_draw.clear();
	Chinese_Dongpo_braised_pork.Coordinate_in_draw.clear();
	Chinese_Beijing_Roast_Duck.Coordinate_in_draw.clear();
	Chinese_Lafite.Coordinate_in_draw.clear();
	Chinese_Royal_Palace_Banquet.Coordinate_in_draw.clear();
	Chinese_Quantityowned.Coordinate_in_draw.clear();
	Chinese_Quality.Coordinate_in_draw.clear();

	Chinese_Price.Coordinate_in_draw.clear();
	Chinese_RowCost.Coordinate_in_draw.clear();
	Chinese_Profit.Coordinate_in_draw.clear();


	Textdisplay_1.Coordinate_in_draw.clear();
	Textdisplay_2.Coordinate_in_draw.clear();
	Textdisplay_3.Coordinate_in_draw.clear();
	Textdisplay_4.Coordinate_in_draw.clear();
	Textdisplay_5.Coordinate_in_draw.clear();

}
void GAMESYSTEM::LoadGameFile() {

	PlayerInformation::Money = 10000000;
	GAMESYSTEM::MainGame();
}