#include "Date.h"

Date::Date()
{}

Date::Date(time_t dateNow)
{
	this->dateNow = dateNow;
}

string Date::getDate()
{
	this->dateNow = time(0);

	tm timeStruct;
	gmtime_s(&timeStruct, &dateNow);

	int dayNow = timeStruct.tm_mday;
	int monthNow = timeStruct.tm_mon + 1;
	int yearNow = 1900 + timeStruct.tm_year;	

	string date = to_string(dayNow) + "." + to_string(monthNow) + "." + to_string(yearNow);

	return (date);
}

	/*char date[30];
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);
	date = asctime(timeinfo);

    return (date);*/