/**	 이것저것
	엔티티에서 특화된 플레이어만의 책임.
	
	
	1. 플레이어는 상하좌우의 이동 뿐 아니라 마나 회복, 공격과 같은 동작을 행 할 수 있어야 한다.
	(그러기 위해선 마나량에 관한 변수도 있어야 한다.)
	
	2. 플레이어는 특정 속성에 따른 친화도를 관리할 수 있어야 한다.
		- 이 부분은 결합도만 높아지는 코드를 작성하기에 적합한 구조인데 신경써서 작성할 것!!!
	
	3. 플레이어는 현재 위치의 타일에 존재하는 Element 객체를 통해 다양한 공격을 할 수 있다.
		-한번 사용하면 노말 Element가 되어야 하는데
	
	4. 레벨에 따른 접두사:
	Lv.0 형편없는
	Lv.1 평범한
	Lv.2 능숙한
	Lv.3 강화된
	Lv.4 강력한
	Lv.5 초월한
	
	갑자기 생각난 아이디어:
	총 마나량은 제약이 없지만 한번 스킬을 사용하면 모아둔 마나를 모두 소모하는 방식.
	사용된 마나량에 따라 발동되는 스킬의 레벨이 달라지는데, 이 레벨의 기준치는 매 게임마다 랜덤하게 산출 됨.
	
	: 마나가 없다면 공격을 못하며 공격 이외의 행동을 할 시 마나가 충전 됨.
	
	로그라이크의 특징을 더 잘 살릴수는 있지만
	이렇게 했을 경우 속성의 조합을 어떻게 해야하지?
	> Element 인스턴스를 통해 공격을 행 할때 메소드에 이전 속성 2개를 넘기자.
	따라서 엘리먼트 클래스에선 미리 조합에 따른 시너지를 정의해 둬야 함.
	
*/

/**
	유저가 조작할 플레이어를 구현할 클래스이다.
*/
class Player : public Entity {
private:
	int x, y, mana;
public:
	Player();
	void attack();
	
	int getMana();
	void healMana(int amount);
	bool useMana(int amount);
	
};

/**
	Player의 생성자이다.
*/

Player::Player() : Entity("player", 100, 1) {
	
}

/**
	현재 플레이어가 위치한 타일에 있는 Element 인스턴스에 공격을 요청한다.
	해당 타일을 기준으로 공격이 발동 된다.
*/
void Player::attack() {
	// Map에게 현재 타일 위에 있는 Element가 누군지 알아온다.
	// 알아온 ELement에게 현재 마나량 만큼의 마나를 소모해 공격해달라고 요청한다.
}

/**
	현재 플레이어의 마나량을 반환한다.
	
	return 플레이어의 남은 마나량
*/
int Player::getMana() {
	return this->mana;
}

/**
	플레이어의 마나를 amount 만큼 회복시킨다.
	
	param 회복시킬 마나량
*/
void Player::healMana(int amount) {
	this->mana += amount;
}


/**
	플레이어의 마나를 amount 만큼 소모하고 true를 반환한다.
	소모할 수 없다면 소모하지 않고 false를 반환한다.
	
	param 소모할 마나량
	return 소모가능 여부를 반환한다.
		true = 소모량 <= 현재 마나
		false = 소모량 > 현재 마나
*/
bool useMana(int amount) {
	if (amount > this->mana)
		return false;
	this->mana -= amount;
	return true;
}