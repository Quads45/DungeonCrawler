#include "Item.h"

Item::Item(int AD, double AS, int HP, int Value, int ProfessionID, std::string Type, std::string Name) {

	ItemAttackDamage = AD;
	ItemAttackSpeed = AS;
	ItemHP = HP;
	ItemValue = Value;
	ItemType = Type;
	ItemName = Name;
	ItemProfID = ProfessionID;

}
int Item::getItemAD() {
	return ItemAttackDamage;
}
double Item::getitemAS() {
	return ItemAttackSpeed;
}
int Item::getItemHP() {
	return ItemHP;
}
int Item::getItemValue() {
	return ItemValue;
}
std::string Item::getItemType() {
	return ItemType;
}
std::string Item::getItemName() {
	return ItemName;
}
int Item::getItemProfId() {
	return ItemProfID;
}

