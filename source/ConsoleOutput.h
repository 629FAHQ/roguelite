#ifndef CONSOLEOUPUT_H
#define CONSOLEOUPUT_H
#define COLOR_EMPTY 1
#define COLOR_WALL 2
#define COLOR_FIRE 3

/*
1. 색 지정
2. 
*/

class ConsoleOutput : public OutputInterface {
private:
	WINDOW* winGame, * winStatus, * winBackground;
public:
	ConsoleOutput(int w, int h);
	~ConsoleOutput();
	
	void updateGame();
	void clearGame();
	void drawGame();
	void drawTile(int x, int y);
	void showGame();
	
	void updateStatus();
	void clearStatus();
	void drawStatus();
	void showStatus();
	
	void _test_print(int letter) {
		mvwprintw(winGame, 2, 2, "[%c]", letter);
		showGame();
	}
	
	void show();
	

};

ConsoleOutput::ConsoleOutput(int w, int h) : OutputInterface(w, h) {
	
	int status_h = 5;
	
	winBackground = newwin(h+status_h+3, w+2, 0, 0);
	winGame = newwin(h, w, 1, 1);
	winStatus = newwin(status_h, w, h+2, 1);
	
	/*
		1. 빈 공간
		2. 벽
		3. 엘리먼트
		4. 
	*/
	// 글자 색, 배경 색
	
	init_pair(COLOR_EMPTY, COLOR_WHITE, COLOR_BLACK);
	init_pair(COLOR_WALL, COLOR_BLACK, COLOR_WHITE); 
	init_pair(COLOR_FIRE, COLOR_WHITE, COLOR_RED);
	
	wbkgd(winBackground, COLOR_PAIR(COLOR_WALL));
	
	wbkgd(winGame, COLOR_PAIR(COLOR_EMPTY));
	
	wbkgd(winStatus, COLOR_PAIR(COLOR_EMPTY));
	refresh();
	wrefresh(winBackground);
	wrefresh(winGame);
	wrefresh(winStatus);
}

ConsoleOutput::~ConsoleOutput() {
	delwin(winGame);
	delwin(winStatus);
}


/**
	현재 게임의 정보를 받아와 업데이트 한다.
*/
void ConsoleOutput::updateGame() {
	clearGame();
	drawGame();
	showGame();
	getch();
}
/**
	화면을 그리기 전 깨끗이 빈 화면으로 만든다.
*/
void ConsoleOutput::clearGame() {
	wclear(winGame);
}
/**
	화면을 그린다.
*/
void ConsoleOutput::drawGame() {
	for (int y = 0 ; y < getHeight(); y++ ) {
		for (int x = 0 ; x < getWidth(); x++) {
			drawTile(x, y);
		}
	}
}
/**
	특정 타일을 그린다.
	(x, y 위치에 있는 타일)
	
	벽이라면 그냥 하얀색바탕에 검은색 X
	
	벽이 아니라면 해당 속성에 맞는 색으로
*/
void ConsoleOutput::drawTile(int x, int y) {
	int color_id = COLOR_EMPTY;
	
	bool wall = 0;// = game->isWall();
	int bg = 0; // = game->getElementId();
	char object = ' '; // = game->getObject();
	
	if (wall)
		color_id = COLOR_WALL;
	else if (bg == 1)
		color_id = COLOR_FIRE;
	else
		color_id = COLOR_EMPTY;
		
	mvwaddch(winGame, y, x, object | COLOR_PAIR(color_id));
}
/**
	화면을 출력한다.
*/
void ConsoleOutput::showGame() {
	wrefresh(winGame);
}


/**
	Status를 업데이트한다. (아래의 메소드들을 사용할 중심이 될 메소드다)
*/
void ConsoleOutput::updateStatus() {
	clearStatus();
	drawStatus();
	showStatus();
	
	getch();
}
/**
	화면을 그리기 전 지운다.
*/
void ConsoleOutput::clearStatus() {
	wclear(winStatus);
}
/**
	화면을 그린다.
*/
void ConsoleOutput::drawStatus() {
	int hp = 58; // game->getPlayerHp();
	int mana = 12; // game->getPlayerMana();
	std::string elementName = ""; // game->getElementName();
	
	mvwprintw(winStatus, 0, 1, "Hp : %d", hp);
	mvwprintw(winStatus, 2, 1, "Mana : %d", mana);
	mvwprintw(winStatus, 4, 1, "You are on the %s element.", elementName);
}
/**
	화면을 출력한다.
*/
void ConsoleOutput::showStatus() {
	wrefresh(winStatus);
}





void ConsoleOutput::show() {
	//refresh();
	wrefresh(winBackground);
	mvwprintw(winGame, 1,2, "A");
	mvwprintw(winGame, 1,3, "B");
	wrefresh(winStatus);
	wrefresh(winGame);
	mvwprintw(winGame, 1,4, "C");
	mvwprintw(winGame, 1,5, "C");
	wrefresh(winGame);
	wclear(winGame);
	mvwprintw(winGame, 1,6, "C");
	mvwprintw(winGame, 1,7, "C");
	wrefresh(winGame);
	
	getch();
}



#endif


/*
	리버시를 만든다면?
	
	게임
		인게임
			보드판
				게임말
		인터페이스
			인풋/아웃풋
	
*/