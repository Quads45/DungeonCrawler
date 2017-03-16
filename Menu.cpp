// Menu.cpp
#include "Menu.h"
using namespace std;
class InvalidInput {};
#include "libsqlite.hpp";

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
	//open the database
	sqlite::sqlite db("dung.db");
	auto cur = db.get_statement();
	
	//count how many records have been read
	int RcdCount = 0;
	//create variables to temporarily hold data on the character
	string tempCharName;
	int tempCharLevel;
	int tempCharID;
	//create a query the 
	//read the relevant values from each record of the Character table
	cur->set_sql("SELECT [CharacterID],[CharacterName],[Level_ID] FROM [Character];");
	cur->prepare();

	while (cur->step()) {
		
		//set the variables equal to the 
		tempCharID = cur->get_int(0);
		tempCharName = cur->get_text(1);
		tempCharLevel = cur->get_int(2);
		//print the the character information
		cout << tempCharID << " , " << tempCharName << " , "<< tempCharLevel << endl;
		//add to the count
		RcdCount += 1;
	}

	//get the user to select a save by typing in a character ID
	cout << "Please select a Character to load.";
	// get the user to inpute what save they want to load
	//by calling the getselection function
	return getSelection(RcdCount);
	
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