#include "Spear.h"

int main() {
	Backpack sweet_apple("Sweet apple", "eat", "Juicy red color.");
	Backpack compass("Compass", "gadget", "It will show the right way.");
	Backpack empty_book("Book", "book", "It is... empty.");
	Backpack last_hope("Last hope", "weapon", "Spear");

	HeroicCreature chalk_traveler("Chalk Traveler", "Hill of storm", "about aboba", 15, 12, 05, 2006);

	chalk_traveler.display_info_about_heroic_creature();
	cout << endl;
	chalk_traveler.add_item(sweet_apple);
	chalk_traveler.add_item(compass);
	chalk_traveler.add_item(empty_book);
	chalk_traveler.display_content_of_backpack();
	/*chalk_traveler.remove_item_by_name("Bo");*/
	if (chalk_traveler.find_by_name("Boo") != -1) { chalk_traveler.remove_item_by_index(chalk_traveler.find_by_name("Boo")); };
	chalk_traveler.display_content_of_backpack();
	cout << endl;
}