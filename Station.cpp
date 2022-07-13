#include "Station.h"

Station::Station(char stationSign)
{
	m_stationID = stationSign;
	m_stationName = stationSign;
}

Station::Station(char number, std::string name)
{
	m_stationID = number;
	m_stationName = name;
}
