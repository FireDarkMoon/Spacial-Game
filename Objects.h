#pragma once
#include "Headers.h"
#include "Fuctions.h"
#include "GameObject.h"
#include "Space.h"

class Objects :public GameObject, public virtual Space {
protected:
	int size;
	char* bodyObject;

public:
	Objects() {
		size = 0;
		bodyObject = new char[size];
	}

	~Objects() {
		delete[] bodyObject;
	}

	void SetSize_(int _size) { size = _size; }
	void SetBodyObject_(char* _bodyObject) { bodyObject = _bodyObject; }

	int GetSize_() { return size; }
	char* GetBodyObject_() { return bodyObject; }

	void ShowAllObject_(char* _bodyObject, bool _move, bool _status, int _x, int _y, int _dx, int _dy, int _size, int _color) {
		StartObject_(_bodyObject, _move, _status, _x, _y, _dx, _dy, _size, _color); if (_status == true) ShowObject_();
	}

	void StartObject_(char* _bodyObject, bool _move, bool _status, int _x, int _y, int _dx, int _dy, int _size, int _color) {
		SetBodyObject_(_bodyObject);
		SetMove_(_move); SetStatus_(_status);
		SetX_(_x); SetY_(_y);
		SetDx_(_dx); SetDy_(_dy);
		SetSize_(_size); SetColor_(_color);
	}

	void ShowObject_() {
		for (int i{ 0 }; i < size; i++) {
			ShowColor_(MoveX + x, MoveY + y + i, GetColor_());
			cout << bodyObject[i];
		}
	}

	void ClearObject_() {
		for (int i{ 0 }; i < size; i++)
			ShowChar_(MoveX + x, MoveY + y + i, ' ');
	}

	void MoveObject_() {
		ClearObject_();
		x += dx; y += dy;
		ShowObject_();
	}

	bool ValidateMoveObject_() {
		if (x + dx <= 0 || x + dx  >= Space::width ||
			y + dy <= 0 || y + dy + size>= Space::height)
			return false;
		return true;
	}

	/*
	bool CheckCollision(Objects* obj1, Objects* obj2) {
		int O1x1 = obj1->GetX_(), O1y1 = obj1->GetY_();
		int O1x2 = obj1->GetX_(), O1y2 = obj1->GetY_() + obj1->GetSize_() - 1;

		int O2x1 = obj2->GetX_(), O2y1 = obj2->GetY_();
		int O2x2 = obj2->GetX_() + obj2->GetSize_() - 1, O2y2 = obj2->GetY_() + obj2->GetSize_() - 1;


		if (O2y1 > O1y2 || O1y1 > O2y2) return false;
		if (O1y2 > O2y1 || O2y2 > O1y1) return false;

		return true;
	}
	*/



};