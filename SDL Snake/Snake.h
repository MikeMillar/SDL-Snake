#ifndef SNAKE_H
#define SNAKE_H


class Snake {
private:
	int m_x, m_y, m_tailSize, headWidth, headHeight, tailWidth, tailHeight;
	char dir;


public:
	Snake();
	~Snake();
	void init();
	int getX() { return m_x; }
	int getY() { return m_y; }
	void updatePosition(char key);
	void updateDirection(char key);
};

#endif