// AncientCityRPG.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <string>
#include "objects.h"
#include "monsters.h"
#include "classes.h"
#include "shop.h"
#include "spells.h"
#include "char.h"


using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

enum {
	mapHeight = 30,
	mapWidth = 30,
	north = 1,
	south = 2,
	east = 3,
	west = 4
};

//Functions
void playerAttack(player* playerOne, Monster* monster);
void monsterAttack(player* playerOne, Monster* monster);
void characterCreation(player* playerOne);
void shop(player* playerOne);
void mainMenu(player* playerOne);
void randMonster(Monster* randomMonster);
void deathCheckM(Monster* randomMonster, bool* infight, char* lastAction);
void deathCheckP(player* playerOne, bool* gameRunning);
void singleMonsterFight(player* playerOne, Monster* monster, bool* gameRunning);

//Intialize Map
vector<vector<int>> map;

int main() {

	//build random Map? Currently all 0's
	int input = 0;
	for (int i = 0; i < mapHeight; i++) {
		vector<int> inputVec;
		for (int j = 0; j < mapWidth; j++) {
			//cin >> input;
			inputVec.push_back(input);
		}
		map.push_back(inputVec);
	}
	while (true) {

		// Intialize srand seed for random number generation
		srand(unsigned int(time(NULL)));

		cout << "\n";
		cout << "\n";
		bool gameRunning = true;
		while (gameRunning) {
			cout << "Welcome to the Ancient City Text Adventure!?\n";
			cout << "Please enter your character name:\n";
			//Set name/create player object
			string playerName;
			cin >> playerName;
			player playerOne(playerName);

			//Creates char and sets stats
			characterCreation(&playerOne);
			
			//TODO Fix or Add to Intro?
			cout << "Growing up in a small village outside of the great forest you have heard tales of the ancient city and its treasures lost within the forest all your life.\n"
				"Upon reaching adulthood you collected your things and headed into the forest to find adventure,\n fortune and the ancient city!\n"
				"As you leave your village you enter a small clearing with a merchant's caravan off the path.\n This is a good chance to buy supplies before heading out!\n";

			//Shop
			shop(&playerOne);
			
			//Display char stats
			playerOne.display();

			//Set starting position 30 x 30 map
			playerOne.setPositionX(15);
			playerOne.setPositionY(1);
			

			//TODO:Create and use map, check each move to make sure its possible.
			//TODO: Terrain types? Obstacles?(i.e. cliffs, caves, climable tree, blocked cave, ruin, crypt/tomb)
			while (gameRunning) {
				mainMenu(&playerOne);
				Monster randomMonster;
				randMonster(&randomMonster);
				singleMonsterFight(&playerOne, &randomMonster, &gameRunning);
			}
		}
	}

}// End


