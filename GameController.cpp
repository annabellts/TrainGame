#include "GameController.h"

GameController::GameController(std::string file)
{
	m_gameMap = ReadGameMapFromFile(file);
}

void GameController::CreateGame()
{
	m_board = std::shared_ptr<Board>(new Board(m_gameMap));
	m_view = std::shared_ptr<View>(new View(m_board));
}



void GameController::ViewBoard()
{
	m_view->printBoard();
}

std::vector<std::string> GameController::ReadGameMapFromFile(std::string file)
{
	std::ifstream read(file);
	if (!read)
	{
		// Print an error and exit
		std::cerr << "File could not be opened.\n";
	}
	while (read) {
		std::string line;
		std::getline(read, line);
		m_gameMap.push_back(line);
	}

	return std::vector<std::string>(m_gameMap);
}
