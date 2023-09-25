#include "Fuctions.h"

void Settings_() {
	srand(time(NULL));
	Console::Title = "Space AXIS";
	Console::CursorVisible = false;
	Console::SetWindowSize(120, 30);
}

int IntRandom_(int min, int max) {
	return min + rand() % (max - min + 1);
}

char CharRandom_(char min, char max) {
	return min + rand() % (max - min + 1);
}

void FontColor_(int color) {
	Console::ForegroundColor = (ConsoleColor)color;
}

void CharColor_(char c, int color) {
	FontColor_(color); cout << c;
}

void StringColor_(string s, int color) {
	FontColor_(color); cout << s;
}

void Show_(int x, int y) {
	Console::SetCursorPosition(x, y);
}

void ShowColor_(int x, int y, int color) {
	Show_(x, y); FontColor_(color);
}

void ShowChar_(int x, int y, char c) {
	Show_(x, y); cout << c;
}

void ShowString_(int x, int y, string s) {
	Show_(x, y); cout << s;
}

void ShowCharColor_(int x, int y, char c, int color) {
	ShowColor_(x, y, color); cout << c;
}

void ShowStringColor_(int x, int y, string s, int color) {
	ShowColor_(x, y, color); cout << s;
}

void ClearScreen_() {
	Console::Clear();
}