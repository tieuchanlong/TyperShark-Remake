#include "BonusEnemy.h"

BonusEnemy::BonusEnemy(float pos_x, float pos_y, float speed_inp, Color _color):
	Enemy(pos_x, pos_y, speed_inp, _color)
{
	value = 50;
}

BonusEnemy::~BonusEnemy()
{
}

void BonusEnemy::Move()
{
	y += speed;
}

void BonusEnemy::ResetPos()
{
	y = -1.0f;
	delay_spawn_time = 100.0f;
}
