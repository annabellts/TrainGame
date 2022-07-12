#include <iostream>

#include "View.h"
#include"Board.h"

View::View() : m_board(nullptr) {}

View::View(Board *board) {
	m_board = board; 
}

void View::printBoard()
{

	std::cout << std::endl;

	for (int row = 0; row < (*m_board).getBoardHeight(); ++row) {

		std::cout << "  ";
		for (int clm = 0; clm < (*m_board).getBoardWidth(); ++clm) {

			std::cout << (*(*m_board).getGameBoard()[row * (*m_board).getBoardWidth() + clm]).draw();
		}
	}
	std::cout << std::endl;
}
