#ifndef VIEW_H
#define VIEW_H

#include "Board.h"

class View
{
private:
	Board *m_board;
public:
	~View() {};
	View();
	View(Board *board);
	void printBoard();
};
#endif