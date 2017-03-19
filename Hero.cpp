// Hero.cpp
#include<iostream>
#include "Hero.h"
using namespace std;
Hero::Hero(string name, int profession)
{
	// Hero class constructor
	// This one is used when creating a new character (new game)

	// assign name and profession given by player to the class members
	heroName = name;
	profID = profession;
	// depending on their class give them starting items 
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
	// start character at level 1 and 0 experience
	level = 1;
	experience = 0;
	// gives player 1 gold coin
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
	cur->set_sql("SELECT [CharacterName], [ProfessionID], [Level_ID], [CharacterExperience] FROM [Character] WHERE [CharacterID]=?;");
	//execute the query
	cur->prepare();
	//the ? in the query allows us to narrow down the query search to a specific character ID
	cur->bind(1, charID);
	cur->step();
	//load the values saved in the database into variables used by the hero class
	heroName = cur->get_text(0);
	profID = cur->get_int(1);
	level = cur->get_int(2);
	experience = cur->get_int(3);

	Inventory inv(charID); //Use diffenent constructor.
						   //This one will load items from database
	updateStats();		   //This will update the stats of the character depending on what level they are.

						   

}


void Hero::getStats()
{
	// display each stat
	cout << "HP: " << hp << '\n';
	cout << "AD: " << attack_damage << '\n';
	cout << "AS: " << attack_speed << '\n' << '\n';
	cout << "Defence: " << defence << '\n';
	cout << "Dodge: " << dodge << '\n';
	cout << "Accuracy: " << accuracy << '\n' << '\n';
}


void Hero::updateStats(){
	// create two new items witht the same ID as the ones equiped
	Item item1(inv.getEquipedItemID(0));
	Item item2(inv.getEquipedItemID(1));
	sqlite::sqlite db("dung.db");    // open database

	// temporary variables hold on to data collected from database

	int heroHP, heroAD, levelHP, levelAD, levelDefence, LevelAccuracy, LevelDodge, heroDefence, heroAccuracy, heroDodge;
	double heroAS, LevelAS;

	auto cur = db.get_statement();            // create query   
	// get all stats from Profession table where profession ID is equal the the one chosen by the player
	cur->set_sql("SELECT [ProfessionHP], [ProfessionAttackDamage], [ProfessionAttackSpeed], [ProfessionDefence], [ProfessionAccuracy], [ProfessionDodge] FROM [Profession] WHERE [ProfessionID]=?;");
	cur->prepare();   // run query
	// binding the profID variable (chosen by the player) to the sql query above (where the question mark is)
	cur->bind(1, profID); // pass variable to sql queary
	cur->step(); // go to the first row of data

	// assign data from the query to the temporar
	heroHP = cur->get_int(0);
	heroAD = cur->get_int(1);
	heroAS = cur->get_double(2);
	heroDefence = cur->get_int(3);
	heroAccuracy = cur->get_int(4);
	heroDodge = cur->get_int(5);
	if (true)
	{
		// this code  is in if statement to by pass errors created by not being able to exit the sql query
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
	// add the hero stats from database to the equiped item stats and the level stats from the databse
}
void Hero::addExp(int expValue)
{
	sqlite::sqlite db("dung.db");    // open database
	auto cur = db.get_statement();            // create query   
	cur->set_sql("SELECT * FROM [Level] WHERE [Level_ID]=?;");
	cur->prepare();   // run query
	cur->bind(1, level); // pass variable to sql queary
	cur->step();
	int expReq = cur->get_int(1);
	if ((experience + expValue) > expReq)
	{
		experience = (experience + expValue) - expReq;
		level += 1;
		cout << "You leveled up!" << endl
			<< "You gained:" << endl
			<< "HP: +" << cur->get_int(7) << endl
			<< "AD: +" << cur->get_int(3) << endl
			<< "AS: +" << cur->get_double(6) << endl
			<< "Defence: +" << cur->get_int(2) << endl
			<< "Dodge: +" << cur->get_int(4) << endl
			<< "Accuracy: +" << cur->get_int(5) << endl;
	}
	else
	{
		experience += expValue;
	}
}

