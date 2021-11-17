#include "Tile.h"

class Map {
private:
	const int width, height;
	vector<vector<Tile>> board;
public:
	Map(int w, int h);
	void generate();
	bool moveEntity(int x1, int y1, int x2, int y2);
	bool deleteEntity(int x, int y);
	bool addEntity(int x, int y, Entity* e);
	bool isWall(int x, int y);
};

/**
	Map 클래스의 생성자이다.
	
	param w, h
	각각, 너비와 높이의 값이다.
*/
Map::Map(int w, int h) : width(w), height(h) {
	
}

/**
	미로 형태의 맵을 만든다.
*/
void Map::generate() {
	
}

/**
	(x1, y1) 타일에 위치한 Entity를 (x2, y2)로 옮긴다
	
	return 성공여부
*/
bool Map::moveEntity(int x1, int y1, int x2, int y2) {}

/**
	(x, y)위치의 타일에 Entity를 추가한다.
	
	return 성공여부
*/
bool Map::addEntity(int x, int y, Entity* e) {
	
}

/**
	(x, y) 타일에 위치한 Entity를 제거한다.
	
	return 성공여부
*/
bool Map::deleteEntity(int x, int y) {
	
}

/**
	(x, y) 타일이 벽인지 아닌지 반환한다.
	
	return 벽 여부
*/
bool Map::isEmpty(int x, int y) {
	
}