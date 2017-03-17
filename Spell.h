#ifndef Spell_H
#define Spell_H
#include <string>
#include <vector>

class Spell {
	int Spell_ID, ProfessionID, SpellHPDamage, SpellDefenceDamage, SpellDodgeDamage, SpellAccuracyDamage, SpellAttDmgDamage;
	std::string SpellName, SpellEffect;
	double SpellAttSpdDamage;
	std::vector<int> possibleSpellIDs;
public:
	//create a constructor 
	Spell(int Spell_ID, int profid);
	Spell(int Spell_ID);
	std::string getSpellName(){ return SpellName; }
	//create functions which retrieve specific data on a spell
	std::string getSpellEffect() { return SpellEffect; }
	int getSpellHPDamage() { return SpellHPDamage; }
	int getSpellDefenceDamage() { return SpellDefenceDamage; }
	int getSpellDodgeDamage() { return SpellDodgeDamage; }
	int getSpellAccuracyDamage() { return SpellAccuracyDamage; }
	int getSpellAttDmgDamage() { return SpellAttDmgDamage; }
	double getSpellAttSpdDamage() { return SpellAttSpdDamage; }

};

#endif