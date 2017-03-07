#include "Monster.h"
#include "libsqlite.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

Monster::Monster(int MonsterLevelSelect){

	
	if (MonsterLevelSelect%5!=0){
		sqlite::sqlite db("dung.db");

		auto cur = db.get_statement();

		cur->set_sql("SELECT [MonsterID] FROM [Monster] WHERE [MonsterLevel]=?;");
		cur->prepare();
		cur->bind(1, MonsterLevelSelect);
		while (cur->step()){
			possibleMonsterIDs.push_back(cur->get_int(0));
		}
		MonsterID = possibleMonsterIDs[RNG(possibleMonsterIDs.size())];
	}
	else {
		sqlite::sqlite db("dung.db");

		auto cur = db.get_statement();
		cur->set_sql("SELECT [MonsterID] FROM [Monster] WHERE [MonsterLevel]=?;");
		cur->prepare();
		cur->bind(1, MonsterLevelSelect);
		cur->step();
		MonsterID = cur->get_int(0);
	}
	sqlite::sqlite db("dung.db");

	auto cur = db.get_statement();

	cur->set_sql("SELECT [MonsterName],[MonsterHP],[MonsterDefence],[MonsterAttackDamage],[MonsterDodge],[MonsterAccuracy],[MonsterExpValue],[MonsterAttackSpeed],[MonsterLevel] FROM [Monster] WHERE [MonsterID]=?;");
	cur->prepare();
	cur->bind(1, MonsterID);
	cur->step();

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
string Monster::getMonsterName() {
	return MonsterName;
}


int Monster::RNG(int maxValue)
{
	int count;
	int RandomNumber;
	
	srand(time(0));
	
	return rand() % (maxValue);
}