//TODO:Create and use map, check each move to make sure its possible, if possible check for monsters at new location and trigger fight,
//no monsters or after fight describe the new scene. 
void move(player* playerOne, int  direction) {
	//north
	if (direction == 1) {
		playerOne->setPositionY(playerOne->getPositionY() + 1);
	}
	//south
	else if (direction == 2) {
		playerOne->setPositionY(playerOne->getPositionY() - 1);
	}
	//east
	else if (direction == 3) {
		playerOne->setPositionX(playerOne->getPositionX() + 1);
	}
	//west
	else if (direction == 4) {
		playerOne->setPositionX(playerOne->getPositionX() - 1);
	}

}
//Main Menu Tree
void mainMenu(player* playerOne) {
	int input = 0;
	while (input < 1 || input > 5) {
		cout << "Choose an action: 1-Travel Onward, 2-Check Surroundings, 3-Inventory, 4-Equipment, 5-Quit Game\n";
		cin >> input;
		switch (input) {
		case 1:
			cout << "You continue your journey.\n";
			cout << "DEBUGINFO: Current Location X:" <<playerOne->getPositionX() << ", Y:" << playerOne->getPositionY() << "\n";
			input = -1;
			cout << "Choose a direction: 1-Path to the north, 2-Path to the south, 3-Path to the east, 4-Path to the west\n";
			while (input < 1 || input > 3) {
				cin >> input;
				if (input == 1) {
					//checkMapMove(); //To see if movewment to this space is possible. put in move.
					//spaceEvent(); // get position info and trigger and event/fight on that space.
					//Implement surroundings and certain actions at certain locations i.e. caves, cliffs, locked doors, ruins, rivers, 
					//paths blocked by underbrush/trees, cemetary?, tomb/crypt?
					cout << "You take the path going north.\n"; //change to getting scence from object make map a vector of said objects.
					move(playerOne, input);
				}
				else if (input == 2) {
					cout << "You take the path going south.\n";
					move(playerOne, input);
				}
				else if (input == 3) {
					cout << "You take the path going east.\n";
					move(playerOne, input);
				}
				else if (input == 4) {
					cout << "You take the path going west.\n";
					move(playerOne, input);
				}
			}
			break;
		case 2:
			//TODO:Examine your surroundings
			cout << "You examine your surroundings....\n";
			cout << "Your current position is X:" << playerOne->getPositionX() << ", Y:" << playerOne->getPositionY() << "\n";
			input = -1;
			break;
		case 3:
			playerOne->displayInventory();
			input = -1;
			break;
		case 4:
			//TODO:Equipment system / menu
			//Display Current Equipment
			cout << "Equipped Weapon: \n";
			playerOne->getWeapon().displayWeapon();
			cout << "Equipped Armor:\n";
			playerOne->getArmor().displayArmor();


			//Present equip menu
			while (input < 1 || input > 2) {
				cout << "Equipment Menu: 1-Equip Weapon, 2-Equip Armor\n";
				cin >> input;
				if (input == 1) {
					
				}
				else if (input == 2) {
					
				}

			}
			//playerOne.getEquipment();
			input = -1;
			break;
		case 5:
			//TODO:Equipment system / menu
			cout << "Are you sure you would like to quit game? (y or n)\n";
			char decision;
			cin >> decision;
			if (decision == 'y' || decision == 'Y') {
				cout << "Quitting Game. See you next time!\n";
				exit(0);
			}
			else {
				input = -1;
			}
			break;
		default: cout << "Please select one of the listed options to continue...\n";
			break;
		}
	}

}

