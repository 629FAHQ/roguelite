#include "InputInterface.h"
#include <ncurses.h>

class ConsoleInput : public InputInterface {
public:
	ConsoleInput();
	int listenInput();
	void up();
	void down();
	void right();
	void left();
	void attack();
	void quit();
};

/**
	ConsoleInput의 생성자이다.
	
	콘솔환경에선 아스키 코드 값을 사용 하므로 인자로 해당 값들을 넘긴다.
	각각 W, S, D, A, SPACE, ESC키의 아스키 코드이다.
*/
ConsoleInput::ConsoleInput() : InputInterface(119, 115, 100, 97, 32, 27) {
	
}

/**
	어떤 키가 입력되었는지 반환한다.
	
	return 입력된 키의 아스키 코드 값
*/
int ConsoleInput::listenInput() {
	return getch();
}

/**
	'위' 키에 대한 메시지를 전파한다.
*/
void ConsoleInput::up() {
		printw("up\n");
}

/**
	'아래' 키에 대한 메시지를 전파한다.
*/
void ConsoleInput::down() {
		printw("down\n");
}

/**
	'왼' 키에 대한 메시지를 전파한다.
*/
void ConsoleInput::left() {
		printw("left\n");
}

/**
	'오른' 키에 대한 메시지를 전파한다.
*/
void ConsoleInput::right() {
		printw("right\n");
}

/**
	'공격' 키에 대한 메시지를 전파한다.
*/
void ConsoleInput::attack() {
		printw("attack\n");
}

/**
	'나가기' 키에 대한 메시지를 전파한다.
*/
void ConsoleInput::quit() {
		printw("quit\n");
}