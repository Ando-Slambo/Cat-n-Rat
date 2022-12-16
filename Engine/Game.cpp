/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> xDist(50, 1900);
	std::uniform_int_distribution<int> yDist(50, 1000);
	std::uniform_int_distribution<int> vDist(-3, 3);
	rat0.x = xDist(rng);
	rat1.x = xDist(rng);
	rat2.x = xDist(rng);

	rat0.y = yDist(rng);
	rat1.y = yDist(rng);
	rat2.y = yDist(rng);

	rat0.vx = vDist(rng);
	rat1.vx = vDist(rng);
	rat2.vx = vDist(rng);

	rat0.vy = vDist(rng);
	rat1.vy = vDist(rng);
	rat2.vy = vDist(rng);
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	cat.Update(wnd.kbd);

	rat0.isAlive *= !cat.Collision(rat0.x, rat0.y, Rat::width, Rat::height);
	rat1.isAlive *= !cat.Collision(rat1.x, rat1.y, Rat::width, Rat::height);
	rat2.isAlive *= !cat.Collision(rat2.x, rat2.y, Rat::width, Rat::height);

	rat0.Update();
	rat1.Update();
	rat2.Update();
}

void Game::ComposeFrame()
{
	DrawBox(cat.x, cat.y, Cat::width, Cat::height, 255, 255, 255);

	if (rat0.isAlive) {
		DrawBox(rat0.x, rat0.y, Rat::width, Rat::height, 255, 0, 0);
	}
	if (rat1.isAlive) {
		DrawBox(rat1.x, rat1.y, Rat::width, Rat::height, 255, 0, 0);
	}
	if (rat2.isAlive) {
		DrawBox(rat2.x, rat2.y, Rat::width, Rat::height, 255, 0, 0);
	}
}

void Game::DrawBox(int x, int y, int width, int height, int r, int g, int b)
{
	for (int i = x; i < x + width; i++) {
		for (int j = y; j < y + height; j++) {
			gfx.PutPixel(i, j, r, g, b);
		}
	}
}