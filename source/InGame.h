/*
	객체간의 구조 (아마도?)
	
	Game
		InGame
			Map
				Monster
				Player
				Element
			Player
		Interface
			InputInterface
			OutputInterface
	
	
	< 갑자기 깨달은 거 >
		initscr과 같은 curses의 함수를 InGame에서 사용하면 안된다.
		InGame은 interface가 어떻게 구현되어 있는지 알 필요가 없다. 
		(알 경우 InGame의 책임이 과도하게 많아지고 결합도가 증가해 객체지향과는 먼 코드가 된다.)
		따라서 Interface 라는 클래스를 따로 만들고 거기에서 관리를 해야한다.
		
		물론, Interface에서도 Interface라는 추상 클래스를 상속받는 ConsoleInterface가 필요할거같다.
*/

class InGame {
private:
	Player* player;
	Map* map;
	int turn;
public:
	InGame();
	~InGame();
	
	void nextTurn(); // 턴을 진행하고 (이번 턴에 턴 카운트가 모두 소모된 몬스터들이 행동을 할 수 있도록 한다. 참고로 이건 맵 > 엔티티 로 책임이 전파될거다.)
	bool isFinished(); // 게임이 종료되었는지 판단한다.
	
	void setPlayer(int action);
	int isWall (int x, int y, bool absolute);
	int isElement (int x, int y, bool absolute);
	bool isEntity (int x, int y, bool absolute);
};

/**
	InGame 클래스의 생성자이다.
*/
InGame::InGame() {
	
}

/**
	게임의 모든 턴을 진행시킨다.
	각 턴은 플레이어의 행동 1회가 기준이며
	각 턴마다 턴 카운트가 0이 된 몬스터들은 
	적절한 행동을 할 수 있도록 메시지를 전파한다.
*/
void InGame::nextTurn() {
	
}

/**
	게임의 종료조건(성공, 실패 등)에 따라 게임이 종료되었는지 여부를 반환한다.
*/
bool InGame::isFinished() {
	
}

/**
	InputInterface에서 입력받은 값에 따라 플레이어가 어떤 행동을 할 지 전파하는데 사용할 메소드이다.
*/
void InGame::setPlayer(int action) {
	
}

/**
	OutputInterface에서 사용할 해당 타일이 벽인지 반환하는 메소드이다.
*/
int InGame::isWall (int x, int y, bool absolute) {
	
}

/**
	OutputInterface에서 사용할 해당 타일에 Element가 있는지,
	있다면 어떤 Element인지 반환하는 메소드이다.
*/
int InGame::isElement (int x, int y, bool absolute) {
	
}

/**
	OutputInterface에서 사용할 해당 타일에 Entity(몬스터나 플레이어)가 있는지,
	있다면 플레이어인지 몬스터인지 반환하는 메소드이다.
*/
bool InGame::isEntity (int x, int y, bool absolute) {
	
}
