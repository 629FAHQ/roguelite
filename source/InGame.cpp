
/**
	InGame 클래스의 생성자이다.
*/
InGame::InGame() {
	player = new Player();
	map = new Map(100, 100);
}

InGame::~InGame() {
	delete player;
	delete map;
	

}

/**
	게임의 모든 턴을 진행시킨다.
	각 턴은 플레이어의 행동 1회가 기준이며
	각 턴마다 턴 카운트가 0이 된 몬스터들은 
	적절한 행동을 할 수 있도록 메시지를 전파한다.
*/
void InGame::nextTurn() {
	player->useTurnCount(1);
	if (player->isTurn()) {
		player->setTurnCount();
		// 여기서 인풋 인터페이스로 입력받고 행동 전파 먼저 하기
	}
		
	int w = map->getWidth(), h = map->getHeight();
	for (int y = 1 ; y < h ; y++) {
		for (int x = 1 ; x < w ; x++) {
			if (map->isEntity(x, y, 0) || map->isEntity(x, y, 1))
				continue;
			
			Entity* e = map->getEntity(x, y);
			
			e->useTurnCount(1);
			if (e->isTurn()) // 이걸 여기서 하지 말고 엔티티 내부에서 하도록 하자.
				((Monster*)e)->doing;
		}
	}
	 //모든 좌표에 있는 엔티티의 턴을 -1 한다
}

/**
	게임의 종료조건(성공, 실패 등)에 따라 게임이 종료되었는지 여부를 반환한다.
*/
bool InGame::isFinished() {
	bool res = 0;
	res |= player->isDead(); // 플레이어가 죽었는지
	
	return res;
}

/**
	InputInterface에서 입력받은 값에 따라 플레이어가 어떤 행동을 할 지 전파하는데 사용할 메소드이다.
*/
void InGame::setPlayer(int action) {
	if (action == 1)
		player->goUp();
	else if (action == 2)
		player->goDown();
	else if (action == 3)
		player->goLeft();
	else if (action == 4)
		player->goRight();
	else if (action == 5)
		player->goAttack();
	else
		player->goMana();
}

/**
	OutputInterface에서 사용할 해당 타일이 벽인지 반환하는 메소드이다.
*/
int InGame::isWall (int x, int y) {
	return map->isWall(x, y);
}

/**
	OutputInterface에서 사용할 해당 타일에 Element가 있는지,
	있다면 어떤 Element인지 반환하는 메소드이다.
*/
int InGame::getElementId (int x, int y) {
	return map->getElementId(x, y);
}

/**
	OutputInterface에서 사용할 해당 타일에 Entity(몬스터나 플레이어)가 있는지,
	있다면 플레이어인지 몬스터인지 반환하는 메소드이다.
*/
bool InGame::getEntityId (int x, int y) {
	return map->getEntityId(x, y);
}

void InGame::makeMonster(int x, int y, int hp, int ar, int sr, int damage) {
	if (!map->isEntity(x, y, 0))
		return;
	if (map->isWall())
		return;
	Monster* m = new Monster(x, y, hp, ar, sr, damage, map);
	map->setEntity(x, y, m);
}