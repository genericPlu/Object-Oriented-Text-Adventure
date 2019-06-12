#ifndef CHAR_H_
#define CHAR_H_
#pragma once
#include <iostream>
#include <string>
//Character sheet variables and functions

class player{
	private:
		//Name and class
		std::string name;
		std::string charClass;

		//Stats
		int charclass;
		int level;
		int experience;
		int health;
		int combat;
		int magic;
		int armor;

	public:
		player(std::string n){
			name = n;
			level = 1;
			experience = 0;
			armor = 1;
		}
		//Setters
		void setName(std::string n){
			name = n;
		};
		void setClass(int c){
			charclass = c;
			if (c == 1) {
				charClass = "Fighter";
			}
			else if (c == 2) {
				charClass = "Mage";
			}
			else {
				charClass = "Thief";
			}
		};
		void setLevel(int l){
			level = l;
		};
		void setExperience(int e){
			experience = e;
		};
		void setHealth(int h) {
			health = h;
		};
		void setCombat(int c){
			combat = c;
		};
		void setMagic(int m){
			magic = m;
		};
		void setArmor(int a){
			armor = a;
		};

		//Getters
		std::string getName(){
			return name;
		};
		std::string getClass(){
			return charClass;
		};
		int getClassN() {
			return charclass;
		};
		int getLevel(){
			return level;
		};
		int getExperience(){
			return experience;
		};
		int getHealth() {
			return health;
		};
		int getCombat(){
			return combat;
		};
		int getMagic(){
			return magic;
		};
		int getArmor(){
			return armor;
		};
	
		//Display Stats Command
		void display() {
			std::cout << "Name:" << name << "\n";
			std::cout << "Class:" << charClass << "\n";
			std::cout << "Level:"<< level << "\n";
			std::cout << "Experience:"<< experience << "\n";
			std::cout << "Health:"<< health << "\n";
			std::cout << "Combat:"<< combat << "\n";
			std::cout << "Magic:"<< magic << "\n";
			std::cout << "Armor:"<< armor << "\n";

		}


};
#endif