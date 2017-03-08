// Game.cpp
#include "Game.h"
#include "Monster.h"
#include "Battle.h"
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
		startBattle(hero1, 1);
		//to do, call dung select screen
		break;
	case 2:
		//to do, call shop
		break;
	case 3:
		showInventory(hero1);
		break;
	case 4:
		showStats(hero1);
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
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
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
void Game::showInventory(Hero hero1)
{
	cout << "Inventory" << endl
		<< "Equiped items: " << endl;
	hero1.inv.displayEquiped();
	cout << "Inventory items: " << endl;
	hero1.inv.displayInventory();
	cout << "1. Change equiped items"
		<< "2. Go back to town " << endl;
	switch (getSelection(2)){
	case 1:
		hero1.inv.addToEquiped(1);
		break;
	case 2:
		showTown(hero1);
		break;
	}
	showTown(hero1);
}
void Game::showStats(Hero hero1)
{
	cout << hero1.getName() << ", your statistics are: \n";
	hero1.getStats();
	showTown(hero1);
}
int Game::startBattle(Hero hero1, int MonsterLevelSelect)
{
	Battle battle1(hero1, MonsterLevelSelect);
	return 1;
}