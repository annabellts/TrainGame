#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include<conio.h>
#include"Board.h"
#include"View.h"

class GameController
{
private:
	std::shared_ptr<Board> m_board;
	std::shared_ptr<View> m_view;
	std::vector<std::string> m_gameMap;

public:
	~GameController() { };
	GameController(std::string file);
	void CreateGame();
	void PlayGame();
	char getMove();
	std::vector<std::string> ReadGameMapFromFile(std::string file);
};
#endif 