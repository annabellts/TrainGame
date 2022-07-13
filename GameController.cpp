#include "GameController.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <conio.h>

//read the game map from provided file and initialize controller
//create new board based on game Map and initialize View

GameController::GameController(std::string file)
{
	m_gameMap = ReadGameMapFromFile(file);
	m_board = std::shared_ptr<Board>(new Board(m_gameMap));
	m_view = std::shared_ptr<View>(new View(m_board));
	m_view->printBoard();
}


// Main Game flow
void GameController::PlayGame()
{
	while (true) {
		std::cout << "Please enter move (w: up, a: left, s: down, d: right) or press q to quit : ";
		char move{ getMove() };
		if (move == 'q') {
			return;
		}
		m_board->moveTrain(move);
		system("cls");
		m_view->printBoard();
	}
}

//reads single character from keyboard to get next move
char GameController::getMove()
{
	bool valid{ false };
	char input = _getch();
	while (!valid) {
		if (input == 'w' || input == 'a' || input == 's' || input == 'd' || input == 'q') {
			valid = true;
		}
		else {
			std::cout << "Please press one of the following keys to move: w (up), a (left), s (down), d (right) or press q to quit";
			input = _getch();
		}
	}

	return input;

}

//translates files to game map
std::vector<std::string> GameController::ReadGameMapFromFile(std::string file)
{
	std::ifstream str(file);
	if (!str)
	{
		// Print an error and exit
		std::cerr << "File could not be opened.\n";
	}
	while (str) {
		std::string line;
		std::getline(str, line);
		m_gameMap.push_back(line);
	}

	return std::vector<std::string>(m_gameMap);
}
