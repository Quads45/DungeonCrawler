#include <iostream>
//#include <stdio.h>
//#include <sqlite3.h>
#include "Hero.h"
#include "Menu.h"
#include "Game.h"
using namespace std;
int main(){
    //int prof;
    Menu menu1;
	int mainDisplayChoice = menu1.displayMenu();
	Game game1;
	string name;
	if (mainDisplayChoice == 1)
	{
		Inventory inv; 
		name = menu1.requestName();
		Hero hero1(name,menu1.displayNewGame());
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
		return 0;
	}
	int a;
	cin >> a;

	
    return 0;
}
