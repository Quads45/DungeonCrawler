// Shop.cpp

#include "Shop.h"
#include <iostream>
#include "Item.h"
using namespace std;
string yes;
string no;
string n;
int value=0	;
int i;
//this  construc is use to create the actual shop
Shop::Shop(Hero hero1)
{
	//Welcome message
	cout << "Welcome traveler ! \n"
		<< "Do you want to buy something?\n"
		<< "If you want , i can present my shop and my valueable weapons. \n"
		<< "(write yes to see the shop, or no to go bag to town).\n";
	//User choice of viewing the shop or to leave it and get back to town
	cin >> n;
	if (n == "yes")
	{
		cout << "Would you like to buy or sell?" << endl;
		string xstring;
		cin >> xstring;
		if (xstring == "buy")
			displayBuy(hero1);
		else if (xstring == "sell")
			displaySell(hero1);
	}


	//hero1.inv.addToInventory();
}
void Shop::displayBuy(Hero hero1) {
	sqlite::sqlite db("dung.db");

	auto cur = db.get_statement();
	cur->set_sql("SELECT [ItemID] FROM [Items] WHERE [ProfessionID]=? AND [ItemLevelReq]=?;");
	cur->prepare();
	cur->bind(1, hero1.getHeroProfID());
	cur->bind(2, 1);
	
	
	cur->step();
	Item item1(cur->get_int(0));
	cur->step();
	Item item2(cur->get_int(0));
	cur->step();
	Item item3(cur->get_int(0));
	cur->step();
	Item item4(cur->get_int(0));
	cout << item1.getItemName()<<" "<<"that costs:"
		<< item1.getItemValue()<<" "<<"gold"
		<<" "<<"and has an attack of:"<< item1.getItemAD() << endl;

	cout << item2.getItemName() << " " << "that costs:" << " "
		<< item2.getItemValue() << " " << "gold"<< " "
		<< "and gives you" << " " << item2.getItemHP() << " " << "HP" << endl;
	
	cout << item3.getItemName() << " " << "that costs:"
		<< item3.getItemValue() << " " << "gold"
		<< " " << "and has an attack of:" << item3.getItemAD() << endl;
	
	cout << item4.getItemName() << " " << "that costs:" << " "
		<< item4.getItemValue() << " " << "gold"<< " "
		<< "and gives you" << " " << item4.getItemHP() << " " << "HP" << endl;

	cout << "So traveler, what do you want to buy?\n";
	cout << "You have" << endl;
	cin >> ;
	if (gold < Value)
	{
		cout << "You don't hsve enough gold to buy this itme!"
	}
	else 
		hero1.inv.addToInventory
}

void Shop::displaySell(Hero hero1){

	hero1.inv.displayInventory();
	int choice;
	cout << "What item do you like to sell ?\n";
	cin >> choice;
	hero1.inv.removeFromInventory(choice-1);
	value = hero1.inv.getValue(choice - 1);
	for (i = 1; i <= value; i++)
	{
		hero1.inv.addToInventory(7);
	} 
	hero1.inv.displayInventory();
	cin >> choice;
}