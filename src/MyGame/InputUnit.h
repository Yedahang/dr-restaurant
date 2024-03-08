#pragma once
#ifndef  _MOUSEINPUTUNIT_
#define _MOUSEINPUTUNIT_

#include<Windows.h>
#include<iostream>
#include"Model.h"
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)  //������ⰴ���ĵ���¼�



static class MouseInputUnit {
public:
	static POINT p;
	static HANDLE hOutput;
	static HWND h;
	static CONSOLE_FONT_INFO consoleCurrentFont;
	static HANDLE hStdin;
	static DWORD mode;
	static void initialMouseInputUnit();
	static void initial_mouse_two_dimensional_coordinate();
	static void get_real_mouse();//���У��
	static void Get_mouse_click_coordinates();
	static void gt(int x, int y);//���ù��λ�ã����ض�λ�����
	static int mouse();
	static void mouse_for_test();
	static void Set_mode();
	//static int Get_mouse_position();
	static double real_x, real_y;
	static int** mouse_two_dimensional_coordinate;
};
#endif // ! _MOUSEINPUTUNIT_