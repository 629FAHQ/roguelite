class Player : public Entity {
	
private:
	Element* elements[3];
public:
	~Player() {
		for (int i=0; i<3; i++)
			delete elements[i];
	}
	
	void get_element() {
		// map에게 내 칸에 있는 원소를 물어보고 등록한다.
	}
	
};