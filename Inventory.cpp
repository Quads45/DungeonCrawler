// Inventory.cpp

#include "Inventory.h"
#include "libsqlite.hpp"
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
	sqlite::sqlite db("dung.db");
	auto cur = db.get_statement();

	// load items from inventory table
	cur->set_sql("SELECT [ItemID],[InventoryQuantity],[InventoryEquipped] FROM [Inventory] WHERE [CharacterID] = ?;");
	cur->prepare(); 
	cur->bind(1, charID);
	// where character == charID
	while (cur->step()) {
		//check whether the character id is correct and then whether its equipped or not
		if (cur->get_int(3) == 1) {
			//so the item is equipped so use the equip item function
			addToEquiped(cur->get_int(1));
		}
		else{
			//the item does not have the equipped status
			//so it is just added to the inventory
			addToInventory(cur->get_int(1));
		}
	}
}
void Inventory::displayEquiped()
{
	// to do
	// test below
	//std::cout << "Equiped: Iron Longsword(+2 AD, +3 AS), Emerald Armour(+15 HP)." << std::endl;
	for (int i = 0; i < equipedItems.size(); i++)
	{
		cout << equipedItems[i].getItemName() << endl;
	}
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
int Inventory::getEquipedItemID(int vectorIDofItem)
{
	// takes in the place of item where it is in vector and 
	// returns the ItemID, which can be used to refernce it from database
	return equipedItems[vectorIDofItem].getItemID();
}
void Inventory::removeFromEquiped(int vectorID)
{
	// removes item from the equiped items vector at the position of vectorID
	equipedItems.erase(equipedItems.begin() + vectorID);
}
int Inventory::countGold()
{
	int gold;
	for (int i; i < inventoryItems.size(); i++)
	{
		if (inventoryItems[i].getItemType() == "Currency"){
			gold += 1;
		}
	}
	return gold;
}
void Inventory::removeFromInventory(int vectorID)
{
	inventoryItems.erase(inventoryItems.begin() + (vectorID+1));
}