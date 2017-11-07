#include "Hiring.h"

Hiring::Hiring(int ID, string date, string nameUnemployed, string surnameUnemployed, string vacancy, string nameFirmEmployer) : DatabaseID(ID)
{
	this->date = date;
	this->nameUnemployed = nameUnemployed;
	this->surnameUnemployed = surnameUnemployed;
	this->vacancy = vacancy;
	this->nameFirmEmployer = nameFirmEmployer;
}

string Hiring::getDate()
{
	return (this->date);
}

string Hiring::getNameUnemployed()
{
	return (this->nameUnemployed);
}

string Hiring::getSurnameUnemployed()
{
	return (this->surnameUnemployed);
}

string Hiring::getVacancy()
{
	return (this->vacancy);
}

string Hiring::getNameFirmEmployer()
{
	return (this->nameFirmEmployer);
}