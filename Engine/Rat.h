#pragma once
#include "Cat.h"
#include "Graphics.h"

class Rat
{
public:
	void Initialize(int init_x, int init_y, int init_vx, int init_vy);
	void Update(Cat& cat);
	void Draw(Graphics& gfx) const;

	static constexpr int width = 25;
	static constexpr int height = 25;

private:
	int x;
	int y;
	int vx;
	int vy;
	bool isAlive = true;
};