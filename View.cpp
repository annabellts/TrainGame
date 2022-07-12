#include <iostream>

#include "View.h"
#include"Board.h"

View::View() : m_board(nullptr) {}

View::View(std::shared_ptr<Board> board) {
	m_board = board; 
}

void View::printBoard()
{

	std::cout << std::endl;

	for (int row = 0; row < m_board->getBoardHeight(); ++row) {

		std::cout << "  ";
		for (int clm = 0; clm < m_board->getBoardWidth(); ++clm) {

			if (m_board->getGameBoard()[row * m_board->getBoardWidth() + clm]) {

				std::cout << (m_board->getGameBoard()[row * m_board->getBoardWidth() + clm])->draw();
			}
			else {
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
