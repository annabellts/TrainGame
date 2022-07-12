#include "GameController.h"

//read the game map from provided file and initialize controller
GameController::GameController(std::string file)
{
	m_gameMap = ReadGameMapFromFile(file);
}

//create new board based on game Map and initialize View
void GameController::CreateGame()
{
	m_board = std::shared_ptr<Board>(new Board(m_gameMap));
	m_view = std::shared_ptr<View>(new View(m_board));
	m_view->printBoard();
}

// Main Game flow
void GameController::PlayGame()
{
	std::cout << "Enter Move (wasd):";
	char move{ getMove() };
	m_board->moveTrain(move);
	m_view->printBoard();
}

//reads single character from keyboard to get next move
char GameController::getMove()
{
		char input = _getch();
		return input;

}

//translates files to game map
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
