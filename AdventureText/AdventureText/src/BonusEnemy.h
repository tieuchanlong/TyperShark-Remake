#pragma once
#ifndef BONUSENEMY_H
#define BONUSENEMY_H

#include "Enemy.h"

class BonusEnemy : public Enemy
{
protected:
	void Move();

public:
	BonusEnemy(float pos_x, float pos_y, float speed_inp, Color _color);
	~BonusEnemy();
	void ResetPos();
};

#endif