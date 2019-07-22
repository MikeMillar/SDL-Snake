#include "Snake.h"
#include "Screen.h"

using namespace std;

Snake::Snake(): m_x(400), m_y(400), m_tailSize(0), headWidth(9), headHeight(9), tailWidth(5), tailHeight(5), dir(' ') {}

Snake::~Snake() {}

void Snake::init() {
	
}

void Snake::updateDirection(char key) {
	dir = key;
}

void Snake::updatePosition(char key) {
	switch (key)
	{
	case 'w':
		m_y += -5;
		break;
	case 's':
		m_y += 5;
		break;
	case 'a':
		m_x += -5;
		break;
	case 'd':
		m_x += 5;
		break;
	}
}