#pragma once

#ifndef ENEMY_H
#define ENEMY_H


#include "Color.h"
#include "Player.h"
#include "Text.h"
#include "TextRenderer.h"

#include <string>

class Enemy
{
protected:
	std::string name;
	int value;
	float x, y, speed, standard_speed, size = 0.17f;
	Color color;
	Text* text;
	float delay_spawn_time;

	virtual void Move();
	

public:
	Enemy(float pos_x, float pos_y, float speed_inp, Color _color);
	~Enemy();
	virtual void Render(TextRenderer* text_renderer, Player* player, char typed_text);
	void SetName(std::string _name);
	virtual void ResetPos();

	float GetX();
	float GetY();
	bool CollidePlayer(Player* player);
};

#endif // !ENEMY_H