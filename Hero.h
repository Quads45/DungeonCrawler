// Hero.h
#include "Inventory.h"
#include "libsqlite.hpp"
#ifndef Hero_H
#define Hero_H
class Hero
{

	int hp, defence, dodge, accuracy, attack_damage, level, experience, profID;
	double attack_speed;
	std::string heroName;
    public:
	enum PROFESSION {Warrior=1, Hunter, Mage};
    Hero(std::string name, int profession);
	Hero(int charID);
	void getStats();
	std::string getName() { return heroName; };	
	Inventory inv; // use standard constructor, unchanged if starting new game
	int getHeroAD(){ return attack_damage; }
	double getHeroAS(){ return attack_speed; }
	int getHeroHP(){ return hp; }
	int getHeroDefence(){ return defence; }
	int getHeroAccuracy() { return accuracy; }
	int getHeroDodge() { return dodge; }
	void updateStats();
	int getHeroProfID() { return profID; }
	int getLevel() { return level; }
	int getExp() {return experience;}
	void addExp(int expValue);
};
#endif
