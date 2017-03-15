#pragma once
#ifndef Shop_H
#define Shop_H
#include <iostream>
#include "Hero.h"

class Shop
{
	int choice;
public:
	Shop(Hero hero1);
	void displayBuy(Hero hero1);
	void displaySell(Hero hero1);
};
#endif

