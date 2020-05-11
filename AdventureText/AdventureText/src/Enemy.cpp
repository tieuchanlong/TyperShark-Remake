#include "Enemy.h"
#include "GLEW/glew.h"
#include "Setting.h"

Enemy::Enemy(float pos_x, float pos_y, float speed_inp, Color _color):
	x(pos_x), y(pos_y), speed(speed_inp), color(_color)
{
	text = new Text("TEXT", pos_x, pos_y, 0.002f);
	delay_spawn_time = 0.0f;
	value = 100;
}

Enemy::~Enemy()
{
}

void Enemy::Move()
{
	if (delay_spawn_time > 0.0f)
	{
		delay_spawn_time -= Setting::GetInstance()->GetTime();
		return;
	}

	x -= speed;
}

void Enemy::Render(TextRenderer* text_renderer, Player* player, char typed_text)
{
	glBegin(GL_POLYGON);

	// Draw square
	glColor3f(color.r, color.g, color.b);
	glVertex3f(x, y, 0.0f);
	glVertex3f(x + size, y, 0.0f);
	glVertex3f(x + size, y + size, 0.0f);
	glVertex3f(x, y + size, 0.0f);
	glEnd();

	if (text_renderer->DrawTextScreen(text, player, typed_text)) {
		ResetPos();
		player->score += value;
	}

	Move();
	text->SetPos(x, y);

	if (x < -0.5f)
		ResetPos();
}

void Enemy::ResetPos()
{
	x = 1.0f;
	text->ResetString();
	text->ResetPos();
	delay_spawn_time = 20.0f;
}

void Enemy::SetName(std::string _name)
{
	name = _name;
}

float Enemy::GetX()
{
	return x;
}

float Enemy::GetY()
{
	return y;
}

bool Enemy::CollidePlayer(Player * player)
{
	if (player->GetX() + player->GetSize() >= x)
		return true;
}
