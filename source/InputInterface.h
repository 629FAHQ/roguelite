/**
	InputInterface의 책임
	
	1. 사용자의 키 입력을 담당한다.
		(유효한 키입력인지 검사할수도 있어야 한다.)
	2. InGame에게 입력에 따른 적절한 메시지를 전파한다.
	
*/
#ifndef INPUTINTERFACE_H
#define INPUTINTERFACE_H
class InputInterface {
private:
	const int UP_KEY, DOWN_KEY, LEFT_KEY, RIGHT_KEY, ATTACK_KEY, MANA_KEY;
public:
	InputInterface(int u, int d, int l, int r, int a, int m);
	int getUserAction();
	int inputToAction(int value);
	
	int getUpKey();
	int getDownKey();
	int getLeftKey();
	int getRightKey();
	int getAttackKey();
	int getManaKey();
	
	virtual int input() = 0;
};



/**
	InputInterface의 생성자이다.
	
	Param: 상위 클래스인 Interface의 주소값 , 각 키에 대한 코드값
*/
InputInterface::InputInterface(int u, int d, int l, int r, int a, int m) : UP_KEY(u), DOWN_KEY(d), LEFT_KEY(l), RIGHT_KEY(r), ATTACK_KEY(a), MANA_KEY(m) {
	
}

/**
	유저의 입력을 검증하고 유효하다면 그 행동번호를 반환한다.
	유효한 값이 들어올때까지 기다린다.
*/
int InputInterface::getUserAction() {
	int action;
	while (!(action = inputToAction(input()))) {}
	return action;
}

/**
	입력 받은 값이 유효한 값인지 확인하고 유효하다면 행동번호(약속된)를 반환한다.
	아닐경우 약속된 무효값(0)을 반환한다.
	
	Param: value 분석할 입력 값
	Return: 행동번호
*/
int InputInterface::inputToAction(int value) {
	if (value == UP_KEY)
		return 1;
	if (value == DOWN_KEY)
		return 2;
	if (value == LEFT_KEY)
		return 3;
	else if (value == RIGHT_KEY)
		return 4;
	else if (value == ATTACK_KEY)
		return 5;
	else if (value == MANA_KEY)
		return 6;
	return 0;
}

#endif