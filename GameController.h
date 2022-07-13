#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include"Board.h"
#include"View.h"

#include <string>
#include <vector>

//Controller to handle game flow

class GameController
{
private:
	std::shared_ptr<Board> m_board;
	std::shared_ptr<View> m_view;
	std::vector<std::string> m_gameMap;

public:
	~GameController() { };
	GameController(std::string file);
	void PlayGame();
	char getMove();
	std::vector<std::string> ReadGameMapFromFile(std::string file);
};
#endif 