void shop(player* playerOne) {
	cout << "Why hello there traveler!\n I have some supplies if you want to browse my wares?\n";
	char inputC;
	int input = -1;

	//Shop object instance
	Shop shopOne;

	//Shop decision tree
	while (input != 5) {

		cout << "Do you wish to buy anything? 1-Weapons, 2-Armor, 3-Items, 4-Sell Equipment, or 5-Continue your Journey?\n";
		cin >> input;
		switch (input) {
		case 1:
			input = -1;
			cout << "What weapon would you like to buy? 1-" << shopOne.getDagger().getName() << "(" << shopOne.getDagger().getCost() <<
				" gold pieces) 2-" << shopOne.getMace().getName() << "(" << shopOne.getMace().getCost() <<
				" gold pieces) 3-" << shopOne.getSword().getName() << "(" << shopOne.getSword().getCost() << " gold pieces).\n";
			cin >> input;
			if (input == 1) {
				if (playerOne->getGold() >= shopOne.getDagger().getCost() && (playerOne->getWeight()+shopOne.getDagger().getWeight()) <= playerOne->getAllowedWeight()) {
					cout << "You bought a " << shopOne.getDagger().getName() << " for " << shopOne.getDagger().getCost() << " gold pieces.\n";
					playerOne->addToInventory(shopOne.getDagger());
					playerOne->setWeight(playerOne->getWeight() + shopOne.getDagger().getWeight());
					playerOne->setGold(playerOne->getGold() - shopOne.getDagger().getCost());
					cout << "You have " << playerOne->getGold() << " gold pieces left.\n";

					//ask if they want to equip weapon if yes equip if no proceed.
					char inputC;
					cout << "Do you want to equip the " << shopOne.getDagger().getName() << " ? (y or n)";
					cin >> inputC;
					if (inputC == 'y' || inputC == 'Y') {
						playerOne->setWeapon(shopOne.getDagger());
						inputC = 'n';
						cout << "You equip the " << playerOne->getWeapon().getName() << ".\n";
					}
					else {
						input = -1;
						break;
					}
				}
				else {
					cout << "You do not have enough gold to purchase this item.\n";
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}
			}
			else if (input == 2) {
				if (playerOne->getGold() >= shopOne.getMace().getCost() && (playerOne->getWeight() + shopOne.getMace().getWeight()) <= playerOne->getAllowedWeight()) {
					cout << "You bought a " << shopOne.getMace().getName() << " for " << shopOne.getMace().getCost() << " gold pieces.\n";
					playerOne->addToInventory(shopOne.getMace());
					playerOne->setWeight(playerOne->getWeight() + shopOne.getMace().getWeight());
					playerOne->setGold(playerOne->getGold() - shopOne.getMace().getCost());
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}
				else {
					cout << "You do not have enough gold to purchase this item.\n";
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}

				
				cout << "Do you want to equip the " << shopOne.getMace().getName() << " ? (y or n)";
				cin >> inputC;
				if (inputC == 'y' || inputC == 'Y') {
					playerOne->setWeapon(shopOne.getMace());
					inputC = 'n' ;
					cout << "You equip the " << playerOne->getWeapon().getName() << ".\n";
				}
				else {
					input = -1;
					break;
				}

			}
			else if (input == 3) {
				if (playerOne->getGold() >= shopOne.getSword().getCost() && (playerOne->getWeight() + shopOne.getSword().getWeight()) <= playerOne->getAllowedWeight()) {
					cout << "You bought a " << shopOne.getSword().getName() << " for " << shopOne.getSword().getCost() << " gold pieces.\n";
					playerOne->addToInventory(shopOne.getSword());
					playerOne->setWeight(playerOne->getWeight() + shopOne.getSword().getWeight());
					playerOne->setGold(playerOne->getGold() - shopOne.getSword().getCost());
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}
				else {
					cout << "You do not have enough gold to purchase this item.\n";
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}
				cout << "Do you want to equip the " << shopOne.getSword().getName() << " ? (y or n)";
				cin >> inputC;
				if (inputC == 'y' || inputC == 'Y') {
					playerOne->setWeapon(shopOne.getSword());
					inputC = 'n';
					cout << "You equip the " << playerOne->getWeapon().getName() << ".\n";
				}
				else {
					input = -1;
					break;
				}
			}
			input = -1;
			break;
		case 2:
			input = -1;
			cout << "What armor would you like to buy? 1-" << shopOne.getLeatherArmor().getName() << "(" << shopOne.getLeatherArmor().getCost() <<
				" gold pieces) 2-" << shopOne.getChainArmor().getName() << "(" << shopOne.getChainArmor().getCost() <<
				" gold pieces) 3-" << shopOne.getPlateArmor().getName() << "(" << shopOne.getPlateArmor().getCost() << " gold pieces).\n";
			cin >> input;
			if (input == 1) {
				if (playerOne->getGold() >= shopOne.getLeatherArmor().getCost() && (playerOne->getWeight() + shopOne.getLeatherArmor().getWeight()) <= playerOne->getAllowedWeight()) {
					cout << "You bought " << shopOne.getLeatherArmor().getName() << " for " << shopOne.getLeatherArmor().getCost() << " gold pieces.\n";
					playerOne->addToInventory(shopOne.getLeatherArmor());
					playerOne->setGold(playerOne->getGold() - shopOne.getLeatherArmor().getCost());
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}
				else {
					cout << "You do not have enough gold to purchase this item.\n";
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}
				cout << "Do you want to equip the " << shopOne.getLeatherArmor().getName() << " ? (y or n)";
				cin >> inputC;
				if (inputC == 'y' || inputC == 'Y') {
					playerOne->setArmor(shopOne.getLeatherArmor());
					inputC = 'n';
					cout << "You equip the " << playerOne->getArmor().getName() << ".\n";
				}
				else {
					input = -1;
					break;
				}
			}
			else if (input == 2) {
				if (playerOne->getGold() >= shopOne.getChainArmor().getCost() && (playerOne->getWeight() + shopOne.getChainArmor().getWeight()) <= playerOne->getAllowedWeight()) {
					cout << "You bought " << shopOne.getChainArmor().getName() << " for " << shopOne.getChainArmor().getCost() << " gold pieces.\n";
					playerOne->setArmor(shopOne.getChainArmor());
					playerOne->setGold(playerOne->getGold() - shopOne.getChainArmor().getCost());
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}
				else {
					cout << "You do not have enough gold to purchase this item.\n";
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}
				cout << "Do you want to equip the " << shopOne.getChainArmor().getName() << " ? (y or n)";
				cin >> inputC;
				if (inputC == 'y' || inputC == 'Y') {
					playerOne->setArmor(shopOne.getChainArmor());
					inputC = 'n';
					cout << "You equip the " << playerOne->getArmor().getName() << ".\n";
				}
				else {
					input = -1;
					break;
				}
			}
			else if (input == 3) {
				if (playerOne->getGold() >= shopOne.getPlateArmor().getCost() && (playerOne->getWeight() + shopOne.getPlateArmor().getWeight()) <= playerOne->getAllowedWeight()) {
					cout << "You bought " << shopOne.getPlateArmor().getName() << " for " << shopOne.getPlateArmor().getCost() << " gold pieces.\n";
					playerOne->setArmor(shopOne.getPlateArmor());
					playerOne->setGold(playerOne->getGold() - shopOne.getPlateArmor().getCost());
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}
				else {
					cout << "You do not have enough gold to purchase this item.\n";
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}
				cout << "Do you want to equip the " << shopOne.getPlateArmor().getName() << " ? (y or n)";
				cin >> inputC;
				if (inputC == 'y' || inputC == 'Y') {
					playerOne->setArmor(shopOne.getPlateArmor());
					inputC = 'n';
					cout << "You equip the " << playerOne->getArmor().getName() << ".\n";
				}
				else {
					input = -1;
					break;
				}
			}
			input = -1;
			break;
		case 3:
			input = -1;
			cout << "What item do you want to buy? 1-" << shopOne.getLockpicks().getName() << "(" << shopOne.getLockpicks().getPicks()
				<< "picks)(" << shopOne.getLockpicks().getCost() << "gold pieces), 2-Minor Heal Potion("
				<< shopOne.getMinorHeal().getCost() << "gold pieces), 3-" << shopOne.getLantern().getName() << "("
				<< shopOne.getLantern().getCost() << " gold pieces), 4-" << shopOne.getBomb().getName() << "("
				<< shopOne.getBomb().getCost() << "gold pieces), 5-" << shopOne.getRope().getName() << "("
				<< shopOne.getRope().getUses() << " uses)(" << shopOne.getRope().getCost() << " gold pieces)";
			cin >> input;
			if (input == 1) {
				if (playerOne->getGold() >= shopOne.getLockpicks().getCost()) {
					cout << "You bought " << shopOne.getLockpicks().getName() << " for " << shopOne.getLockpicks().getCost() << " gold pieces.\n";
					playerOne->addToInventory(shopOne.getLockpicks());
					playerOne->setGold(playerOne->getGold() - shopOne.getLockpicks().getCost());
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}
				else {
					cout << "You do not have enough gold to purchase this item.\n";
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}

			}
			else if (input == 2) {
				if (playerOne->getGold() >= shopOne.getMinorHeal().getCost()) {
					cout << "You bought " << shopOne.getMinorHeal().getName() << " for " << shopOne.getMinorHeal().getCost() << " gold pieces.\n";
					playerOne->addToInventory(shopOne.getMinorHeal());
					playerOne->setGold(playerOne->getGold() - shopOne.getMinorHeal().getCost());
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}
				else {
					cout << "You do not have enough gold to purchase this item.\n";
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}

			}
			else if (input == 3) {
				if (playerOne->getGold() >= shopOne.getLantern().getCost()) {
					cout << "You bought " << shopOne.getLantern().getName() << " for " << shopOne.getLantern().getCost() << " gold pieces.\n";
					playerOne->addToInventory(shopOne.getLantern());
					playerOne->setGold(playerOne->getGold() - shopOne.getLantern().getCost());
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}
				else {
					cout << "You do not have enough gold to purchase this item.\n";
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}

			}
			else if (input == 4) {
				if (playerOne->getGold() >= shopOne.getBomb().getCost()) {
					cout << "You bought " << shopOne.getBomb().getName() << " for " << shopOne.getBomb().getCost() << " gold pieces.\n";
					playerOne->addToInventory(shopOne.getBomb());
					playerOne->setGold(playerOne->getGold() - shopOne.getBomb().getCost());
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}
				else {
					cout << "You do not have enough gold to purchase this item.\n";
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}
			}
			else if (input == 5) {
				if (playerOne->getGold() >= shopOne.getRope().getCost()) {
					cout << "You bought " << shopOne.getRope().getName() << " for " << shopOne.getRope().getCost() << " gold pieces.\n";
					playerOne->addToInventory(shopOne.getRope());
					playerOne->setGold(playerOne->getGold() - shopOne.getRope().getCost());
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}
				else {
					cout << "You do not have enough gold to purchase this item.\n";
					cout << "You have " << playerOne->getGold() << " gold pieces.\n";
				}

			}
			input = -1;
			break;
		case 4:
			cout << "What would you like to sell?";
			//playerOne.setGold(playerOne.getGold() - shopOne.getRope().getCost());
			cin >> input;
			input = -1;
			break;
		default:
			break;
		}//end of switch
	}//end of while

}

