#ifndef Item_H
#define Item_H
#include <string>

class Item {
	int ItemAttackDamage, ItemHP, ItemValue, ItemProfID, ItemID;
	std::string ItemType, ItemName;
	double ItemAttackSpeed;
public: 
	Item(int ItemID);
	int getItemAD();
	int getItemHP();
	double getitemAS();
	int getItemValue();
	int getItemProfId();
	std::string getItemType();
	std::string getItemName();
	int getItemID() { return ItemID; };
};

#endif
