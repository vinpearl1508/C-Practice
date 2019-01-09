#include<iostream>
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include "Patient.h"

#include <cstdlib> // For srand()
#include <ctime> // For time
using namespace std;
int main() {
	/*fluVirus *f = new fluVirus();
	cout << "Flu: " << f->getM_dna() << " " << f->getM_resistance() << " " << f->getM_color() << endl;
	dengueVirus *d = new dengueVirus();
	cout << "Den: " << d->getM_dna() << " " << d->getM_resistance() << " " << d->getM_protein() << endl;*/
	
	patient *p = new patient();
	char t;
	while (p->getState()==1)
	{
		cout << "Take Medicine (0 = NO, 1 = YES): ";
		cin >> t;
		if (t == '1') {
			srand(time(NULL));
			int medicine_resistance = 1 + rand() % 27; // 1 - 60
			cout << "Medicine resistance: " << medicine_resistance << endl;
			p->takeMedicine(medicine_resistance);
		}
		else
		{
			break;
		}
	}
	system("pause");
	return 0;
}