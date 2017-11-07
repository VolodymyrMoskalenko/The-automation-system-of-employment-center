#include "Firm.h"

Firm::Firm(int ID, string name, string description, int vacancyCount, int number) : DatabaseID(ID)
{
	this->name = name;
	this->description = description;
	this->vacancyCount = vacancyCount;
	this->number = number;
}

string Firm::getName()
{
	return (this->name);
}

string Firm::getDescription()
{
	return (this->description);
}

int Firm::getVacancyCount()
{
	return (this->vacancyCount);
}

int Firm::getNumber()
{
	return (this->number);
}

void Firm::setName(string name)
{
	this->name = name;
}

void Firm::setDescription(string description)
{
	this->description = description;
}

void Firm::setVacancyCount(int vacancyCount)
{
	this->vacancyCount = vacancyCount;
}

void Firm::setNumber(int number)
{
	this->number = number;
}