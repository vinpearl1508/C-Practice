#include <iostream>
#include "MyPoint.h"
using namespace std;

int main() {
	/*MyPoint A(0, 0), B(6, 8);
	cout << "Distance between two points A(0, 0) and B(6, 8) is ";
	cout << B.distance(A) << endl;*/

	MyPoint *A = new MyPoint(0, 0);
	MyPoint *B = new MyPoint(6, 8);
	cout << "Distance between two points A(0, 0) and B(6, 8) is ";
	cout << A->distance(B) << endl;
	system("pause");
	return 0;
}