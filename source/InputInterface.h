class InputInterface {
private:
	const int NUM_UP, NUM_DOWN, NUM_RIGHT, NUM_LEFT, NUM_ATTACK, NUM_QUIT;
public:
	InputInterface(int u, int d, int r, int l, int a, int q) : NUM_UP(u), NUM_DOWN(d), NUM_RIGHT(r), NUM_LEFT(l), NUM_ATTACK(a),  NUM_QUIT(q){}
	virtual int listenInput() = 0;
	virtual void up() {}
	virtual void down() {}
	virtual void right() {}
	virtual void left() {}
	virtual void attack() {}
	virtual void quit() {}
	void whatKeyIsPressed() {
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
};