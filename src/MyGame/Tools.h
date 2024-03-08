#pragma once
#include<Windows.h>
extern void Pop_up_message_box(const char* content, const char* title);//弹窗输出特定信息
extern wchar_t* trasform_char_to_wchart(const char* ch);

extern int** Calculation_mouse_click_function_area(int left_x, int left_y,
	int right_x, int right_y,
	int top_x, int top_y,
	int bottom_x, int bottom_y,
	int Function_ID);
