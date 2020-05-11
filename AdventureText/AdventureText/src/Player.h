#pragma once

#include <iostream>
#include "Color.h"
#include "Text.h"

class Player
{
private:
	const float size = 0.1f;
	const float step = 0.001f;
	float x, y, dest_x, dest_y, speed;
	Color color;

	void MoveTo();
public:
	int score = 0;

	Player(float pos_x, float pos_y, float speed_inp, Color _color);
	~Player();
	void Render();
	void SetPosition(char direction);
	void SetDestination(float _dest_x, float _dest_y);
	float GetX();
	float GetY();
	float GetSize();
};