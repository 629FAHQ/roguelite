#include <iostream>
#include <vector>
#include <queue>
#include "Map.h"

using namespace std;

int main() {
	Map m0 = Map(30, 30);
	Map m1 = Map(31, 31);
	Map m2 = Map(32, 32); // dlrj
	Map m3 = Map(33, 33);
	Map m4 = Map(34, 34);	
	Map m5 = Map(35, 35);
	Map m6 = Map(36, 36); // dlrj
	Map m7 = Map(37, 37);
	Map m8 = Map(38, 38);
	Map m9 = Map(39, 39);
	Map m10 = Map(40, 40); // dlrj
	
	
	m0._test_printBoard();
	cout << "\n\n\n00===================================\n\n\n";
	m1._test_printBoard();
	cout << "\n\n\n11===================================\n\n\n";
	m2._test_printBoard();
	cout << "\n\n\n22===================================\n\n\n";
	m3._test_printBoard();
	cout << "\n\n\n33===================================\n\n\n";
	m4._test_printBoard();
	cout << "\n\n\n44===================================\n\n\n";
	m5._test_printBoard();
	cout << "\n\n\n55===================================\n\n\n";
	m6._test_printBoard();
	cout << "\n\n\n66===================================\n\n\n";
	m7._test_printBoard();
	cout << "\n\n\n77===================================\n\n\n";
	m8._test_printBoard();
	cout << "\n\n\n88===================================\n\n\n";
	m9._test_printBoard();
	cout << "\n\n\n99===================================\n\n\n";
	m10._test_printBoard();
	cout << "\n\n\n1010===================================\n";
}