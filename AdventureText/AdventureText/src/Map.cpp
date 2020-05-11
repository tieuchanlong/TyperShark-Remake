#include "Map.h"
#include "Setting.h"
#include <time.h>

Map::Map()
{
	text_renderer = new TextRenderer();
	enemy_count = bonusenemy_count = 0;
	spawn_count = 0;
}

Map::~Map()
{
}

TextRenderer * Map::GetTextRenderer()
{
	return text_renderer;
}

void Map::SpawnEnemy()
{
	if (State == MAIN_ROUND) {
		if (enemies.size() >= Setting::GetInstance()->GetMaxEnemy())
			return;

		srand(time(NULL));
		if (enemy_count == 0) {
			int sign = (rand() % 2 == 0) ? 1 : -1;
			float y = (float)(rand() % 8) / 8.0f * sign;
			enemies.push_back(new Enemy(1.0f, y, 0.0001f, Color(0.0f, 0.0f, 1.0f, 1.0f)));
		}
		enemy_count += Setting::GetInstance()->GetTime();

		if (enemy_count >= enemy_delay)
			enemy_count = 0;
	}
	else if (State == BONUS_ROUND){
		if (bonus_enemies.size() >= 6)
			return;

		srand(time(NULL));
		if (enemy_count == 0) {
			int sign = (rand() % 2 == 0) ? 1 : -1;
			float x = (float)(rand() % 8) / 8.0f * sign;
			bonus_enemies.push_back(new BonusEnemy(x, -1.0f, 0.0002f, Color(0.0f, 0.0f, 1.0f, 1.0f)));
		}
		enemy_count += Setting::GetInstance()->GetTime();

		if (enemy_count >= enemy_delay)
			enemy_count = 0;
	}
	else if (State == TANK_FILL_ROUND)
	{
		if (tank_text == nullptr)
			tank_text = new TankFillEnemy(0.2f, -1.0f, 0.0002f, Color(0.0f, 0.0f, 1.0f, 1.0f));
	}
}

void Map::MoveEnemy(Player* player, char typed_text)
{
	if (State == MAIN_ROUND) {
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies[i]->Render(text_renderer, player, typed_text);
		}
	}
	else if (State == BONUS_ROUND)
	{
		for (int i = 0; i < bonus_enemies.size(); i++)
		{
			bonus_enemies[i]->Render(text_renderer, player, typed_text);
		}
	}
	else if (State == TANK_FILL_ROUND)
	{
		tank_text->Render(text_renderer, player, typed_text);
	}
}

void Map::ChangeLevel(UserInterface* user_interface, int& render_stage)
{
	if (State == START_SCREEN) {
		for (int i = 0; i < enemies.size(); i++)
		{
			delete enemies[enemies.size()-1];
			enemies[enemies.size() - 1] = 0;
			enemies.pop_back();
		}

		for (int i = 0; i < bonus_enemies.size(); i++)
		{
			delete bonus_enemies[enemies.size() - 1];
			bonus_enemies[enemies.size() - 1] = 0;
			bonus_enemies.pop_back();
		}

	}
	else if (State == MAIN_ROUND) {
		time_btwn_level -= Setting::GetInstance()->GetTime();
		if (time_btwn_level <= 0.0f) {
			State = BONUS_ROUND;
			bonustime_btwn_level = 100;

			for (int i = 0; i < enemies.size(); i++)
			{
				enemies[i]->ResetPos();
			}
		}
	}
	else if (State == BONUS_ROUND) {
		bonustime_btwn_level -= Setting::GetInstance()->GetTime();
		if (bonustime_btwn_level <= 0.0f) {
			State = MAIN_ROUND;
			time_btwn_level = 3000;
			bonustime_btwn_level = 100;

			// Increase time
			Setting::GetInstance()->IncreaseTime();

			for (int i = 0; i < bonus_enemies.size(); i++)
			{
				bonus_enemies[i]->ResetPos();
			}
		}
	}
	else if (State == TANK_FILL_ROUND)
	{
		tankfilltime_btwn_level -= Setting::GetInstance()->GetTime();
		if (tankfilltime_btwn_level <= 0.0f)
		{
			State = MAIN_ROUND;
			time_btwn_level = 3000;

			user_interface->ResetMark();

			// Increase time
			Setting::GetInstance()->IncreaseTime();

			for (int i = 0; i < enemies.size(); i++)
			{
				enemies[i]->ResetPos();
			}

			for (int i = 0; i < bonus_enemies.size(); i++)
			{
				bonus_enemies[i]->ResetPos();
			}

			render_stage = 3;
		}
	}
}

void Map::SetStage(state newState)
{
	State = newState;

	if (State == TANK_FILL_ROUND && tankfilltime_btwn_level <= 0.0f)
		tankfilltime_btwn_level = 200.0f;
}
