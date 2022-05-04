#include "Spear.h"

int main() {
	Backpack sweet_apple("Sweet apple", "eat", "Juicy red color.");
	Backpack compass("Compass", "gadget", "It will show the right way.");
	Backpack empty_book("Book", "book", "It is... empty.");
	Backpack excalibur("Excalibur", "weapon", "Return it to owner.");
	Backpack last_hope("Last hope", "weapon", "Spear that will help you.");

	HeroicCreature chalk_traveler("Chalk Traveler", "Hill of storm", "about aboba", 15, 12, 05, 2006);

	chalk_traveler.display_info_about_heroic_creature();
	cout << endl;
	chalk_traveler.add_item(sweet_apple);
	chalk_traveler.add_item(compass);
	chalk_traveler.add_item(empty_book);
	chalk_traveler.add_item(excalibur);
	chalk_traveler.add_item(last_hope);
	cout << endl;
	chalk_traveler.display_content_of_backpack();
	//if (chalk_traveler.find_by_name("Book") != -1) { chalk_traveler.remove_item_by_index(chalk_traveler.find_by_name("Book")); }; //example of removing
	chalk_traveler.display_content_of_backpack();
	cout << endl;

	ATOMIC_WCHAR_T_LOCK_FREE
}