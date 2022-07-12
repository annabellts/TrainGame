#ifndef STATION_H
#define STATION_H


#include<string>
#include "IGameObj.h"
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