/**	이것저것

	엔티티에서 특화된 플레이어만의 책임.
	
	
	1. 몬스터는 플레이어와의 거리에 따라 행동을 정할 수 있어야 한다.
	
	2. 몬스터는 자신의 활성화 상태를 관리 할 수 있어야 한다.
		- 내 근처에 플레이어가 있는지 확인 할 수 있어야 한다.
	
	3. 몬스터는 자신이 활성화 상태일때만 턴을 관리할 수 있어야 한다.
	
	4. 몬스터의 행동은 플레이어의 이득을 최소화 해야한다.
		4-1. 이번턴에 플레이어를 공격할 수 있으면 플레이어를 공격한다.
		4-2. 그렇지 않다면 플레이어에게 접근한다.
		(그렇다면 특정 타일에 몬스터가 있는지랑 플레이어가 있는지를 물어볼 수 있어야 한다.)
	
	5. 몬스터는 자신의 공격 사거리를 관리할 줄 알아야 한다.
	

*/

/**
	몬스터들을 구현할 클래스이다.
*/

class Monster : public Entity {
private:
	bool state;
	int range, damage;
public:
	Monster();
	void doing();
	bool isPlayerInRange();
	void changeState();
	bool getState();
	bool canAttack();
	void attack();
	void move();
	
	
};

/**
	Monster의 생성자이다.
*/
Monster::Monster() {
	
}

/**
	몬스터가 현재 턴에 할 수 있는 최적의 동작을 행한다.
	(움직인다 / 공격한다)
*/
void Monster::doing() {
	// 구현 예정
}


/**
	플레이어가 일정 범위(range) 내에 있으면 'true'를 반환한다.
	아니라면 false를 반환한다.
	
	return 범위 내 플레이어 존재 여부
*/
bool Monster::isPlayerInRange() {
	
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
	
}

/**
	몬스터가 이번 턴에 플레이어를 공격할 수 있는지 여부를 반환한다.
	
	return 공격 가능 여부
*/
bool Monster::canAttack() {
	
}

/**
	몬스터가 공격 범위에 있는 플레이어를 공격한다.
*/
void Monster::attack() {
	
}

/**
	몬스터가 플레이어에게 가까워지는 쪽으로 한 칸 움직인다.
*/
void Monster::move() {
	
}