#include "Spear.h"

string random_name(int min, int max) {
	srand(time(NULL));
	int length = (rand() % (max - min + 1)) + min;
	bool is_vowel = rand() % 2;
	bool is_double = rand() % 3;
	is_double = !(is_double);
	string alphabet_vowel = "eyuioa";
	string alphabet_not_vowel = "qwrtpsdfghjklzxcvbnm";
	string name;
	for (int i = 0; i < length; i++) {
		if (is_vowel) {
			//double vowel is a bit strange looking.

			//if (is_double) {
			//	i++;
			//	name += alphabet_vowel[rand() % 6];
			//	name += alphabet_vowel[rand() % 6];
			//	is_vowel = false;
			//	is_double = rand() % 3;
			//	is_double = !(is_double);
			//}
			//else {
				name += alphabet_vowel[rand() % 6];
				is_vowel = false;
				is_double = rand() % 3;
				is_double = !(is_double);
			//}
		}
		else {
			if (is_double) {
				i++;
				name += alphabet_not_vowel[rand() % 20];
				name += alphabet_not_vowel[rand() % 20];
				is_vowel = true;
				is_double = rand() % 3;
				is_double = !(is_double);
			}
			else {
				name += alphabet_not_vowel[rand() % 20];
				is_vowel = true;
				is_double = rand() % 3;
				is_double = !(is_double);
			}
		}
	}

	return name;
}