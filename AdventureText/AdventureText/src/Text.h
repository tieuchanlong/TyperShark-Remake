#pragma once

#include <string>

class Text
{
private:
	std::string text;
	int matched_character;
	float x, y, step;
public:
	bool selected = true;
	Text(std::string _text, float _x, float _y, float _step);
	~Text();
	void Move();
	void ResetString(std::string test = "HI");
	void SetString(std::string test = "JO");

	int GetMatchedText();
	void IncreaseMatchedText();
	void ResetPos();
	std::string GetText();
	float GetX();
	float GetY();
	void SetPos(float _posx, float _posy);
};