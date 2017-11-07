#include "Vacancy.h"

Vacancy::Vacancy(int ID, string name, string description, string nameFirmEmployer, string date) : DatabaseID(ID)
{
	this->name = name;
	this->description = description;
	this->nameFirmEmployer = nameFirmEmployer;
	this->date = date;
}

string Vacancy::getName()
{
	return (this->name);
}

string Vacancy::getDescription()
{
	return (this->description);
}

string Vacancy::getNameFirmEmployer()
{
	return (this->nameFirmEmployer);
}

string Vacancy::getDate()
{
	return (this->date);
}

void Vacancy::setName(string name)
{
	this->name = name;
}

void Vacancy::setDescription(string description)
{
	this->description = description;
}

void Vacancy::setNameFirmEmployer(string nameFirmEmployer)
{
	this->nameFirmEmployer = nameFirmEmployer;
}

void Vacancy::setDate(string date)
{
	this->date = date;
}