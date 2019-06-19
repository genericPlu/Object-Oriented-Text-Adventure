#ifndef OBJECTS_H_
#define OBJECTS_H_
#pragma once

//All physical object class defintions, including potions, weapons, armor. 

//Weapons
//Weapon damage types "B"- bludgeoning, "S"- slashing, "P"- piercing

using std::string;
using std::cout;
enum {
	TOTAL_WEAPONS = 4,
	TOTAL_ITEMS = 3,
	TOTAL_ARMOR = 3,
	TOTAL_POTIONS = 2

};

class item {
private:
	int cost;
	int weight;
	string name;
	string description;
public:
	item(){}

	string getName() {
		return name;
	}
	string getDescription() {
		return description;
	}
	int getCost() {
		return cost;
	}
	int getWeight() {
		return weight;
	}
	void setName(string n) {
		name = n;
	}
	void setDescription(string d) {
		description = d;
	}
	void setCost(int c) {
		cost = c;
	}
	void setWeight(int w) {
		weight = w;
	}
	void displayItem() {
		cout << "Name:" << name << "\n";
		cout << "Cost:" << cost << "\n";
		cout << "Weight:" << weight << "\n";
		cout << "Description:" << description << "\n";
	}
	~item() {};
};

//Miscellaneous is useable items like rope, bomb, lanterns and anything else we come up withalong those lines.
class Rope : public item {
private:
	int uses;
public:
	Rope() : uses(2) {
		setName("rope");
		setCost(35);
		setWeight(3);
	}
};

class Bomb : public item {
private:
	int uses;
public:
	Bomb() : uses(1){
		setName("bomb");
		setCost(50);
		setWeight(4);
	}
};

class Lantern : public item {
private:
	int oil;
public:
	Lantern() : oil(5)  {
		setName("lantern");
		setCost(25);
		setWeight(2);
	}
};


//Weapons subclasses
class Weapon: public item{
private:
	char type;
	int condition;
	int dmg;
public:
	Weapon(){}
	
	char getType(){
		return type;
	}
	int getCondition(){
		return condition;
	}
	string getConditionD() {
		string returnString;
		if (getCondition() == 1) {
			returnString = "badly worn";
		}
		else if (getCondition() == 2) {
			returnString = "worn";
		}
		else if (getCondition() == 0) {
			returnString = "barely useable";
		}
		else if (getCondition() == 3) {
			returnString = "fair";
		}
		else if (getCondition() == 4) {
			returnString = "good";
		}
		else if (getCondition() == 5) {
			returnString = "very good";
		}
		else {
			returnString = "excellent";
		}
		return returnString;
	}
	int getDmg() {
		return dmg;
	}
	void setType(char t){
		type = t;
	}
	void setCondition(int c){
		 condition = c;
	}
	void setDmg(int d) {
		dmg = d;
	}
	//Display Weapon Stats Command
	void displayWeapon() {
		cout << "Weapon:" << getName() << "\n";
		cout << "Cost:" << getCost() << "\n";
		cout << "Type:" << type << "\n";
		cout << "Damage:" << dmg << "\n";
		cout << "Condition:" << getConditionD() << "\n";
		cout << "Weight:" << getWeight() << "\n";
		cout << "Description:" << getDescription() << "\n";
	}
};

//Slashing Weapons
class Sword : public Weapon {
private:
	
public:
	Sword(){
		setName("sword");
		setType('s');
		setCost(100);
		setDmg(8);
		setCondition(0);
		if (getCondition() == 1) {
			setDmg(getDmg()-2);
		}
		else if (getCondition() == 2) {
			setDmg(getDmg() - 1);
		}
		else if (getCondition() == 0) {
			setDmg(getDmg() - 3);
		}
		else if (getCondition() == 3) {
			setDmg(getDmg() - 0);
		}
		else if (getCondition() == 4) {
			setDmg(getDmg() + 1);
		}
		else if (getCondition() == 5) {
			setDmg(getDmg() + 2);
		}
		else {
			setDmg(getDmg() + 3);
		}
	}
	
	
};

//Piercing Weapons
class Dagger : public Weapon {
private:

public:
	Dagger() {
		setName("dagger");
		setType('p');
		setCost(25);
		setDmg(3);
		setCondition(0);
		if (getCondition() == 1) {
			setDmg(getDmg()-2);
		}
		else if (getCondition() == 2) {
			setDmg(getDmg() - 1);
		}
		else if (getCondition() == 0) {
			setDmg(getDmg() - 3);
		}
		else if (getCondition() == 3) {
			setDmg(getDmg() - 0);
		}
		else if (getCondition() == 4) {
			setDmg(getDmg() + 1);
		}
		else if (getCondition() == 5) {
			setDmg(getDmg() + 2);
		}
		else {
			setDmg(getDmg() + 3);
		}
	}
	
};

//Bludgeoning weapons
class Mace : public Weapon {
private: 

public:
	Mace() {
		setName("mace");
		setType('b');
		setCost(50);
		setDmg(6);
		setCondition(0);
		if (getCondition() == 1) {
			setDmg(getDmg() - 2);
		}
		else if (getCondition() == 2) {
			setDmg(getDmg() - 1);
		}
		else if (getCondition() == 0) {
			setDmg(getDmg() - 3);
		}
		else if (getCondition() == 3) {
			setDmg(getDmg() - 0);
		}
		else if (getCondition() == 4) {
			setDmg(getDmg() + 1);
		}
		else if (getCondition() == 5) {
			setDmg(getDmg() + 2);
		}
		else {
			setDmg(getDmg() + 3);
		}
	}

};

class Stick : public Weapon {
private:

public:
	Stick() {
		setName("stick");
		setType('b');
		setCost(2);
		setDmg(2);
		//no condtion for sticks
		setCondition(0);
		
	}
};

class Staff : public Weapon {
private:
	int cost = 35;
	int dmg = 4;
public:
	Staff() {
		setName("staff");
		setType('b');
		setCost(35);
		setDmg(4);
		setCondition(0);
		if (getCondition() == 1) {
			setDmg(getDmg() - 2);
		}
		else if (getCondition() == 2) {
			setDmg(getDmg() - 1);
		}
		else if (getCondition() == 0) {
			setDmg(getDmg() - 3);
		}
		else if (getCondition() == 3) {
			setDmg(getDmg() - 0);
		}
		else if (getCondition() == 4) {
			setDmg(getDmg() + 1);
		}
		else if (getCondition() == 5) {
			setDmg(getDmg() + 2);
		}
		else {
			setDmg(getDmg() + 3);
		}
	}
};

//Armor Subclasses
class Armor : public item {
private:
	int armor;
public:
	Armor(){}
};

//Potion subclasses
class Potion : public item {
private:

public:
	Potion() {}
};


#endif