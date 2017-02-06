// Menu.cpp

#include "Menu.h"

Menu::Menu()
{
    displayMenu(0);
    
};
int Menu::getSelection()
{
    cout << ">> ";
    cin >> choice;
    return choice;
};
void Menu::displayMenu(int x)
{
  if(x == 0)
  {
      cout << "Welcome to DungeonCrawler!" << endl
          <<"Main Menu"<< endl
          <<"1. New Game" << endl
          <<"2. Load Game" << endl
          <<"3. Settings" << endl
          <<"4. Exit"<<endl;
      displayMenu(getSelection());
  }
  if(x==1)
  {
      character_prof = displayNewGame();
  }
};
int Menu::displayNewGame()
{
    cout << "New Game" << endl
          << "Choose your class" << endl
          << "1. Warrior" << endl
          << "2. Hunter" << endl
          << "3. Mage" << endl;
    return(getSelection());
};