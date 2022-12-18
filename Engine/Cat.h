#pragma once
#include "Keyboard.h"
#include "Graphics.h"

class Cat
{
public:
	void Update(const Keyboard& kbd);
	int GetX();
	int GetY();
	void Draw(Graphics& gfx) const;

	//leaving these public bcuz they're static constexpr
	static constexpr int width = 25;
	static constexpr int height = 25;
	static constexpr int speed = 4;

private:
	int x = 10;
	int y = 10;
};