//Create char, intial stats/class
void characterCreation(player* playerOne) {
	int input = -1;
	while (input < 1 || input > 3) {
		cout << "Please select a class:\n"
			"1- Fighter: High Health, High Combat, Low Magic, Always needs Keys. \n"
			"2- Mage: Low Health, Low Combat, High Magic, Can learn unlock spell, allowing a medium chance to pick locks.\n"
			"3- Thief: Medium Health, Medium Combat, Medium Magic, Has a chance a high chance to pick locks.\n";
		cin >> input;
		switch (input) {

		case 1:
			playerOne->setClass(input);
			cout << "You selected a fighter.\n";
			break;
		case 2:
			playerOne->setClass(input);
			cout << "You selected a mage.\n";
			break;
		case 3:
			playerOne->setClass(input);
			cout << "You selected a thief.\n";
			break;
		default:cout << "Please select one of the listed options to continue...\n";
			break;
		}
	}



	//Roll intial health + modifier and stats based on class
	int i = playerOne->getClassN();
	//Set player starting stats
	//Fighter
	if (input == 1) {
		playerOne->setHealth((rand() % 20) + 20);
		playerOne->setCombat(18);
		playerOne->setMagic(20);
	}
	//Mage
	else if (input == 2) {
		playerOne->setHealth((rand() % 20) + 5);
		playerOne->setCombat(20);
		playerOne->setMagic(18);
	}
	//Thief
	else {
		playerOne->setHealth((rand() % 20) + 10);
		playerOne->setCombat(19);
		playerOne->setMagic(19);
	}

	//Display current player stats
	cout << "Your current stats are:\n";
	playerOne->display();
}

