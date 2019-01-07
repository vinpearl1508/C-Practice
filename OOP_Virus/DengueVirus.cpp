#include<iostream>
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"
using namespace std;

dengueVirus::dengueVirus() {
	doBorn();
	initResistance();
}
dengueVirus::~dengueVirus() {
	setM_protein("");
}
dengueVirus::dengueVirus(const dengueVirus* dengueVirus) {
	*this = *dengueVirus;
}

void dengueVirus::doBorn() {
	loadADNInformation();
	int n = 1 + rand() % 3;
	if (n == 1) {
		setM_protein("NS3");
	}
	else if (n == 2) {
		setM_protein("NS5");
	}
	else {
		setM_protein("E");
	}
}
vector<virus*> dengueVirus::doClone() {
	vector<virus*> virusList;
	dengueVirus *newDengueVirus1 = new dengueVirus(this);
	virusList.push_back(newDengueVirus1);
	dengueVirus *newDengueVirus2 = new dengueVirus(this);
	virusList.push_back(newDengueVirus2);
	return virusList;
}
void dengueVirus::doDie() {
	this->~dengueVirus();
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

void dengueVirus::setM_protein(char m_protein[4]) {
	this->m_protein[4] = m_protein[4];
}
char dengueVirus::getM_protein() {
	return m_protein[4];
}