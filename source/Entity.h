#ifndef ENTITY_H
#define ENTITY_H


#include <string>

class Map;

class Entity {
private:
	const std::string name;
	const int id;
	int totalHp, hp, totalTc, tc, x, y;
	Map* mapInfo;
public:
	Entity(std::string name, int x, int y, int hp, int tc, int id, Map* map);
	
	void setPostion(int x, int y);
	
	int getX();
	int getY();
	
	void getDamage(int amount);
	void useTurnCount(int amount);
	bool isTurn();
	bool isAlive();
	
	int getHp();
	int getTurnCount();
	
	Map* getMap();
	int getId();
	virtual void attack() = 0;
};

#endif