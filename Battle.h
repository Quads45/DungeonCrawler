// Battle.h


#ifndef Battle_H
#define Battle_h
#include "Hero.h"
#include "Monster.h"
#include "Spell.h"
#include <string>


class Battle
{
	//declaring variable type
	struct currentHero {
		double HP;
		int AD;
		double AS;
		int dodge;
		int accuracy;
		int defence;
	};
	struct currentMonster {
		double HP;
		int AD;
		double AS;
		int dodge;
		int accuracy;
		int defence;
	};
	bool hit;
	char firstTurn;
	currentHero curHero1;
	currentMonster curMonster1;
	std::vector<Spell> currentSpells;
	std::vector<Spell> MonsterSpells;
	std::vector<int> MonsterSpellIDs;
	
public:
	Battle(Hero &hero1, int monsterLevel);
	char firstAttack();
	void startOfBattle(Hero &hero1, Monster monster1);
	double getAccuracy(char whoseTurn);
	void heroTurn(Hero hero1, Monster monster1);
	void monsterTurn(Hero hero1, Monster monster1);
	void gameEngine(Hero &hero1, Monster monster1);
	void playSound(Monster monster1);
	void dispImage(Monster monster1);
	void loadMonsterSpell(Monster monster1);
	void dropLoot(Monster monster1, Hero &hero1);
	void getFileContents(Monster monster1);
};




#endif 