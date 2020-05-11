#pragma once

#include "Text.h"
#include "TextRenderer.h"

#include <string>
#include <vector>

class UserInterface
{
private:
	int maxDepth = 320;
	int curDepth = 0;
	float spaceBetweenMark = 0.5f;
	float markSpeed = 0.00005f;
	std::vector<Text*> marks;

	bool reachBottom = false;

	void DrawScaleLine();
	void RenderText(std::string text, const float &pos_x, const float &pos_y, void* font = GLUT_BITMAP_8_BY_13);

public:
	UserInterface();
	~UserInterface();
	void RenderStartMenu();
	void RenderPauseMenu();
	void RenderEndGameScreen(const int& score);
	void Render(int& score);
	void DrawMark(TextRenderer* text_renderer);
	void ResetMark();

	bool ReachedBottom();
};