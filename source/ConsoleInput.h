#include "InputInterface.h"
#include <ncurses.h>
/*
W 119
A 97
S 115
D 100
SPACE 32
ESC 27
*/
class ConsoleInput : public InputInterface {
public:
	ConsoleInput() : InputInterface(119, 115, 100, 97, 32, 27) {}
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
	virtual void quit() {
		printw("quit\n");
	}
	
};