//Allows monsters to attack the player
void monsterAttack(player* playerOne, Monster* monster) {
	//Attack roll
	int roll = (rand() % 20) + 1;
	
	if (monster->getCombat() > monster->getMagic() && monster->getHealth() > 0) {
		cout << "The " << monster->getSpecies() << " attempts to attack you!\n";
		if (roll > monster->getCombat() - playerOne->getArmorV()) {
			cout << "The " << monster->getSpecies() << " hits you for " << monster->getWeapon().getDmg() << " damage.\n";
			playerOne->setHealth(playerOne->getHealth() - monster->getWeapon().getDmg());
			cout << "You have " << playerOne->getHealth() << " health left.";
		}
		else {
			cout << "The " << monster->getSpecies() << " missed you.\n";
		}
	}
}

//Allows player to attack, cast spell, or run away during monster encounter
void playerAttack(player* playerOne, Monster* monster) {
	int input = 0;
	//Attack roll
	int roll = (rand() % 20) + 1;
	while (input < 1 || input > 3 && monster->getHealth() > 0) {
		cout << "Which action will you take: \n"
			"1- Attack\n"
			"2- Magic\n"
			"3- Run Away\n";
		cin >> input;
		switch (input) {
		case 1:
			cout << "The " << monster->getSpecies() << " has " << monster->getHealth() << " health left.\n";
			cout << "You attempt to attack the " << monster->getSpecies() << " with your "<< playerOne->getWeapon().getName() <<".\n";
			if (roll >= (playerOne->getCombat() - monster->getArmor())) {
				cout << "You hit the " << monster->getSpecies() << " for " << playerOne->getWeapon().getDmg() << " damage!\n";
				if (monster->getHealth() - playerOne->getWeapon().getDmg() <= 0)
					monster->setHealth(0);
				else
					monster->setHealth(monster->getHealth() - playerOne->getWeapon().getDmg());
				cout << "The " << monster->getSpecies() << " has " << monster->getHealth() << " health left.\n";
			}
			else {
				cout << "You missed the " << monster->getSpecies() << "!\n";;
			}
			break;
		case 2:
			cout << "The " << monster->getHealth() << " has " << monster->getHealth() << " health left.\n";
			cout << "You try to cast magic missle...\n";
			if (roll >= playerOne->getMagic() - monster->getArmor()) {
				cout << "Your spell hits the " << monster->getSpecies() << " for 5 damage!\n";
				
				if (monster->getHealth() - 5 <= 0)
					monster->setHealth(0);
				else
					monster->setHealth(monster->getHealth() - 5);
				cout << "The " << monster->getSpecies() << " has " << monster->getHealth() << " health left.\n";
			}
			else {
				cout << "Your spell fizzled and died, having no effect on the " << monster->getSpecies() << ".\n";
			}
			break;
		case 3:
			cout << "You attempt to turn run away from the " << monster->getSpecies() << ".\n";
			//TODO:Percentage check of some kind to run away?
			break;
		default: cout << "Please select one of the listed options to continue...\n";
			break;
			
		}
	}
}

