#include "Spell.h"
#include "libsqlite.hpp"

Spell::Spell(int Spell_ID, int profid) {
	//open the database
	sqlite::sqlite db("dung.db");
	//create a query
	auto cur = db.get_statement();
	cur->set_sql("SELECT [Spell_ID] FROM [Spell] WHERE [ProfessionID]=?");
	//execute the query
	cur->prepare();
	//get all the spells with a specific profID
	cur->bind(1, profid);
	//use a while loop to add all the spells found to a vector
	while (cur->step())
	{
		possibleSpellIDs.push_back(cur->get_int(0));
	}
	//create a namespace to open the database again
	//without the new namespace theres possible errors
	//since the database was not properly closed before
	if (true) {
		//open the database
		sqlite::sqlite db("dung.db");
		//create a query
		auto cur = db.get_statement();
		cur->set_sql("SELECT [SpellName], [SpellEffect], [SpellHPDamage], [SpellDefenceDamage], [SpellDodgeDamage], [SpellAccuracyDamage], [SpellAttDmgDamage], [SpellAttSpdDamage] FROM [Spell] WHERE [Spell_ID]=?;");
		//execute the query
		cur->prepare();
		//get the spell that has been passed through the constructor
		cur->bind(1, possibleSpellIDs[Spell_ID]);
		cur->step();
		//get all the spell data from the database, put them into
		//variables
		SpellName = cur->get_text(0);
		SpellEffect = cur->get_text(1);
		SpellHPDamage = cur->get_int(2);
		SpellDefenceDamage = cur->get_int(3);
		SpellDodgeDamage = cur->get_int(4);
		SpellAccuracyDamage = cur->get_int(5);
		SpellAttDmgDamage = cur->get_int(6);
		SpellAttSpdDamage = cur->get_double(7);
	}

}
Spell::Spell(int Spell_ID) {
	// alternate constructor called to create a spell for a monster
	//open the database
	sqlite::sqlite db("dung.db");
	//create a query
	auto cur = db.get_statement();
	cur->set_sql("SELECT [SpellName], [SpellEffect], [SpellHPDamage], [SpellDefenceDamage], [SpellDodgeDamage], [SpellAccuracyDamage], [SpellAttDmgDamage], [SpellAttSpdDamage] FROM [Spell] WHERE [Spell_ID]=?;");
	//execute the query
	cur->prepare();
	//get the spell from the database using the Spell_ID
	//that was passed throught the constructor
	cur->bind(1, Spell_ID);
	cur->step();

	//load all the spell information from the database into variables
	SpellName = cur->get_text(0);
	SpellEffect = cur->get_text(1);
	SpellHPDamage = cur->get_int(2);
	SpellDefenceDamage = cur->get_int(3);
	SpellDodgeDamage = cur->get_int(4);
	SpellAccuracyDamage = cur->get_int(5);
	SpellAttDmgDamage = cur->get_int(6);
	SpellAttSpdDamage = cur->get_double(7);
}