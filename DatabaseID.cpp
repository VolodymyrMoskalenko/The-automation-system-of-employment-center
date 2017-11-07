#include "DatabaseID.h"

DatabaseID::DatabaseID(int ID)
{
	this->ID = ID;
}

int DatabaseID::getID()
{
	return (this->ID);
}

void DatabaseID::setID(int ID)
{
	this->ID = ID;
}