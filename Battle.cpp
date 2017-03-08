//Battle.cpp
#include "Battle.h"
#include "libsqlite.hpp"
using namespace std;

Battle::Battle(Hero hero1,int monsterLevel) // constructor
{
	Monster monster1(monsterLevel);
	startOfBattle(hero1, monster1);
		
		//auto cur = db.get_statement();            // create query
	//cur->set_sql("SELECT [ProfessionHP],[ProfessionDefence],[ProfessionDodge],[ProfessionAccuracy],[ProfessionAttackDamage],[ProfessionAttackSpeed] FROM [Profession] WHERE [ProfessionID]=?;");

}

char Battle::firstAttack(Hero hero1, Monster monster1)
{
	// compares the attack speed of hero with monster
	// returns whos turn is first
	
	if (hero1.getHeroAS() >= monster1.getMonsterAS()) {
		cout << "It is your turn" << hero1.getName() << " Please choose your turn Wisely! ..." << endl;
		return('h');

	}
	else {
		cout << "It is "  << monster1.getMonsterName() << " turn ... Please Wait ..." << endl;
		return('m');
	}
	



}

void Battle::startOfBattle(Hero hero1, Monster monster1)
{
	cout << "As you walk along you stop and notice a level " /*<< monster1.getMonsterName() */<< "1 " << monster1.getMonsterName() << " has appeared! " <<endl;
	firstTurn=firstAttack(hero1, monster1);





}

void Battle::getAccuracy(Hero hero1)
{
	// Depending on whos turn it is, check the accuracy of the hero with the dodge of the monster and vice versa
	//Returns chance of hit
}