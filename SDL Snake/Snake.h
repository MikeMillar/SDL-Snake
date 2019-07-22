#ifndef SNAKE_H
#define SNAKE_H


class Snake {
private:
	int m_x, m_y, m_tailSize, headWidth, headHeight, tailWidth, tailHeight;


public:
	Snake();
	~Snake();
	void init();
	void drawSnake();
	int getX() { return m_x; }
	int getY() { return m_y; }

};

#endif