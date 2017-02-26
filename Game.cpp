// Game.cpp
#include<iostream>
#include "Game.h"
#include "Hero.h"
using namespace std;
Game::Game() 
{

}
void Game::startNewGame(Hero hero1) 
{
	//Describe lore
	//Talk about spooky monsters invading town and how you, the hero, must defend it.
	cout << "Welcome to <insert town name>, " << hero1.getName() << "." << endl;

}
void Game::displayTown()
{
	//to do
}