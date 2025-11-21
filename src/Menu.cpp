#include "Menu.h"

#include "Templates.h"
#include "Config.h"

namespace menu
{
	GameState nextState;

	btn::Button playButton;
	btn::Button play2Button;
	btn::Button creditsButton;
	btn::Button exitButton;

	void init()
	{
		playButton = templates::button;
		playButton.pos = { 0.5f, 0.6f };
		playButton.textData.text = "1P";
		btn::Init(playButton);

		play2Button = templates::button;
		play2Button.pos = { 0.5f, 0.5f };
		play2Button.textData.text = "2P";
		btn::Init(play2Button);

		creditsButton = templates::button;
		creditsButton.pos = { 0.5f, 0.4f };
		creditsButton.textData.text = "Credits";
		btn::Init(creditsButton);

		exitButton = templates::button;
		exitButton.pos = { 0.5f, 0.3f };
		exitButton.textData.text = "Exit";
		btn::Init(exitButton);

		nextState = GameState::MAIN_MENU;
	}

	GameState update()
	{
		btn::UpdateInput(playButton);
		btn::UpdateInput(play2Button);
		btn::UpdateInput(creditsButton);
		btn::UpdateInput(exitButton);

		if (playButton.signal)
		{
			config::playersInGame = 1;
			nextState = GameState::GAMEPLAY;
		}
		if (play2Button.signal)
		{
			config::playersInGame = 2;
			nextState = GameState::GAMEPLAY;
		}
		if (creditsButton.signal) {
			nextState = GameState::CREDITS;
		}
		if (exitButton.signal) {
			nextState = GameState::EXIT;
		}
		return nextState;
	}

	void draw()
	{
		btn::Draw(playButton);
		btn::Draw(play2Button);
		btn::Draw(creditsButton);
		btn::Draw(exitButton);
	}
}