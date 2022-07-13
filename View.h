#ifndef VIEW_H
#define VIEW_H

#include "Board.h"

// handles print of board
class View
{
private:
	std::shared_ptr<Board> m_board;
public:
	~View() {};
	View(std::shared_ptr<Board> board);
	void printBoard();
};
#endif