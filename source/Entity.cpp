#include "Entity.h"
#include "Map.h"

/**
	Entity 클래스의 생성자이다.
	
	PARAM 이름, x좌표, y좌표, 최대 체력, 최대 턴
		name 이름
		hp 체력
		tc 턴 주기
*/
Entity::Entity(std::string name, int x, int y,  int hp, int tc, int id, Map* map) : name(name), x(x), y(y), totalHp(hp), hp(hp), totalTc(tc), tc(tc), id(id), mapInfo(map) {
	map->setEntity(x, y, this);
}

/**
	해당 엔티티의 위치를 x, y로 옮긴다.
*/
void Entity::setPostion(int nx, int ny) {
	//mapInfo->setEntity(nx, ny, this);
	//mapInfo->setEntity(x, y, 0);
	
	x = nx;
	y = ny;
}

/**
	해당 엔티티의 x좌표를 반환한다.
*/
int Entity::getX() {
	return x;
}

/**
	해당 엔티티의 y좌표를 반환한다.
*/
int Entity::getY() {
	return y;
}

/**
	해당 Entity의 체력을 amount만큼 감소시킨다.
	
	param int amount
*/
void Entity::getDamage(int amount) {
	hp -= amount;
	if (hp < 0)
		hp = 0;
}

/**
	해당 Entity의 턴 카운트를 amount만큼 감소시킨다.
*/
void Entity::useTurnCount(int amount) {
	tc += amount;
	if (tc / totalTc >= 1)
		tc = 0;
	tc %= totalTc;
}

/**
	해당 엔티티의 턴이 돌아왔는지 여부를 참/거짓으로 반환한다.
*/
bool Entity::isTurn() {
	if (tc == 0)
		return true;
	return false;
}

/**
	해당 Entity의 생존 여부를 반환한다.
	
	return 생존 여부(bool)
	(살아있음 / 죽어있음)
*/
bool Entity::isAlive() {
	if (hp > 0)
		return true;
	return false;
}

/**

*/
Map* Entity::getMap() {
	return mapInfo;
}

int Entity::getId() {
	return id;
}


int Entity::getHp() {
	return hp;
}

int Entity::getTurnCount() {
	return tc;
}