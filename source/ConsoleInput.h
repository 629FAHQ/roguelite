#ifndef CONSOLEINPUT_H
#define CONSOLEINPUT_H
/*		
	   87
	65 83 68
	  W
	A S D
	
	75 76
	K  L
*/
class ConsoleInput : public InputInterface{
private:
public:
	ConsoleInput();
	int input();
};

/**
	생성자
*/
ConsoleInput::ConsoleInput() : InputInterface(87, 83, 65, 68, 75, 76) {
	
}

/**
	사용자의 입력을 받는다.
	(여기선 Ncurses를 이용해 받는다.)
*/
int ConsoleInput::input() {
	int key = getch();
	key -= (key >= 97) ? 32 : 0;
	return key;
}

#endif