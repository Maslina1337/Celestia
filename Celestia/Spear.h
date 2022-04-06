#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Backpack {
public:
	string item_name;
	string about;
	int index; // for arreys (it's beggining from 0)

	Backpack() {
		item_name = "no_name";
		about = "no_about";
		index = 0;
	}

	Backpack(string item_name, string about, int index) {
		this->item_name = item_name;
		this->about = about;
		this->index = index;
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

	Backpack* backpack;
	int backpack_size; // beggining from 1

	HeroicCreature() {
		public_name = "no_name";
		constellation = "no_constellation";
		about = "no_about";
		age = 0;
		birth_day = 0;
		birth_month = 0;
		backpack = NULL;
		backpack_size = 0;
	};

	//Make a HC without backpack.
	HeroicCreature(string public_name, string constellation, string about, int age, int birth_day, int birth_month) {
		this->public_name = public_name;
		this->constellation = constellation;
		this->about = about;
		this->age = age;
		this->birth_day = birth_day;
		this->birth_month = birth_month;
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
			backpack[1] = item;
			item.index = 0;
			backpack_size = 1;

			return;
		}

		Backpack* temp = new Backpack[backpack_size++];
		for (int i = 0; i < backpack_size; i++) {
			temp[i] = backpack[i];
		}
		temp[backpack_size] = item;
		backpack = temp;
		delete[] temp;
	}

	/*void remove_item(Backpack item) {
		Backpack* temp = new Backpack[backpack_size--];
		for (int i = 0, j = 0; i < backpack_size; i++, j++) {
			if (item == backpack[j]) {
				
			}
				temp[i] = backpack[i];
		}
		temp[backpack_size] = item;
		backpack = temp;
		delete[] temp;
	}*/
	;
private:
	string private_name;
	int birth_year;
	;
};