#ifndef SNAKE_H
#define SNAKE_H


class Snake {
private:
	int m_x, m_y, m_tailSize, headWidth, headHeight, tailWidth, tailHeight;
	enum directions {STOP, LEFT, RIGHT, UP, DOWN};
	directions dir;


public:
	Snake();
	~Snake();
	void init();
	int getX() { return m_x; }
	int getY() { return m_y; }
	directions getDir() { return dir; }
	void updatePosition(directions dir);
	void updateDirection(int direct);
};

#endif