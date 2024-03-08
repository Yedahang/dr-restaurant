#include"InputUnit.h"
extern StaticModel ID_2;
HANDLE MouseInputUnit::hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
HWND MouseInputUnit::h = GetForegroundWindow();
HANDLE MouseInputUnit::hStdin = GetStdHandle(STD_INPUT_HANDLE);
DWORD MouseInputUnit::mode;
CONSOLE_FONT_INFO MouseInputUnit::consoleCurrentFont;
//int** MouseInputUnit::mouse_two_dimensional_coordinate;
double MouseInputUnit::real_x;
double MouseInputUnit::real_y;
int** MouseInputUnit::mouse_two_dimensional_coordinate;

 void MouseInputUnit::initialMouseInputUnit() {
	
	 Set_mode();//要先setmode再get_real_mouse
	get_real_mouse();
	 initial_mouse_two_dimensional_coordinate();
}
void MouseInputUnit::initial_mouse_two_dimensional_coordinate() {
	
	mouse_two_dimensional_coordinate = new int* [497];
	for (int i = 0; i < 497; i++) {
		mouse_two_dimensional_coordinate[i] = new int [1917] {0};
	}

 }
 //鼠标校正
 void MouseInputUnit::get_real_mouse() {
	 system("cls");
	 int x = rand() % 10 + 35, y = rand() % 10 + 75;//35 75
	 POINT pt = { 0,0 };
	 gt(x, y - 7);
	 printf("-------+-------");
	 for (int i = 1; i < 5; i++) {
		 gt(x - i, y);
		 printf("|");
		 gt(x + i, y);
		 printf("|");
	 }

	 for (int i = 0; i < ID_2.model_size_y; i++) {
		 gt(x + 10 + i, y + 10);
		 std::cout << ID_2.model_data[i];
	 }
	 while (1)
	 {
		 GetCursorPos(&pt);    //获取鼠标当前位置
		 ScreenToClient(h, &pt);
		 extern wchar_t* trasform_char_to_wchart(const char* ch);
		 if (KEY_DOWN(VK_LBUTTON) && MessageBox(0, trasform_char_to_wchart("您确定您点击了\"+\"吗?\n如果您没有点击此点可能会导致程序错乱."), 
			 trasform_char_to_wchart("鼠标校正"), 4) == IDYES)
		 {
			 double temp_y = y, temp_x = x;
			 real_x = pt.x / temp_y; real_y = pt.y / temp_x;
			/* char ch[100];
			 sprintf(ch, "pt.x=%d,pt.y=%d,y=%d,x=%d,(real_x=%d,real_y=%d)", pt.x, pt.y, y, x, real_x, real_y);
			 extern void Pop_up_message_box(const char* content, const char* title);
			 Pop_up_message_box(c, ch);*/
			 break;
		 }
	 }
	 Sleep(500);
	system("cls");
 }
 void MouseInputUnit::Get_mouse_click_coordinates() {

	 //----------循环检测----------
	 while (1) {    //循环检测
		 /*char tem[20];
	 sprintf(tem, "Have come int to while\n");
	 extern void Pop_up_message_box(const char* content, const char* title);
	 Pop_up_message_box(tem, tem); */
	 //system("cls");

		 if (KEY_DOWN(VK_LBUTTON)) {  			//鼠标左键按下
			 POINT p;
			 GetCursorPos(&p);
			 ScreenToClient(h, &p);               //获取鼠标在窗口上的位置
			 GetCurrentConsoleFont(hOutput, FALSE, &consoleCurrentFont); //获取字体信息
			 int x = (p.x / real_x);// consoleCurrentFont.dwFontSize.X;// /= consoleCurrentFont.dwFontSize.X;
			 int y = (p.y / real_y);// consoleCurrentFont.dwFontSize.Y;// /= consoleCurrentFont.dwFontSize.Y;
			 /*char tem[10];
			 sprintf(tem, "key down (%d,%d)\n", x, y);*/
			 //writeintofile(tem);
			 //printf("key down (%d,%d)\n", x, y);
			 // 
			 //弹窗显示鼠标点击坐标
			 //if (y>0 && x > 0) {
			 char tem[20];
			 sprintf(tem, "key down (x=%d,y=%d),(p.x=%d,p.y=%d),(real_x=%d,p.real_y=%d)\n", x, y, p.x, p.y, real_x, real_y);
			 extern void Pop_up_message_box(const char* content, const char* title);
			 Pop_up_message_box(tem, tem);
			 //}

		 }
		 Sleep(100);                 			//等待100毫秒，减少CPU占用
	 }
	 return;
 }
 void  MouseInputUnit::gt(int x, int y) {
	 COORD coord;
	 coord.X = y;
	 coord.Y = x;
	 HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);
	 SetConsoleCursorPosition(a, coord);
 }
