#include "Item.h"
#include "libsqlite.hpp"
Item::Item(int ItemSelectID) {
	sqlite::sqlite db("dung.db");
	
	auto cur = db.get_statement();
	cur->set_sql("SELECT * FROM [Items] WHERE [ItemID]=?;");
	cur->prepare();
	cur->bind(1, ItemSelectID);
	cur->step();
	ItemID = cur->get_int(0);
	ItemAttackDamage = cur->get_int(1);
	ItemAttackSpeed = cur->get_double(2);
	ItemHP = cur->get_int(3);
	ItemType = cur->get_text(4);
	ItemValue = cur->get_int(5);
	ItemName = cur->get_text(6);
	ItemProfID = cur->get_int(7);

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

