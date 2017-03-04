// Menu.cpp
#include "Menu.h"
using namespace std;
class InvalidInput {};
Menu::Menu()
{
    
}
int Menu::getSelection(int maxChoice)
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
int Menu::displayMenu()
{
      cout << "Welcome to DungeonCrawler!" << endl
          <<"Main Menu"<< endl
          <<"1. New Game" << endl
          <<"2. Load Game" << endl
          <<"3. Help" << endl
          <<"4. Exit"<<endl;
      return(getSelection(4));
}
int Menu::displayNewGame()
{
	cout << "New Game" << endl
		<< "Choose your class" << endl
		<< "1. Warrior" << endl
		<< "2. Hunter" << endl
		<< "3. Mage" << endl;
	return getSelection(3);
}
int Menu::displayLoadGame()
{
	//To do..
	return 0;
}
int Menu::displayHelp()
{
	//To do..
	return 0;
}
string Menu::requestName()
{
	cout << "What is your name? ";
	cin >> tempName;
	return tempName;
}