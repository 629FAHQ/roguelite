class InputInterface {
private:
	const int NUM_UP, NUM_DOWN, NUM_RIGHT, NUM_LEFT, NUM_ATTACK;
public:
	InputInterface(int u, int d, int r, int l, int a) : NUM_UP(u), NUM_DOWN(d), NUM_RIGHT(r), NUM_LEFT(l), NUM_ATTACK(a) {}
	virtual int listenInput() = 0;
	virtual void up() {}
	virtual void down() {}
	virtual void right() {}
	virtual void left() {}
	virtual void attack() {}
	void whatKeyIsPressed() {
		int key = listenInput();
		
		if (key == NUM_UP)
			up();
		else if (key == NUM_DOWN)
			down();
		else if (key == NUM_RIGHT)
			right();
		else if (key == NUM_LEFT)
			left();
		else
			attack();
	}
};