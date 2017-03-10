// Hero.cpp
#include<iostream>
#include "Hero.h"
using namespace std;
Hero::Hero(string name, int profession)
{
	sqlite::sqlite db("dung.db");    // open database

	auto cur = db.get_statement();            // create query   
	cur->set_sql("SELECT [ProfessionHP],[ProfessionDefence],[ProfessionDodge],[ProfessionAccuracy],[ProfessionAttackDamage],[ProfessionAttackSpeed] FROM [Profession] WHERE [ProfessionID]=?;");
	cur->prepare();   // run query
	cur->bind(1, profession); // pass variable to sql queary
	cur->step();
	heroName = name;
	profID = profession;
	setStats(cur->get_int(0), cur->get_int(1), cur->get_int(2), cur->get_int(3), cur->get_int(4), cur->get_double(5));
    if (profession == Hero::Warrior){
        cout << "You have chosen warrior."<< endl;
		inv.addToInventory(1);
		inv.addToInventory(6);
    }
    if (profession == Hero::Hunter){
        cout << "You have chosen hunter."<< endl;
		inv.addToInventory(2);
		inv.addToInventory(5);
    }
	if (profession == Hero::Mage) {
		cout << "You have chosen mage." << endl;
		inv.addToInventory(3);
		inv.addToInventory(4);
	};
	Inventory inv; // use standard constructor, unchanged if starting new game
}
Hero::Hero(int charID)
{
	Inventory inv(charID); //Use diffenent constructor.
						   //This one will load items from database

}
void Hero::setStats(int newHp, int newDefence,int newDodge, int newAccuracy, int newAD, double newAS)
{
	hp=newHp;
    attack_damage=newAD;
    attack_speed = newAS;
	defence = newDefence;
	dodge = newDodge;
	accuracy = newAccuracy;
}
void Hero::getStats()
{
    cout << "HP: " << hp<<'\n';
    cout << "AD: " << attack_damage<<'\n';
    cout << "AS: " << attack_speed <<'\n' << '\n';
	cout << "Defence: " << defence << '\n';
	cout << "Dodge: " << dodge << '\n';
	cout << "Accuracy: " << accuracy << '\n' << '\n';
}


void Hero::removeEquipedItem(int vectorID){
	Item item(inv.getEquipedItemID(vectorID));
	hp -= item.getItemHP();
	attack_damage -= item.getItemAD();
	attack_speed -= item.getitemAS();
	inv.removeFromEquiped(vectorID);
	inv.addToInventory(item.getItemID());
}
