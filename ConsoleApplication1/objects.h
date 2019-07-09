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

class Item {
private:
	int cost;
	int weight;
	string name;
	string description;
public:
	Item(): 
		cost(0),
		weight(0)	{}

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
	~Item() {};
};

//Miscellaneous is useable Items like rope, bomb, lanterns and anything else we come up withalong those lines.
class Rope : public Item {
private:
	int uses;
public:
	Rope() : uses(2) {
		setName("rope");
		setCost(35);
		setWeight(3);
	}
	int getUses() {
		return uses;
	}
};

class Bomb : public Item {
private:
	int uses;
public:
	Bomb() : uses(1){
		setName("bomb");
		setCost(50);
		setWeight(4);
	}
};

class Lantern : public Item {
private:
	int oil;
public:
	Lantern() : oil(5)  {
		setName("lantern");
		setCost(25);
		setWeight(2);
	}
};

class Lockpicks : public Item {
private:
	int picks;
public:
	Lockpicks() : picks(3) {
		setName("lock picks");
		setCost(50);
		setWeight(2);
	}
	int getPicks() {
		return picks;
	}
	void setPicks(int p) {
		picks = p;
	}
};

//Weapons subclasses
class Weapon: public Item{
private:
	char type;
	int condition;
	int dmg;
	
public:
	Weapon(): 
		type('p'),
		condition(0),
		dmg(0){}
	
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
		setWeight(8);
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
		setWeight(4);
		setCondition(0);
		if (getCondition() == 1) {
			setDmg(getDmg()-1);
		}
		else if (getCondition() == 2) {
			setDmg(getDmg() - 0);
		}
		else if (getCondition() == 0) {
			setDmg(getDmg() - 2);
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
		setWeight(6);
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
		setWeight(2);
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
		setWeight(3);
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
class Armor : public Item {
private:
	int armor;
public:
	Armor()	:
	armor(0){}
	int getArmor() {
		return armor;
	}
	void setArmor(int a) {
		armor = a;
	}

	//Display Armor Stats Command
	void displayArmor() {
		cout << "Armor Type:" << getName() << "\n";
		cout << "Armor Rateing:" << armor << "\n";
		cout << "Cost:" << getCost() << "\n";
		cout << "Weight:" << getWeight() << "\n";
		cout << "Description:" << getDescription() << "\n";
	}
};

class LeatherArmor : public Armor {
private:

public:
	LeatherArmor(){
		setName("leather armor");
		setArmor(7);
		setDescription("Light armor that offers minimal protection.");
		setCost(25);
		setWeight(10);
	}
	
};

class ChainArmor : public Armor {
private:

public:
	ChainArmor() {
		setName("chain armor");
		setArmor(3);
		setDescription("Medium armor that offers medium protection.");
		setCost(50);
		setWeight(12);
	}

};

class PlateArmor : public Armor {
private:

public:
	PlateArmor() {
		setName("plate armor");
		setArmor(0);
		setDescription("Heavy armor that offers heavy protection.");
		setCost(100);
		setWeight(15);
	}

};


//Potion subclasses
class Potion : public Item {
private:
	int uses;
public:
	Potion() :
	uses(3){}
	int getUses() {
		return uses;
	}

	void setUses(int u) {
		uses = u;
	}
};

//Heal potion subclass
class HealPotion : public Potion {
private:
	int health;
public:
	HealPotion(): health(0) {}

	int getHealth() {
		return health;
	}

	void setHealth(int h) {
		health = h;
	}
};

//Minor heal...
class MinorHealPotion : public HealPotion {
private:

public:
	MinorHealPotion() {
		setHealth(10);
		setName("minor healing potion");
		setDescription("A potion of minor healing.");
		setCost(50);
		setWeight(3);
	}
};


#endif