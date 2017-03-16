// Inventory.cpp

#include "Inventory.h"
class InvalidInput{};
using namespace std;
Inventory::Inventory()
{
	Item item(7);
	
	equipedItems.push_back(item);
	equipedItems.push_back(item);
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
	for (int i = 0; i < equipedItems.size(); i += 1)
	{
		cout << i + 1 << ". " << equipedItems[i].getItemName() << "(";
		if (equipedItems[i].getItemAD() != 0){
			cout << "AD: " << equipedItems[i].getItemAD() << " ,";
		}
		if (equipedItems[i].getitemAS() != 0){
			cout << "AS: " << equipedItems[i].getitemAS() << " ,";
		}
		if (equipedItems[i].getItemHP() != 0){
			cout << "HP: " << equipedItems[i].getItemHP() << " ,";
		}
		cout << ", Value: " << equipedItems[i].getItemValue() << " ";
		cout << ", Type: " << equipedItems[i].getItemType() << ")" << endl;
	}
}
void Inventory::addToInventory(int ItemID)
{
	Item item(ItemID); //  creates item using the ID given when called the function
	inventoryItems.emplace_back(item);//  add the item to the vector
	//add item to inventory using ID

}
void Inventory::moveToEquiped(int vectorIDInventory)
{	

	if (inventoryItems[vectorIDInventory].getItemType() == "Sword")
	{
		equipedItems[0] = inventoryItems[vectorIDInventory];
	}
	else if (inventoryItems[vectorIDInventory].getItemType() == "Bow")
	{
		equipedItems[0] = inventoryItems[vectorIDInventory];
	}
	else if (inventoryItems[vectorIDInventory].getItemType() == "Wand")
	{
		equipedItems[0] = inventoryItems[vectorIDInventory];
	}
	else if (inventoryItems[vectorIDInventory].getItemType() == "Armor")
	{
		equipedItems[1] = inventoryItems[vectorIDInventory];
	}
	inventoryItems.erase(inventoryItems.begin() + vectorIDInventory);

	
}
void Inventory::displayInventory()
{
	for (int i=0; i < inventoryItems.size() ; i+=1)
	{
		cout << i+1 <<". " << inventoryItems[i].getItemName() << "(";
		if (inventoryItems[i].getItemAD() != 0){
			cout << "AD: " << inventoryItems[i].getItemAD() << " ,";
		}
		if (inventoryItems[i].getitemAS() != 0){
			cout << "AS: " << inventoryItems[i].getitemAS() << " ,";
		}
		if (inventoryItems[i].getItemHP() != 0){
			cout << "HP: " << inventoryItems[i].getItemHP() << " ,";
		}
		cout << "Value: " << inventoryItems[i].getItemValue() << " ,";
		cout << "Type: " << inventoryItems[i].getItemType() << ")" << endl;
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
int Inventory::countGold()
{
	// Sequential search
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
int Inventory::getInventorySize()
{
	return inventoryItems.size();
}
int Inventory::getItemValue(int vectorPosition)
{
	return inventoryItems[vectorPosition].getItemValue();
}
int Inventory::getInventoryItemID(int vectorPosition){
	return inventoryItems[vectorPosition].getItemID();
}