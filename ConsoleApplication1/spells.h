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

//Defense Spells

//Action Spells
class Light : public Spell {
private:

public:
	Light() {
		setCost(50);
		setPointCost(2);
		setType('a');
		setDescription("Light spell that functions the same as the lantern item.");
	}
};

class Unlock : public Spell {
private:

public:
	Unlock() {
		setCost(75);
		setPointCost(4);
		setType('a');
		setDescription("Unlock spell that functions the same as the lockpicks item.");
	}

};

class Levitate : public Spell {
private:

public:
	Levitate() {
		setCost(75);
		setPointCost(4);
		setType('a');
		setDescription("Levitate spell that functions the same as the rope item.");
	}

};
#endif