// Game.cpp
#include "Game.h"
using namespace std;
class InvalidInput {};
Game::Game() 
{

}
void Game::startNewGame(Hero hero1) 
{
	//Describe lore
	//Talk about spooky monsters invading town and how you, the hero, must defend it.
	cout << "Welcome to <insert town name here>, " << hero1.getName() << "." << endl;
	showTown(hero1);
}
void Game::showTown(Hero hero1)
{
	//to do
	//ask user what he would like to do
	//shop/dungeone select/view inv etc.
	cout << "<insert town name here>" << endl
		<< "Where would you like to enter?" << endl
		<< "1. Dungeon Select Screen" << endl
		<< "2. Shop" << endl
		<< "3. Inventory" << endl
		<< "4. Save" << endl;
	choice = getSelection(4);
	if (choice == 3)
	{
		gotoInventory(hero1);
	}

}
int Game::getSelection(int maxChoice)
{
	try {
		cout << ">> ";
		cin >> choice;
		if (choice < 1 || choice > maxChoice)
		{
			throw InvalidInput{};
		}

	}
	catch (InvalidInput) {
		cout << "Invalid input, try again." << endl;
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		getSelection(maxChoice);
	}

	return choice;
}
void Game::gotoInventory(Hero hero1)
{
	cout << "Inventory" << endl
		<< "Equiped items:" << endl;
	hero1.inv.displayEquiped();

}