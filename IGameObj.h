#ifndef IGAMEOBJ_H
#define IGAMEOBJ_H

//Interface for every game object. Currently only Rail, for possible future extensions
class IGameObj
{

public:
	virtual ~IGameObj()  {};
	virtual char draw() = 0;
	virtual bool getIsNorthRail() =0;
	virtual bool getIsEastRail() =0;
	virtual bool getIsSouthRail() =0;
	virtual bool getIsWestRail() =0;
	//virtual std::shared_ptr<Station> getStation() =0;
};

#endif