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
	cout << "You have arrived at Aynor, " << hero1.getName() << "." << endl
		<< "[------------------------------------]"<<"\n\n\n\n\n"
		<< "          lore placeholder            "<<"\n\n\n\n\n"
		<< "[------------------------------------]\n\n";
	showTown(hero1);
}
void Game::showTown(Hero hero1)
{
	//to do
	//ask user what he would like to do
	//shop/dungeone select/view inv etc.
	cout << "Aynor" << endl
		<< "Where would you like to enter?" << endl
		<< "1. Dungeon Select Screen" << endl
		<< "2. Shop" << endl
		<< "3. Inventory" << endl
		<< "4. Stats" << endl
		<< "5. Save" << endl;
	choice = getSelection(5);
	switch (choice)	
	{
	case 1:
		//to do, call dung select screen
		break;
	case 2:
		//to do, call shop
		break;
	case 3:
		gotoInventory(hero1);
		break;
	case 4:
		hero1.getStats();
		break;
	case 5:
		//to do, call save function
		break;
	default:
		break;
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