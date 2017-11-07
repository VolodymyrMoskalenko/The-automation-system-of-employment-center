#ifndef HIRING_H
#define HIRING_H

#include "Main.h"
#include "Vacancy.h"
#include "Resume.h"
#include "DatabaseID.h"
#include "Date.h"

class Hiring : public DatabaseID
{
private:
	string date;
	string nameUnemployed;
	string surnameUnemployed;
	string vacancy;
	string nameFirmEmployer;
public:
	Hiring(int ID, string date, string nameUnemployed, string surnameUnemployed, string vacancy, string nameFirmEmployer);

	string getDate();
	string getNameUnemployed();
	string getSurnameUnemployed();
	string getVacancy();
	string getNameFirmEmployer();

	/*void setDate(string date);
	void setNameUnemployer(string nameUnemployer);
	void setSurnameUnemployer(string surnameUnemployer);
	void setVacancy(string vacancy);
	void setNameFirmEmployer(string nameFirmEmployer);*/
};
#endif