#ifndef MAP_H
#define MAP_H

#include <vector>

class Tile;
class Random;
class Entity;

class Map {
private:
	const int width, height;
	std::vector<std::vector<Tile>> board;
	int** visitArray;
public:
	Map(int w, int h);
	~Map();
	// board
	void initBoard();
	void generate();
	// visit
	void initVisit();
	void setVisit(int x, int y, int v);
	int getVisit(int x, int y);
	
	bool setEntity(int x, int y, Entity* e);
	Entity* getEntity(int x, int y);
	
	int getMinDis(int fx, int fy, int tx, int ty);
	int getPx();
	int getPy();
	int getNextRoute(int fx, int fy, int tx, int ty);
	
	bool isWall(int x, int y);
	bool isEntity(int x, int y, int entityId);
	
	void _test_printBoard();
};

#endif