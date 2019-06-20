#pragma once

class Game {
private:
	unsigned int positionX, positionY;
	bool gameRunning;


public:
	Game();

	Game(const string& file_name);

	void runGame();

	void handleInput();

	void currentPosition();

	void default_map();
};