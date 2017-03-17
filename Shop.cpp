// Shop.cpp

#include "Shop.h"
#include <iostream>

using namespace std;
string yes;
string no;
string n;
int value=0	;
int i;
//this  construc is use to create the actual shop
Shop::Shop(Hero &hero1)
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
}
void Shop::displayBuy(Hero &hero1) {
	sqlite::sqlite db("dung.db");

	auto cur = db.get_statement();
	cur->set_sql("SELECT [ItemID] FROM [Items] WHERE [ProfessionID]=? AND [ItemLevelReq]=?;");
	cur->prepare();
	cur->bind(1, hero1.getHeroProfID());
	cur->bind(2, 1);
	while (cur->step()){
		Item item1(cur->get_int(0));
		shopItems.push_back(item1);
	}
	
	for (int i = 0; i < shopItems.size();++i){
		cout << i + 1 << ". " << shopItems[i].getItemName() << "(";
		if (shopItems[i].getItemAD() != 0){
			cout << "AD: " << shopItems[i].getItemAD() << " ,";
		}
		if (shopItems[i].getitemAS() != 0){
			cout << "AS: " << shopItems[i].getitemAS() << " ,";
		}
		if (shopItems[i].getItemHP() != 0){
			cout << "HP: " << shopItems[i].getItemHP() << " ,";
		}
		cout << "Value: " << shopItems[i].getItemValue() << " ,";
		cout << "Type: " << shopItems[i].getItemType() << ")" << endl;
	}
	cin >> choice;
	choice -= 1;
	if (hero1.inv.countGold() < shopItems[choice].getItemValue())
	{
		cout << "You don't have enough gold to buy this itme!" << endl;
		cout << shopItems[choice].getItemName() << " costs " << shopItems[choice].getItemValue() << ", you have " << hero1.inv.countGold() << " gold." << endl;
	}
	else {		
	
		hero1.inv.addToInventory(shopItems[choice].getItemID());
		cout << shopItems[choice].getItemValue();
		int a;
		cin >> a;
		hero1.inv.removeGold(shopItems[choice].getItemValue());
	}
}

void Shop::displaySell(Hero &hero1){

	hero1.inv.displayInventory();
	int choice;
	cout << "What item do you like to sell ?\n";
	cin >> choice;
	value = hero1.inv.getItemValue(choice - 1);
	hero1.inv.removeFromInventory(choice-1);
	for (i = 1; i <= value; i++)
	{
		hero1.inv.addToInventory(7);
	} 
	hero1.inv.displayInventory();
	cin >> choice;
}
