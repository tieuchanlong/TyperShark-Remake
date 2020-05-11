#include "Text.h"
#include "Setting.h"

Text::Text(std::string _text, float _x, float _y, float _step):
	text(_text), x(_x), y(_y), step(_step)
{
	ResetString();
	matched_character = 0;
}

Text::~Text()
{
}

void Text::Move()
{
	x -= step;
}

void Text::ResetString(std::string test)
{
	int length = rand() % Setting::GetInstance()->GetMaxCharacter() + 1;
	text = "";

	for (int i = 0; i < length; i++)
	{
		char ran_char = 'A' + rand() % 26;
		text += ran_char;
	}

	matched_character = 0;
}

void Text::SetString(std::string test)
{
	text = test;
}

int Text::GetMatchedText()
{
	return matched_character;
}

void Text::IncreaseMatchedText()
{
	matched_character++;
}

void Text::ResetPos()
{
	x = 1.0f;
}

std::string Text::GetText()
{
	return text;
}

float Text::GetX()
{
	return x;
}

float Text::GetY()
{
	return y;
}

void Text::SetPos(float _posx, float _posy)
{
	x = _posx;
	y = _posy;
}
