#ifndef DENGUE_VIRUS_H
#define DENGUE_VIRUS_H
#include "Virus.h"
#include "FluVirus.h"
#include <vector>
//Inherit Virus
class dengueVirus : public virus
{
public:
	//Constructor
	dengueVirus();
	//Destructor
	~dengueVirus();
	//Copy Constructor
	dengueVirus(const dengueVirus&);

	//Call LoadADNInformation() and randomly initialize protein for Dengue Virus
	void doBorn() override;
	//Virus that all its attributes are copied to new viruses
	std::vector<virus*> doClone() override;
	//Release all virus data
	void doDie() override;
	//Initialize the resistance (m_resistance) of virus to medicine and store it in m_resistance
	void initResistance() override;

	//Getter method
	void setM_protein(char*);
	char* getM_protein();
private:
	//Protein in virus represent the type of Dengue virus
	char m_protein[4];
};
#endif // !DENGUE_VIRUS_H
