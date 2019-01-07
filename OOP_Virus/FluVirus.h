#ifndef FLU_VIRUS_H
#define FLU_VIRUS_H
#include "Virus.h"
#include <vector>
//Inherit Virus
class fluVirus : public virus
{
public:
	//Constructor
	fluVirus();
	//Destructor
	~fluVirus();
	//Copy Constructor
	fluVirus(const fluVirus&);

	//Call LoadADNInformation() and randomly initialize Flu m_color
	void doBorn() override;
	//A new virus that all its attributes are copied to a new one
	std::vector<virus*> doClone() override;
	//Release all virus data
	void doDie() override;
	//Set value for m_resistance
	void initResistance() override;
	
	//Setter, getter methods
	void setM_color(int);
	int getM_color();
private:
	//the color of Flu virus is blue or red
	int m_color;
	enum Color
	{
		BLUE = 1,
		RED = 2
	};
};
#endif // !FLU_VIRUS_H
