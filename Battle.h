// Battle.h


#ifndef Battle_H
#define Battle_h

#include "Hero.h"
#include "Monster.h"

class Battle
{
	//declaring variable type
	int percentage;
	bool hit;
	char firstTurn;
public:
	Battle(Hero hero1, int monsterLevel);
	char firstAttack(Hero hero1, Monster monster1);
	
	void startOfBattle(Hero hero1, Monster monster1);
	void getAccuracy(Hero hero1);

	
};




#endif 