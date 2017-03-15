// Game.h
#include "Hero.h"
#include "Battle.h"
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
	void showInventory(Hero hero1);
	void showStats(Hero hero1);
	int getSelection(int maxChoice);
	void Save(Hero hero1);
	void SaveInventory(Hero hero1);
	int getCharID();
	void SaveEquiped(Hero hero1);
	void goToBattle(Hero hero1);
};
#endif // !Game_H
	