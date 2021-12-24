/*
	Testing 해볼거 :
	0. 버그없이 실행
	1. 맵을 생성 한다.
	2. 맵에 몬스터와 플레이어를 생성한다.
	3-1. 플레이어를 움직여 본다.
	3-2. 몬스터를 움직여 본다.
	4-1. 플레이어가 몬스터를 공격한다.
	4-2. 몬스터가 플레이어를 공격한다.
	5-1. 몬스터가 죽는다. -> 죽은 엔티티는 삭제해 주는 코드를 추가해줘야 할 듯.
	5-2. 플레이어가 죽는다.
	
	
	
	.h 파일과 cpp 파일 분리후 다시 테스트 해보기
*/

//#include <ncurses.h>
#include "Map.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>
#include <unistd.h>
using namespace std;


int main() {
	Map* map = new Map(12, 12);
	Player* p1 = new Player(1, 1, map);
	Monster* m1 = new Monster(11, 11, 2, 4, 1000, map);
	
	//map->setEntity(1, 1, p1);
	
	//map->setEntity(7, 1, m1);
	//cout << map->getMinDis(p1->getX(), p1->getY(), m1->getX(), m1->getY()) << "\n";
	while (!(m1->isPlayerInRange(2))) {
		m1->doing();
		
		map->_test_printBoard();
		usleep(100000);
		cout << "\n\n";
	}
	m1->doing();
	cout << "Player: " << p1->getHp() << "\n";
	cout << "Monster: " << m1->getHp() << "\n";
}

/*
g++ main.cpp Map.cpp Random.cpp Tile.cpp Entity.cpp Player.cpp Monster.cpp -o a
g++ main.o Map.o Random.o Tile.o Entity.o Player.o Monster.o -o a
*/