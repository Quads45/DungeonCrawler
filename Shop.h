
#ifndef Shop_H
#define Shop_H
#include <vector>
#include "Hero.h"
#include "Item.h"

class Shop
{
	int choice;
	std::vector<Item> shopItems;
public:
	Shop(Hero &hero1);
	void displayBuy(Hero &hero1);
	void displaySell(Hero &hero1);
};
#endif

