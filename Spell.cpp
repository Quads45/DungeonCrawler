#include "Spell.h"
#include "libsqlite.hpp"

Spell::Spell(int Spell_ID, int profid) {
	
	sqlite::sqlite db("dung.db");
	auto s = db.get_statement();
	s->set_sql("SELECT [Spell_ID] FROM [Spell] WHERE [ProfessionID]=?");
	s->prepare();
	s->bind(1, profid);
	while (s->step())
	{
		possibleSpellIDs.push_back(s->get_int(0));
	}
	if (true) {
		sqlite::sqlite db("dung.db");

		auto cur = db.get_statement();
		cur->set_sql("SELECT [SpellName], [SpellEffect], [SpellHPDamage], [SpellDefenceDamage], [SpellDodgeDamage], [SpellAccuracyDamage], [SpellAttDmgDamage], [SpellAttSpdDamage] FROM [Spell] WHERE [Spell_ID]=?;");
		cur->prepare();
		cur->bind(1, possibleSpellIDs[Spell_ID]);
		cur->step();

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
	sqlite::sqlite db("dung.db");

	auto cur = db.get_statement();
	cur->set_sql("SELECT [SpellName], [SpellEffect], [SpellHPDamage], [SpellDefenceDamage], [SpellDodgeDamage], [SpellAccuracyDamage], [SpellAttDmgDamage], [SpellAttSpdDamage] FROM [Spell] WHERE [Spell_ID]=?;");
	cur->prepare();
	cur->bind(1, Spell_ID);
	cur->step();

	SpellName = cur->get_text(0);
	SpellEffect = cur->get_text(1);
	SpellHPDamage = cur->get_int(2);
	SpellDefenceDamage = cur->get_int(3);
	SpellDodgeDamage = cur->get_int(4);
	SpellAccuracyDamage = cur->get_int(5);
	SpellAttDmgDamage = cur->get_int(6);
	SpellAttSpdDamage = cur->get_double(7);
}