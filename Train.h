#ifndef TRAIN_H
#define TRAIN_H

#include "IGameObj.h"


class Train : public IGameObj
{
	private:
		char m_drawChar{ 'T' };

	public:
		~Train() {};
		Train();

		char draw() { return m_drawChar; };

};


#endif 