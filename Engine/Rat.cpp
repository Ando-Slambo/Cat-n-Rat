#include "Rat.h"
#include "Graphics.h"

void Rat::Update()
{
	BindToScreen();
	x += vx * isAlive;
	y += vy * isAlive;
}

void Rat::BindToScreen()
{
	int next_location = x + vx;
	if ((next_location < 0) || (next_location + width > Graphics::ScreenWidth)) {
		vx = -vx;
	}

	next_location = y + vy;
	if ((next_location < 0) || (next_location + height > Graphics::ScreenHeight)) {
		vy = -vy;
	}
}
