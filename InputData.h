#ifndef INPUTDATA_H
#define INPUTDATA_H

#include "Main.h"
#include "Output.h"
#include <regex>

class InputData
{
private:
	Output output;
public:
	InputData();

	string getLine();
	string getStringLine(string stringRegex);
	string getIntegerLine();
};
#endif