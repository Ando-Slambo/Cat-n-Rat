#include "Rat.h"
#include "Graphics.h"

void Rat::Initialize(int init_x, int init_y, int init_vx, int init_vy)
{
	x = init_x;
	y = init_y;
	vx = init_vx;
	vy = init_vy;
}

void Rat::Update(Cat& cat)
{
	if (!isAlive) { return; }

	int next_location = x + vx;
	if ((next_location < 0) || (next_location + width > Graphics::ScreenWidth)) {
		vx = -vx;
	}

	next_location = y + vy;
	if ((next_location < 0) || (next_location + height > Graphics::ScreenHeight)) {
		vy = -vy;
	}

	x += vx;
	y += vy;

	const int cat_x = cat.GetX();
	const int cat_y = cat.GetY();

	isAlive *=
		!(x < cat_x + Cat::width &&
		  cat_x < x + width &&
		  y < cat_y + Cat::height &&
		  cat_y < y + height);
}

void Rat::Draw(Graphics& gfx) const
{
	if (!isAlive) { return; }

	for (int i = x; i < x + width; i++) {
		for (int j = y; j < y + height; j++) {
			gfx.PutPixel(i, j, 255, 0, 0);
		}
	}
}
