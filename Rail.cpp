#include "Rail.h"

Rail::Rail() : m_isNorthRail(false), m_isEastRail(false), m_isSouthRail(false), m_isWestRail(false) {}


Rail::Rail(bool isNorthRail, bool isEastRail, bool isSouthRail, bool isWestRail)
{
    m_isNorthRail = isNorthRail;
    m_isEastRail = isEastRail;
    m_isSouthRail = isSouthRail;
    m_isWestRail = isWestRail;
}

