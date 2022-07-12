#ifndef IGAMEOBJ_H
#define IGAMEOBJ_H

class IGameObj
{

public:
	virtual ~IGameObj()  {};
	virtual char draw() = 0;

};

#endif