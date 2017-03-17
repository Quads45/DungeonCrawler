//Battle.cpp
#include "Battle.h"
#include "libsqlite.hpp"
#include "windows.h"
#include "MMSystem.h"

using namespace std;


Battle::Battle(Hero &hero1,int monsterLevel) // constructor
{
	Monster monster1(monsterLevel);
	Spell spell1(0, hero1.getHeroProfID());
	Spell spell2(1, hero1.getHeroProfID());
	currentSpells.push_back(spell1);
	currentSpells.push_back(spell2);
	loadMonsterSpell(monster1);
	startOfBattle(hero1, monster1);
	
}

char Battle::firstAttack()
{
	// compares the attack speed of hero with monster
	// returns whos turn is first
	
	if (curHero1.AS >= curMonster1.AS) {
		return('h');
	}
	else {
		return('m');
	}
}

void Battle::startOfBattle(Hero &hero1, Monster monster1)
{
	//Clear Console
	system("cls");
	
	//Dungeon level
	cout << "==============================================================================" << "\n DUNGEON - Level " << monster1.getMonsterLevel() 
		<< "\n==============================================================================" << "\n" << endl;
	//Intro
	cout << "As you walk along you stop and notice a level " << monster1.getMonsterLevel() << " " << monster1.getMonsterName() << " has appeared! " << "\n" << endl;
	
	//Display Monster
	dispImage(monster1);

	//Monster Sound
	playSound(monster1);
	
	//In Battle Stats
	curHero1.HP = hero1.getHeroHP();
	curHero1.AD = hero1.getHeroAD();
	curHero1.AS = hero1.getHeroAS();
	curHero1.defence = hero1.getHeroDefence();
	curHero1.accuracy = hero1.getHeroAccuracy();
	curHero1.dodge = hero1.getHeroDodge();
	curMonster1.HP = monster1.getMonsterHP();
	curMonster1.AD = monster1.getMonsterAD();
	curMonster1.AS = monster1.getMonsterAS();
	curMonster1.defence = monster1.getMonsterDefence();
	curMonster1.accuracy = monster1.getMonsterAccuracy();
	curMonster1.dodge = monster1.getMonsterDodge();
	gameEngine(hero1, monster1);
}


double Battle::getAccuracy(char whoseTurn)
{
	// Depending on whos turn it is, check the accuracy of the hero with the dodge of the monster and vice versa
	//Returns chance of hit
	if (whoseTurn == 'h')
	{
		if (curMonster1.dodge > curHero1.accuracy)
		{
			return (0);
		}
		return((curHero1.accuracy - curMonster1.dodge));
	}
	else
	{
		if (curHero1.dodge > curMonster1.accuracy)
		{
			return (0);
		}
		return((curMonster1.accuracy - curHero1.dodge));
	}
	


}
void Battle::gameEngine(Hero &hero1, Monster monster1)
{
	while ((curHero1.HP > 1) && (curMonster1.HP>1)) {
		if (firstAttack()=='h') {
			HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
			heroTurn(hero1, monster1);
			if (curMonster1.HP > 0) {
				HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
				monsterTurn(hero1, monster1);
				cin.get();
			}
		}
		else {
			HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
			monsterTurn(hero1, monster1);
			cin.get();
			if (curHero1.HP > 0) {
				HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
				heroTurn(hero1, monster1);

			}

		}
	}
	if (curMonster1.HP > 0){
		cout << "You lost, have another go. " << endl;
	}
	else
	{
		dropLoot(monster1, hero1);
		cout << "\nYou won the battle." << endl;
		hero1.addExp(monster1.getMonsterExpValue()); //function to do, in hero class
		cout << "You have gained " << monster1.getMonsterExpValue() << " EXP." << endl;
	}
	string x;
	cin >> x;
	system("cls");
	system("Color 7");
}

