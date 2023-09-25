#pragma once
#include "Headers.h"
#include "Fuctions.h"
#include "Objects.h"

bool CheckCollision(Objects* obj1, Objects* obj2) {
	int left1 = obj1->GetX_();
	int top1 = obj1->GetY_();
	int right1 = obj1->GetX_() + obj1->GetSize_() - 1;
	int bottom1 = obj1->GetY_() + obj1->GetSize_() - 1;

	int left2 = obj2->GetX_();
	int top2 = obj2->GetY_();
	int right2 = obj2->GetX_() + obj2->GetSize_() - 1;
	int bottom2 = obj2->GetY_() + obj2->GetSize_() - 1;

	// Comprueba si los rectángulos se superponen
	if (right1 >= left2 && left1 <= right2 && bottom1 >= top2 && top1 <= bottom2) {
		return true;  // Hay colisión
	}

	return false;  // No hay colisión
}

class ArrayObjects {
private:
	int n;
	Objects** arrayObjects;

public:
	ArrayObjects() {
		n = 0;
		arrayObjects = nullptr;
	}

	~ArrayObjects() {}

	void SetN_(int _n) { n = _n; }
	void SetArrayObjects_(Objects** _arrayObjects) { arrayObjects = _arrayObjects; }

	int GetN_() { return n; }
	Objects* GetArrayObjects_(int _index) { return arrayObjects[_index]; }

	void AddObject_(Objects* _newObject) {
		Objects** tempObjects1{ new Objects * [n + 1] };

		for (int i{ 0 }; i < n; i++)
			tempObjects1[i] = arrayObjects[i];
		tempObjects1[n] = _newObject; n++;

		if (arrayObjects != nullptr)
			delete arrayObjects;
		arrayObjects = tempObjects1;
	}

	void DeleteObject_(int _index) {
		for (int i{ 0 }; i < n; i++)
			arrayObjects[i]->ClearObject_();

		if (0 <= _index && _index < n) {
			delete arrayObjects[_index];
			for (int i{ _index }; i < n - 1; i++)
				arrayObjects[i] = arrayObjects[i + 1];
			n--;

			Objects** tempObjects2{ new Objects * [n] };
			for (int i{ 0 }; i < n; i++)
				tempObjects2[i] = arrayObjects[i];

			delete[] arrayObjects;
			arrayObjects = tempObjects2;
		}
	}

	void MoveArrayObjects_() {
		for (int i{ 0 }; i < n; i++) {
			if (arrayObjects[i]->ValidateMoveObject_())
				arrayObjects[i]->MoveObject_();
			else DeleteObject_(i);
		}
	}

};




