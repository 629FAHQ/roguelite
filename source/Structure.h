class Structure {
private:
	const int width, height, x, y;
public:
	Structure(int x, int y, int width, int height) : x(x), y(y), width(w), height(h) {
		for (int i=y; i<y+height; i++) {
			for (int j=x; j<x+width; j++) {
				// 해당 위치의 타일을 벽이 아닌 공간으로 만들기
			}
		}
	}
};