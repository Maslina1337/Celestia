#include <iostream>
#include <string>
#include <ctime>

#define ENG_ALPHABET "abcdefghijklmnopqrstuvwxyz"

using namespace std;

//layouts of functions.
string random_name(int min, int max);

//classes.
class Backpack {
public:
	string item_name;
	string item_type;
	string item_about;

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

	int get_index() {
		return index;
	}

	void set_index(int index) {
		this->index = index;
	}
private:
	int index; // for arreys (it's beggining from 0). DO NOT TOUCH.
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
	Backpack* backpack_sorted;
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
		backpack_sorted = NULL;
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
			item.set_index(0);
			backpack_size = 1;

			return;
		}

		Backpack* temp = new Backpack[backpack_size + 1];
		for (int i = 0; i < backpack_size; i++) {
			temp[i] = backpack[i];
		}
		backpack_size++;
		item.set_index(backpack_size - 1);
		temp[item.get_index()] = item;
		backpack = temp;
	}

	void remove_item_by_name(string name) { // Remove by item_name.
		if (backpack == NULL) {
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

	void remove_item_by_about(string about) { // Remove by item_about.
		if (backpack == NULL) {
			return;
		}

		Backpack* temp = new Backpack[backpack_size - 1];
		for (int i = 0, j = 0; i < backpack_size; i++, j++) {
			if (backpack[i].item_about == about) {
				j--;
			}
			else {
				temp[j] = backpack[i];
			}
		}
		backpack_size--;
		backpack = temp;
	}

	void remove_item_by_index(int index) { // Remove by index.
		if (backpack == NULL) {
			return;
		}

		Backpack* temp = new Backpack[backpack_size - 1];
		for (int i = 0, j = 0; i < backpack_size; i++, j++) {
			if (backpack[i].get_index() == index) {
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

	int find_by_name(string name) { //if (find_by_name(...) != -1) {...}
		for (int i = 0; i < backpack_size; i++) {
			if (backpack[i].item_name == name) {
				return i;
			}
		}

		return -1;
	}

	int find_by_about(string about) { //if (find_by_about(...) != -1) {...}
		for (int i = 0; i < backpack_size; i++) {
			if (backpack[i].item_about == about) {
				return i;
			}
		}

		return -1;
	}

	/*void sort_by_name_eng() {
		string eng = ENG_ALPHABET;
		Backpack* temp = new Backpack[backpack_size];
		for (int i = 0; i < backpack_size; i++) {
			if ()
		}
		backpack_size++;
		item.set_index(backpack_size - 1);
		temp[item.get_index()] = item;
		backpack = temp;
	}*/

	void display_info_about_heroic_creature() {
		cout << "Name: " << public_name << endl << "Constellation: " << constellation << endl << "About: " << about << endl;
	}

	void display_content_of_backpack() {
		cout << "Backpack:" << endl;
		for (int i = 0; i < backpack_size; i++) {
			cout << endl << backpack[i].item_name << endl << backpack[i].item_about << endl;
		}
	}
	;
private:
	string private_name;
	;
};