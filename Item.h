#ifndef Item_H
#define Item_H
#include <string>

class Item {
	//create variables for each field in the item table
	//so they can be called by the functions below
	int ItemAttackDamage, ItemHP, ItemValue, ItemProfID, ItemID;
	std::string ItemType, ItemName;
	double ItemAttackSpeed;
public: 
	//create a constructor
	Item(int ItemID);
	//create functions which retrieves specific data on an item.
	int getItemAD() { return ItemAttackDamage; };
	int getItemHP() { return ItemHP; };
	double getitemAS() { return ItemAttackSpeed; };
	int getItemValue() { return ItemValue; };
	int getItemProfId() { return ItemProfID; };
	std::string getItemType() { return ItemType; };
	std::string getItemName() { return ItemName; };
	int getItemID() { return ItemID; };
};

#endif
