#include "Spear.h"

int main() {
	Backpack sweet_apple("Sweet apple", "eat", "Juicy red color.");
	Backpack compass("Compass", "gadget", "It will show the right way.");
	Backpack empty_book("Book", "book", "It is... empty.");
	//Backpack ("Book", "It is... empty.");

	HeroicCreature chalk_traveler("Chalk Traveler", "Hill of storm", "about aboba", 15, 12, 05, 2006);

	chalk_traveler.display_info_about_heroic_creature();
	cout << endl;
	chalk_traveler.add_item(sweet_apple);
	chalk_traveler.add_item(compass);
	chalk_traveler.add_item(empty_book);
	chalk_traveler.display_content_of_backpack();
	cout << endl;
	chalk_traveler.remove_item_first_added();
	chalk_traveler.display_content_of_backpack();
	cout << endl;
}