int MouseInputUnit::mouse() {
	 //----------循环检测----------
	 //while (1) {       
	 HWND hw = GetForegroundWindow();
	 if (KEY_DOWN(VK_LBUTTON)) {  			//鼠标左键按下
		 POINT p;
		 GetCursorPos(&p);
		 ScreenToClient(hw, &p);               //获取鼠标在窗口上的位置
		 GetCurrentConsoleFont(hOutput, FALSE, &consoleCurrentFont); //获取字体信息
		 int x = (p.x / real_x) / consoleCurrentFont.dwFontSize.X;// /= consoleCurrentFont.dwFontSize.X;
		 int y = (p.y / real_y) / consoleCurrentFont.dwFontSize.Y;// /= consoleCurrentFont.dwFontSize.Y;
		 if (x > 0 && y > 0 && x < 1917 && y < 497) {
			 //char tem[20];
			 //sprintf(tem, "%d\n", mouse_two_dimensional_coordinate[y][x]);
			 //extern void Pop_up_message_box(const char* content, const char* title);
			 //Pop_up_message_box(tem, tem);
			 return mouse_two_dimensional_coordinate[y][x];
		 }
	 }
	 //Sleep(100);                 			//等待100毫秒，减少CPU占用
// }
	 return 0;
 }
void MouseInputUnit::mouse_for_test() {
	//----------循环检测----------
 while (1) {       
	HWND hw = GetForegroundWindow();
	if (KEY_DOWN(VK_LBUTTON)) {  			//鼠标左键按下
		POINT p;
		GetCursorPos(&p);
		ScreenToClient(hw, &p);               //获取鼠标在窗口上的位置
		GetCurrentConsoleFont(hOutput, FALSE, &consoleCurrentFont); //获取字体信息
		int x = (p.x / real_x) / consoleCurrentFont.dwFontSize.X;// /= consoleCurrentFont.dwFontSize.X;
		int y = (p.y / real_y) / consoleCurrentFont.dwFontSize.Y;// /= consoleCurrentFont.dwFontSize.Y;
		if (x > 0 && y > 0 && x < 1917 && y < 497) {
			char tem[20];
			sprintf(tem, "%d\n", mouse_two_dimensional_coordinate[y][x]);
			extern void Pop_up_message_box(const char* content, const char* title);
			Pop_up_message_box(tem, tem);
			
		}
	}
	Sleep(100);                 			//等待100毫秒，减少CPU占用
  }
	return ;



}
//int MouseInputUnit::Get_mouse_position() {
//	HWND hw = GetForegroundWindow();
//	if (KEY_DOWN(VK_LBUTTON)) {  			//鼠标左键按下
//		POINT p;
//		GetCursorPos(&p);
//		ScreenToClient(hw, &p);               //获取鼠标在窗口上的位置
//		GetCurrentConsoleFont(hOutput, FALSE, &consoleCurrentFont); //获取字体信息
//		int x = (p.x / real_x) / consoleCurrentFont.dwFontSize.X;// /= consoleCurrentFont.dwFontSize.X;
//		int y = (p.y / real_y) / consoleCurrentFont.dwFontSize.Y;// /= consoleCurrentFont.dwFontSize.Y;
//		if (x > 0 && y > 0 && x < 1917 && y < 497) {
//			char tem[20];
//			sprintf(tem, "%d\n", mouse_two_dimensional_coordinate[y][x]);
//			extern void Pop_up_message_box(const char* content, const char* title);
//			Pop_up_message_box(tem, tem);
//			return mouse_two_dimensional_coordinate[y][x];
//		}
//	}
//	//Sleep(100);                 			//等待100毫秒，减少CPU占用
//// }
//	return 0;
//
//
//
//
//}
 void MouseInputUnit::Set_mode() {
	 //----------移除快速编辑模式(对于win10用户)----------
	 GetConsoleMode(hStdin, &mode);
	 //mode &= ~ENABLE_QUICK_EDIT_MODE;
	 mode &= ~ENABLE_QUICK_EDIT_MODE;  //移除快速编辑模式
	 mode &= ~ENABLE_INSERT_MODE;      //移除插入模式
	 mode &= ~ENABLE_MOUSE_INPUT;
	 SetConsoleMode(hStdin, mode);
 }