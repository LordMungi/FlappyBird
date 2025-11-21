#include "Credits.h"

#include "Templates.h"

namespace credits
{
	GameState nextState;

	btn::Button backButton;
	drw::TextData creditsTitleTextData;
	drw::TextData creditsTextData;
	drw::TextData credits2TextData;

	void init()
	{
		backButton = templates::button;
		backButton.pos = { 0.5f, 0.3f };
		backButton.textData.text = "Back";
		btn::Init(backButton);

		creditsTitleTextData.fontSize = 0.07f;
		creditsTitleTextData.text = "Programming";

		creditsTextData.fontSize = 0.05f;
		creditsTextData.text = "Borja Lia";

		credits2TextData.fontSize = 0.05f;
		credits2TextData.text = "Santino Verrua";

		nextState = GameState::CREDITS;
	}

	GameState update()
	{
		btn::UpdateInput(backButton);
		if (backButton.signal) {
			nextState = GameState::MAIN_MENU;
		}
		return nextState;
	}

	void draw()
	{
		btn::Draw(backButton);
		drw::Text(creditsTitleTextData.text.c_str(), creditsTitleTextData, { 0.5f, 0.7f }, creditsTitleTextData.fontSize, { 0,0 }, BLACK_B);
		drw::Text(creditsTextData.text.c_str(), creditsTextData, { 0.5f, 0.6f }, creditsTextData.fontSize, { 0,0 }, BLACK_B);
		drw::Text(credits2TextData.text.c_str(), credits2TextData, { 0.5f, 0.53f }, credits2TextData.fontSize, { 0,0 }, BLACK_B);
	}
}