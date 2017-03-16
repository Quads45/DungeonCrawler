// Game.cpp
#include "Game.h"
#include "Monster.h"
#include "Battle.h"
#include "sqlite3/sqlite3.h"
using namespace std;
class InvalidInput {};
Game::Game() 
{

}
void Game::startNewGame(Hero &hero1) 
{
	//Describe lore
	//Talk about spooky monsters invading town and how you, the hero, must defend it.
	cout << "You have arrived at Aynor, " << hero1.getName() << "." << endl
		<< "[------------------------------------]"<<"\n\n\n\n\n"
		<< "          lore placeholder            "<<"\n\n\n\n\n"
		<< "[------------------------------------]\n\n";
	showTown(hero1);
}
void Game::showTown(Hero &hero1)
{
	//to do
	//ask user what he would like to do
	//shop/dungeone select/view inv etc.
	cout << "Aynor" << endl
		<< "Where would you like to enter?" << endl
		<< "1. Dungeon Select Screen" << endl
		<< "2. Shop" << endl
		<< "3. Inventory" << endl
		<< "4. Stats" << endl
		<< "5. Save" << endl;
	choice = getSelection(5);
	switch (choice)	
	{
	case 1:
		goToBattle(hero1);
		showTown(hero1);
		break;
	case 2:
		//to do, call shop
		break;
	case 3:
		showInventory(hero1);
		break;
	case 4:
		showStats(hero1);
		break;
	case 5:
		Save(hero1);
		break;
	default:
		break;
	}
}
int Game::getSelection(int maxChoice)
{
	
	try {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << ">> ";
		cin >> choice;
		if (choice < 1 || choice > maxChoice)
		{
			throw InvalidInput{};
		}

	}
	catch (InvalidInput) {
		cout << "Invalid input, try again." << endl;
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		getSelection(maxChoice);
	}

	return choice;
}
void Game::showInventory(Hero &hero1)
{
	cout << "Inventory" << endl
		<< "Equiped items: " << endl; 
	hero1.inv.displayEquiped();
	cout << "Inventory items: " << endl;
	hero1.inv.displayInventory();
	cout << "\n1. Equip item" << endl
		<< "2. Go back to town" << endl;
	switch (getSelection(3)){
	case 1:
		// ask user what item use would like to equip
		cout << "Which item would you like to equip?" << endl;
		hero1.inv.moveToEquiped(getSelection(hero1.inv.getInventorySize())-1);
		break;
	default:
		showTown(hero1);
	}
	showInventory(hero1);
}
void Game::showStats(Hero hero1)
{ 
	hero1.updateStats();
	cout << hero1.getName() << ", your statistics are: \n";
	hero1.getStats();
	showTown(hero1);
}
void Game::Save(Hero hero1)
{
	// saving the character
	sqlite3 *db;
	if (sqlite3_open_v2("dung.db", &db, 2, NULL) == 0) {
		cout << "Database Successfully Opened" << endl;
	}
	sqlite3_stmt *stmt;
	const char *sql = "INSERT INTO [Character] ([CharacterName], [ProfessionID], [Level_ID], [CharacterExperience]) VALUES (?, ?, ?, ?);"; // ? is placeholder
	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	std::string str = hero1.getName();
	const char * c = str.c_str();
	sqlite3_bind_text(stmt, 1,c,-1,0);
	sqlite3_bind_int(stmt, 2, hero1.getHeroProfID()); 
	sqlite3_bind_int(stmt, 3, hero1.getLevel());
	sqlite3_bind_int(stmt, 4, hero1.getExp());
	if (rc != SQLITE_OK) {
		cout << "Error writing to the database." << endl;
	}
	rc = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	sqlite3_close(db);
	SaveInventory(hero1);
	SaveEquiped(hero1);
	//cur->set_sql("INSERT INTO [Character] ([CharacterName], [ProfessionID], [Level_ID], [CharacterExperience]) VALUES (?, ?, ?, ?); ");

}
void Game::SaveInventory(Hero hero1){
		int characterID = getCharID();
		for (int i = 0; i < hero1.inv.getInventorySize(); i++){
			sqlite3 *db;
			if (sqlite3_open_v2("dung.db", &db, 2, NULL) == 0) {
				cout << "Database Successfully Opened" << endl;
			}
			sqlite3_stmt *stmt;
			const char *sql = "INSERT INTO [Inventory] ([CharacterID], [ItemID], [InventoryQuantity], [InventoryEquipped]) VALUES (?, ?, ?, ?);"; // ? is placeholder
			int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
			sqlite3_bind_int(stmt, 1, characterID);
			sqlite3_bind_int(stmt, 2, hero1.inv.getInventoryItemID(i));
			sqlite3_bind_int(stmt, 3, 1);
			sqlite3_bind_int(stmt, 4, 0);
			if (rc != SQLITE_OK) {
				cout << "Error writing to the database." << endl;
			}
			rc = sqlite3_step(stmt);
			sqlite3_finalize(stmt);
			sqlite3_close(db);
		}
}
int Game::getCharID(){

	sqlite::sqlite db("dung.db");    // open database

	auto cur = db.get_statement();            // create query   
	cur->set_sql("SELECT MAX(CharacterID) FROM Character;");
	cur->prepare();   // run query
	cur->step();
	return cur->get_int(0);
}
void Game::SaveEquiped(Hero hero1){
	int characterID = getCharID();
	for (int i = 0; i < 2; i++){
		sqlite3 *db;
		if (sqlite3_open_v2("dung.db", &db, 2, NULL) == 0) {
			cout << "Database Successfully Opened" << endl;
		}
		sqlite3_stmt *stmt;
		const char *sql = "INSERT INTO [Inventory] ([CharacterID], [ItemID], [InventoryQuantity], [InventoryEquipped]) VALUES (?, ?, ?, ?);"; // ? is placeholder
		int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
		sqlite3_bind_int(stmt, 1, characterID);
		sqlite3_bind_int(stmt, 2, hero1.inv.getEquipedItemID(i));
		sqlite3_bind_int(stmt, 3, 1);
		sqlite3_bind_int(stmt, 4, 1);
		if (rc != SQLITE_OK) {
			cout << "Error writing to the database." << endl;
		}
		rc = sqlite3_step(stmt);
		sqlite3_finalize(stmt);
		sqlite3_close(db);
	}
}
void Game::goToBattle(Hero &hero1)
{
	Battle battle1(hero1, 1);
}