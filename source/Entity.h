class Entity{
private:
	std::string name;
	int total_hp, hp, total_tc, tc;
	
public:
	Entity(std::string name, int hp, int tc) : name(name), total_hp(hp), hp(hp), total_tc(tc), tc(tc){}
		
	bool go_right(int d) {
		// 추후 구현 예정
		// Map 객체에게 옮겨달라고 요청하기.
	}
	
	bool go_left(int d) {
		// 위와 동일
	}
	
	bool go_down(int d) {
		// 위와 동일
	}
	
	bool go_up(int d) {
		// 위와 동일
	}
	
	void get_damage(int amount) {
		hp -= amount;
		if (hp < 0)
			hp = 0;
	}
	
	// 나의 턴이 끝났었다면 false 반환
	bool down_turn_count() {
		tc = tc - 1;
		if (tc == 0) {
			tc = total_tc;
			return false;
		}
		return true;
	}
	
	bool is_alive() {
		if (hp > 0)
			return true;
		return false;
	}
	
	// 공격 방식은 엔티티 종류마다 다르기 때문에
	// 가상 메소드로 남겨둔다.
	virtual void atack() {
	}
	
	
	
};