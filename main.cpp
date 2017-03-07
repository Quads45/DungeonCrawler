#include <iostream>
#include "sqlite3/sqlite3.h"
#include "Hero.h"
#include "Menu.h"
#include "Game.h"
#include "Monster.h"
using namespace std;
int main(){
    Menu menu1;
	int mainDisplayChoice = menu1.displayMenu();
	Game game1;
	string name;
	if (mainDisplayChoice == 1)
	{
		name = menu1.requestName();
		Hero hero1(name,menu1.displayNewGame());
		Monster monster1(1);
		cout << monster1.getMonsterName() << endl;
		game1.startNewGame(hero1);
	}
	else if (mainDisplayChoice == 2)
	{
		menu1.displayLoadGame();
		//get saved stats from data base
		//create character after this if statement
	}
	else if (mainDisplayChoice == 3)
	{
		menu1.displayHelp();
	}
	else if (mainDisplayChoice == 4)
	{
		cout << "exit" << endl;
	}
	int a;
	cin >> a;

	
    return 0;
}
