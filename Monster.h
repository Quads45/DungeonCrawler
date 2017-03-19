#ifndef  Monster_H
#define Monster_H
#include <string>
#include <vector>
class Monster {
	// Create variables for each field in the Monster table 
	//so they can be called by the functions below
	int MonsterID, MonsterHP, MonsterSelect, MonsterDefence, MonsterAttackDamage, MonsterDodge, MonsterAccuracy, MonsterExpValue, MonsterLevel;
	std::string MonsterName;
	double MonsterAttackSpeed;
	bool MonsterBoss;
	std::vector<int> possibleMonsterIDs;

public:
	//create a constructor for the function which selects a random
	//monster based on the level
	Monster(int MonsterLevelSelect);
	//create functions which retrieve the statistics of the monster
	//so the rest of the program can call it
	int getMonsterAD() { return MonsterAttackDamage; };
	int getMonsterHP() { return MonsterHP; };
	double getMonsterAS() { return MonsterAttackSpeed; };
	int getMonsterDodge() { return MonsterDodge; };
	int getMonsterDefence() { return MonsterDefence; };
	std::string getMonsterName() { return MonsterName; };
	int getMonsterAccuracy() { return MonsterAccuracy; };
	bool getMonsterBoss() { return MonsterBoss; };
	int getMonsterExpValue() { return MonsterExpValue; };
	int getMonsterLevel() { return MonsterLevel; };
	//create a constructor for the random number generator function.
	int RNG(int maxValue);
	int getMonsterID(){ return MonsterID; }

};

#endif 