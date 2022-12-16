#pragma once
#include "Keyboard.h"

class Cat
{
public:
	int x = 100;
	int y = 100;
	static constexpr int width = 25;
	static constexpr int height = 25;
	static constexpr int speed = 4;

	void Update(Keyboard& kbd);
	bool Collision(int in_x, int in_y, int in_width, int in_height);

private:
};