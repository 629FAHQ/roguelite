#include "Player.h"
#include "Map.h"
#include <iostream>
//#include "Entity"
/**
	Player의 생성자이다.
*/

Player::Player(int x, int y, Map* map) : Entity("player", x, y, 100, 1, 1, map) {
	
}

/**
	현재 플레이어가 위치한 타일에 있는 Element 인스턴스에 공격을 요청한다.
	해당 타일을 기준으로 공격이 발동 된다.
*/
void Player::attack() {
	// mana 범위 안에 Monster가 있다면 공격한다.
	// 공격은 십자 형태로 한다.
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	
	for (int i=0; i<4; i++) {
		
		int nx = getX(), ny = getY();
		for (int r = 0; r<10; r++) {
			nx += dx[i];
			ny += dy[i];
			if (getMap()->isWall(nx, ny))
				break;
			
			if (getMap()->isEntity(nx, ny, 2)) {
				Entity* e = getMap()->getEntity(nx, ny);
				e->getDamage(mana*10);
			}
		}
	}
	useMana(mana);
	//Element* e = getMap()->getElement();
	//e->attack();
	
}

/**
	현재 플레이어의 마나량을 반환한다.
	
	return 플레이어의 남은 마나량
*/
int Player::getMana() {
	return this->mana;
}

/**
	플레이어의 마나를 amount 만큼 회복시킨다.
	
	param 회복시킬 마나량
*/
void Player::healMana(int amount) {
	this->mana += amount;
}


/**
	플레이어의 마나를 amount 만큼 소모하고 true를 반환한다.
	소모할 수 없다면 소모하지 않고 false를 반환한다.
	
	param 소모할 마나량
	return 소모가능 여부를 반환한다.
		true = 소모량 <= 현재 마나
		false = 소모량 > 현재 마나
*/
void Player::useMana(int amount) {
	if (amount > this->mana)
		return;
	this->mana -= amount;
}