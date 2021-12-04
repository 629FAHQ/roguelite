#include "Tile.h"
#include "Random.h"
/*
- 맵 -
1. 특정 타일에 엔티티를 위치 시킬수 있는 메소드가 있어야 한다.
2. 특정 타일에 엘리먼트를 위치 시킬수 있는 메소드가 있어야 한다.
3. 특정 타일의 엔티티를 제거할 수 있는 메소드가 있어야 한다.
4. 특정 타일의 엘리먼트를 제거할 수 있는 메소드가 있어야 한다.
5. 해당 위치로 엔티티가 이동할 수 있는지 검사하는 메소드가 있어야 한다.

- 타일 Tile -
1. Entity를 추가하는 메소드를 만들어야 한다.
2. Entity를 제거하는 메소드를 만들어야 한다.
3. Element를 추가하는 메소드를 만들어야 한다.
4. Element를 제거하는 메소드를 만들어야 한다.
5. Normal Element를 추가하는 메소드를 만들어야 한다.
*/
class Map {
private:
	const int width, height;
	vector<vector<Tile>> board;
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
	
	void _test_printBoard() {
		for (int w=0; w<=width; w++) {
			for (int h=0; h<=height; h++) {
				
				if (board[h][w].isWall())
					cout << "■";
				else
					cout << "　";
				cout << " ";
			}
			cout << "\n";
		}
	}
};




/**
	Map 클래스의 생성자이다.
	
	param w, h
	각각, 너비와 높이의 값이다.
*/
Map::Map(int w, int h) : width(w + (w%4)%4), height(h + (h%4)%4 {
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
		board.push_back(vector<Tile>());
		for (int w=0; w<=width; w++) {
			board[h].push_back(Tile());
		}
	}
	
	
	/*
	for (int h=0; h < height; h++) {
		v.push_back(vector<int>(width));
		for (int w=0; w<width; w++) {
			cout << v[h][w] << " ";
		}
		cout << "\n";
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
	
	priority_queue<pair<int, pair<pair<int, int>, pair<int, int>>>> pq;
	int k1 = width/2 + (width%2 == 0), k2 = height/2 + (height%2 == 0);
	weight[0][0];
	
	pq.push(make_pair(0, make_pair(make_pair(k1, k2), make_pair(k1, k2))));
	while (!pq.empty()) {
		int x = pq.top().second.second.first, y = pq.top().second.second.second;
		int x1 = pq.top().second.first.first, y1 = pq.top().second.first.second;
		//cout << x << ", " << y << "   " << x1 << ", " << y1 << "\n";
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
			pq.push(make_pair(cost, make_pair(make_pair(nx1, ny1), make_pair(nx2, ny2))));
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