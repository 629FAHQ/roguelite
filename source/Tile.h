#include "Entity.h"
#include "Element.h"

class Tile {
private:
	bool wall;
	Entity* entity;
	Element* element;
	const int x, y;
public:
	Tile(int x, int y);
	
	void setWall(bool wall);
	bool isWall();
	void setEntity(Entity* e);
	void setElement(Element* e);
	Entity* getEntity();
	Element* getElement();
};

Tile::Tile(int x, int y) : x(x), y(y), wall(1), entity(0), element(0) {
	
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
	해당 타일이 벽이면 '참'을 반환한다.
	(아닐 경우 '거짓' 반환)
	
	return 해당 타일의 벽 여부
*/
bool Tile::isWall() {
	return wall;
}

/**
	해당 타일에 Entity 인스턴스의 주소값을 등록한다.
*/
void Tile::setEntity(Entity* e) {
	this->entity = e;
}

/**
	해당 타일 위에 있는 Entity 인스턴스의 주소값을 반환한다.
	
	return Entity 개체의 주소
*/
Entity* Tile::getEntity() {
	return this->entity;
}

/**
	해당 타일에 Element 인스턴스의 주소값을 등록한다
	
	param e 올려둘 Element 개체의 주소값
*/
void Tile::setElement(Element* e) {
	this->element = e;
}

/**
	해당 타일 위에 있는 Element 인스턴스의 주소값을 반환한다.
	
	return 올려둔 개체의 주소값
*/
Element* Tile::getElement() {
	return this->element;
}