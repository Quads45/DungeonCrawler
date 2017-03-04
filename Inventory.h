// Inventory.h

#ifndef Inventory_H
#define Inventory_H
#include <iostream>
#include <vector>
#include <string>

class Inventory
{
	std::vector<int> equipedItemsID; //change it to multidimension vectors later
	std::vector<int> inventoryItemsID;
public:
	Inventory();
	Inventory(int charID);
	void initializeEquiped();
	void loadInventory(int charID);
	void displayEquiped();
	void displayInventory();
	void removeFromInventory(); // ie when someone sells item
	void removeFromEquiped(); // removes item from equipped and places into inventory
};

#endif Inventory_H