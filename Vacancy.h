#include "Main.h"
#include "DatabaseID.h"
#include "Date.h"

#ifndef VACANCY_H
#define VACANCY_H

class Vacancy : public DatabaseID
{
private:
	string name;
	string description;
	string nameFirmEmployer;
	string date;
	int category;
public:
	Vacancy(int ID, string name, string description, string nameFirmEmployer, string date);

	string getName();
	string getDescription();
	string getNameFirmEmployer();
	string getDate();

	void setName(string name);
	void setDescription(string description);
	void setNameFirmEmployer(string nameFirmEmployer);
	void setDate(string date);	
};
#endif