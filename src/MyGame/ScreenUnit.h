#pragma once
#include<Windows.h>


static class ScreenUnit {
public:
	static HANDLE hOutput, hOutputBuf;	//���ھ��  ���������� �����л���������
	static bool hop_flag;
	static COORD coord; //��ʼ���λ��
	static DWORD bytes;
	static void CreateCreenBuffers();//����˫��������ͬʱ���ù�겻�ɼ�
	static void Double_Buffershow(char** thePicture);
	static void FullScreen();//ȡ������
	static void InitialScreenUnit();//��ʼ��
	static void MaximizeWindow();//ʹ�������
	static void SetFont(int size = 1);//���ÿ���̨��������С
};