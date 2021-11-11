/*
생각해보니 Room은 타일의 메모리에 직접 접근할 필요가 없음.
Map이 가지고 있는데 굳이? 그냥 자기자신의 방이 어디서부터 어디고
몬스터는 어떻게 관리하고 이런것만 관리하면 될 듯.
*/

#include "Tile.h"

class Map {
private:
	const int width, height;
	vector<Tile> board;
	vector<Room> rooms;
	vector<Passage> passages;
	
	// 빈 타일들을 저장해 둔 board를 만든다.
	void makeToEmptyBoard() {
	}
	
public:
	Map(int w, int h) : width(w), height(h) {
		// 보드 초기화
		createEmptyBoard();
	}
	
	// (x, y) 타일에 위치한 값을 반환한다.
	Tile* getTile(int x, int y) {}
	
	void generateMap() {
		// 맵내의 방, 통로 등을 생성한다.
	}
};