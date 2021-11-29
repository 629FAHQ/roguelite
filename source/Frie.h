// 테스트를 위한 코드
#include "Element.h"
#include "Random.h"
#include <queue>

class Fire : public Element {
private:
	static int affinity;
	static int prefixTable[10];
	static Random rd;
public:
	Fire();
		
	static void initPrefixTable();
	static int getPrefix(int mana);
	
	static int getAffinityLevel();
	static void addAffinity(int num);
	
	int interactWithOtherElement(int damage);
	void attack(int mana);
};

int Fire::affinity = 0;
int Fire::prefixTable = {};
Random Fire::rd = Random();

Fire::Fire(Map* board) : Element(1, board, "Fire", 4) {
	
}

void Fire::initPrefixTable() {
	prefixTable[0] = rd.getRandomInt(1, 7);
	for (int i=1; i<10; i++) {
		prefixTable[i] = prefixTable[i - 1] + rd.getRandomInt(1, 7);
	}
}

int Fire::getPrefix(int mana) {
	int level = 0;
	for (int i=0; i<10; i++) {
		if (prefixTable[i] > mana)
			break;
		level = i+1;
	}
	return level;
}
/**
	친화도를 반환할 수 있는 스태틱 메소드이다.
	
	return 현재 나의 친화도
*/
int Fire::getAffinityLevel() {
	int level = 0, tmpAffinity = affinity;
	
	tmpAffinity >>= 1;
	while (tmpAffinity) {
		level++;
		tmpAffinity >>= 1;
	}
	return level;
}


/**
	친화도를 수정할 수 있는 스태틱 메소드이다.
	
	param 수정할 친화도의 변화량
*/
void Fire::addAffinity(int num) {
	affinity += num;
}

/**
	mana를 소모해 공격을 한다.
*/
void Fire::attack(int mana) {
	int x = board.getPlayerX(), y = board.getPlayerY();
	int size = board.getSize();
	/*
	// 근데 이건 Map한테 책임 전가 해야할 듯
	bool** visit = new * int[size]; // 동적할당
	
	// 배열 초기화
	for (int i=0; i<size; i++) {
		visit[i] = new int[size];
		for (int j=0; j<size; j++) {
			visit[i][j] = 0;
		}
	}
	for (int i=0; i<size; i++) {
		delete [] visit[i];
	}
	
	delete [] visit;*/
	
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	
	board.initVisit();
	board.setVisit(x, y, 0);
	
	while (!q.empty()) {
		x = q.front().first, y = q.front().second;
		
		// (x, y)에 몬스터 있음, 데미지나 먹어라~
		if (board.isMonster(x, y)) {
			Monster mon = board.getMonster(x, y);
			mon.getDamage(damage);
		}
		int d = board.getVisit(x, y);
		q.pop();
		if (d == range)
			continue;
		
		for (int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (x < 0 || x >= size || y < 0 || y >= size)
				continue;
			
			if (!board.getVisit(nx, ny) || !board.isWall(nx, ny)) {
				board.setVisit(nx, ny, d+1);
			}
		}
	}
	
	
	
}

/**
	최종 대미지를 인자로 받고 속성 친화도에 영향을 받은 대미지를 반환한다.
*/
int interactWithOtherElement(int damage) {
	// 불 속성이니 바람 속성이나 물 속성의 레벨에 영향을 받는다.
	return damage;
}