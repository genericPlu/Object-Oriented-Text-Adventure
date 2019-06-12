#pragma once

//All physical object defintions game including potions, weapons, armor, doors, traps? and any addtional physical items.

//Weapons
//Weapon types 1- bludgeoning, 2- slashing, 3- piercing
class weapon{
private:
	int type;
	int condition;

public:
	weapon(int t = 1, int c = 3) : type(t), condition(c){

	}

	int getType(){
		return type;
	};
	int getCondition(){
		return condition;
	};
	void setType(int t){
		type = t;
	};
	void setCondition(int c){
		 condition = c;
	};

};

class sword : public weapon {
private:
	int cost;
	int dmg;
public:
	sword(int cost = 100, int dmg = 5) : cost(cost), dmg(dmg) {
		setType(2);
		setCondition(rand() % 6);
		if (getCondition() == 1) {
			dmg = dmg - 2;
		}
		else if (getCondition() == 2) {
			dmg = dmg - 1;
		}
		else if (getCondition() == 0) {
			dmg = dmg - 3;
		}
		else if (getCondition() == 3) {
			dmg = dmg - 0;
		}
		else if (getCondition() == 4) {
			dmg = dmg + 1;
		}
		else if (getCondition() == 5) {
			dmg = dmg + 2;
		}
		else {
			dmg = dmg + 3;
		}
	};
	int getCost() {
		return cost;
	};
	int getDmg() {
		return dmg;
	};
};
//Armor

//Potions

//Miscellaneous