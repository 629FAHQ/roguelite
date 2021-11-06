#include "InputInterface.h"
#include <ncurses.h>
/*
up 119
left 97
down 115
right 100
attack 32
*/
class ConsoleInput : public InputInterface {
public:
	ConsoleInput() : InputInterface(119, 115, 100, 97, 32) {}
	virtual int listenInput() {
		return getch();
	}
	virtual void up() {
		// 임시 구현
		printw("up\n");
	}
	virtual void down() {
		printw("down\n");
	}
	virtual void right() {
		printw("right\n");
	}
	virtual void left() {
		printw("left\n");
	}
	virtual void attack() {
		printw("attack\n");
	}
	
};