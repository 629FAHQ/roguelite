#include <iostream>
#include "Map.h"
#include <queue>
#include "Tile.h"
#include "Random.h"
#include "Entity.h"
//using namespace std;

/**
	Map 클래스의 생성자이다.
	
	param w, h
	각각, 너비와 높이의 값이다.
*/
Map::Map(int w, int h) : width(w + (w%4)%4), height(h + (h%4)%4) {
	this->initBoard();
	this->initVisit();
	this->generate();
}

/**
	Map 클래스의 소멸자이다.
	visit 배열에 사용된 메모리를 해제한다.
*/
Map::~Map() {
	for (int i=0; i<=height; i++) {
		delete [] visitArray[i];
	}
	delete [] visitArray;
}

/**
	가로 세로 길이에 맞는 크기의 맵을 생성한다.
*/
void Map::initBoard() {
	
	// 이미 보드가 사용중일 경우 검사후 초기화 ㅎ ㅏ는 코드를 여기에 넣을지 말지 고민중임
	// board는 Tile로 구성되어야 하므로 일케 말고 그냥 벡터로 구현하자.
	for (int h=0; h <= height; h++) {
		board.push_back(std::vector<Tile>());
		for (int w=0; w<=width; w++) {
			board[h].push_back(Tile());
		}
	}
	
	
	/*
	for (int h=0; h < height; h++) {
		v.push_back(vector<int>(width));
		for (int w=0; w<width; w++) {
			std::cout << v[h][w] << " ";
		}
		std::cout << "\n";
	}*/
}

/**
	미로 형태의 맵을 만든다.
*/
void Map::generate() {
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	int** weight = new int * [height+1];
	Random random = Random();
	
	for (int h=0; h<=height; h++) {
		weight[h] = new int[width+1];
		for (int w=0; w<=width; w++) {
			weight[h][w] = random.getRandomInt(1, 15);
			board[h][w].setWall(1);
		}
	}
	
	for (int w=0; w<=width; w++) {
		for (int h=0; h<=height; h++) {
			if (h%2 == 0 || w%2 == 0)
				continue;
			if (!((h+w)%2)) {
				board[h][w].setWall(0);
				if (h+1 < height)
					weight[h+1][w] = rand()%9+1;
				if (w+1 < width)
					weight[h][w+1] = rand()%9+1;
			}
		}
	}
	
	std::priority_queue<std::pair<int, std::pair<std::pair<int, int>, std::pair<int, int>>>> pq;
	int k1 = width/2 + (width%2 == 0), k2 = height/2 + (height%2 == 0);
	weight[0][0];
	
	pq.push(std::make_pair(0, std::make_pair(std::make_pair(k1, k2), std::make_pair(k1, k2))));
	while (!pq.empty()) {
		int x = pq.top().second.second.first, y = pq.top().second.second.second;
		int x1 = pq.top().second.first.first, y1 = pq.top().second.first.second;
		//std::cout << x << ", " << y << "   " << x1 << ", " << y1 << "\n";
		pq.pop();
		
		if (visitArray[y][x]) ////////////////////////////// To do 비짓어레이 메소드 이용하는걸로 바꾸기 
			continue;
		
		board[y1][x1].setWall(0);
		visitArray[y][x] = 1;
		
		for (int i=0; i<4; i++) {
			int nx1 = x + dx[i], ny1 = y + dy[i], nx2 = x + dx[i] * 2, ny2 = y + dy[i] * 2;
			if (nx1 <= 0 || nx1 >= width || ny1 <= 0 || ny1 >= height || visitArray[ny2][nx2])
				continue;
			int cost = weight[ny1][nx1];
			pq.push(std::make_pair(cost, std::make_pair(std::make_pair(nx1, ny1), std::make_pair(nx2, ny2))));
		}
	}
	
	for (int h=0; h<=height; h++) {
		delete [] weight[h];
	}
	delete [] weight;
	
}

// Visit 구현 ##########################################


/**
	visit 배열을 초기화 한다.
*/
void Map::initVisit() {
	visitArray = new int * [height+1];
	
	for (int h = 0; h <= height; h++) {
		visitArray[h] = new int[width+1];
		for (int w = 0; w<=width; w++) {
			visitArray[h][w] = 0;
		}
	}
}

/**
	visit[y][x] 에 v값을 넣는다.
*/
void Map::setVisit(int x, int y, int v) {
	visitArray[y][x] = v;
}

/**
	visit[y][x] 에 있는 값을 받는다.
*/
int Map::getVisit(int x, int y) {
	return visitArray[y][x];
}

/**
	(x, y)에 Entity를 설치(?)한다.
*/
bool Map::setEntity(int x, int y, Entity* e) {
	if (board[y][x].isEntity())
		return 0;
	
	int ox = e->getX(), oy = e->getY();
	
	// 뒤에 x, y 인자는 없앨 수 있도록 todo
	
	board[oy][ox].clearEntity();
	board[y][x].setEntity(e, x, y);
	
	return 1;
}

/**
	(fx, fy) <-> (tx, ty) 간의 최단 거리를 구한다.
*/
int Map::getMinDis(int fx, int fy, int tx, int ty) {
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	
	std::queue<std::pair<int, int>> q;
	initVisit();
	q.push(std::make_pair(fx, fy));
	setVisit(fx, fy, 1);
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if (x == tx && y == ty)
			return getVisit(x, y) - 1;
		
		for (int i=0; i<4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			
			if (nx <= 0 || nx >= width || ny <= 0 || ny >= height || board[ny][nx].isWall() || getVisit(nx, ny))
				continue;
			
			setVisit(nx, ny, getVisit(x, y) + 1);
			q.push(std::make_pair(nx, ny));
		}
		
	}
	return -1;
}

/**
	Player가 있는 곳의 x좌표를 반환한다.
*/
int Map::getPx() {
	for (int y = 1 ; y < height ; y++) {
		for (int x = 1 ; x < height ; x++) {
			if (board[y][x].isEntity() == 1)
				return x;
		}
	}
	
	return -1;
}

/**
	Player가 있는 곳의 y좌표를 반환한다.
*/
int Map::getPy() {
	for (int y = 1 ; y < height ; y++) {
		for (int x = 1 ; x < height ; x++) {
			if (board[y][x].isEntity() == 1)
				return y;
		}
	}
	
	return -1;
}

/**
	(x, y)에 있는 Entity의 주소값을 받아온다.
*/
Entity* Map::getEntity(int x, int y) {
	return board[y][x].getEntity();
}

/**
	(fx, fy)로부터 (tx, ty)까지 최단 경로 중
	1 칸 움직인 곳의 위치를 반환한다.
	
	1. 오른쪽
	2. 왼쪽
	3. 아래쪽
	4. 위쪽
*/
int Map::getNextRoute(int fx, int fy, int tx, int ty) {
	int d = getMinDis(tx, ty, fx, fy);
	
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	
	for (int i = 0 ; i < 4 ; i++) {
		int x = fx + dx[i];
		int y = fy + dy[i];
		
		if (getVisit(x, y) == getVisit(fx, fy) - 1)
			return i;
	}
	return -1;
}

void Map::_test_printBoard() {
	
		for (int w=0; w<=width; w++) {
			for (int h=0; h<=height; h++) {
				if (board[h][w].isEntity() != 0) {
					std::cout << board[h][w].isEntity()<<" ";
				}
				else if (board[h][w].isWall())
					std::cout << "■";
				else
					std::cout << "　";
				std::cout << " ";
			}
			std::cout << "\n";
		}
}