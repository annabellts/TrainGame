#ifndef TRAIN_H
#define TRAIN_H

#include "IGameObj.h"


class Train
{
	private:
		char m_drawChar{ '+' };

	public:
		~Train() {};
		Train() {};

		char draw() { return m_drawChar; };

};


#endif 