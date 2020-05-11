#include <iostream>
#include <string>
#include <algorithm>

#include "GLEW/glew.h"
#include "GLUT/glut.h"
#include "Player.h"
#include "Text.h"
#include "Map.h"
#include "UserInterface.h"

Player* player = new Player(-0.8f, 0, 0.001f, Color(1.0f, 0.0f, 0.0f, 1.0f));
UserInterface* user_interface = new UserInterface();
Map* map = new Map();

std::string keyboard_input;
char key_input;
int render_state = 0;
void render(void);
void keyboard_down(unsigned char key, int x, int y);
void keyboard_up(unsigned char key, int x, int y);
void render_startscreen();
void render_maingame();
void render_pausescreen();
void render_endgame();

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Adventure Text");

	glutDisplayFunc(render);
	glutMainLoop();

	return 1;
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (render_state == 0)
		render_startscreen();
	else if (render_state == 1)
		render_maingame();
	else if (render_state == 2)
		render_pausescreen();
	else if (render_state == 3)
		render_endgame();

	glutSwapBuffers();

	glutKeyboardFunc(keyboard_down);
	glutKeyboardUpFunc(keyboard_up);

	glutPostRedisplay();
}

void render_startscreen()
{
	map->SetStage(map->START_SCREEN);
	user_interface->RenderStartMenu();

	// Go to the main game
	if (key_input == 32)
		render_state = 1;
}

void render_maingame()
{
	if (user_interface->ReachedBottom())
		map->SetStage(map->TANK_FILL_ROUND);

	if (!user_interface->ReachedBottom())
		map->SetStage(map->MAIN_ROUND);
	map->ChangeLevel(user_interface, render_state);
	map->SpawnEnemy();
	map->MoveEnemy(player, key_input);
	

	player->SetPosition(key_input);
	player->Render();

	user_interface->DrawMark(map->GetTextRenderer());
	user_interface->Render(player->score);

	if ((int)key_input == 9)
		render_state = 2;
}

void render_pausescreen()
{
	map->SetStage(map->PAUSE_SCREEN);
	user_interface->RenderPauseMenu();
	player->Render();

	if ((int)key_input == 9)
		render_state = 1;

	if ((int)key_input == 27)
		render_state = 0;
}

void render_endgame()
{
	user_interface->RenderEndGameScreen(player->score);
	if (key_input == 'r')
		render_state = 1;

	if ((int)key_input == 27)
		render_state = 0;
}

void keyboard_down(unsigned char key, int x, int y)
{
	if (key >= 'a' && key <= 'z') {
		keyboard_input += key;
		key_input = key;
	}
	else
	{
		key_input = key;
	}
	std::cout << key << std::endl;
}

void keyboard_up(unsigned char key, int x, int y)
{
	key_input = '/';
	std::cout << key << std::endl;
}