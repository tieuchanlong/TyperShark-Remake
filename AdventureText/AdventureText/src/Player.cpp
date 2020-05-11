#include "GLEW/glew.h"
#include "GLUT/glut.h"
#include "Player.h"

Player::Player(float pos_x, float pos_y, float speed_inp, Color _color):
	x(pos_x), y(pos_y), speed(speed_inp), color(_color)
{
	dest_x = -2;
	dest_y = -2;
}

Player::~Player()
{
}

void Player::Render()
{
	MoveTo();

	glBegin(GL_POLYGON);

	// Draw square
	glColor3f(color.r, color.g, color.b);
	glVertex3f(x, y, 0.0f);
	glVertex3f(x + size, y, 0.0f);
	glVertex3f(x + size, y + size, 0.0f);
	glVertex3f(x, y + size, 0.0f);
	glEnd();
}

void Player::SetPosition(char direction)
{
	/*if (direction != 'w' && direction != 'a' && direction != 's' && direction != 'd')
		return;

	switch (direction)
	{
	case 'w':
		y += step;
		break;
	case 'a':
		x -= step;
		break;
	case 's':
		x += step;
		break;
	case 'd':
		y -= step;
		break;
	default:
		std::cout << "Wrong input direction";
	}*/
}

void Player::SetDestination(float _dest_x, float _dest_y)
{
	dest_x = _dest_x;
	dest_y = _dest_y;
}

float Player::GetX()
{
	return x;
}

float Player::GetY()
{
	return y;
}

float Player::GetSize()
{
	return size;
}

void Player::MoveTo()
{
	if (dest_x <= -2 || dest_y <= -2)
		return;

	if (sqrt((x - dest_x) * (x - dest_x) + (y - dest_y) * (y - dest_y)) <= 0.01f)
	{
		x = dest_x;
		y = dest_y;
		dest_x = -2;
		dest_y = -2;
	}

	if (x > dest_x)
		x -= speed;
	else
		x += speed;

	if (y > dest_y)
		y -= speed;
	else
		y += speed;
}
