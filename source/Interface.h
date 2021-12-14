/**
	일단 이거는 추상클래스임.
	
	Interface의 책임
	
	게임의 상황을 출력한다.
	사용자의 키 입력을 받고 InGame에 메시지를 전파한다.
	
	
*/
#ifndef INTERFACE_H
#define INTERFACE_H

#include "InputInterface.h"
#include "OutputInterface.h"

class Interface {
private:
	//InGame* game;
	//InputInterface* inputInterface;
	OutputInterface* outputInterface;
public:
	Interface();
	void printScreen();
	void letPlayerDo();
};

Interface::Interface() {
	
}

#endif