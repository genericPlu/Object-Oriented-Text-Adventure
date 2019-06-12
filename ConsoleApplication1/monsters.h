#ifndef MONSTERS_H_
#define MONSTERS_H_
#pragma once
#include <iostream>
#include <string>
//Monster type definitions, variables , and functions.
class monster {
private:
	int experience;
	int health;
	int combat;
	int magic;
	int armor;

public:
	monster(int e = 0, int c = 0, int h = 0, int m = 0, int a = 0) : experience(e), combat(c), health(h), magic(m), armor(a) {
		
	}
	int getExperience() {
		return experience;
	};
	void setExperience(int e) {
		experience = e;
	};

	int getHealth() {
		return health;
	};
	void setHealth(int h) {
		health = h;
	};

	int getCombat() {
		return combat;
	};
	void setCombat(int c) {
		combat = c;
	};

	int getMagic() {
		return magic;
	};
	void setMagic(int m) {
		magic = m;
	};

	int getArmor() {
		return armor;
	};
	void setArmor(int a) {
		armor = a;
	};
};

class goblin {

	//Stats
	std::string type = "goblin";
	int type;

public:
	goblin() {
		experience = 100;
		health = 20;
		combat = 5;
		magic = 0;
		armor = 2;
		int temp = rand() % 4;
		switch (temp) {
			case 1:
				weapon = "spear";
				break;
			case 2:
				weapon = "sword";
				break;
			case 3:
				weapon = "mace";
				break;
			default:
				weapon = "dagger";
				break;
	}
}
	
	//Getters
	std::string getType() {
		return type;
	};
	std::string getWeapon() {
		return weapon;
	};
	int getExperience() {
		return experience;
	};
	int getHealth() {
		return health;
	};
	int getCombat() {
		return combat;
	};
	int getMagic() {
		return magic;
	};
	int getArmor() {
		return armor;
	};

};


class skeleton {

	//Stats
	std::string type = "skeleton";
	std::string weapon;
	int experience;
	int health;
	int combat;
	int magic;
	int armor;

public:
	skeleton() {
		experience = 200;
		health = 30;
		combat = 7;
		magic = 0;
		armor = 3;
		int temp = rand() % 4;
		switch (temp) {
		case 1:
			weapon = "spear";
			break;
		case 2:
			weapon = "sword";
			break;
		case 3:
			weapon = "mace";
			break;
		default:
			weapon = "dagger";
			break;
		}
	}
	//Getters
	std::string getType() {
		return type;
	};
	std::string getWeapon() {
		return type;
	};
	int getExperience() {
		return experience;
	};
	int getHealth() {
		return health;
	};
	int getCombat() {
		return combat;
	};
	int getMagic() {
		return magic;
	};
	int getArmor() {
		return armor;
	};

};


#endif