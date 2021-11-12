/*
기본적인 로그라이크의 맵을 따르지 않기로 결정함.
내가 만들 게임의 맵은 미로 형태이며, 우선적으로
맵을 구성하는데에 필요한 객체는 Tile과 Map이면
충분할거같음. 따라서 기존에 구상했던, Room과 Passage
그리고 Structure는 삭제함.

우선 갑자기 게임의 컨셉이 바뀐거기 때문에 여기에
이 주석만 남겨두고, 커밋 후 브랜치 옮겨가겠음~
*/

#include "Tile.h"

class Map {
private:
	/*
	const int width, height;
	vector<vector<Tile *>> board;
	vector<Room> rooms;
	vector<Passage> passages;
	
	// 빈 타일들을 저장해 둔 board를 만든다.
	void setEmptyTile() {
		makeBoardEmpty();
		
		for (int h=0; h<height; h++) {
			tmpTile.clear();
			for (int w=0; w<width; w++) {
				tmpTile.push_back(new Tile());
			}
			board.push_back(tmpTile);
		}
	}
	
	void makeBoardEmpty() {
		// 만약 board에 값이 있다면
		while (!board.empty()) {
			while (!board.back().empty()) {
				delete board.back().back();
			}
			board.pop();
		}
	}
	
public:
	Map(int w, int h) : width(w), height(h) {
		// 보드 초기화
		makeBoardEmpty();
	}
	
	// (x, y) 타일에 위치한 타일을 반환한다.
	Tile* getTile(int x, int y) {}
	
	void generateMap() {
		// 맵내의 방, 통로 등을 생성한다.
	}
	*/
};