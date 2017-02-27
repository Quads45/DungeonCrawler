// Game.cpp
#include "Game.h"
using namespace std;
Game::Game() 
{

}
void Game::startNewGame(Hero hero1) 
{
	//Describe lore
	//Talk about spooky monsters invading town and how you, the hero, must defend it.
	cout << "Welcome to <insert town name>, " << hero1.getName() << "." << endl;
	displayTown(hero1);
}
void Game::displayTown(Hero hero1)
{
	//to do
	//ask user what he would like to do
	//shop/dungeone select/view inv etc.
	hero1.inv.displayEquiped();
}