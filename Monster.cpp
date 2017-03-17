#include "Monster.h"
#include "libsqlite.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

Monster::Monster(int MonsterLevelSelect){

	//if the current level isnt modulus of 5 load a normal monster
	if (MonsterLevelSelect%5!=0){
		//open the database
		sqlite::sqlite db("dung.db");
		//create a query
		auto cur = db.get_statement();
		cur->set_sql("SELECT [MonsterID] FROM [Monster] WHERE [MonsterLevel]=?;");
		//execute the query
		cur->prepare();
		//get monsters that have a monster level equal to the
		//MonsterLevelSelect
		cur->bind(1, MonsterLevelSelect);
		//add all the monsters with the level to a vector
		while (cur->step()){
			possibleMonsterIDs.push_back(cur->get_int(0));
		}
		//select one of those monster using a random number generator
		MonsterID = possibleMonsterIDs[RNG(possibleMonsterIDs.size())];
	}
	else {			//else get a boss from the database
					//bosses are every 5 levels 
		//open the database
		sqlite::sqlite db("dung.db");
		//create a query
		auto cur = db.get_statement();
		cur->set_sql("SELECT [MonsterID] FROM [Monster] WHERE [MonsterLevel]=?;");
		//execute the query
		cur->prepare();
		//get the boss where there MonsterLevel==MonsterLevelSelect
		cur->bind(1, MonsterLevelSelect);
		cur->step();
		//there is only one boss for every 5th level 
		//so a random selection isnt needed
		//get the monsters id
		MonsterID = cur->get_int(0);
	}
	//load the rest of the monsters information from the database
	//open the database
	sqlite::sqlite db("dung.db");

	//create a query
	auto cur = db.get_statement();
	cur->set_sql("SELECT [MonsterName],[MonsterHP],[MonsterDefence],[MonsterAttackDamage],[MonsterDodge],[MonsterAccuracy],[MonsterExpValue],[MonsterAttackSpeed],[MonsterLevel] FROM [Monster] WHERE [MonsterID]=?;");
	//execute the query
	cur->prepare();
	//find the record with the monsterID equal to the one found earlier
	cur->bind(1, MonsterID);
	cur->step();
	//load all the monster information into vairables ready for use
	//by the battle
	MonsterName = cur->get_text(0);
	MonsterHP = cur->get_int(1);
	MonsterDefence = cur->get_int(2);
	MonsterAttackDamage = cur->get_int(3);
	MonsterDodge = cur->get_int(4);
	MonsterAccuracy = cur->get_int(5);
	MonsterExpValue = cur->get_int(6);
	MonsterAttackSpeed = cur->get_double(7);
	MonsterLevel = cur->get_int(8);
}

// Random Time Generator.cpp : Defines the entry point for the console application.
//


int Monster::RNG(int maxValue)
{
	//this random from a book
	//C++ Programming for the absolute beginner 2nd edition
	//by Mark Lee
	//Page 74
	int seed = static_cast<int>(time(0));
	srand(seed);
	return rand() % (maxValue);
}