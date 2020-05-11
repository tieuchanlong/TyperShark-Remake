#include "Setting.h"

Setting* Setting::instance;

Setting* Setting::GetInstance()
{
	if (instance == nullptr)
		instance = new Setting();
	return instance;
}

float Setting::GetTime()
{
	return time;
}

int Setting::GetMaxEnemy()
{
	return maxEnemy;
}

int Setting::GetMaxCharacter()
{
	return maxCharacter;
}

int Setting::GerMaxBonusEnemy()
{
	return maxBonusEnemy;
}

int Setting::GetMaxBonusCharacter()
{
	return maxBonusCharacter;
}

void Setting::IncreaseTime()
{
	time += 0.03f;
}

void Setting::IncreaseMaxEnemy()
{
	maxEnemy++;
}

void Setting::IncreaseMaxCharacter()
{
	maxCharacter++;

	if (maxCharacter > 8)
		maxCharacter = 8;
}

void Setting::IncreaseMaxBonusCharacter()
{
	maxBonusCharacter++;

	if (maxBonusCharacter > 4)
		maxBonusCharacter = 4;
}
