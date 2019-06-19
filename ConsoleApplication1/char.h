#ifndef CHAR_H_
#define CHAR_H_
#pragma once
//Character sheet variables and functions
using std::cout;
using std::string;
using std::vector;

class player{
	private:
		//Name and class
		 string name;
		 string charClass;

		//Stats
		 unsigned int charclass;
		 unsigned int level;
		 unsigned int experience;
		 int health;
		 unsigned int combat;
		 unsigned int magic;
		 int armor;
		 unsigned int gold;
		 unsigned int positionX;
		 unsigned int positionY;
		 
		 //Equipment
		 Weapon playerWeapon;
		 Armor playerArmor;
		 vector<item>  inventory;



	public:
		player(const string n) :
			level(1),
			experience(0),
			health(0),
			combat(0),
			magic(0),
			armor(0){
			Stick startWeapon;
			setWeapon(startWeapon);
			name = n;
		}
		//Setters
		void setName(string n){
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
		}
		void setLevel(int l){
			level = l;
		}
		void setExperience(int e){
			experience = e;
		}
		void setHealth(int h) {
			health = h;
		}
		void setCombat(int c){
			combat = c;
		}
		void setMagic(int m){
			magic = m;
		}
		void setArmor(int a){
			armor = a;
		}
		void setPositionX(int p) {
			positionX = p;
		}
		void setPositionY(int p) {
			positionY = p;
		}
		void setGold(int g) {
			gold = g;
		}
		void setWeapon(Weapon w) {
			playerWeapon = w;
		}
		void setArmor(Armor a) {
			playerArmor = a;
		}
		
		//Getters
		Weapon getWeapon() {
			return playerWeapon;
		}
		Armor getArmorE() {
			return playerArmor;
		}
		string getName(){
			return name;
		}
		string getClass(){
			return charClass;
		}
		int getClassN() {
			return charclass;
		}
		int getLevel(){
			return level;
		}
		int getExperience(){
			return experience;
		}
		int getHealth() {
			return health;
		}
		int getCombat(){
			return combat;
		}
		int getMagic(){
			return magic;
		}
		int getArmor(){
			return armor;
		}
		int getPositionX() {
			return positionX;
		}
		int getPositionY() {
			return positionY;
		}
		int getGold() {
			return gold;
		}


		//Display Stats Command
		void display() {
			cout << "Name:" << name << "\n";
			cout << "Class:" << charClass << "\n";
			cout << "Level:"<< level << "\n";
			cout << "Experience:"<< experience << "\n";
			cout << "Health:"<< health << "\n";
			cout << "Combat:"<< combat << "\n";
			cout << "Magic:"<< magic << "\n";
			cout << "Armor:"<< armor << "\n";
			cout << "Gold:" << gold << "\n";
			cout << "Equipped weapon:" << playerWeapon.getName() << "\n";
			cout << "Equipped armor:" << playerArmor.getName() << "\n";
			cout << "Inventory:\n";
			for (int i = 0; i < inventory.size(); i++) {
				inventory[i].displayItem();
				cout << ", ";
			}
			
		}


};
#endif