//Monster ASCII
void Battle::dispImage(Monster monster1)
{
	if (monster1.getMonsterName() == "Zombie") {
		cout << "           		.....    \n" 
		     << "                   C C  /   \n" 
			 << "                  /<   /    \n"
			 << "   ___ __________/_#__=o    \n"
			 << "  /(- /(\_\________   \     \n"
			 << "  \ ) \ )_      \o     \    \n"
			 << "  /|\ /|\       |'     |    \n"
			 << "                |     _|    \n"
			 << "                /o   __\    \n"
			 << "               / '     |    \n"
			 << "              / /      |    \n"
			 << "             /_/\______|    \n"
			 << "            (   _(    <     \n"
			 << "             \    \    \    \n"
			 << "              \    \    |   \n"
			 << "               \____\____\  \n"
			 << "               ____\_\__\_\ \n"
			 << "             /`   /`     o\ \n"
			 << "             |___ |_______| \n" << endl;
	}
	/*if (monster1.getMonsterName() == "Orc") {
		;
	}
	if (monster1.getMonsterName() == "Troll") {
		;
	}
	if (monster1.getMonsterName() == "Big Foot") {
		;
	}
	if (monster1.getMonsterName() == "Vampire") {
		;
	}
	if (monster1.getMonsterName() == "Gremlin") {
		;
	}*/
}


//Monster Sounds

void Battle::playSound(Monster monster1)
{
	if (monster1.getMonsterName() == "Zombie") {
		PlaySound(TEXT("zombie.wav"), NULL, SND_SYNC);
	}
	if (monster1.getMonsterName() == "Orc") {
		PlaySound(TEXT("orc.wav"), NULL, SND_SYNC);
	}
	if (monster1.getMonsterName() == "Troll") {
		PlaySound(TEXT("troll.wav"), NULL, SND_SYNC);
	}
	if (monster1.getMonsterName() == "Big Foot") {
		PlaySound(TEXT("bigfoot.wav"), NULL, SND_SYNC);
	}
	if (monster1.getMonsterName() == "Vampire") {
		PlaySound(TEXT("vampire.wav"), NULL, SND_SYNC);
	}
	if (monster1.getMonsterName() == "Gremlin") {
		PlaySound(TEXT("gremlin.wav"), NULL, SND_SYNC);
	}
}




