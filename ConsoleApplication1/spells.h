#ifndef SPELLS_H_
#define SPELLS_H_
#pragma once
using std::string;
//Spells defintions, variables and functions.
class Spell{
private:
	int cost;
	int pointCost;
	char type;
	string description;


public:
	Spell():cost(0),
		pointCost(0),
		type(0),
		description(""){}

	//setters
	void setCost(int c) {
		cost = c;
	}
	void setPointCost(int p) {
		pointCost = p;
	}
	void setType(int t) {
		type = t;
	}
	void setDescription(string s) {
		description = s;
	}

	//Getters
	int setCost() {
		return cost;
	}
	int setPointCost() {
		return pointCost;
	}
	char getType() {
		return type;
	}
	string getDescription(string s) {
		return description;
	}

};

//Attack Spells
class explosion : public Spell {
private:
	
public:
	explosion() {
		setCost(60);
		setPointCost(4);
		setType('a');
		setDescription("A spell that damages enemys in an area around you, also functions as a bomb.");
		

	}
};
class magicMissle : public Spell {
private:

public:
	magicMissle() {
		setCost(30);
		setPointCost(1);
		setType('a');
		setDescription("A simple spell that allows the user to shoot missle made up of magic at an enemy.");
	}
};

//Defense Spells
class Sheild : public Spell {
private:

public:
	Sheild() {
		setCost(40);
		setPointCost(2);
		setType('d');
		setDescription("A speel made to protect the user from all attacks for a period of time");
	}


};
class Darkness : public Spell {
private:

public:
	Darkness() {
		setCost(10);
		setPointCost(1);
		setType('d');
		setDescription("A spell that envelops the area around your character in darkness.");
	}
};

//Item Spells
class Light : public Spell {
private:

public:
	Light() {
		setCost(50);
		setPointCost(2);
		setType('i');
		setDescription("Light spell that functions the same as the lantern item.");
	}
};

class Unlock : public Spell {
private:

public:
	Unlock() {
		setCost(75);
		setPointCost(4);
		setType('i');
		setDescription("Unlock spell that functions the same as the lockpicks item.");
	}

};

class Levitate : public Spell {
private:

public:
	Levitate() {
		setCost(75);
		setPointCost(4);
		setType('i');
		setDescription("Levitate spell that functions the same as the rope item.");
	}

};
#endif