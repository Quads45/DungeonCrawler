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
	level = 1;
	experience = 0;
	inv.addToInventory(7);
	inv.moveToEquiped(1);
	inv.moveToEquiped(0);
	updateStats();
}
Hero::Hero(int charID)
{
	//open the database
	sqlite::sqlite db("dung.db");
	//create a query and access the table
	auto cur = db.get_statement();
	cur->set_sql("SELECT [CharacterID],[CharacterName],[ProfessionID],[Level_ID],[CharacterExperience] FROM [Character] WHERE [CharacterID] = ?;");
	//execute the query
	cur->prepare();
	//the ? in the query allows us to narrow down the query search to a specific character ID
	cur->bind(1, charID);
	//load the values saved in the database into variables used by the hero class
	heroName = cur->get_text(1);
	profID = cur->get_int(2);
	level = cur->get_int(3);
	experience = cur->get_int(4);

	Inventory inv(charID); //Use diffenent constructor.
						   //This one will load items from database
	updateStats();		   //This will update the stats of the character depending on what level they are.
}
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


void Hero::updateStats(){
	// call function from inventory that returns the 
	// call it again
	Item item1(inv.getEquipedItemID(0));
	Item item2(inv.getEquipedItemID(1));
	sqlite::sqlite db("dung.db");    // open database
	int heroHP, heroAD, levelHP, levelAD, levelDefence, LevelAccuracy, LevelDodge, heroDefence, heroAccuracy, heroDodge;
	double heroAS, LevelAS;
	auto cur = db.get_statement();            // create query   
	cur->set_sql("SELECT [ProfessionHP], [ProfessionAttackDamage], [ProfessionAttackSpeed], [ProfessionDefence], [ProfessionAccuracy], [ProfessionDodge] FROM [Profession] WHERE [ProfessionID]=?;");
	cur->prepare();   // run query
	cur->bind(1, profID); // pass variable to sql queary
	cur->step();
	heroHP = cur->get_int(0);
	heroAD = cur->get_int(1);
	heroAS = cur->get_double(2);
	heroDefence = cur->get_int(3);
	heroAccuracy = cur->get_int(4);
	heroDodge = cur->get_int(5);
	if (true)
	{
		auto cur = db.get_statement();            // create query   
		cur->set_sql("SELECT [LevelAddDefence],[LevelAddAttDmg],[LevelAddDodge],[LevelAddAccuracy],[LevelAddAttSpd],[LevelAddHp] FROM [Level] WHERE [Level_ID]=?;");
		cur->prepare();   // run query
		cur->bind(1, level); // pass variable to sql queary
		cur->step();
		levelDefence = cur->get_int(0);
		levelAD = cur->get_int(1);
		LevelDodge = cur->get_int(2);
		LevelAccuracy = cur->get_int(3);
		LevelAS = cur->get_double(4);
		levelHP = cur->get_int(5);
	}
	hp = heroHP + item1.getItemHP() + item2.getItemHP() + levelHP;
	attack_damage = heroAD + item1.getItemAD() + item2.getItemAD() + levelAD;
	attack_speed = heroAS + item1.getitemAS() + item2.getitemAS() + LevelAS;
	defence = heroDefence + levelDefence;
	accuracy = heroAccuracy + LevelAccuracy;
	dodge = heroDodge + LevelAccuracy;
}


