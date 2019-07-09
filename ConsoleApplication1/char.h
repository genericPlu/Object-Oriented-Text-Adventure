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
		 int charclass;
		 int level;
		 int experience;
		 int health;
		 int combat;
		 int magic;
		 int armor;
		 int gold;
		 int weight;
		 int allowedWeight;
		 int positionX;
		 int positionY;
		 
		 //Equipment
		 Weapon playerWeapon;
		 Armor playerArmor;
		 vector<Item>  inventory;
		 vector<Spell> spellbook;

	public:
		player(const string n) :
			level(1),
			experience(0),
			health(0),
			combat(0),
			magic(0),
			armor(0),
			gold(100),
			weight(0),
			allowedWeight(50), 
			name(n) {
			Stick startWeapon;
			setWeapon(startWeapon);
			setWeight(startWeapon.getWeight());
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
		void setWeight(int w) {
			weight = w;
		}
		void setAllowedWeight(int w) {
			allowedWeight = w;
		}
		void setWeapon(Weapon w) {
			playerWeapon = w;
		}
		void setArmor(Armor a) {
			playerArmor = a;
		}
		void addToInventory(Item a) {
			inventory.push_back(a);
		}

		

		//Getters
		Weapon getWeapon() {
			return playerWeapon;
		}
		Armor getArmor() {
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
		int getArmorV(){
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
		int getWeight() {
			return weight;
		}
		int getAllowedWeight() {
			return allowedWeight;
		}
		Item getInventoryItem(string name) {
			for (int i = 0; i < inventory.size(); i++) {
				if(inventory[i].getName() == name)
					return inventory[i];
			}
		}

		void displayInventory() {

			playerWeapon.displayWeapon();


			playerArmor.displayArmor();

			if (inventory.size() == 0) {
				cout << "Your inventory is currently empty!\n";
			}
			else {
				for (int i = 0; i < inventory.size(); i++) {
					cout << "Item:" << inventory[i].getName() << "\n";
					cout << "Cost:" << inventory[i].getCost() << "\n";
					cout << "Weight:" << inventory[i].getWeight() << "\n";
					cout << "Description:" << inventory[i].getDescription() << "\n";
				}
			}

			
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
			}
			
		}


};
#endif