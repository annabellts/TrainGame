#ifndef STATION_H
#define STATION_H

#include <string>

//station with stationID (display symbol) and name
class Station 
{
private:
	std::string m_stationName;
	char m_stationID;
public:
	~Station() {};
	Station(char number, std::string name);
	char draw() { return m_stationID; };
	std::string getStationName() { return m_stationName; };
};

#endif