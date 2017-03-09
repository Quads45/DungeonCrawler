#ifndef Spell_H
#define Spell_H
#include <string>

class Spell {
	int Spell_ID, ProfessionID, SpellHPDamage, SpellDefenceDamage, SpellDodgeDamage, SpellAccuracyDamage, SpellAttDmgDamage;
	std::string SpellName, SpellEffect;
	double SpellAttSpdDamage;
public:

	Spell(int Spell_ID, int profid);
	std::string getSpellName;
	std::string getSpellEffect;
	int getSpellHPDamage() { return SpellHPDamage; };
	int getSpellDefenceDamage() { return SpellDefenceDamage; };
	int getSpellDodgeDamage() { return SpellDodgeDamage; };
	int getSpellAccuracyDamage() { return SpellAccuracyDamage; };
	int getSpellAttDmgDamage() { return SpellAttDmgDamage; };
	double getSpellAttSpdDamage() { return SpellAttSpdDamage; };

};

#endif