#include "Tile.h"
#include "Entity.h"
/**
	해당 클래스의 생성자이다.
*/
Tile::Tile() : wall(1), entity(0) {
	
}

/**
	해당 타일의 벽 유무를 wall로 바꾼다. 
	
	param wall
	(wall이 참일때 벽)
*/
void Tile::setWall(bool wall) {
	this->wall = wall;
}

/**
	해당 타일에 Entity를 등록한다.
						 (위치시킨다.)
*/
void Tile::setEntity(Entity* e, int x, int y) {	
	entity = e;
	
	if (!entity)
		return;
	
	entity->setPostion(x, y);
}

/**
	해당 타일에 있던 Entity 정보를 말소시킨다.
*/
void Tile::clearEntity() {
	entity = 0;
}

/**
	해당 타일이 벽이면 '참'을 반환한다.
	(아닐 경우 '거짓' 반환)
	
	return 해당 타일의 벽 여부
*/
bool Tile::isWall() {
	return wall;
}

/**
	0 : nothing
	1 : player
	2 : Monster
*/
int Tile::isEntity() {
	if (entity)
		return entity->getId();
	return 0;
}


/**
	해당 타일에 있는 Entity의 주소를 반환한다.
*/
Entity* Tile::getEntity() {
	if (entity)
		return entity;
	return 0;
}