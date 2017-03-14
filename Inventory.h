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
	void moveToEquiped(int ItemID);
	void addToInventory(int ItemId);
	int getSelection(int maxCHoice);
	int getEquipedItemID(int vectorIDofItem);
	int countGold();
	int getInventoryItemID(int vectorPosition);
	int getInventorySize();	
	void removeFromInventory(int vectorID);
	int getItemValue(int vectorPosition);
};

#endif Inventory_H