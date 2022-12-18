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

	rat0.Initialize(xDist(rng), yDist(rng), vDist(rng), vDist(rng));
	rat1.Initialize(xDist(rng), yDist(rng), vDist(rng), vDist(rng));
	rat2.Initialize(xDist(rng), yDist(rng), vDist(rng), vDist(rng));
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

	rat0.Update(cat);
	rat1.Update(cat);
	rat2.Update(cat);
}

void Game::ComposeFrame()
{
	cat.Draw(gfx);

	rat0.Draw(gfx);
	rat1.Draw(gfx);
	rat2.Draw(gfx);
}