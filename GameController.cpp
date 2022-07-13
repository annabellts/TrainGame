#include "GameController.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <conio.h>

//read the game map from provided file and initialize controller
//create new board based on game Map and initialize View

GameController::GameController(std::string file)
{
	std::pair<std::vector<std::string>, std::vector<std::string>> gameMapInfo {ReadGameMapFromFile(file)};
	m_board = std::shared_ptr<Board>(new Board(gameMapInfo.first, gameMapInfo.second));
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
		std::shared_ptr < IGameObj> currentPositionObj{ m_board->getGameBoard()[m_board->getTrainCoordinates().at(0) * m_board->getBoardWidth() + m_board->getTrainCoordinates().at(1)]};
		std::shared_ptr<Station> currentStation{ currentPositionObj->getStation() };
		if (currentStation) {
			std::cout << "You have reached Station " << currentStation->getStationName() << '\n';
		}
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
std::pair<std::vector<std::string>, std::vector<std::string>> GameController::ReadGameMapFromFile(std::string file)
{
	std::vector<std::string> gameMap;
	std::vector<std::string> stationNames;
	std::ifstream fileStream(file);
	if (!fileStream)
	{
		// Print an error and exit
		std::cerr << "File could not be opened.\n";
	}
	std::string line;
	std::getline(fileStream, line);
	while (fileStream && line != "-") {
		gameMap.push_back(line);
		std::getline(fileStream, line);
	}
	while (fileStream) {			
		std::getline(fileStream, line);
		stationNames.push_back(line);
	}
	return std::make_pair(gameMap,stationNames);
}
