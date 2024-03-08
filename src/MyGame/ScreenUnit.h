#pragma once
#include<Windows.h>


static class ScreenUnit {
public:
	static HANDLE hOutput, hOutputBuf;	//窗口句柄  两个缓冲区 用于切换缓存区域
	static bool hop_flag;
	static COORD coord; //初始输出位置
	static DWORD bytes;
	static void CreateCreenBuffers();//创建双缓存区域同时设置光标不可见
	static void Double_Buffershow(char** thePicture);
	static void FullScreen();//取消滑框
	static void InitialScreenUnit();//初始化
	static void MaximizeWindow();//使窗口最大化
	static void SetFont(int size = 1);//设置控制台输出字体大小
};