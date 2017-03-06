
#ifndef Item_H
#define Item_H
#include <string.>

class Item {
	int ItemAttackDamage, ItemHP, ItemValue, ItemProfID;
	std::string ItemType, ItemName;
	double ItemAttackSpeed;
public: 
	Item(int AD, double AS, int HP, int Value, int ProfessionID, std::string Type, std::string Name);
	int getItemAD();
	int getItemHP();
	double getitemAS();
	int getItemValue();
	int getItemProfId();
	std::string getItemType();
	std::string getItemName();
};

#endif
