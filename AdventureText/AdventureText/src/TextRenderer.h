#pragma once

#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H


#include "Text.h"
#include "Player.h"

#include "GLEW/glew.h"
#include "GLUT/glut.h"
#include <vector>

class TextRenderer
{
private:
	std::vector<std::string> vocab
		=
	{
		"HELLO",
		"HI",
		"FIGHT",
		"YUP",
		"TOOO"
	};
public:
	TextRenderer();
	~TextRenderer();

	bool DrawTextScreen(Text* text, Player* player, char typed_text, void *font = GLUT_BITMAP_8_BY_13);
	bool DrawStaticText(Text* text, void *font = GLUT_BITMAP_8_BY_13);
};

#endif // !TEXTRENDERER_H