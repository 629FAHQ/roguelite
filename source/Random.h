#ifndef RANDOM_H
#define RANDOM_H

class Random {
public:
	Random(int seed);
	Random();
	int getRandomInt(int from, int to);
};

#endif