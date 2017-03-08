// Hero.h
#include "Inventory.h"
#include "libsqlite.hpp"
#include <string>
#ifndef Hero_H
#define Hero_H
class Hero
{

	int hp, defence, dodge, accuracy, attack_damage;
	double attack_speed;
	std::string heroName;

    public:
	enum PROFESSION {Warrior=1, Hunter, Mage};
    Hero(std::string name, int profession);
	Hero(int charID);
	void setStats(int newHp,int newDefence, int newDodge, int newAccuracy, int newAD, double newAS);
    void getStats();
	std::string getName() { return heroName; };	
	Inventory inv; // use standard constructor, unchanged if starting new game
	int getHeroAD();
	double getHeroAS();
	int getHeroHP();
	int getHeroDefence();
	int getHeroAccuracy();
	int getHeroDodge();

};

#endif
