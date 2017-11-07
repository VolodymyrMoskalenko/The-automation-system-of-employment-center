#include "Output.h"

Output::Output()
{}

void Output::showText(string text)
{
	cout << text;
}

void Output::showTextNewLine(string text)
{
	cout << text << endl;
}

void Output::viewCategory(vector<Category>::iterator categoryIT)
{
	cout << "Category ID: " << categoryIT->getID() << endl;
	cout << "Category name: " << categoryIT->getCategoryName() << endl;
}

void Output::viewVacancy(vector<Vacancy>::iterator vacancyIT)
{
	cout << "Vacancy ID: " << vacancyIT->getID() << endl;
	cout << "Vacancy name: " << vacancyIT->getName() << endl;
	cout << "Vacancy description: " << vacancyIT->getDescription() << endl;
	cout << "Name firm employer: " << vacancyIT->getNameFirmEmployer() << endl;
	cout << "Date: " << vacancyIT->getDate() << endl;
}

void Output::viewResume(vector<Resume>::iterator resumeIT)
{
	cout << "Resume ID: " << resumeIT->getID() << endl;
	cout << "Resume name: " << resumeIT->getName() << endl;
	cout << "Resume description: " << resumeIT->getDescription() << endl;
	cout << "Name unemployer: " << resumeIT->getNameUnemployed() << endl;
	cout << "Date: " << resumeIT->getDate() << endl;
}

void Output::viewUnemployed(vector<Unemployed>::iterator unemployedIT)
{
	cout << "Unemployed ID: " << unemployedIT->getID() << endl;
	cout << "Unemployed name: " << unemployedIT->getName() << endl;
	cout << "Unemployed surname: " << unemployedIT->getSurname() << endl;
}

void Output::viewFirm(vector<Firm>::iterator firmIT)
{
	cout << "Firm ID: " << firmIT->getID() << endl;
	cout << "Firm name: " << firmIT->getName() << endl;
	cout << "Firm description: " << firmIT->getDescription() << endl;
	cout << "Firm vacancy count: " << firmIT->getVacancyCount() << endl;
	cout << "Firm register number: " << firmIT->getNumber() << endl;
}

void Output::viewHiring(vector<Hiring>::iterator hiringIT)
{
	cout << "Hiring ID:" << hiringIT->getID() << endl;
	cout << "Date:" << hiringIT->getDate() << endl;
	cout << "Unemployer name:" << hiringIT->getNameUnemployed() << endl;
	cout << "Vacancy: " << hiringIT->getVacancy() << endl;
	cout << "Firm-employer name:" << hiringIT->getNameFirmEmployer() << endl;
}