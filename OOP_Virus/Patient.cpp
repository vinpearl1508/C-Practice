#include <iostream>
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include "Patient.h"
using namespace std;

patient::patient() {
	initResistance();
	doStart();
}
patient::~patient() {

}
void patient::initResistance() {
	//Rand resistance of his body 1000 - 9000
	m_resistance = 1000 + rand() % 8001;
}
void patient::doStart() {
	int numVirus = 10 + rand() % 11; //Rand num of virus 10 - 20
	for (int i = 0; i < numVirus; i++) {
		//Rand type of virus: 1. Flu 2. Den
		int typeVirus = 1 + rand() % 2;
		if (typeVirus == 1) {
			fluVirus* flu = new fluVirus();
			m_virusList.push_back(flu);
		}
		else {
			dengueVirus* den = new dengueVirus();
			m_virusList.push_back(den);
		}
	}
	m_state = 1;
}
void patient::takeMedicine() {

}
void patient::doDie() {
	m_virusList.clear();
	m_state = 0;
}
int patient::getState() {
	return m_state;
}
vector<virus*> patient::getM_virusList() {
	return m_virusList;
}