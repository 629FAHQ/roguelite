#include <iostream>
#include <cstring>
#include "Entity.h"
using namespace std;

int main() {
	cout << "test\n";
	Entity test1 = Entity("monster", 100);
	cout << test1.name << " " << test1.total_hp << " " << test1.hp << "\n";
	return 0;	
}