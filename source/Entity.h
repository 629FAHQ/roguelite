/**
	Monseter와 Player가 상속 받을 추상 클래스이다.
*/

class Entity{
private:
	std::string name;
	int total_hp, hp, total_tc, tc;
	
public:
	Entity(std::string name, int hp, int tc);
		
	bool go_right(int d);
	bool go_left(int d);
	bool go_up(int d);
	bool go_down(int d);
	void get_damage(int amount);
	bool down_turn_count();
	bool is_alive();
	
	virtual void atack() = 0;
};

/**
	Entity 클래스의 생성자이다.
	
	param
		name 이름
		hp 체력
		tc 턴 주기
*/
Entity::Entity(std::string name, int hp, int tc) : name(name), total_hp(hp), hp(hp), total_tc(tc), tc(tc){
	
}

/**
	해당 Entity를 'd'칸 오른쪽으로 움직이고 움직임
	성공 여부를 반환한다.

	param int d 움직일 거리
	return 움직임 성공 여부(bool)
	(움직임 성공 / 움직임 실패)
*/
bool Entity::go_right(int d) {
}

/**
	위와 동일 하므로 주석 생략.
*/
bool Entity::go_left(int d) {
}

/**
	위와 동일 하므로 주석 생략.
*/
bool Entity::go_up(int d) {
}

/**
	위와 동일 하므로 주석 생략.
*/
bool Entity::go_down(int d) {
}


/**
	해당 Entity의 체력을 'amount'만큼  뺀다.
	
	param int amount
*/
void Entity::get_damage(int amount) {
	hp -= amount;
	if (hp < 0)
		hp = 0;
}

/**
	해당 Entity의 생존 여부를 반환한다.
	
	return 생존 여부(bool)
	(살아있음 / 죽어있음)
*/
bool Entity::is_alive() {
	if (hp > 0)
		return true;
	return false;
}