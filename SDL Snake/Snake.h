#ifndef SNAKE_H
#define SNAKE_H


class Snake {
private:
	int m_x, m_y, m_tailSize, headWidth, headHeight, tailWidth, tailHeight;
	int dir;


public:
	Snake();
	~Snake();
	void init();
	int getX() { return m_x; }
	int getY() { return m_y; }
	int getDir() { return dir; }
	void updatePosition(int dir);
	void updateDirection(int direct);
};

#endif