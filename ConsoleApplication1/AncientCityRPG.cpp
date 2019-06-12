// AncientCityRPG.cpp : Defines the entry point for the console application.
#include "stdafx.h"

#include <iostream>
#include <string>
#include <time.h>

#include "monsters.h"
#include "objects.h"
#include "classes.h"
#include "char.h"
#include "spells.h"

#define TOTAL_MONSTERS  2

using namespace std;

int main() {

	cout << "Welcome to the Ancient City RPG Text Adventure!?\n";
	cout << "Please enter your name:\n";
	string playerName; 
	cin >> playerName;
	player player1(playerName);

	int input = -1;
	while (input < 1 || input > 3) {
		cout << "Please select a class:\n" 
			"1- Fighter: High Health, High Combat, Low Magic, Always needs Keys. \n" 
			"2- Mage: Low Health, Low Combat, High Magic, Can learn unlock spell, allowing a medium chance to pick locks.\n"
			"3- Thief: Medium Health, Medium Combat, Medium Magic, Has a chance a high chance to pick locks.\n";
		cin >> input;
		switch (input){

		case 1:
			player1.setClass(input);
			cout << "You selected a fighter.\n";
			break;
		case 2:
			player1.setClass(input);
			cout << "You selected a mage.\n";
			break;
		case 3:
			player1.setClass(input);
			cout << "You selected a thief.\n";
			break;
		default:cout << "Please select one of the listed options to continue...\n";
			break;
		}
	}	

	

	//Intialize srand seed for random number generation
	srand(time(NULL));

	//Roll intial health + modifier and stats based on class
	int i = player1.getClassN();
	//Set player starting stats
	//Fighter
	if (input == 1) {
		player1.setHealth((rand() % 20) + 20);
		player1.setCombat(10);
		player1.setMagic(3);
	}
	//Mage
	else if (input == 2) {
		player1.setHealth((rand() % 20) + 5);
		player1.setCombat(3);
		player1.setMagic(10);
	}
	//Thief
	else {
		player1.setHealth((rand() % 20) + 10);
		player1.setCombat(7);
		player1.setMagic(5);
	}
	
	//Display current player stats
	player1.display();

	//TODO Fix or Add to Intro?
	cout << "Growing up in a small village outside of the great forest you have heard tales of the ancient city and its treasures lost within the forest all your life.\n"
		"Upon reaching adulthood you collected your things and headed into the forest to find adventure, fortune and the ancient city!\n"
		"As you leave your village you enter a small clearing with a merchant's caravan off the path.This is a good chance to buy supplies before heading out!\n";
	
	//TODO shop


	
	input = -1;
	//TODO First directional choice, cant go south; reuseable for any path is blocked etc.....
	while (input < 0 || input > 3) {
		cout << "Choose a direction: Path to the north - 0, Path to the south - 1, Path to the east - 2 , Path to the west - 3\n";
		cin >> input;
		switch (input) {
		case 0:
			cout << "You take the path going north.\n";
			break;
		case 1:
			cout << "You attempt to take the path going south, " 
				"but you quickly realize this path leads back home and the call of adventure forces you to turn around.\n"
				"Choose another path.\n";
			input = -1;
			break;
		case 2:
			cout << "You take the path going east.\n";
			break;
		case 3:
			cout << "You take the path going west.\n";
			break;
		default:cout << "Please select one of the listed options to continue...\n";
			break;
		}
	}

	//TODO First Monster fight
	
	//TODO:Random monster Generation
	goblin one;
	/*
	int randomMonster  = rand() % TOTAL_MONSTERS;
	if(randomMonster == 2)
		skeleton one;
	else if (randomMonster == 3) {
		
	}
	else {
		goblin one;
	}
	*/
	//Single monster encounter (one), change one to be whatever monster, or generate.
	cout << "Upon reaching the next clearing you come upon a lone " << one.getType() << ".\n"
		"Once it sees you the " << one.getType() << " charges you and attacks with a " << one.getWeapon()  << ".\n";

	input = -1;
	while ((input < 1 || input > 3) && one.getHealth() > 0) {
		cout << "Which action will you take: \n"
			"1- Attack\n"
			"2- Magic\n"
			"3- Run Away\n";

		cin >> input;
		switch (input) {

		case 1:
			cout << "You attempt to attack the " << one.getType() << ".\n";
			if (rand() % player1.getCombat() >= one.getArmor()) {
				cout << "You hit the " << one.getType() << "!\n";
			}
			else{
				cout << "You missed the " << one.getType() << "!\n";;
			}
			break;
		case 2:
			cout << "You try to cast magic missle...\n";
			if (rand() % player1.getMagic() >= one.getArmor()) {
				cout << "Your spell hits the " << one.getType() << "!\n";
			}
			else {
				cout << "Your spell fizzled and died, having no effect on the " << one.getType() << ".\n";
			}
			break;
		case 3:
			cout << "You attempt to turn run away from the " << one.getType() << ".\n";;
			break;
		default:cout << "Please select one of the listed options to continue...\n";
			break;
		}
	}

}

/* reusable directional choice
while (input < 0 || input > 3) {
cin >> input;
switch (input) {
case 0:
cout << "You take the path going north.";
break;
case 1:
cout << "You take the path going south.";
break;
case 2:
cout << "You take the path going east.";
break;
case 3:
cout << "You take the path going west.";
break;
default:cout << "Please select one of the listed options to continue...\n";
break;
}
}

*/

