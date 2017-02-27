// Inventory.cpp

#include "Inventory.h"

Inventory::Inventory()
{
	// add starting items to inventory(basic sword/staff/crossbow and cloth armour?)
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
	std::cout << "Equiped: Iron Longsword(+2 AD, +3 AS), Emerald Armour(+15 HP)." << std::endl;
}
