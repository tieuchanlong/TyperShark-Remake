#pragma once

#include <vector>
#include <string>

#include "TextRenderer.h"
#include "Text.h"
#include "Player.h"
#include "BonusEnemy.h"
#include "TankFillEnemy.h"
#include "UserInterface.h"


class Map
{
private:
	TankFillEnemy* tank_text = new TankFillEnemy(-0.2f, -0.7f, 0.0002f, Color(0.0f, 0.0f, 1.0f, 1.0f));
	std::vector<Enemy*> bonus_enemies;
	std::vector<Enemy*> enemies;


	TextRenderer* text_renderer;
	float time_btwn_level = 3000;
	float bonustime_btwn_level = 100;
	float tankfilltime_btwn_level = 1000;
	const int spawn_delay = 200;
	int spawn_count;
	const float enemy_delay = 100;
	float enemy_count;
	const float bonusenemy_delay = 300;
	float bonusenemy_count;

public:
	enum state { MAIN_ROUND, BONUS_ROUND, TANK_FILL_ROUND, START_SCREEN, PAUSE_SCREEN };

	Map();
	~Map();

	TextRenderer* GetTextRenderer();

	void SpawnEnemy();
	void MoveEnemy(Player* player, char typed_text);
	void ChangeLevel(UserInterface* user_interface, int& render_stage);
	void SetStage(state newState);

private:
	state State = BONUS_ROUND;
};