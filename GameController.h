#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include"Board.h"
#include"View.h"

class GameController
{
private:
	Board *m_board;
	View *m_view;

public:
	~GameController() {};
	GameController();
	void ViewBoard();
};
#endif 