/**
	OutputInterface의 책임
	
	1. 게임의 현황(맵, 플레이어, 몬스터 등)을 보여준다.
	2. 플레이어의 status와 같은 게임 플레이에 도움이 되는 정보를 보여준다.
*/
#ifndef OUTPUTINTERFACE_H
#define OUTPUTINTERFACE_H

class OutputInterface {
private:
	const int height, width;
public:
	OutputInterface(int w, int h);
	virtual ~OutputInterface() = 0;
	int getHeight();
	int getWidth();
	//bool canDisplayAll(); // 이건 터미널 인터페이스에 추가하자.
	
	//virtual void drawMap(int w, int h, int x, int y) = 0; // 보여줄 보드 사이즈에 맞춰 맵을 보여준다.
	//virtual void drawStatus(int w, int h, int x, int y) = 0;
	
	/*
	void drawMessage(int x, int y, int mx, int my, string message); // mx, my는 메시지 박스의 가로 세로 크기. 메시지 박스보다 긴 문장은 그냥 짤림.
	void drawHP(int x, int y); // 해당 좌표에 현재 체력을 표시한다.
	void drawMana(int x, int y); // 해당 좌표에 현재 마나를 표시한다.
	*/
};

OutputInterface::OutputInterface(int w, int h) : height(h), width(w) {
	
}

OutputInterface::~OutputInterface() {
	
}

int OutputInterface::getHeight() {
	return height;
}

int OutputInterface::getWidth() {
	return width;
}
#endif