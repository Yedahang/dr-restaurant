#pragma once
#include<iostream>
#include"ScreenUnit.h"
#include"Model.h"
#include"InputUnit.h"
#define Weight 1917;
#define Height 497;


static class UI {
public:
	static void ClearthePicture();
	static void initialUI();
	static void PaintthePicture();
	static void Insert_ModelandFunctionArea(int x, int y, AbstrastModel& model);
	static void Insert_ModelandFunctionArea(AbstrastModel& model);
	static void  Insert_ModelandFunctionArea_superposition(AbstrastModel& model);
	static void ClearFunctionArea();
	static void Insert_Customer(AbstrastModel& model);

	static char** thePicturedata;//当前数据
	static int UI_SIZE_MAX_x;
	static int UI_SIZE_MAX_y;
};