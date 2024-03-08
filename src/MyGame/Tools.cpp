#include"Tools.h"
#include<iostream>
#include<algorithm>
void Pop_up_message_box(const char* content, const char* title) {
	//�Ȼ�ȡת���ɿ��ַ���ĳ��ȣ�һ��Ҫͨ�����ַ�ʽ���Ȼ�ȥ�ַ����ȣ���Ϊ��ָ������ΪCP_ACP�����벻ͬ������Ҳ�᲻ͬ��
	int nLen1 = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, content, -1, NULL, 0);
	//����һ�����ַ����ͱ��������ڴ��ת������ַ�
	wchar_t* wcontent = new wchar_t[nLen1];
	//����΢��ANSIת���ַ��ĺ�����name:ANSI�ַ���wname:���ַ���
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, content, -1, wcontent, nLen1);

	int nLen2 = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, title, -1, NULL, 0);
	wchar_t* wtitle = new wchar_t[nLen2];
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, title, -1, wtitle, nLen2);

	MessageBox(NULL, wcontent, wtitle, MB_OK);
}
int Pop_up_message_box_MB_YESNO(const char* content, const char* title) {
	//�Ȼ�ȡת���ɿ��ַ���ĳ��ȣ�һ��Ҫͨ�����ַ�ʽ���Ȼ�ȥ�ַ����ȣ���Ϊ��ָ������ΪCP_ACP�����벻ͬ������Ҳ�᲻ͬ��
	int nLen1 = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, content, -1, NULL, 0);
	//����һ�����ַ����ͱ��������ڴ��ת������ַ�
	wchar_t* wcontent = new wchar_t[nLen1];
	//����΢��ANSIת���ַ��ĺ�����name:ANSI�ַ���wname:���ַ���
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, content, -1, wcontent, nLen1);

	int nLen2 = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, title, -1, NULL, 0);
	wchar_t* wtitle = new wchar_t[nLen2];
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, title, -1, wtitle, nLen2);

	return MessageBox(NULL, wcontent, wtitle, MB_YESNO);
}
wchar_t* trasform_char_to_wchart(const char* ch) {
	//�Ȼ�ȡת���ɿ��ַ���ĳ��ȣ�һ��Ҫͨ�����ַ�ʽ���Ȼ�ȥ�ַ����ȣ���Ϊ��ָ������ΪCP_ACP�����벻ͬ������Ҳ�᲻ͬ��
	int nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, ch, -1, NULL, 0);
	int wchar_size = nLen;
	//����һ�����ַ����ͱ��������ڴ��ת������ַ�
	wchar_t* wcontent = new wchar_t[wchar_size];
	//����΢��ANSIת���ַ��ĺ�����name:ANSI�ַ���wname:���ַ���
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, ch, -1, wcontent, wchar_size);
	return wcontent;
}


int line(double k, double b, int x) {
	return k * x + b;
}
//�Ƿ�������
int** Calculation_mouse_click_function_area(int left_x, int left_y,
										int right_x, int right_y,
										int top_x, int top_y,
										int bottom_x, int bottom_y,
                                         int Function_ID) {
	int height =  bottom_y -top_y;
	int width = right_x - left_x;

	int **Function_area = new int*[height];
	for (int i = 0; i < height; i++) {
		Function_area[i] = new int[width] {0};
	}
	
	double k1 = (right_y - top_y) /(double) (right_x - top_x);
	double k2 = (top_y - left_y) / (double)(top_x - left_x);
	double b1 = 0 - k1 * (top_x - left_x);
	double b2 = 0 - k2 * (top_x - left_x);
	double b3 = (right_y- top_y) - k2 * (right_x - left_x);
	double b4 = (left_y - top_y) - 0;

	// line(k1,b1,x)  L1
	//line(k2,b2,x)  L2
	//line(k2,b3,x)  L3
	//line(k1,b4,x)  L4
	int det_x = right_x - left_x;
	for (int i = 0; i < det_x; i++) {
		int ymin = max(line(k2, b2, i), line(k1, b1, i));
		int ymax = min(line(k2, b3, i), line(k1, b4, i));
		for (int j = 0; j < height; j++) {
			if (j > ymin && j < ymax)
				Function_area[j][i] = Function_ID;
		}

	}
	return Function_area;
}
//���溯���Ĳ��Դ���
//extern int** Calculation_mouse_click_function_area(int left_x, int left_y,
//	int right_x, int right_y,
//	int top_x, int top_y,
//	int bottom_x, int bottom_y,
//	int Function_ID);
//int ** ar = Calculation_mouse_click_function_area(0, 25,
//	50,  25,
//	 25,  0,
//	 25,  50,
//	2);
//for (int i = 0; i < 50; i++) {
//	for (int j = 0; j < 50; j++)
//		cout << ar[i][j];
//	cout << endl;
//}