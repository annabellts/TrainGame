#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Rail.h"

class Board {
private:
	const int m_cBoardHeight{ 20 };
	const int m_cBoardWidth{ 20 };

	std::vector<IGameObj> gameBoard;
public:

};

#endif