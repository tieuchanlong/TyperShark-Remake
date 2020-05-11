#include "UserInterface.h"
#include "GLEW/glew.h"
#include "GLUT/freeglut.h"

#include <iostream>

UserInterface::UserInterface()
{
	// Initialize the marks
	double depth = 1.0f;
	int count = 0;

	for (int i = 0; i <= 320; i += 20)
	{
		marks.push_back(new Text(std::to_string(i), -0.9f, depth, 0.0f));
		marks[count]->SetString(std::to_string(i));
		depth -= spaceBetweenMark;
		count++;
	}
}

UserInterface::~UserInterface()
{

}

void UserInterface::RenderStartMenu()
{
	// Render the white text Title
	RenderText("ADVENTURE TEXT", -0.3f, 0.2f, GLUT_BITMAP_TIMES_ROMAN_24);


	// Render the white text for instructions
	RenderText("Press Space to Start", -0.2f, -0.1f);
}

void UserInterface::RenderPauseMenu()
{
	// Render the white text for Pause Title
	RenderText("PAUSED", -0.1f, 0.2f, GLUT_BITMAP_TIMES_ROMAN_24);


	// Render the white text for instructions
	RenderText("Press Esc to Exit the game", -0.2f, -0.1f);

	// Render the white text for instructions
	RenderText("Press Space to Continue the game", -0.2f, -0.2f);
}

void UserInterface::RenderEndGameScreen(const int& score)
{
	RenderText("SCORE: " + std::to_string(score), -0.1f, 0.2f, GLUT_BITMAP_TIMES_ROMAN_24);
	// Render the white text for instructions
	RenderText("Press R to Retry the game", -0.2f, -0.1f);

	// Render the white text for instructions
	RenderText("Press Esc to Exit to main menu", -0.2f, -0.2f);
}

void UserInterface::Render(int& score)
{
	// Render the top bar
	glBegin(GL_POLYGON);

	// Draw square
	glColor3f(0.7f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 0.9f, 0.0f);
	glVertex3f(-1.0f, 0.9f, 0.0f);
	glEnd();

	// Render the white text for score
	RenderText("Score: " + std::to_string(score), -1.0f, 0.95f);
}

void UserInterface::DrawScaleLine()
{
	for (int i = 0; i < marks.size(); i++)
	{
		glLineWidth(0.1f);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex3f(marks[i]->GetX() - 0.1f, marks[i]->GetY(), 0.0);
		glVertex3f(marks[i]->GetX() - 0.01f, marks[i]->GetY(), 0);
		glEnd();
	}
}

// There is still some error with this code with the std::copy()
void UserInterface::RenderText(std::string text, const float &pos_x, const float &pos_y, void* font)
{
	// Render the white text for score
	unsigned char test1[sizeof(text) + 2] = "";
	std::copy(text.begin(), text.end(), test1);
	test1[sizeof(text)] = 0;

	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2f(pos_x, pos_y);
	for (int i = 0; i < strlen((char*)test1); i++)
	{
		glutBitmapCharacter(font, test1[i]);
	}
}

void UserInterface::DrawMark(TextRenderer* text_renderer)
{
	DrawScaleLine();

	for (int i = 0; i < marks.size(); i++)
		text_renderer->DrawStaticText(marks[i]);

	if (marks[marks.size() - 1]->GetY() < -0.9f) {
		for (int i = 0; i < marks.size(); i++)
			marks[i]->SetPos(marks[i]->GetX(), marks[i]->GetY() + markSpeed);
	}
	else
		reachBottom = true;
}

void UserInterface::ResetMark()
{
	double depth = 1.0f;
	int count = 0;

	for (int i = 0; i <= 320; i += 20)
	{
		marks[count]->SetPos(marks[count]->GetX(), depth);
		depth -= spaceBetweenMark;
		count++;
	}

	reachBottom = false;
}

bool UserInterface::ReachedBottom()
{
	return reachBottom;
}
