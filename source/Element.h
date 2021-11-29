/*
	 엘리먼트의 책임:
	 공격을 한다
	 접두사를 관리한다. (조회 및 변경)
	 친화도를 관리한다. (조회 및 변경)
	 
*/
class Element {
private:
	
	const int elementId;
	const string name;
	Map* const board;
	
	int range;
	
public:
	Element(int id, Map* board, string name, int 00000000range);
	
	string getName();
	int getElementId();
	virtual int interactWithOtherElement(int damage) = 0; // 다른 속성의 레벨에 따라 내 최종 대미지를 업데이트 한다.
	virtual void attack(int mana) = 0; // mana를 사용해 공격한다.
};



/**
	Element의 생성자이다.
	id, 보드판, 이름을 초기화 한다.
*/
Element::Element(int id, Map* board, string name, range) : elementId(id), board(board), name(name), range(range){
	
}
/**
	Element의 이름을 반환한다.
	return Element의 name;
*/
string Element::getName() {
	return name;
}

/**
	Element의 Id를 반환한다. 
	return string getName();
	
	return Element의 Id
*/
int Element::getElementId() {
	return elementId;
}