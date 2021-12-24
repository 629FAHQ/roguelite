#ifndef MONSTER_H
#define MONSTER_H

//class Entity;
#include "Entity.h"
class Map;

class Monster : public Entity {
private:
	bool state;
	int attackRange, senseRange, damage;
public:
	Monster(int x, int y, int ar, int sr, int damage, Map* map);
	
	void doing();
	
	bool isPlayerInRange(int range);
	
	void changeState();
	bool getState();
	
	void attack();
	void move();
	
	
};

#endif