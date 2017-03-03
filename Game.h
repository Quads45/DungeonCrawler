// Game.h
#include "Hero.h"
#include<iostream>
#ifndef Game_H
#define Game_H
class Game
{
	int choice;
public:
	Game();
	void startNewGame(Hero hero1);
	void showTown(Hero hero1);
	void gotoInventory(Hero hero1);
	int getSelection(int maxChoice);
};
#endif // !Game_H
