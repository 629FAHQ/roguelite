class InputInterface {
private:
	const int NUM_UP, NUM_DOWN, NUM_RIGHT, NUM_LEFT, NUM_ATTACK, NUM_QUIT;
public:
	InputInterface(int u, int d, int r, int l, int a, int q);
	virtual int listenInput() = 0;
	virtual void up() = 0;
	virtual void down() = 0;
	virtual void right() = 0;
	virtual void left() = 0;
	virtual void attack() = 0;
	virtual void quit() = 0;
	void whatKeyIsPressed();
};
/**
	InputInterface의 생성자이다.
	
	param u, d, r, l, a, q
	각각 위, 아래, 오른, 왼, 공격, 나가기 키에 대한 값을 받는다.
*/
InputInterface::InputInterface(int u, int d, int r, int l, int a, int q) : NUM_UP(u), NUM_DOWN(d), NUM_RIGHT(r), NUM_LEFT(l), NUM_ATTACK(a),  NUM_QUIT(q) {
	
}


/**
	어떤 키가 눌러졌는지 보고 눌러진 키에 따라 메시지를 전파한다.
*/
void InputInterface::whatKeyIsPressed() {
	while (1) {
		int key = listenInput();
		
		if (key == NUM_UP) {
			up();
			break;
		}
		
		if (key == NUM_DOWN) {
			down();
			break;
		}
		
		if (key == NUM_RIGHT) {
			right();
			break;
		}
		
		if (key == NUM_LEFT) {
			left();
			break;
		}
		
		if (key == NUM_ATTACK) {
			attack();
			break;
		}
		
		if (key == NUM_QUIT) {
			quit();
			break;
		}
	}
}