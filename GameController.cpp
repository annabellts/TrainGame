#include "GameController.h"

GameController::GameController()
{
	m_board = new Board;
	m_view = new View(m_board);
}

void GameController::ViewBoard()
{
	m_view->printBoard();
}
