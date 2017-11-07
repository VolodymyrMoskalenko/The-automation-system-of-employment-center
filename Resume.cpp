#include "Resume.h"

Resume::Resume(int ID, string name, string description, string nameUnemployed, string date) : DatabaseID(ID)
{
	this->name = name;
	this->description = description;
	this->nameUnemployed = nameUnemployed;
	this->date = date;
}

string Resume::getName()
{
	return (this->name);
}

string Resume::getDescription()
{
	return (this->description);
}

string Resume::getNameUnemployed()
{
	return (this->nameUnemployed);
}

string Resume::getDate()
{
	return (this->date);
}

void Resume::setName(string name)
{
	this->name = name;
}

void Resume::setDescription(string description)
{
	this->description = description;
}

void Resume::setNameUnemployed(string nameUnemployed)
{
	this->nameUnemployed = nameUnemployed;
}

void Resume::setDate(string date)
{
	this->date = date;
}