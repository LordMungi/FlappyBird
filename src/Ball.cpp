#include "BorjaLib.h"
#include "Ball.h"

//TEMPORALMENTE AQUI
float gravity = 3.0f;

namespace bll {

	void Init(Ball& ball, int player)
	{
		ball.player = player;

		switch (ball.player)
		{
		case 1:
			ball.jumpKey = ctrl::Key::W;
			ball.jumpButton = ctrl::ButtonMouse::LMB;
			break;
		case 2:
			ball.jumpKey = ctrl::Key::UP;
			ball.jumpButton = ctrl::ButtonMouse::RMB;
			break;
		}

		Reset(ball);
	}

	void Reset(Ball& ball)
	{
		ball.pos = Ball().pos;
		ball.vel = Ball().vel;
		ball.crashPoint = Ball().crashPoint;
		switch (ball.player)
		{
		case 1:
			ball.color = MAROON_B;
			break;
		case 2:
			ball.color = BLUEBERRY_B;
			break;
		}

		ball.isActive = true;
		ball.isAlive = true;
	}

	void UpdateInput(Ball& ball)
	{
		if (!ball.isAlive || !ball.isActive) {
			return;
		}

		if (ctrl::IsKeyPressed(ball.jumpKey) || ctrl::IsMousePressed(ball.jumpButton)) {
			ball.vel.y = ball.jumpForce;
		}
	}

	void Update(Ball& ball)
	{
		if (!ball.isAlive || !ball.isActive) {
			return;
		}

		ball.vel.y -= gravity * rend::deltaTime;

		ball.pos += ball.vel * rend::deltaTime;

		if (ball.pos.y + ball.size.y > 1.0f) {
			ball.pos.y = 1.0f - ball.size.y;
			ball.vel = 0.0f;
		}
		if (ball.pos.y - ball.size.y < 0.0f) {
			ball.pos.y = ball.size.y;
			Die(ball);
		}
	}

	void Draw(Ball& ball)
	{
		if (!ball.isActive) {
			return;
		}
		drw::Circle(ball.pos, ball.size, ball.color);
		if (!ball.isAlive) {

			drw::Circle(ball.crashPoint, ball.size * (1.0f/3.0f), MAGENTA_B);
		}
	}
	void Die(Ball& ball)
	{
		ball.isAlive = false;
		ball.vel = 0.0f;
		ball.color = GREY_B;
	}
}