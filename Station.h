#ifndef STATION_H
#define STATION_H

#include<string>
#include "IGameObj.h"

//station with stationID (display symbol) and name
class Station 
{
private:
	std::string m_stationName;
	char m_stationID;
public:
	~Station() {};
	Station(char number);
	char draw() { return m_stationID; };
};

#endif