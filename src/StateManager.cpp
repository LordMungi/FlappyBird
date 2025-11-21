#include "StateManager.h"
#include "GameState.h"

#include "Game.h"
#include "Menu.h"
#include "Credits.h"

#include "Templates.h"

namespace statemanager
{
	static void init();
	static void update(); 
	static void draw();
	static void changeState();

	GameState previousState = GameState::MAIN_MENU;
	GameState currentState = GameState::MAIN_MENU;
	
	bool isRunning = true;

	drw::TextData versionTextData;

	void MainLoop()
	{
		init();
		while (isRunning) 
		{
			isRunning = !rend::ShouldExit();

			update();
			draw();
			changeState();
		}
		rend::Close();
	}

	static void init()
	{
		bLib::Init("Flappy Bird");

		versionTextData.fontSize = 0.05f;
		versionTextData.text = "v0.4";
		versionTextData.color = SEMITRANSPARENT_B;

		templates::init();
		menu::init();
	}

	static void update()
	{
		bLib::UpdateStart();
		switch (previousState)
		{
		case GameState::MAIN_MENU:
			currentState = menu::update();
			break;

		case GameState::GAMEPLAY:
			currentState = game::update();
			break;

		case GameState::CREDITS:
			currentState = credits::update();
			break;
		}
		bLib::UpdateEnd();
	}

	static void draw()
	{
		drw::Begin();
		drw::Clear(DARKGREY_B);

		switch (previousState)
		{
		case GameState::MAIN_MENU:
			menu::draw();
			drw::Text(versionTextData.text.c_str(), versionTextData, { 0.95f, 0.045f }, versionTextData.fontSize, { 0,0 }, WHITE_B);
			break;

		case GameState::GAMEPLAY:
			game::draw();
			break;

		case GameState::CREDITS:
			credits::draw();
			drw::Text(versionTextData.text.c_str(), versionTextData, { 0.95f, 0.045f }, versionTextData.fontSize, { 0,0 }, WHITE_B);
			break;
		}
		drw::End();
	}

	static void changeState()
	{
		if (currentState != previousState)
		{
			switch (currentState)
			{
			case GameState::MAIN_MENU:
				menu::init();
				break;

			case GameState::GAMEPLAY:
				game::init();
				break;

			case GameState::CREDITS:
				credits::init();
				break;
			case GameState::EXIT:
				isRunning = false;
				break;
			}
		}
		previousState = currentState;
	}
}
