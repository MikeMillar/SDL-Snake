#include "Snake.h"
#include "Screen.h"


Snake::Snake(): m_x(400), m_y(400), m_tailSize(0), headWidth(9), headHeight(9), tailWidth(5), tailHeight(5), dir(STOP) {}

Snake::~Snake() {}

void Snake::init() {
	
}

void Snake::updateDirection(int direct) {
	switch (direct)
	{
	case 0:
		dir = STOP;
		break;
	case 1:
		dir = UP;
		break;
	case 2:
		dir = RIGHT;
		break;
	case 3:
		dir = DOWN;
		break;
	case 4:
		dir = LEFT;
		break;
	}
}

void Snake::updatePosition(directions dir) {
	switch (dir)
	{
	case Snake::STOP:
		break;
	case Snake::LEFT:
		m_x += -10;
		break;
	case Snake::RIGHT:
		m_x += 10;
		break;
	case Snake::UP:
		m_y += -10;
		break;
	case Snake::DOWN:
		m_y += 10;
		break;
	}
}