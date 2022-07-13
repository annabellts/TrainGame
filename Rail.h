#ifndef RAIL_H
#define RAIL_H


#include "IGameObj.h"
#include "Station.h"

#include <memory>


class Rail: public IGameObj
{
private:
	bool m_isNorthRail;
	bool m_isEastRail;
	bool m_isSouthRail;
	bool m_isWestRail;
	char m_drawChar{ '#' };
	std::shared_ptr<Station> m_station;

public:
	~Rail() {};
	Rail(bool isNorthRail, bool isEastRail, bool isSouthRail, bool isWestRail, std::shared_ptr<Station>);
	bool getIsNorthRail() { return m_isNorthRail; };
	bool getIsEastRail() { return m_isEastRail; };
	bool getIsSouthRail() { return m_isSouthRail; };
	bool getIsWestRail() { return m_isWestRail; };
	std::shared_ptr<Station> getStation() { return m_station; }

	void setIsNorthRail(bool isRail) { m_isNorthRail = isRail; };
	void setIsEastRail(bool isRail) { m_isEastRail = isRail; };
	void setIsSouthRail(bool isRail) { m_isSouthRail = isRail; };
	void setIsWestRail(bool isRail) { m_isWestRail = isRail; };
	std::shared_ptr<Station> setStation(std::shared_ptr<Station> station) { m_station = station; }

	char draw() { return m_drawChar; };

};

#endif