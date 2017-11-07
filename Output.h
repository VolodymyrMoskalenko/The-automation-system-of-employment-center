#ifndef OUTPUT_H
#define OUTPUT_H

#include "Main.h"

#include "Category.h"
#include "Vacancy.h"
#include "Firm.h"
#include "Hiring.h"
#include "Resume.h"
#include "Unemployed.h"

class Output
{
public:
	Output();

	void showText(string text);
	void showTextNewLine(string text);
	
	void viewCategory(vector<Category>::iterator categoryIT);
	void viewVacancy(vector<Vacancy>::iterator vacancyIT);
	void viewResume(vector<Resume>::iterator resumeIT);
	void viewUnemployed(vector<Unemployed>::iterator unemployedIT);
	void viewFirm(vector<Firm>::iterator firmIT);
	void viewHiring(vector<Hiring>::iterator hiringIT);
};
#endif