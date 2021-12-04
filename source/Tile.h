class Tile {
private:
	bool wall;
	//const int x, y;
public:
	Tile(/*int x, int y*/);
	
	void setWall(bool wall);
	bool isWall();
};

Tile::Tile(/*int x, int y*/) : /*x(x), y(y), */wall(1) {
	
}

/**
	해당 타일의 벽 유무를 wall로 바꾼다. 
	
	param wall
	(wall이 참일때 벽)
*/
void Tile::setWall(bool wall) {
	this->wall = wall;
}

/**
	해당 타일이 벽이면 '참'을 반환한다.
	(아닐 경우 '거짓' 반환)
	
	return 해당 타일의 벽 여부
*/
bool Tile::isWall() {
	return wall;
}
