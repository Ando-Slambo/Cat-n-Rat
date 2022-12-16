#include "Cat.h"
#include "Graphics.h"

void Cat::Update(Keyboard& kbd)
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

bool Cat::Collision(int in_x, int in_y, int in_width, int in_height)
{
	return
		x < in_x + in_width &&
		in_x < x + width &&
		y < in_y + in_height &&
		in_y < y + height;
}
