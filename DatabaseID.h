#ifndef DATABASEID_H
#define DATABASEID_H

//#include "pugixml.hpp"
#include <sstream>
#include <string>
#include "Main.h"

// ���� �������� ��� ���������� � ��� �����
class DatabaseID
{
private:
	int ID;
public:
	DatabaseID(int ID);

	int getID();
	void setID(int ID);
};
#endif