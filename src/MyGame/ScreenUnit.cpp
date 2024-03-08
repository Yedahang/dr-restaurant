#include"ScreenUnit.h"
HANDLE ScreenUnit::hOutput;
HANDLE ScreenUnit::hOutputBuf;
bool ScreenUnit::hop_flag = true;
COORD ScreenUnit::coord = { 0,0 };//初始输出位置 
DWORD ScreenUnit::bytes = 0;



//双缓存技术 初始化缓存区
void ScreenUnit::CreateCreenBuffers() {
	//创建控制台缓冲区1
	hOutputBuf = CreateConsoleScreenBuffer(
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	//创建控制台缓冲区2
	hOutput = CreateConsoleScreenBuffer(
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	//设置缓冲区的光标不可见
	//创建光标
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo(hOutput, &cci);
	SetConsoleCursorInfo(hOutputBuf, &cci);
}
//void ScreenUnit::Double_Buffershow() {
//	while (1) {
//		Sleep(600);
//		ScreenUnit::hop_flag = !ScreenUnit::hop_flag;
//		if (!hop_flag) {
//			char score_char1[] = "这是一个缓存区显示内容！11111111";
//			coord.Y = 1;
//			WriteConsoleOutputCharacterA(hOutputBuf, score_char1, strlen(score_char1), coord, &bytes);
//			SetConsoleActiveScreenBuffer(hOutputBuf);
//		}
//		else {
//			char score_char2[] = "这是另一个缓存区显示内容！22222222";
//			coord.Y = 1;
//			WriteConsoleOutputCharacterA(hOutput, score_char2, strlen(score_char2), coord, &bytes);
//			SetConsoleActiveScreenBuffer(hOutput);
//		}
//	}
//}
int Max_x = 1917;
int Max_y = 497;
void ScreenUnit::Double_Buffershow(char** thePicture) {
		ScreenUnit::hop_flag = !ScreenUnit::hop_flag;
		if (!hop_flag) {
			for (int y = 0; y < Max_y; y++) {
				coord.Y = y;
				WriteConsoleOutputCharacterA(hOutputBuf, thePicture[y], Max_x, coord, &bytes);
			}
			SetConsoleActiveScreenBuffer(hOutputBuf);
		}
		else {
			for (int y = 0; y < Max_y; y++) {
				coord.Y = y;
				WriteConsoleOutputCharacterA(hOutput, thePicture[y], Max_x, coord, &bytes);
			}
			SetConsoleActiveScreenBuffer(hOutput);
		}
		//Sleep(60);
		
}
//取消滑框
void ScreenUnit::FullScreen() {
	HANDLE Hand;
	CONSOLE_SCREEN_BUFFER_INFO Info;
	Hand = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(Hand, &Info);
	SMALL_RECT rect = Info.srWindow;
	COORD size = { rect.Right + 1 ,rect.Bottom + 1 };	//定义缓冲区大小，保持缓冲区大小和屏幕大小一致即可取消边框 
	SetConsoleScreenBufferSize(Hand, size);
}
void ScreenUnit::InitialScreenUnit() {
	SetFont(1);
	MaximizeWindow();
	FullScreen();
	CreateCreenBuffers();
	
}
void ScreenUnit::MaximizeWindow() {
	HWND hwnd = GetForegroundWindow();
	ShowWindow(hwnd, SW_MAXIMIZE);
}
//设置控制台输出字体大小
void ScreenUnit::SetFont(int size) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = size;  //设置字体大小
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL; //字体粗细 FW_BOLD
	wcscpy_s(cfi.FaceName, L"黑体");  //设置字体，L"Consolas"L"黑体"
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	//获得当前字体
	//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//CONSOLE_FONT_INFO consoleCurrentFont;
	//GetCurrentConsoleFont(handle, FALSE, &consoleCurrentFont);
}