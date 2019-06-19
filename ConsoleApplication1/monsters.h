#ifndef MONSTERS_H_
#define MONSTERS_H_

#pragma once

enum {
	TOTAL_MONSTERS = 3

};

using std::string;

//Monster class definitions, variables , and functions.
class Monster {
	unsigned int experience;
	int health;
	unsigned int combat;
	unsigned int magic;
	int armor;
	int gold;
	item treasure;
	string species;
	Weapon monsterWeapon;


public:
	Monster() :
		experience(0),
		health(0),
		combat(0),
		magic(0),
		armor(10){}


	//Getters
	unsigned int getExperience() {
		return experience;
	}
	int getHealth() {
		return health;
	}
	unsigned int getCombat() {
		return combat;
	}
	unsigned int getMagic() {
		return magic;
	}
	int getArmor() {
		return armor;
	}
	int getGold() {
		return gold;
	}
	string getSpecies() {
		return species;
	}
	item getTreasure() {

	}
	Weapon getWeapon() {
		return monsterWeapon;
	}

	void setHealth(int h) {
		health = h;
	}
	void setExperience(int e) {
		experience = e;
	}
	void setCombat(int c) {
		combat = c;
	}
	void setMagic(int m) {
		magic = m;
	}
	void setArmor(int a) {
		armor = a;
	}
	void setGold(int g) {
		gold = g;
	}
	void setTreausre(item t) {
		treasure = t;
	}
	void setSpecies(string s) {
		species = s;
	}
	void setWeapon(Weapon w) {
		monsterWeapon = w;
	}
	~Monster() {}
};

class Goblin : public Monster {
private:


public:
	Goblin() {
		setSpecies("goblin");
		setExperience(100);
		setHealth(10);
		setCombat(20);
		setArmor(10);
	}
};
	class Skeleton : public Monster {
	private:
		
	public:
		Skeleton() {
			setSpecies("skeleton");
			setExperience(100);
			setHealth(10);
			setCombat(19);
			setArmor(8);
		}
		
};

	class Lizardman : public Monster {
	private:
		
	public:
		Lizardman() {
			setSpecies("lizard man");
			setExperience(100);
			setHealth(10);
			setCombat(18);
			setArmor(9);
			
		}

};


#endif