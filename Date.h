#ifndef DATE_H
#define DATE_H

#include "Main.h"
#include <ctime>
class Date
{
private:
	time_t dateNow;
public:
	Date();
	Date(time_t dateNow);

	string getDate();	
};
#endif