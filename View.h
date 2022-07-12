#ifndef VIEW_H
#define VIEW_H

#include<memory>
#include "Board.h"

class View
{
private:
	std::shared_ptr<Board> m_board;
public:
	~View() {};
	View();
	View(std::shared_ptr<Board> board);
	void printBoard();
};
#endif