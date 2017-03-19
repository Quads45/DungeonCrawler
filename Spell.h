#ifndef Spell_H
#define Spell_H
#include <string>
#include <vector>

class Spell {
	//create variables to save the database values to
	int Spell_ID, ProfessionID, SpellHPDamage, SpellDefenceDamage, SpellDodgeDamage, SpellAccuracyDamage, SpellAttDmgDamage;
	std::string SpellName, SpellEffect;
	double SpellAttSpdDamage;
	std::vector<int> possibleSpellIDs;
public:
	//create a constructor so spells can be loaded for the hero
	Spell(int Spell_ID, int profid);
	//create a constructor so spells can be loaded for the monster
	Spell(int Spell_ID);
	std::string getSpellName(){ return SpellName; }
	//create functions which retrieve specific data on a spell
	//for the rest of the program to access.
	std::string getSpellEffect() { return SpellEffect; }
	int getSpellHPDamage() { return SpellHPDamage; }
	int getSpellDefenceDamage() { return SpellDefenceDamage; }
	int getSpellDodgeDamage() { return SpellDodgeDamage; }
	int getSpellAccuracyDamage() { return SpellAccuracyDamage; }
	int getSpellAttDmgDamage() { return SpellAttDmgDamage; }
	double getSpellAttSpdDamage() { return SpellAttSpdDamage; }

};

#endif