void Battle::heroTurn(Hero hero1, Monster monster1)
{	//hero and monster defence
	int choice;
	
	
	cout << "It is your turn " << hero1.getName() << " Please choose your turn Wisely! ..." << endl;
	cout << "Select your ability:" << endl;
	for (int i=0; i < currentSpells.size(); i++) {
		cout << i+1 << ". " << currentSpells[i].getSpellName() << endl;
	}

	cin >> choice;
	choice -= 1;

	int hpDamage=0;
	int accuracyDamage=0;
	int attDmgDamage=0;
	double attSpdDamage=0;
	int DefenceDamage=0;
	int DodgeDamage=0;
	cout  << currentSpells[choice].getSpellEffect() << endl;
	if (monster1.RNG(100) <= getAccuracy('h')) {
		hpDamage = curHero1.AD + currentSpells[choice].getSpellHPDamage();
		accuracyDamage = curHero1.AD + currentSpells[choice].getSpellAccuracyDamage();
		attDmgDamage = curHero1.AD + currentSpells[choice].getSpellAttDmgDamage();
		attSpdDamage = curHero1.AD + currentSpells[choice].getSpellAttSpdDamage();
		DefenceDamage = curHero1.AD + currentSpells[choice].getSpellDefenceDamage();
		DodgeDamage = curHero1.AD + currentSpells[choice].getSpellDodgeDamage();
		
		cout << "You hit for (" << hpDamage << " HP) damage!" << endl;
		double percentHP = curMonster1.HP / monster1.getMonsterHP() * 100;
		cout << monster1.getMonsterName() << " took " << hpDamage*(1 - (curMonster1.defence / 100)) << " damage." << endl;

	}
	else {
		cout << "You have missed" << endl;
	}
	curMonster1.accuracy -= accuracyDamage;
	curMonster1.AD -= attDmgDamage;
	curMonster1.AS -= attSpdDamage;
	curMonster1.defence -= DefenceDamage;
	curMonster1.HP -= hpDamage*(1 - (curMonster1.defence / 100));
	curMonster1.dodge -= DodgeDamage;
	
	cout << monster1.getMonsterName() << " now has " << curMonster1.HP << " HP." << endl << endl;
}
void Battle::monsterTurn(Hero hero1, Monster monster1)
{

	int rndChoice = 0;
	
	cout << "It is " << monster1.getMonsterName() << " turn ... Please Wait ..." << endl;
	cout << "The " << monster1.getMonsterName() << " has used " << MonsterSpells[rndChoice].getSpellName() << endl;
	//Random number for picking spell
	//rndChoice = RNG;
	
	int hpDamage = 0;
	int accuracyDamage = 0;
	int attDmgDamage = 0;
	double attSpdDamage = 0;
	int DefenceDamage = 0;
	int DodgeDamage = 0;
	
	if (monster1.RNG(100) <= getAccuracy('m')) {
		cout << MonsterSpells[rndChoice].getSpellHPDamage() << endl;
		hpDamage = curMonster1.AD + MonsterSpells[rndChoice].getSpellHPDamage();
		accuracyDamage = curMonster1.AD + MonsterSpells[rndChoice].getSpellAccuracyDamage();
		attDmgDamage = curMonster1.AD + MonsterSpells[rndChoice].getSpellAttDmgDamage();
		attSpdDamage = curMonster1.AD + MonsterSpells[rndChoice].getSpellAttSpdDamage();
		DefenceDamage = curMonster1.AD + MonsterSpells[rndChoice].getSpellDefenceDamage();
		DodgeDamage = curMonster1.AD + MonsterSpells[rndChoice].getSpellDodgeDamage();

		cout << "Monster hit you for (" << hpDamage << " HP) damage!" << endl;
		double percentHP = curMonster1.HP / monster1.getMonsterHP() * 100;
		cout << "You" <<" took " << hpDamage*(1 - (curHero1.defence / 100)) << " damage." << endl;
	}
	else {
		cout << "The " << monster1.getMonsterName() << " has missed" << endl;
	}
	curHero1.accuracy -= accuracyDamage;
	curHero1.AD -= attDmgDamage;
	curHero1.AS -= attSpdDamage;
	curHero1.defence -= DefenceDamage;
	curHero1.HP -= hpDamage*(1 - (curHero1.defence / 100));
	curHero1.dodge -= DodgeDamage;
	
	cout << "You now have " << curHero1.HP << " HP." << endl<< endl<< endl;

}
void Battle::loadMonsterSpell(Monster monster1) {
	//readin all spell ids where monster id equal to monster1.id

	sqlite::sqlite db("dung.db");    // open database

	auto cur = db.get_statement();            // Allows acess
	cur->set_sql("SELECT [Spell_ID] FROM [MonsterSpellList] WHERE [MonsterID]=?;");
	cur->prepare(); //Exectues the query
	cur->bind(1, monster1.getMonsterID());
	while (cur->step()) {
		MonsterSpellIDs.push_back(cur->get_int(0));
	}
	for (int i=0; i < MonsterSpellIDs.size(); i++) {
		Spell spell1(MonsterSpellIDs[i]);
		MonsterSpells.push_back(spell1);
	}




	//push all spell id into vector
	//create a new loop add spells to vector 
}
void Battle::dropLoot(Monster monster1, Hero &hero1) {
	// load items and chance into seperate vectors
	// if the chance in the chance vector gives item add item from vector to inventory
	vector<int> possibleItemIDs;
	vector<double> chance;

	sqlite::sqlite db("dung.db");    // open database

	auto cur = db.get_statement();            // Allows acess
	cur->set_sql("SELECT [ItemID], [Chance] FROM [MonsterLoot] WHERE [MonsterID]=?;");
	cur->prepare(); //Exectues the query
	cur->bind(1, monster1.getMonsterID());
	while (cur->step()) {
		possibleItemIDs.push_back(cur->get_int(0));
		chance.push_back(cur->get_int(1));
	}
	int RNG = monster1.RNG(100);
	for (int i = 0; i < possibleItemIDs.size(); i++)
	{
		if (RNG < chance[i]) {
			hero1.inv.addToInventory(possibleItemIDs[i]);
			Item item1(possibleItemIDs[i]);
			cout << "You have received " << item1.getItemName() << endl;
		}
	}
}
