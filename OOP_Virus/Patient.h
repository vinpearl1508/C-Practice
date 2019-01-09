#ifndef PATIENT_H
#define PATIENT_H
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include <vector>
class patient
{
public:
	//Constructor
	patient();
	//Destructor
	~patient();
	//Randomly initialize the resistance of Patient
	void initResistance();
	//Initialize all virus randomly(around 10 – 20 virus) and add them to m_virusList
	void doStart();
	void takeMedicine(int);
	void doDie();
	int getState();
	std::vector<virus*> getM_virusList();
	int getM_resistance();
private:
	int m_resistance; //His natural resitance
	std::vector<virus*> m_virusList; //The current virus in his body
	int m_state; //0 - DIE, 1 - ALIVE
};
#endif // !PATIENT_H
