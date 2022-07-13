#ifndef BOARD_H
#define BOARD_H


#include "Rail.h"
#include "Train.h"

#include <memory>
#include <vector>
#include <string>

// game board class, consists of rails objetcts (with stations) and one train object
//train can move around the board on rails
class Board {
private:
	const int m_cBoardHeight{ 18 };
	const int m_cBoardWidth{ 21 };

	std::vector<std::shared_ptr<IGameObj>> m_gameBoard{ m_cBoardHeight * m_cBoardWidth};
	std::vector<std::shared_ptr<Station>> m_stationList;
	std::shared_ptr<Train> m_train;
	std::vector<int> m_trainCoordinates;

public:
	~Board() {};
	Board(std::vector<std::string> gameMap, std::vector<std::string> stationNames);

	int getBoardHeight() { return m_cBoardHeight; }
	int getBoardWidth() { return m_cBoardWidth; }
	std::vector<int> getTrainCoordinates() { return m_trainCoordinates; }
	std::shared_ptr<Train> getTrain() { return m_train; }
	std::vector<std::shared_ptr<IGameObj>> getGameBoard() { return m_gameBoard; }

	void moveTrain(char move);
};

#endif