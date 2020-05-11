#pragma once

#include "Enemy.h"

class TankFillEnemy : public Enemy
{
protected:
	virtual void Move();
public:
	TankFillEnemy(float pos_x, float pos_y, float speed_inp, Color _color);
	~TankFillEnemy();
	virtual void Render(TextRenderer* text_renderer, Player* player, char typed_text);
	virtual void ResetPos();
};