#ifndef VIRUS_H
#define VIRUS_H
#include <vector>
class virus
{
public:
	//Constructor
	virus();
	//Destructor
	~virus();
	//Copy Constructor
	virus(const virus&);
	//Load DNA information from a ATGX.bin and store it in m_dna
	void loadADNInformation();
	//When a Patient call TakeMedicine, the medicine has the medicine_resistance and it will reduce the resistance of virus
	void reduceResistance(int);
	
	//Virus is an abstract class with pure virtual function
	virtual void doBorn() = 0;
	virtual std::vector<virus*> doClone() = 0;
	virtual void doDie() = 0;
	virtual void initResistance() = 0;
	
	//Setter, getter methods
	void setM_dna(char*);
	char* getM_dna();
	void setM_resistance(int);
	int getM_resistance();
private:
	//Store the order of acid nucleic sequence
	char* m_dna;
	//The virus resistance ability(10 – 30)
	int m_resistance;
};
#endif // !VIRUS_H