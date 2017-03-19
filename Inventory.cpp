// Inventory.cpp

#include "Inventory.h"
#include "libsqlite.hpp"
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
	sqlite::sqlite db("dung.db");
	auto cur = db.get_statement();

	// load items from inventory table
	cur->set_sql("SELECT [ItemID], [InventoryQuantity], [InventoryEquipped] FROM [Inventory] WHERE [CharacterID]=?;");
	cur->prepare();
	cur->bind(1, charID);
	// where character == charID
	while (cur->step()) {
		//check whether the character id is correct and then whether its equipped or not
		if (cur->get_int(3) == 1) {
			//so the item is equipped so use the equip item function
			addToEquiped(cur->get_int(0));
		}
		else{
			//the item does not have the equipped status
			//so it is just added to the inventory
			addToInventory(cur->get_int(0));
		}
	}
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
		cout << "Value: " << equipedItems[i].getItemValue() << " ,";
		cout << "Type: " << equipedItems[i].getItemType() << ")" << endl;
	}
	cout << '\n';
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
		addToInventory(equipedItems[0].getItemID());
		equipedItems[0] = inventoryItems[vectorIDInventory];
	}
	else if (inventoryItems[vectorIDInventory].getItemType() == "Bow")
	{
		addToInventory(equipedItems[0].getItemID());
		equipedItems[0] = inventoryItems[vectorIDInventory];
	}
	else if (inventoryItems[vectorIDInventory].getItemType() == "Wand")
	{
		addToInventory(equipedItems[0].getItemID());
		equipedItems[0] = inventoryItems[vectorIDInventory];
	}
	else if (inventoryItems[vectorIDInventory].getItemType() == "Armor")
	{
		addToInventory(equipedItems[1].getItemID());
		equipedItems[1] = inventoryItems[vectorIDInventory];
	}
	if (inventoryItems[vectorIDInventory].getItemType() != "Currency"){
		inventoryItems.erase(inventoryItems.begin() + vectorIDInventory);
	}
	else{
		cout << "You cannot equip gold!"<<endl;
	}
	
}
void Inventory::displayInventory()
{
	int gold = 0;
	int x = 0;
	for (int i=0; i < inventoryItems.size() ; i+=1)
	{
		if (inventoryItems[i].getItemType() != "Currency") {
			x += 1;
			cout << x << ". " << inventoryItems[i].getItemName() << "(";
			if (inventoryItems[i].getItemAD() != 0) {
				cout << "AD: " << inventoryItems[i].getItemAD() << " ,";
			}
			if (inventoryItems[i].getitemAS() != 0) {
				cout << "AS: " << inventoryItems[i].getitemAS() << " ,";
			}
			if (inventoryItems[i].getItemHP() != 0) {
				cout << "HP: " << inventoryItems[i].getItemHP() << " ,";
			}
			cout << "Value: " << inventoryItems[i].getItemValue() << " ,";
			cout << "Type: " << inventoryItems[i].getItemType() << ")" << endl;
		}
		else{
			gold += 1;
		}
	}
	x += 1;
	cout << x << ". " << gold << " gold." << endl;

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
	gold = 0;
	for (int i=0; i < inventoryItems.size(); i++)
	{
		if (inventoryItems[i].getItemType() == "Currency"){
			gold += 1;
		}
	}
	return gold;
}
void Inventory::removeFromInventory(int vectorID)
{
	inventoryItems.erase(inventoryItems.begin() + (vectorID));
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
void Inventory::removeGold(int gold)
{
	for (int i = 0; gold != 0; i++)
	{
		if (inventoryItems[i].getItemType() == "Currency")
		{
			removeFromInventory(i);
			gold -= 1;
		}

	}
}
void Inventory::addToEquiped(int ItemID)
{
	equipedItems.push_back(ItemID);
}