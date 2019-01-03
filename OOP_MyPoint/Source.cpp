#include <iostream>
#include "MyPoint.h"
using namespace std;

int main() {
	MyPoint A(0, 0), B(6, 8);
	cout << "Distance between two points A(0, 0) and B(6, 8) is ";
	cout << B.distance(A) << endl;
	system("pause");
	return 0;
}