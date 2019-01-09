#include <iostream>
#include "Virus.h"
#include <fstream>
#include <string>
using namespace std;

virus::virus() {
	m_dna = new char[50];
}
virus::~virus() {
}
virus::virus(const virus& virus) {
	this->m_dna = virus.m_dna;
	this->m_resistance = virus.m_resistance;
}
void virus::loadADNInformation() {
	ifstream fi;
	fi.open("ATGX.bin");
	if (fi.fail())
	{
		cout << "File load failed" << endl;
	}
	else {
		while (!fi.eof())
		{
			fi >> m_dna;
		}
		//cout << "File load successful" << endl;
	}
	fi.close();
}
void virus::reduceResistance(int medicine_resistance) {
	m_resistance -= medicine_resistance;
	if (m_resistance <= 0) {
		doDie();
		//cout << "The virus was destroyed!" << endl;
	}
}

void virus::setM_dna(char* m_dna) {
	this->m_dna = m_dna;
}
char* virus::getM_dna() {
	return m_dna;
}
void virus::setM_resistance(int m_resistance) {
	this->m_resistance = m_resistance;
}
int virus::getM_resistance() {
	return m_resistance;
}