void randMonster(Monster* randomMonster) {
	int random = rand() % 3;//or total in random list for day/night or difficulty?
	
	//put in function->
	if (random == 2) {
		Skeleton skel;
		*randomMonster = skel;
	}
	else if (random == 3) {
		Lizardman liz;
		*randomMonster = liz;
	}
	else {
		Goblin gob;
		*randomMonster = gob;
	}

	//random weapon generation for monsters in function
	int rn = rand() % 5;
	if (rn == 1) {
		Sword mon;
		randomMonster->setWeapon(mon);

	}
	else if (rn == 2) {
		Dagger mon;
		randomMonster->setWeapon(mon);

	}
	else if (rn == 3) {
		Mace mon;
		randomMonster->setWeapon(mon);

	}
	else if (rn == 4) {
		Staff mon;
		randomMonster->setWeapon(mon);

	}
	else{
		Stick mon;
		randomMonster->setWeapon(mon);

	}
	
}


void deathCheckM(Monster* randomMonster, bool* infight, char* lastAction) {
	if (randomMonster->getHealth() <= 0) {
		*infight = false;
		cout << "The " << randomMonster->getSpecies() << " has died.\n";
		*lastAction = 'd';
	}
}

void deathCheckP(player* playerOne, bool* gameRunning) {
	if (playerOne->getHealth() <= 0) {
		gameRunning = false;
		cout << "You Died! Please try again.\n";
	}
}

void singleMonsterFight(player* playerOne, Monster* randomMonster, bool* gameRunning) {
	//Single monster encounter (one), change one to be whatever monster, or generate.
	cout << "As you reach the next clearing you come upon a lone " << randomMonster->getSpecies() << ".\n"
		"Upon seeing you the " << randomMonster->getSpecies() << " charges you and attacks with a " << randomMonster->getWeapon().getName() << ".\n";
	bool inFight = true;
	int playInit = (rand() % 10) + 1;
	int monsterInit = (rand() % 10) + 1;
	cout << "Initative is rolled, you got a " << playInit << ", the monsters got a " << monsterInit << ".\n";
	while (inFight) {
		char lastAction = 'n';
		if (playInit <= monsterInit && lastAction == 'n') {
			playerAttack(playerOne, randomMonster);
			lastAction = 'p';
			deathCheckM(randomMonster, &inFight, &lastAction);

		}
		else if (playInit > monsterInit && lastAction == 'n') {
			monsterAttack(playerOne, randomMonster);
			deathCheckP(playerOne,gameRunning);
			lastAction = 'm';
		}
		if (lastAction == 'm') {
			playerAttack(playerOne, randomMonster);
			deathCheckM(randomMonster, &inFight, &lastAction);
			cout << "Round Complete###############(One Action each is a round...)\n";

		}
		else if (lastAction == 'p') {
			monsterAttack(playerOne, randomMonster);
			deathCheckP(playerOne, gameRunning);
			cout << "Round Complete###############(One Action each is a round...)\n";
			lastAction = 'm';
			
		}
	}
}
