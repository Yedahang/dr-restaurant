// MyGame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"ScreenUnit.h"
#include"Database.h"
#include"InputUnit.h"
#include"Astar.h"
using namespace std;
int main()
{
      srand((int)time(0));//随机数种子
      GAMESYSTEM::InitialGamesystem();
      ID_1_StartButton.OutputModel();
      MouseInputUnit::Get_mouse_click_coordinates();



      // GAMESYSTEM::Beginmenu();
    //   GAMESYSTEM::MainGame();

}


