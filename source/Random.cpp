#include "Random.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
	seed가 주어졌을때의 생성자이다.
*/
Random::Random(int seed) {
	srand(seed);
}

/**
	seed가 주어지지 않았을 때의 생성자이다. 
	현재 시간을 seed로 사용한다.
*/
Random::Random() {
	srand((unsigned int)time(0));
}

/**
	from부터 to까지의 숫자중 임의의 숫자 하나를 반환한다.
*/
int Random::getRandomInt(int from, int to) {
		int num = rand();
		return num % (to - from + 1) + from;
}