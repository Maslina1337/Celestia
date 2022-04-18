#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//layouts of functions.
string random_name(int min, int max);

//classes.
class Backpack {
public:
	string item_name;
	string item_type;
	string item_about;
	int index; // for arreys (it's beggining from 0). DO NOT TOUCH.

	Backpack() {
		item_name = "no_name";
		item_type = "no_type";
		item_about = "no_about";
		index = -1;
	}

	Backpack(string item_name, string item_type, string about) {
		this->item_name = item_name;
		this->item_type = item_type;
		this->item_about = about;
	}
	;
};

class HeroicCreature {
public:
	string public_name;
	string constellation;
	string about;
	int age;
	int birth_day;
	int birth_month;
	int birth_year;

	Backpack* backpack;
	int backpack_size; // beggining from 1

	HeroicCreature() {
		public_name = "no_name";
		constellation = "no_constellation";
		about = "no_about";
		age = 0;
		birth_day = 0;
		birth_month = 0;
		birth_year = 0;
		backpack = NULL;
		backpack_size = 0;
	};

	//Make a HC without backpack.
	HeroicCreature(string public_name, string constellation, string about, int age, int birth_day, int birth_month, int birth_year) {
		this->public_name = public_name;
		this->constellation = constellation;
		this->about = about;
		this->age = age;
		this->birth_day = birth_day;
		this->birth_month = birth_month;
		this->birth_year = birth_year;
	}

	~HeroicCreature() {
		if (backpack != NULL) {
			delete[] backpack;
		}
	}

	string get_public_name() {
		return public_name;
	}

	void set_public_name(string public_name) {
		this->public_name = public_name;
	}

	//Make a backpack
	void add_item(Backpack item) {
		if (backpack == NULL) {
			backpack = new Backpack[1];
			backpack[0] = item;
			item.index = 0;
			backpack_size = 1;

			return;
		}

		Backpack* temp = new Backpack[backpack_size + 1];
		for (int i = 0; i < backpack_size; i++) {
			temp[i] = backpack[i];
		}
		backpack_size++;
		item.index = backpack_size - 1;
		temp[item.index] = item;
		backpack = temp;
	}

	void remove_item(string name) { // Remove by name.
		if (backpack == NULL) {
			return;
		}

		if (backpack_size == 1) {
			backpack = NULL;
			return;
		}

		Backpack* temp = new Backpack[backpack_size - 1];
		for (int i = 0, j = 0; i < backpack_size; i++, j++) {
			if (backpack[i].item_name == name) {
				j--;
			}
			else {
				temp[j] = backpack[i];
			}
		}
		backpack_size--;
		backpack = temp;
	}

	void remove_item_last_added() { // Remove last added.
		if (backpack == NULL) {
			return;
		}

		if (backpack_size == 1) {
			backpack = NULL;
			return;
		}

		Backpack* temp = new Backpack[backpack_size - 1];
		for (int i = 0; i < backpack_size - 1; i++) {
				temp[i] = backpack[i];
		}
		backpack_size--;
		backpack = temp;
	}

	void remove_item_first_added() { // Remove first added. (useless i think...)
		if (backpack == NULL) {
			return;
		}

		if (backpack_size == 1) {
			backpack = NULL;
			return;
		}

		Backpack* temp = new Backpack[backpack_size - 1];
		for (int i = 1; i < backpack_size; i++) {
			temp[i - 1] = backpack[i];
		}
		backpack_size--;
		backpack = temp;
	}

	void clear_backpack() {
		backpack = NULL;
	}

	void display_info_about_heroic_creature() {
		cout << "Name: " << public_name << endl << "Constellation: " << constellation << endl << "About: " << about << endl;
	}

	void display_content_of_backpack() {
		cout << "Backpack:" << endl;
		for (int i = 0; i < backpack_size; i++) {
			cout << endl << backpack[i].item_name << endl << backpack[i].about << endl;
		}
	}
	;
private:
	string private_name;
	;
};