#pragma once
#include "Headers.h"
#include "Fuctions.h"

class GameObject {
protected:
	bool move, status;
	int x, y, dx, dy, color;

public:
	GameObject() {
		move = false; status = false;
		x = 0; y = 0;
		dx = 0; dy = 0;
		color = White;
	}

	void SetMove_(bool _move) { move = _move; }
	void SetStatus_(bool _status) { status = _status; }
	void SetX_(int _x) { x = _x; }
	void SetY_(int _y) { y = _y; }
	void SetDx_(int _dx) { dx = _dx; }
	void SetDy_(int _dy) { dy = _dy; }
	void SetColor_(int _color) { color = _color; }

	bool GetMove_() { return move; }
	bool GetStatus_() { return status; }
	int GetX_() { return x; }
	int GetY_() { return y; }
	int GetDx_() { return dx; }
	int GetDy_() { return dy; }
	int GetColor_() { return color; }
};