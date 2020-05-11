#include "TankFillEnemy.h"

void TankFillEnemy::Move()
{
	// Stay
}

TankFillEnemy::TankFillEnemy(float pos_x, float pos_y, float speed_inp, Color _color):
	Enemy(pos_x, pos_y, speed_inp, _color)
{
	value = 200;
}

TankFillEnemy::~TankFillEnemy()
{
}

void TankFillEnemy::Render(TextRenderer * text_renderer, Player * player, char typed_text)
{
	if (text_renderer->DrawTextScreen(text, player, typed_text, GLUT_BITMAP_TIMES_ROMAN_24)) {
		ResetPos();
		player->score += value;
	}

	Move();
	text->SetPos(x, y);

	if (x < -0.5f)
		ResetPos();
}

void TankFillEnemy::ResetPos()
{
	text->ResetString();
}
