#ifndef RESUME_H
#define RESUME_H

#include "Main.h"
#include "DatabaseID.h"
#include "Date.h"

class Resume : public DatabaseID
{
private:
	string name;
	string description;
	string nameUnemployed;
	string date;
public:
	Resume(int ID, string name, string description, string nameUnemployed, string date);

	string getName();
	string getDescription();
	string getNameUnemployed();
	string getDate();

	void setName(string name);
	void setDescription(string description);
	void setNameUnemployed(string nameUnemployed);
	void setDate(string date);
};
#endif