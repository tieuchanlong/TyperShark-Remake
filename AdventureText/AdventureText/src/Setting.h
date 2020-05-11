#pragma once

class Setting
{
private:
	static Setting* instance;
	float time = 0.01f;
	int maxEnemy = 3;
	int maxBonusEnemy = 10;
	int maxCharacter = 4;
	int maxBonusCharacter = 1;
	Setting() {};
public:
	static Setting* GetInstance();
	float GetTime();
	int GetMaxEnemy();
	int GetMaxCharacter();
	int GerMaxBonusEnemy();
	int GetMaxBonusCharacter();

	void IncreaseTime();
	void IncreaseMaxEnemy();
	void IncreaseMaxCharacter();
	void IncreaseMaxBonusCharacter();
};