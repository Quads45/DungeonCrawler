#ifndef  Monster_H
#define Monster_H
#include <string>

class Monster {
	int MonsterID, MonsterHP, MonsterSelect, MonsterDefence, MonsterAttackDamage, MonsterDodge, MonsterAccuracy, MonsterExpValue, MonsterLevel;
	std::string MonsterName;
	double MonsterAttackSpeed;
	bool MonsterBoss;

public:
	Monster(int MonsterLevelSelect);
	int getMonsterAD();
	int getMonsterHP();
	double getMonsterAS();
	int getMonsterDodge();
	int getMonsterDefence();
	std::string getMonsterName();
	int getMonsterAccuracy();
	bool getMonsterBoss();
	int getMonsterExpValue();
	int getMonsterLevel();

};

#endif 