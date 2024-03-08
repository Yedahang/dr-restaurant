#include"UI.h"

char** UI::thePicturedata = new char* [UI_SIZE_MAX_y];
int UI::UI_SIZE_MAX_x=Weight;
int UI::UI_SIZE_MAX_y=Height;
void UI::ClearthePicture() {
	int ysize = UI_SIZE_MAX_y;
	int xsize = UI_SIZE_MAX_x;
	for (int y = 0; y < ysize; y++) {
		for (int x = 0; x < xsize - 1; x++)
			thePicturedata[y][x] = ' ';
		thePicturedata[y][xsize - 1] = '\0';
	}
}


void UI::initialUI() {
	//³õÊ¼»¯thePicturedata
	//this->thePreviousPicturedata = new char* [this->UI_SIZE_MAX_y];
	for (int i = 0; i < UI_SIZE_MAX_y; i++)
		thePicturedata[i] = new char[UI_SIZE_MAX_x];
	ClearthePicture();
	//PaintthePicture();
	//system("pause");
}
void UI::Insert_ModelandFunctionArea(int x, int y, AbstrastModel& model) {
	for (int j = 0; j < model.model_size_y; j++) {
		for (int i = 0; i < model.model_size_x; i++) {
			thePicturedata[y + j][x + i] = model.model_data[j][i];
			if (model.Function_area[j][i] != 0)
			MouseInputUnit::mouse_two_dimensional_coordinate[y + j][x + i] = model.Function_area[j][i];
		}
	}
}
void UI::Insert_ModelandFunctionArea(AbstrastModel& model) {
	for (auto& it : model.Coordinate_in_draw) {
		int x = it.x, y = it.y;
		for (int j = 0; j < model.model_size_y; j++) {
			for (int i = 0; i < model.model_size_x; i++) {
				thePicturedata[y + j][x + i] = model.model_data[j][i];
				if (model.Function_area[j][i] != 0)
					MouseInputUnit::mouse_two_dimensional_coordinate[y + j][x + i] = model.Function_area[j][i];
			}
		}
	}
}
//superposition
void UI::Insert_ModelandFunctionArea_superposition(AbstrastModel& model) {
	for (auto& it : model.Coordinate_in_draw) {
		int x = it.x, y = it.y;
		for (int j = 0; j < model.model_size_y; j++) {
			for (int i = 0; i < model.model_size_x; i++) {
				if(model.model_data[j][i]!=' ')
				thePicturedata[y + j][x + i] = model.model_data[j][i];
				if (model.Function_area[j][i] != 0)
					MouseInputUnit::mouse_two_dimensional_coordinate[y + j][x + i] = model.Function_area[j][i];
			}
		}
	}
}
void  UI::ClearFunctionArea() {
	for (int j = 0; j < UI_SIZE_MAX_y; j++) {
		for (int i = 0; i < UI_SIZE_MAX_x; i++) {
			MouseInputUnit::mouse_two_dimensional_coordinate[j][i] = 0;
		}
	}

}


void UI::Insert_Customer(AbstrastModel& model) {
	//for (auto& it : model.Coordinate_in_draw) {
	auto it = model.Coordinate_in_draw.begin();
	if (it != model.Coordinate_in_draw.end()) {

		int x = (*it).x - model.model_size_x / 2, y = (*it).y - model.model_size_y;
		for (int j = 0; j < model.model_size_y; j++) {
			for (int i = 0; i < model.model_size_x; i++) {
				if (model.model_data[j][i] != ' ')
					thePicturedata[y + j][x + i] = model.model_data[j][i];
				//if (model.Function_area[j][i] != 0)
					//MouseInputUnit::mouse_two_dimensional_coordinate[y + j][x + i] = model.Function_area[j][i];
			}
		}
	}
	//}
}
void UI::PaintthePicture() {
	//while(true)
	//ScreenUnit::Double_Buffershow(thePicturedata);
	for (int i = 0; i < UI_SIZE_MAX_y; i++)
		std::cout << thePicturedata[i] << std::endl;
};