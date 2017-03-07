// Inventory.cpp

#include "Inventory.h"
class InvalidInput{};
using namespace std;
Inventory::Inventory()
{
	// this constructor is used when new game is created
}
Inventory::Inventory(int charID)
{
	loadInventory(charID);
}
void Inventory::loadInventory(int charID)
{
	//to do
	// open database
	// load items from inventory table
	// where character == charID
}
void Inventory::displayEquiped()
{
	// to do
	// test below
	//std::cout << "Equiped: Iron Longsword(+2 AD, +3 AS), Emerald Armour(+15 HP)." << std::endl;
}
void Inventory::addToInventory(int ItemID)
{
	Item item(ItemID);
	inventoryItems.push_back(item);
	//add item
}
void Inventory::addToEquiped(int ItemID)
{
	//moves item from inventory to equiped
	cout << "Which item would you like to move?" << endl;
	getSelection(inventoryItems.size());

	
}
void Inventory::displayInventory()
{
	for (int i=0; i < inventoryItems.size() ; i+=1)
	{
		cout << inventoryItems[i].getItemName() << "(";
		if (inventoryItems[i].getItemAD() != 0){
			cout << "AD: " << inventoryItems[i].getItemAD() << " ";
		}
		if (inventoryItems[i].getitemAS() != 0){
			cout << ", AS: " << inventoryItems[i].getitemAS() << " ";
		}
		if (inventoryItems[i].getItemHP() != 0){
			cout << ", HP: " << inventoryItems[i].getItemHP() << " ";
		}
		cout << ", Value: " << inventoryItems[i].getItemValue() << " ";
		cout << ", Type: " << inventoryItems[i].getItemType() << ")" <<  endl;
	}
}
int Inventory::getSelection(int maxChoice)
{

	try {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
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
