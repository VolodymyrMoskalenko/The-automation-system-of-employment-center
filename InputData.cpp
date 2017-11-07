#include "InputData.h"

InputData::InputData()
{}

string InputData::getLine()
{
	string inputString;
	getline(cin, inputString);
	return (inputString);
}

string InputData::getStringLine(string stringRegex)
{
	string inputString;
	bool correctInput = false;

	while (correctInput == false)
	{
		inputString = this->getLine();
		if (regex_match(inputString, regex(stringRegex)))
		{
			correctInput = true;
		}
		else
		{
			output.showTextNewLine("Incorrect input string. Please try again. Enter a-z, A-Z value");
		}
	}

	return (inputString);
}

string InputData::getIntegerLine()
{
	string inputString;
	bool correctInput = false;

	while (correctInput == false)
	{
		inputString = this->getLine();
		if (regex_match(inputString, regex("[0-9]{1,}")))
		{
			correctInput = true;
		}
		else
		{
			output.showTextNewLine("Incorrect input string. Please try again. Enter 0-9 value");
		}
	}

	return (inputString);
}