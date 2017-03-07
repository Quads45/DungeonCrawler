#include "Item.h"
#include "libsqlite.hpp"
Item::Item(int ItemID) {
	sqlite::sqlite db("dung.db");
	
	auto cur = db.get_statement();
	cur->set_sql("SELECT [ItemAttackDamage],[ItemAttackSpeed],[ItemHP],[ItemType],[ItemValue],[ItemName],[ProfessionID] FROM [Items] WHERE [ItemID]=?;");
	cur->prepare();
	cur->bind(1, ItemID);
	cur->step();
	ItemAttackDamage = cur->get_int(0);
	ItemAttackSpeed = cur->get_double(1);
	ItemHP = cur->get_int(2);
	ItemType = cur->get_text(3);
	ItemValue = cur->get_int(4);
	ItemName = cur->get_text(5);
	ItemProfID = cur->get_int(6);

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

