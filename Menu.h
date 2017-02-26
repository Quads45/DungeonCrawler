// Menu.h
#ifndef Menu_H
#define Menu_H
#include <string>
class Menu
{
    int choice;
    int current_position;
public:
    Menu(); 
    int getSelection(int maxChoice);
    int displayMenu();
    int displayNewGame();
	int displayLoadGame();
	int displayHelp();
	std::string tempName;
	std::string requestName();

};


#endif