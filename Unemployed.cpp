#include "Unemployed.h"

Unemployed::Unemployed(int ID, string name, string surname) : DatabaseID(ID)
{
	this->name = name;
	this->surname = surname;
}

string Unemployed::getName()
{
	return (this->name);
}

string Unemployed::getSurname()
{
	return (this->surname);
}

void Unemployed::setName(string name)
{
	this->name = name;
}

void Unemployed::setSurname(string surname)
{
	this->surname = surname;
}