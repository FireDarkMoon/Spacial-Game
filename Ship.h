#pragma once
#include "Fuctions.h"
#include "Headers.h"
#include "GameObject.h"
#include "Space.h"
#include "ArrayObjects.h"


class Ship :public GameObject, public virtual Space {
private:
	int width, height, lives;
	char** body;

public:
	Ship() {
		width = 0; height = 0; lives = 0;
		body = new char* [height];
		for (int i = 0; i < height; i++)
			body[i] = new char[width];
	}

	~Ship() {
		for (int i{ 0 }; i < height; i++)
			delete[] body[i];
		delete[] body;
	}

	void SetBody_(char** _body) { body = _body; }
	void SetWidth_(int _width) { width = _width; }
	void SetHeight_(int _height) { height = _height; }
	void SetLives_(int _lives) { lives = _lives; }

	char** GetBody_() { return body; }
	int GetWidth_() { return width; }
	int GetHeight_() { return  height; }
	int GetLives_() { return  lives; }

	void ShowAll_(char** _body, bool _move, bool _status, int _x, int _y, int _dx, int _dy, int _width, int _height, int _color, int _lives) {
		Start_(_body, _move, _status, _x, _y, _dx, _dy, _width, _height, _color, lives);
		if (_status == true) Show_();
	}

	void Start_(char** _body, bool _move, bool _status, int _x, int _y, int _dx, int _dy, int _width, int _height, int _color, int _lives) {
		SetBody_(_body);
		SetMove_(_move); SetStatus_(_status);
		SetX_(_x); SetY_(_y);
		SetDx_(_dx); SetDy_(_dy);
		SetWidth_(_width); SetHeight_(_height);
		SetColor_(_color); SetLives_(_lives);
	}

	void Show_() {
		for (int i{ 0 }; i < height; i++)
			for (int j{ 0 }; j < width; j++) {
				ShowColor_(MoveX + x + j, MoveY + y + i, color);
				cout << body[i][j];
			}
	}

	void Clear_() {
		for (int i{ 0 }; i < height; i++)
			for (int j{ 0 }; j < width; j++)
				ShowString_(MoveX + x + j, MoveY + y + i, " ");
	}

	void Move_() {
		Clear_();
		x += dx; y += dy;
		Show_();
	}

	bool ValidateMove_() {
		if (x + dx <= 0 || x + dx + width >= Space::width ||
			y + dy <= 0 || y + dy + height >= Space::height)
			return false;
		return true;
	}
};
