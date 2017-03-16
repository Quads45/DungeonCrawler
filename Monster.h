#ifndef  Monster_H
#define Monster_H
#include <string>
#include <vector>
class Monster {
	int MonsterID, MonsterHP, MonsterSelect, MonsterDefence, MonsterAttackDamage, MonsterDodge, MonsterAccuracy, MonsterExpValue, MonsterLevel;
	std::string MonsterName;
	double MonsterAttackSpeed;
	bool MonsterBoss;
	std::vector<int> possibleMonsterIDs;

public:
	Monster(int MonsterLevelSelect);
	int getMonsterAD(){ return MonsterAttackDamage; }
	int getMonsterHP(){ return MonsterHP; }
	double getMonsterAS(){ return MonsterAttackSpeed; }
	int getMonsterDodge(){ return MonsterDodge; }
	int getMonsterDefence(){ return MonsterDodge; }
	std::string getMonsterName();
	int getMonsterAccuracy(){ return MonsterAccuracy; }
	bool getMonsterBoss(){ return MonsterBoss; }
	int getMonsterExpValue(){ return MonsterExpValue; }
	int getMonsterLevel(){ return MonsterLevel; }
	int RNG(int maxValue);
	int getMonsterID(){ return MonsterID; }

};

#endif 