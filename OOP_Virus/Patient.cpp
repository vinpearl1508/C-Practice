#include <iostream>
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include "Patient.h"

#include <cstdlib> // For srand()
#include <ctime> // For time
using namespace std;

patient::patient() {
	initResistance();
	doStart();
}
patient::~patient() {
	doDie();
}
void patient::initResistance() {
	//Rand resistance of his body 1000 - 9000
	srand(time(NULL));
	m_resistance = 1000 + rand() % 8001;
	cout << "**Human resistance: " << m_resistance << "**" << endl;
	cout << endl;
}
void patient::doStart() {
	srand(time(NULL));
	int numVirus = 10 + rand() % 11; //Rand num of virus 10 - 20
	cout << "Numb of virus before drug: " << numVirus << endl;
	for (int i = 0; i < numVirus; i++) {		
		/*srand(time(NULL));
		int typeVirus = 1 + rand() % 2;
		if (typeVirus == 1) {
			fluVirus* flu = new fluVirus();
			cout << "Flu " << flu->getM_resistance() << " " << flu->getM_color() << endl;
			m_virusList.push_back(flu);
		}
		else {
			dengueVirus* den = new dengueVirus();
			cout << "Den " << den->getM_resistance() << " " << den->getM_protein() << endl;
			m_virusList.push_back(den);
		}*/

		//Rand type of virus: 1. Flu 2. Den
		virus* typeVirus;
		srand(time(NULL));
		if (rand() % 2 == 0) {
			typeVirus = new fluVirus();
		}
		else {
			typeVirus = new dengueVirus();
		}
		m_virusList.push_back(typeVirus);
	}
	m_state = 1;
}
void patient::takeMedicine(int medicine_resistance) {
	int virusList = m_virusList.size();
	for (int i = 0; i < virusList; i++)
	{
		this->m_virusList[i]->reduceResistance(medicine_resistance);
		if (m_virusList[i]->getM_resistance() > 0) {
			//cout << "Virus clone " << endl;
			for (auto virusClone : m_virusList[i]->doClone()) {
				this->m_virusList.push_back(virusClone);
			}
		}
		else
		{
			m_virusList[i]->setM_resistance(0);
			//cout << "Virus die " << endl;
		}
	}
	//If virus resistance = 0, please delete that virus away from m_virusList
	for (int i = 0; i < m_virusList.size(); i++)
	{
		if (m_virusList[i]->getM_resistance() == 0) {
			m_virusList.erase(m_virusList.begin()+i);
			i--;
		}
	}
	int totalVirusResistance = 0;
	for (virus* virus : m_virusList) {
		totalVirusResistance += virus->getM_resistance();
	}
	cout << "Numb of virus after drug: " << m_virusList.size() << endl;
	cout << "Total resistance of virus: " << totalVirusResistance << endl;
	if (totalVirusResistance > this->m_resistance) {
		doDie();
		cout << "-->Patient died" << endl;
	}else if (m_virusList.size() == 0) {
		cout << "-->Patient was recovered" << endl;
	}
	else {
		cout << "-->Patient still alive" << endl;
	}
	cout << endl;
}
void patient::doDie() {
	m_resistance = 0;
	m_virusList.clear();
	m_state = 0;
}
int patient::getState() {
	return m_state;
}
vector<virus*> patient::getM_virusList() {
	return m_virusList;
}
int patient::getM_resistance() {
	return m_resistance;
}