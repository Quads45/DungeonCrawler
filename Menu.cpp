// Menu.cpp

#include "Menu.h"

Menu::Menu()
{
    if (displayMenu()==1) {displayNewGame();}
    
};
int Menu::getSelection()
{
    cout << ">> ";
    cin >> choice;
    return choice;
};
int Menu::displayMenu()
{
      cout << "Welcome to DungeonCrawler!" << endl
          <<"Main Menu"<< endl
          <<"1. New Game" << endl
          <<"2. Load Game" << endl
          <<"3. Settings" << endl
          <<"4. Exit"<<endl;
      return(getSelection());
};
int Menu::displayNewGame()
{
    cout << "New Game" << endl
          << "Choose your class" << endl
          << "1. Warrior" << endl
          << "2. Hunter" << endl
          << "3. Mage" << endl;
    character_prof = getSelection();
    return character_prof;
};