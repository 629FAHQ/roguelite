/**
	콘솔인터페이스가 할 일
	
	
	- 출력 -
	1. Ingame에게 x, y 좌표에 뭐 있는지 물어보기
		좌표에 벽이나 어떤 엔티티가 있는지
		좌표의 어떤 엘리먼트가 있는지
		
	
	2. 물어본거 콘솔아웃풋에게 알려주기
	3. 반영하기
	4. 출력해주기
	
*/

#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H

#include "Interface.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"

class ConsoleInterface : public Interface {
private:
	OutputInterface* outputInterface;
	InputInterface* inputInterface;
public:
	ConsoleInterface();
	~ConsoleInterface();
	
	bool isWall(int x, int y);
	int getEntityId(int x, int y);
	int getElementId(int x, int y);
	
	void updateDisplay();
	void letPlayerAct();
};


/**
	ConsoleInterface의 생성자이다.
*/
ConsoleInterface::ConsoleInterface() {
	//inputInterface = new ConsoleInput(119, 115, 97, 100, 107, 108);
	// W A S D K L
	initscr();
    curs_set(0);
	start_color();
	outputInterface = new ConsoleOutput(40, 10);
	inputInterface = new ConsoleInput();
}

ConsoleInterface::~ConsoleInterface() {
	
    endwin();
	delete inputInterface;
	delete outputInterface;
}

/**
	좌표(x, y)에 벽이 있는지 여부를 반환한다.
	
*/
bool isWall(int x, int y) {
	
}

/**
	좌표(x, y)에 있는 엔티티의 유형을 반환한다.
*/
int getEntityId(int x, int y) {
	
}

/**
	좌표(x, y)에 있는 엘리먼트의 유형을 반환한다.
*/

int getElementId(int x, int y) {
	
}

/**
	현재 게임의 상태를 받아오고 output interface에게 출력하도록 한다.
*/
void ConsoleInterface::updateDisplay() {
	
	/* Game 업데이트 */
	//((ConsoleOutput*)outputInterface)->clearGame();
	//((ConsoleOutput*)outputInterface)->drawGame();
	//((ConsoleOutput*)outputInterface)->showGame();
	
	/* Status 업데이트 */
	//((ConsoleOutput*)outputInterface)->clearStatus();
	//((ConsoleOutput*)outputInterface)->drawStatus();
	//((ConsoleOutput*)outputInterface)->showStatus();
	
	//((ConsoleOutput*)outputInterface)->show();
	
	((ConsoleOutput*)outputInterface)->updateGame();
	((ConsoleOutput*)outputInterface)->updateStatus();
	//((ConsoleOutput*)outputInterface)->_test_print(((ConsoleInput*)inputInterface)->input());
	//getch();
	
	
}

/**
	유저가 입력한 키에 따라 플레이어가 행동할 수 있도록 메시지를 전파한다.
*/
void ConsoleInterface::letPlayerAct() {
	
}
/*
InputInterface(int u, int d, int l, int r, int a, int m);
int getUserAction();
int inputToAction(int value);
virtual int input() = 0;
*/

#endif