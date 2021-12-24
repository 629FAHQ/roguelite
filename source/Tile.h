#ifndef TILE_H
#define TILE_H

class Entity;

class Tile {
private:
	bool wall;
	Entity* entity;
	//const int x, y;
public:
	Tile(/*int x, int y*/);
	
	void setWall(bool wall);
	
	void setEntity(Entity* e, int x, int y);
	void clearEntity();
	
	bool isWall();
	int isEntity();
	Entity* getEntity();
};
#endif


