#ifndef MONSTER_H
#define MONSTER_H

class Monster : public Entity {
private:
	bool state;
	int attackRange, senseRange, damage;
public:
	Monster(int ar, int sr);
	
	void doing();
	
	bool isPlayerInRange(int range);
	
	void changeState();
	bool getState();
	
	void attack();
	void move();
	
	
};

/**
	Monster의 생성자이다.
*/
Monster::Monster(int x, int y, int ar, int sr) : attackRange(ar), senseRange(sr), Entity("monster", x, y, 50, 2) {
	
}

/**
	몬스터가 현재 턴에 할 수 있는 최적의 동작을 행한다.
	(움직인다 / 공격한다)
*/
void Monster::doing() {
	if (isPlayerInRange())
		attack();
	else
		move();
}


/**
	플레이어가 일정 범위(range) 내에 있으면 'true'를 반환한다.
	아니라면 false를 반환한다.
	
	return 범위 내 플레이어 존재 여부
*/
bool Monster::isPlayerInRange(int range) {
	//getMap()->getMinDis(int x1, int y1, int x2, int y2);
	//getMap()->getMinDis(int x1, int y1, int x2, int y2);
	int px = getMap()->getPx(), py = getMap()->getPy();
	if (getMap()->getMinDis(px, py, getX(), getY()) <= range)
		return true;
	return false;
}

/**
	몬스터의 state를 변경한다.
	true라면 false로, false라면 true로 바꾼다.
*/
void Monster::changeState() {
	this->state = !this->state;
}

/**
	몬스터의 상태(state)를 반환한다. 
	
	return state
*/
bool Monster::getState() {
	return state;
}

/**
	플레이어를 공격한다.
*/
void Monster::attack() {
	int px = getMap()->getPx(), py = getMap()->getPy();
	
	Entity* e = getMap()->getEntity(px, py);
	e->getDamage(damage);
	
}

/**
	몬스터가 플레이어에게 가까워지는 쪽으로 한 칸 움직인다.
*/
void Monster::move() {
	int px = getMap()->getPx(), py = getMap()->getPy();
	//Entity* e = getMap()->getNextRoute(int fx, int fy, int tx, int ty);
	int dx = getMap()->getNextRouteX(getX(), gety(), px, py);
	int dy = getMap()->getNextRouteY(getX(), gety(), px, py);
	
	setPostion(getX()+dx, getY()+dy);	
}

#endif