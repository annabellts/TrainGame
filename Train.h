#ifndef TRAIN_H
#define TRAIN_H

class Train
{
	private:
		char m_drawChar{ '+' };
		char m_orientation;

	public:
		~Train() {};
		Train();

		char draw() { return m_drawChar; };
		char getOrientation() { return m_orientation; };

		void setOrientation(char direction) { m_orientation = direction; };

};


#endif 