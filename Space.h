#pragma once
#include "Headers.h"
#include "Fuctions.h"

class Space {
protected:
	int width, height, windowWidth, windowHeight;

public:
	Space() {
		windowWidth = 200; windowHeight = 54;
		width = 150; height = 50;
	}

	void SetWindowWidth_(int _windowWidth) { windowWidth = _windowWidth; }
	void SetWindowHeight_(int _windowHeight) { windowHeight = _windowHeight; }
	void SetWidth_(int _width) { width = _width; }
	void SetHeight_(int _height) { height = _height; }

	int GetWindowWidth_() { return windowWidth; }
	int GetWindowHeight_() { return windowHeight; }
	int GetWidth_() { return width; }
	int GetHeight_() { return height; }



	void ShowSpace_() {
		for (int i{ 0 }; i < height; i++)
			for (int j{ 0 }; j < width; j++) {
				ShowColor_(MoveX + j, MoveY + i, DarkBlue);
				if ((i == 0 || i == height - 1) && (0 < j && j < width - 1)) cout << CharLDH;
				if ((j == 0 || j == width - 1) && (0 < i && i < height - 1)) cout << CharLDV;
				if (i == 0 && j == 0) cout << CharEDSI;
				if (i == 0 && j == width - 1) cout << CharEDSD;
				if (i == height - 1 && j == 0) cout << CharEDII;
				if (i == height - 1 && j == width - 1) cout << CharEDID;
			}
	}

	void ShowLimit_() {
		for (int i{ 0 }; i < MoveY + height + 2; i++)
			for (int j{ 0 }; j < 2; j++) {
				ShowColor_(MoveX + j + width + 4, i, White);
				if (i == 0 && j == 0) cout << CharEDSI;
				else if (i == 0 && j == 1) cout << CharEDSD;
				else if (i == MoveY + height + 1 && j == 0) cout << CharEDII;
				else if (i == MoveY + height + 1 && j == 1) cout << CharEDID;
				else cout << CharLDV;
			}
	}
};