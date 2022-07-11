#ifndef RAIL_H
#define RAIL_H

#include "IGameObj.h"

class Rail: IGameObj
{
private:
	bool m_isNorthRail;
	bool m_isEastRail;
	bool m_isSouthRail;
	bool m_isWestRail;
	char m_drawChar{ '#' };

public:
	~Rail()
	{
	}
	Rail();
	Rail(bool isNorthRail, bool isEastRail, bool isSouthRail, bool isWestRail);
	bool getIsNorthRail() { return m_isNorthRail; };
	bool getIsEastRail() { return m_isEastRail; };
	bool getIsSouthRail() { return m_isSouthRail; };
	bool getIsWestRail() { return m_isWestRail; };

	void setIsNorthRail(bool isRail) { m_isNorthRail = isRail; };
	void setIsEastRail(bool isRail) { m_isEastRail = isRail; };
	void setIsSouthRail(bool isRail) { m_isSouthRail = isRail; };
	void setIsWestRail(bool isRail) { m_isWestRail = isRail; };

	char draw() { return m_drawChar; };

};

#endif