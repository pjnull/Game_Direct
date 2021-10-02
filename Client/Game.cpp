#include "pch.h"
#include "Game.h"
#include "Engine.h"

void Game::Init(const WindowInfo& windowinfo)
{
	GEngine->Init(windowinfo);
}

void Game::Update()
{
	GEngine->Render();
}
