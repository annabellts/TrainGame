#include "Rail.h"

//creates rail with info of neighboring rails and adds station if desired
Rail::Rail(bool isNorthRail, bool isEastRail, bool isSouthRail, bool isWestRail, std::shared_ptr<Station> station)
{
    m_isNorthRail = isNorthRail;
    m_isEastRail = isEastRail;
    m_isSouthRail = isSouthRail;
    m_isWestRail = isWestRail;
    m_station = station;
    if (station){
        m_drawChar = station->draw();
    }
}