#ifndef FIRM_H
#define FIRM_H

#include "Main.h"
#include "DatabaseID.h"

class Firm : public DatabaseID
{
private:
	string name;
	string description;
	int vacancyCount;
	int number;
public:
	Firm(int ID, string name, string description, int vacancyCount, int number);

	string getName();
	string getDescription();
	int getVacancyCount();
	int getNumber();

	void setName(string name);
	void setDescription(string description);
	void setVacancyCount(int vacancyCount);
	void setNumber(int number);
};
#endif