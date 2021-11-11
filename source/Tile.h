#include "Entity.h"
#include "Element.h"

class Tile {
private:
	bool wall;
	Entity* entity;
	Element* element;
	const int x, y;
public:
	Tile() : wall(1), entity(0), element(0) {}
	
	void setWall(bool wall) {
		this->wall = wall;
	}
	
	bool isWall() {
		return wall;
	}
	
	void setEntity(Entity* e) {
		this->entity = e;
	}
	
	Entity* getEntity() {
		return this->entity;
	}
	
	void setElement(Element* e) {
		this->element = e;
	}
	
	Element* getElement() {
		return this->element;
	}
};