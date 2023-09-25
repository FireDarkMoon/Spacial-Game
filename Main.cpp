#include "Headers.h"
#include "Fuctions.h"
#include "Space.h"
#include "Ship.h"
#include "ArrayObjects.h"
#include "Objects.h"


int main() {
	Console::CursorVisible = false;

	Space Space;
	Ship* SpaceShip{ new Ship };
	Console::SetWindowSize(Space.GetWindowWidth_(), Space.GetWindowHeight_());

	Space.ShowSpace_();
	Space.ShowLimit_();
	SpaceShip->SetWidth_(5);
	SpaceShip->SetHeight_(3);
	char** BodySpaceShip = new char* [SpaceShip->GetHeight_()];
	for (int i{ 0 }; i < SpaceShip->GetHeight_(); i++)
		BodySpaceShip[i] = new char[SpaceShip->GetWidth_()];

	BodySpaceShip[0][0] = ' ';
	BodySpaceShip[0][1] = ' ';
	BodySpaceShip[0][2] = 182;
	BodySpaceShip[0][3] = ' ';
	BodySpaceShip[0][4] = ' ';

	BodySpaceShip[1][0] = ' ';
	BodySpaceShip[1][1] = '(';
	BodySpaceShip[1][2] = 'x';
	BodySpaceShip[1][3] = ')';
	BodySpaceShip[1][4] = ' ';

	BodySpaceShip[2][0] = 182;
	BodySpaceShip[2][1] = 'v';
	BodySpaceShip[2][2] = ' ';
	BodySpaceShip[2][3] = 'v';
	BodySpaceShip[2][4] = 182;


	ArrayObjects* arrayBullets{ new ArrayObjects }, * arrayAsteroids{ new ArrayObjects };
	Objects* bullet, * asteroid;




	SpaceShip->ShowAll_(BodySpaceShip, true, true, 7, 4, 0, 0,
		SpaceShip->GetWidth_(), SpaceShip->GetHeight_(), DarkGreen, 3);

	while (true) {
		char KeyB; SpaceShip->SetMove_(true);
		Sleep(20);
		asteroid = new Objects;
		asteroid->SetSize_(1);
		char* BodyAsteroid = new char[asteroid->GetSize_()];
		for (int i{ 0 }; i < asteroid->GetSize_(); i++)
			BodyAsteroid[i] = 157;

		arrayAsteroids->AddObject_(asteroid);
		asteroid->ShowAllObject_(BodyAsteroid, true, true,
			IntRandom_(3, Space.GetWidth_() - 4)  , 1, 0, 1,
			asteroid->GetSize_(), DarkRed);


		if (kbhit()) {
			KeyB = _getch();

			if (KeyB == 'a' || KeyB == 'A') {
				SpaceShip->SetMove_(true);
				SpaceShip->SetDx_(-1);
				SpaceShip->SetDy_(0);
			}
			if (KeyB == 'd' || KeyB == 'D') {
				SpaceShip->SetMove_(true);
				SpaceShip->SetDx_(1);
				SpaceShip->SetDy_(0);
			}
			if (KeyB == 'w' || KeyB == 'W') {
				SpaceShip->SetMove_(true);
				SpaceShip->SetDx_(0);
				SpaceShip->SetDy_(-1);
			}
			if (KeyB == 's' || KeyB == 'S') {
				SpaceShip->SetMove_(true);
				SpaceShip->SetDx_(0);
				SpaceShip->SetDy_(1);
			}
			if (KeyB == 'l' || KeyB == 'L') {
				if (SpaceShip->GetY_() != 1) {
					bullet = new Objects;
					bullet->SetSize_(1);
					char* BodyBullet = new char[bullet->GetSize_()];
					BodyBullet[0] = 213;
					arrayBullets->AddObject_(bullet);
					bullet->ShowAllObject_(BodyBullet, true, true,
						SpaceShip->GetX_() + 2,
						SpaceShip->GetY_() - 1,
						0, -1, bullet->GetSize_(), Green);
				}
			}
		}

		if (asteroid->GetStatus_() == true) {
			if (arrayAsteroids->GetN_() > 0)
				arrayAsteroids->MoveArrayObjects_();


		}


		if (arrayBullets->GetN_() > 0)
			arrayBullets->MoveArrayObjects_();

		if (SpaceShip->GetMove_())
			if (SpaceShip->ValidateMove_())
				SpaceShip->Move_();

	}

	char c = _getch();
	return 0;
}