#pragma once

class Rat
{
public:
	void Update();
	void BindToScreen();

	int x;
	int y;
	int vx;
	int vy;
	bool isAlive = true;
	static constexpr int width = 25;
	static constexpr int height = 25;

private:
};