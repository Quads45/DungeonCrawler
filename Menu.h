// Menu.h
#ifndef Menu_H
#define Menu_H
#include<iostream>
#include <string>
class Menu
{
    int choice;
    int current_position;
public:
    Menu(); 
    int getSelection(int maxChoice); //Recieves input and checks for error	s
    int displayMenu();
    int displayNewGame();
	int displayLoadGame();
	int displayHelp();
	std::string tempName;
	std::string requestName();

};


#endif