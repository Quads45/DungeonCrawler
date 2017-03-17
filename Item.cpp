#include "Item.h"
#include "libsqlite.hpp"
Item::Item(int ItemSelectID) {
	//open the database
	sqlite::sqlite db("dung.db");
	//create a query
	auto cur = db.get_statement();
	cur->set_sql("SELECT * FROM [Items] WHERE [ItemID]=?;");
	//execute the query
	cur->prepare();
	//bind will look for the items where the ItemID==ItemSelectID (?)
	cur->bind(1, ItemSelectID);
	cur->step();
	//load the corresponding values from the database into 
	//the relevant variables
	ItemID = cur->get_int(0);
	ItemAttackDamage = cur->get_int(1);
	ItemAttackSpeed = cur->get_double(2);
	ItemHP = cur->get_int(3);
	ItemType = cur->get_text(4);
	ItemValue = cur->get_int(5);
	ItemName = cur->get_text(6);
	ItemProfID = cur->get_int(7);

}

