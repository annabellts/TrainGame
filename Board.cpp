#include "Board.h"

Board::Board()
{
	for (int it = 0; it < m_cBoardHeight * m_cBoardWidth; ++it) {
		m_gameBoard[it] = (std::shared_ptr<IGameObj>) new Rail;
	}
}
