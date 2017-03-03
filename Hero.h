// Hero.h
#include "Inventory.h"
#ifndef Hero_H
#define Hero_H
class Hero
{
    int hp, attack_damage, range, inventory_size, inventory_space, invetory_taken;
    double attack_speed;
    double crit_chance = 0.0;
    double crit_multiplier = 1.0;
	std::string heroName;


    public:
	enum PROFESSION {Warrior=1, Hunter, Mage};
    Hero(std::string name, int profession);
	Hero(int charID);
	void setStats(int newHp, int newAD, int newRange, float newAS);
    void getStats();
	std::string getName() { return heroName; };	
	Inventory inv; // use standard constructor, unchanged if starting new game
};
#endif
