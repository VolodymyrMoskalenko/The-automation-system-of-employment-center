#ifndef UNEMPLOYED_H
#define UNEMPLOYED_H
#include "Main.h"
#include "DatabaseID.h"

class Unemployed : public DatabaseID
{
private:
	string name;
	string surname;
public:
	Unemployed(int ID, string name, string surname);

	string getName();
	string getSurname();

	void setName(string name);
	void setSurname(string surname);
};
#endif