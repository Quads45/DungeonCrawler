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
	void showInventory(Hero hero1);
	void showStats(Hero hero1);
	int getSelection(int maxChoice);
	int startBattle(Hero hero1, int MonsterLevelSelect);
};
#endif // !Game_H
	