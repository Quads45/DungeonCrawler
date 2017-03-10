// Inventory.h

#ifndef Inventory_H
#define Inventory_H
#include <iostream>
#include <vector>
#include <string>
#include "Item.h"
#include "Inventory.h"
class Inventory
{	
	int choice;
	std::vector<Item> equipedItems; //stores equiped items
	std::vector<Item> inventoryItems; // stores items that are in inventory but not equiped
public:
	Inventory();
	Inventory(int charID);
	void initializeEquiped();
	void loadInventory(int charID);
	void displayEquiped();
	void displayInventory();
	void removeFromInventory(); // ie when someone sells item
	void removeFromEquiped(int vectorID); // removes item from equipped and places into inventory
	void addToEquiped(int ItemID);
	void addToInventory(int ItemId);
	int getSelection(int maxCHoice);
	int getEquipedItemID(int vectorIDofItem);
	int countGold();
	void removeFromInventory(int vectorID);
};

#endif Inventory_H