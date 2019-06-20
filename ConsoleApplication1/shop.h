#pragma once

class Shop {
private:
	int gold;
	Sword sword;
	Mace mace;
	Dagger dagger;
	LeatherArmor  leather;
	ChainArmor  chain;
	PlateArmor  plate;
	Rope   rope;
	Lantern lantern;
	Bomb bomb;
	Lockpicks lockpicks;
	MinorHealPotion minorHeal;

public:

	Shop() :
		gold(500) {
		
	}
	Sword getSword() {
		return sword;
	}
	Mace getMace() {
		return mace;
	}
	Dagger getDagger() {
		return dagger;
	}
	LeatherArmor getLeatherArmor() {
		return leather;
	}
	ChainArmor getChainArmor() {
		return chain;
	}
	PlateArmor getPlateArmor() {
		return plate;
	}
	Rope getRope() {
		return rope;
	}
	Lockpicks getLockpicks() {
		return lockpicks;
	}
	Lantern getLantern() {
		return lantern;
	}
	Bomb getBomb() {
		return bomb;
	}
	MinorHealPotion getMinorHeal() {
		return minorHeal;
	}
	int getGold() {
		return gold;
	}

	void setGold(int g) {
		gold = g;
	}

	~Shop() {}

};