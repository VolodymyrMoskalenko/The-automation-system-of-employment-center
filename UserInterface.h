#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Main.h"
#include "Database.h"
#include "Help.h"

class UserInterface
{
private:
	InputData input;
	Output output;
	Help help;
public:
	UserInterface();
	~UserInterface();

	void show();
};
#endif