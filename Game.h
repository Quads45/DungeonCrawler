// Game.h
#include "Hero.h"
#include<iostream>
#ifndef Game_H
#define Game_H
class Game
{
public:
	Game();
	void startNewGame(Hero hero1);
	void displayTown(Hero hero1);
};
#endif // !Game_H
