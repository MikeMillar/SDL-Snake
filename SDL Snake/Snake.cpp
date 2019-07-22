#include "Snake.h"
#include "Screen.h"


Snake::Snake(): m_x(400), m_y(400), m_tailSize(0), headWidth(9), headHeight(9), tailWidth(5), tailHeight(5), dir(0) {}

Snake::~Snake() {}

void Snake::init() {
	
}

void Snake::updateDirection(int direct) {
	switch (direct)
	{
	case 0:
		dir = direct;
		break;
	case 1:
		dir = direct;
		break;
	case 2:
		dir = direct;
		break;
	case 3:
		dir = direct;
		break;
	case 4:
		dir = direct;;
		break;
	}
}

void Snake::updatePosition(int dir) {
	switch (dir)
	{
	case 0:
		break;
	case 4:
		m_x += -10;
		break;
	case 2:
		m_x += 10;
		break;
	case 1:
		m_y += -10;
		break;
	case 3:
		m_y += 10;
		break;
	}
}