#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
class Map;
//class Entity;

class Player : public Entity {
private:
	int mana;
public:
	Player(int x, int y, Map* map);
	void attack();
	
	int getMana();
	void healMana(int amount);
	void useMana(int amount);
	
};

#endif