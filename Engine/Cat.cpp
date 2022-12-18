#include "Cat.h"
#include "Graphics.h"

void Cat::Update(const Keyboard& kbd)
{
	x += kbd.KeyIsPressed(0x27) * speed;
	x -= kbd.KeyIsPressed(0x25) * speed;

	y += kbd.KeyIsPressed(0x28) * speed;
	y -= kbd.KeyIsPressed(0x26) * speed;

	x *= x > 0;
	if (x + width > Graphics::ScreenWidth) {
		x = Graphics::ScreenWidth - width;
	}

	y *= y > 0;
	if (y + height > Graphics::ScreenHeight) {
		y = Graphics::ScreenHeight - height;
	}
}

int Cat::GetX()
{
	return x;
}

int Cat::GetY()
{
	return y;
}

void Cat::Draw(Graphics& gfx) const
{
	for (int i = x; i < x + width; i++) {
		for (int j = y; j < y + height; j++) {
			gfx.PutPixel(i, j, 255, 255, 255);
		}
	}
}
