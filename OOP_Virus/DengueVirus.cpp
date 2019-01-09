#include<iostream>
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include <cstring>

#include <cstdlib> // For srand()
#include <ctime> // For time
using namespace std;

dengueVirus::dengueVirus() {
	doBorn();
	initResistance();
}
dengueVirus::~dengueVirus() {
	doDie();
}
dengueVirus::dengueVirus(const dengueVirus& dengueVirus) : virus(dengueVirus)
{
	//*this = *dengueVirus;
	strcpy_s(this->m_protein, dengueVirus.m_protein);
}

void dengueVirus::doBorn() {
	loadADNInformation();
	srand(time(NULL));
	int n = 1 + rand() % 3;
	if (n == 1) {
		strcpy_s(m_protein, "NS3");

	}
	else if (n == 2) {
		strcpy_s(m_protein, "NS5");

	}
	else {
		strcpy_s(m_protein, "E");
	}
}
vector<virus*> dengueVirus::doClone() {
	vector<virus*> virusList;
	dengueVirus *newDengueVirus1 = new dengueVirus(*this);
	virusList.push_back(newDengueVirus1);
	dengueVirus *newDengueVirus2 = new dengueVirus(*this);
	virusList.push_back(newDengueVirus2);
	return virusList;
}
void dengueVirus::doDie() {

}
void dengueVirus::initResistance() {
	if (m_protein == "NS3") {
		setM_resistance(1 + rand() % 10);
	}
	else if (m_protein == "NS5") {
		setM_resistance(11 + rand() % 10);
	}
	else {
		setM_resistance(21 + rand() % 10);
	}
}

void dengueVirus::setM_protein(char* m_protein) {
	strcpy_s(this->m_protein, m_protein);
}
char* dengueVirus::getM_protein() {
	return m_protein;
}