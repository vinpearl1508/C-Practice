#include<iostream>
#include "Virus.h"
#include "FluVirus.h"
using namespace std;

fluVirus::fluVirus() {
	doBorn();
	initResistance();
}
fluVirus::~fluVirus() {
	m_color = 0;
}
fluVirus::fluVirus(const fluVirus& fluVirus) : virus(fluVirus){
	//Copy all attributes of current virus
	//*this = *fluVirus;
	this->m_color = fluVirus.m_color;
}

void fluVirus::doBorn() {
	loadADNInformation();
	int n = 1 + rand() % 2;
	if (n == 1) {
		m_color = BLUE;
	}
	else {
		m_color = RED;
	}
}
vector<virus*> fluVirus::doClone() {
	vector<virus*> virusList;
	fluVirus *newFluVirus = new fluVirus(*this);
	virusList.push_back(newFluVirus);
	return virusList;
}
void fluVirus::doDie() {
	this->~fluVirus();
	cout << "The virus was died";
}
void fluVirus::initResistance() {
	if (m_color == RED) {
		setM_resistance(10 + rand() % 11); // 10 - 20
	}
	else {
		setM_resistance(10 + rand() % 6); // 10 - 15
	}
}

void fluVirus::setM_color(int m_color) {
	this->m_color = m_color;
}
int fluVirus::getM_color() {
	return m_color;
}