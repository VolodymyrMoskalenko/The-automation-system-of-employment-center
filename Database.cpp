#include "Database.h"

Database::Database(string name)
{
	this->name = name;

	this->categoryID = 0;
	this->vacancyID = 0;
	this->resumeID = 0;
	this->unemployedID = 0;
	this->firmID = 0;
	this->hiringID = 0;

	this->hiredID = 0;
	this->closedVacancyID = 0;
}

Database::~Database()
{}

// [ Category
Category Database::returnCategoryFromDatabase(int categoryID)
{
	return (categoryList.at(categoryID));
}

void Database::changeCategoryInDatabase(Category category)
{
	for (vector<Category>::iterator it = this->categoryList.begin(); it != this->categoryList.end(); it++)
	{
		if (it->getID() == category.getID())
		{
			*it = category;
		}
	}
}

////// 
void Database::addCategory()
{
	string categoryName;
	int categoryID = this->categoryID;

	output.showTextNewLine("Enter category name:");
	categoryName = input.getStringLine("[A-Z a-z.]{1,}");

	Category newCategory(categoryID, categoryName);
	this->categoryList.push_back(newCategory);

	cout << endl;
	this->categoryID++;
}

void Database::deleteCategory()
{	
	output.showTextNewLine("Enter category ID:");
	string stringCategoryID = input.getIntegerLine();
	int categoryID = stoi(stringCategoryID);

	categoryList.erase(categoryList.begin() + categoryID);
}

void Database::changeCategory()
{	
	output.showTextNewLine("Enter category ID:");
	string stringCategoryID = input.getIntegerLine();
	int categoryID = std::stoi(stringCategoryID);

	Category category = this->returnCategoryFromDatabase(categoryID);

	output.showTextNewLine("Enter category name:");
	string categoryName = input.getStringLine("[A-Za-z.]{1,}");

	category.setCategoryName(categoryName);
	this->changeCategoryInDatabase(category);
}

void Database::viewCategory(int categoryID)
{
	vector<Category> categoryList = this->categoryList;

	for (vector<Category>::iterator it = categoryList.begin(); it != categoryList.end(); it++)
	{
		if (it->getID() == categoryID)
		{
			output.viewCategory(it);
		}
	}
}

void Database::viewAllCategories()
{
	vector<Category> categoryList = this->categoryList;

	for (vector<Category>::iterator it = categoryList.begin(); it != categoryList.end(); it++)
	{
		output.viewCategory(it);
	}
}
// ]



// [ Vacancy
Vacancy Database::returnVacancyFromDatabase(int vacancyID)
{
	return (vacancyList.at(vacancyID));
}

void Database::changeVacancyInDatabase(Vacancy vacancy)
{
	for (vector<Vacancy>::iterator it = this->vacancyList.begin(); it != this->vacancyList.end(); it++)
	{
		if (it->getID() == vacancy.getID())
		{
			*it = vacancy;
		}
	}
}

////
void Database::addVacancy()
{
	Date date;

	output.showTextNewLine("Enter vacancy name:");
	string vacancyName = input.getStringLine("[A-Za-z.]{1,}");

	output.showTextNewLine("Enter vacancy description:");
	string vacancyDescription = input.getStringLine("[A-Za-z.]{1,}");

	output.showTextNewLine("Existing firm:");
	viewAllFirms();

	output.showTextNewLine("Enter firm-employer ID:");
	string stringFirmID = input.getIntegerLine();
	int firmID = stoi(stringFirmID);

	Firm choosingFirm = this->returnFirmFromDatabase(firmID);
	string vacancyNameFirmEmployer = choosingFirm.getName();

	date.getDate();

	int vacancyID = this->vacancyID;

	Vacancy newVacancy(vacancyID, vacancyName, vacancyDescription, vacancyNameFirmEmployer, date.getDate());
	vacancyList.push_back(newVacancy);
	this->vacancyID++;
}

void Database::deleteVacancy()
{
	output.showTextNewLine("Enter vacancy ID:");
	string stringVacancyID = input.getIntegerLine();
	int vacancyID = stoi(stringVacancyID);

	vacancyList.erase(vacancyList.begin() + vacancyID);
}

void Database::changeVacancy()
{	
	output.showTextNewLine("Enter vacancy ID:");
	string stringVacancyID = input.getIntegerLine();
	int vacancyID = stoi(stringVacancyID);

	Vacancy vacancy = this->returnVacancyFromDatabase(vacancyID);

	output.showTextNewLine("Enter new vacancy name:");
	string vacancyNewName = input.getStringLine("[A-Za-z.]{1,}");

	output.showTextNewLine("Enter new vacancy description:");
	string vacancyNewDescription = input.getStringLine("[A-Za-z.]{1,}");

	output.showTextNewLine("Enter new vacancy name firm-employer:");
	string vacancyNewNameFirmEmployer = input.getStringLine("[A-Za-z.]{1,}");

	Date newDate;

	vacancy.setName(vacancyNewName);
	vacancy.setDescription(vacancyNewDescription);
	vacancy.setNameFirmEmployer(vacancyNewNameFirmEmployer);
	vacancy.setDate(newDate.getDate());

	this->changeVacancyInDatabase(vacancy);
}

void Database::viewVacancy(int vacancyID)
{
	vector<Vacancy> vacancyList = this->vacancyList;

	for (vector<Vacancy>::iterator it = vacancyList.begin(); it != vacancyList.end(); it++)
	{
		if (it->getID() == vacancyID)
		{
			output.viewVacancy(it);
		}
	}
}

void Database::sortVacancyByName()
{
	for (int i = 0; i < vacancyList.size(); i++)
	{
		for (int k = 0; k < vacancyList.size() - 1; k++)
		{
			if (vacancyList.at(k).getName() > vacancyList.at(k + 1).getName())
			{
				Vacancy temp = vacancyList.at(k + 1);
				vacancyList.at(k + 1) = vacancyList.at(k);
				vacancyList.at(k) = temp;
			}
		}
	}
}

void Database::viewAllVacancies()
{
	vector<Vacancy> vacancyList = this->vacancyList;

	for (vector<Vacancy>::iterator it = vacancyList.begin(); it != vacancyList.end(); it++)
	{
		output.viewVacancy(it);
	}
}
// ]



// [ Resume
Resume Database::returnResumeFromDatabase(int resumeID)
{
	return (resumeList.at(resumeID));
}

void Database::changeResumeInDatabase(Resume resume)
{
	for (vector<Resume>::iterator it = this->resumeList.begin(); it != this->resumeList.end(); it++)
	{
		if (it->getID() == resume.getID())
		{
			*it = resume;
		}
	}
}

////
void Database::addResume()
{
	Date date;

	output.showTextNewLine("Enter resume name:");
	string resumeName = input.getStringLine("[A-Za-z]{1,}");

	output.showTextNewLine("Enter resume description:");
	string resumeDescription = input.getStringLine("[A-Za-z]{1,}");

	output.showTextNewLine("Existing unemployed:");
	viewAllUnemployed();

	output.showTextNewLine("Enter unemployer ID:");
	string stringUnemployedID = input.getIntegerLine();

	int unemployedID = stoi(stringUnemployedID);
	Unemployed choosingUnemployed = this->returnUnemployedFromDatabase(unemployedID);
	string resumeNameUnemployer = choosingUnemployed.getName();

	date.getDate();

	int resumeID = this->resumeID;

	Resume newResume(vacancyID, resumeName, resumeDescription, resumeNameUnemployer, date.getDate());
	resumeList.push_back(newResume);
	this->resumeID++;
}

void Database::deleteResume()
{	
	output.showTextNewLine("Enter resume ID:");
	string stringResumeID = input.getIntegerLine();
	int resumeID = stoi(stringResumeID);

	resumeList.erase(resumeList.begin() + resumeID);
}

void Database::changeResume()
{
	output.showTextNewLine("Enter resume ID:");
	string stringResumeID = input.getIntegerLine();
	int resumeID = stoi(stringResumeID);

	Resume resume = this->returnResumeFromDatabase(resumeID);
	
	output.showTextNewLine("Enter new resume name:");
	string resumeNewName = input.getStringLine("[A-Za-z]{1,}");

	output.showTextNewLine("Enter new resume description:");
	string resumeNewDescription = input.getStringLine("[A-Za-z]{1,}");

	output.showTextNewLine("Enter new unemployer name:");
	string vacancyNewNameUnemployed = input.getStringLine("[A-Za-z]{1,}");

	Date newDate;

	resume.setName(resumeNewName);
	resume.setDescription(resumeNewDescription);
	resume.setNameUnemployed(vacancyNewNameUnemployed);
	resume.setDate(newDate.getDate());

	this->changeResumeInDatabase(resume);
}

void Database::viewResume(int resumeID)
{
	vector<Resume> resumeList = this->resumeList;

	for (vector<Resume>::iterator it = resumeList.begin(); it != resumeList.end(); it++)
	{
		if (it->getID() == resumeID)
		{
			output.viewResume(it);
		}
	}
}

void Database::sortResumeByName()
{
	for (int i = 0; i < resumeList.size(); i++)
	{
		for (int k = 0; k < resumeList.size() - 1; k++)
		{
			if (resumeList.at(k).getName() > resumeList.at(k + 1).getName())
			{
				Resume temp = resumeList.at(k + 1);
				resumeList.at(k + 1) = resumeList.at(k);
				resumeList.at(k) = temp;
			}
		}
	}
}

void Database::viewAllResumies()
{
	vector<Resume> resumeList = this->resumeList;

	for (vector<Resume>::iterator it = resumeList.begin(); it != resumeList.end(); it++)
	{
		{
			output.viewResume(it);
		}
	}
}
// ]



// [ Unemployed
Unemployed Database::returnUnemployedFromDatabase(int unemployedID)
{
	return (unemployedList.at(unemployedID));	
}

void Database::changeUnemployedInDatabase(Unemployed unemployed)
{
	for (vector<Unemployed>::iterator it = this->unemployedList.begin(); it != this->unemployedList.end(); it++)
	{
		if (it->getID() == unemployed.getID())
		{
			*it = unemployed;
		}
	}
}

////
void Database::addUnemployed()
{
	output.showTextNewLine("Enter unemployed name:");
	string unemployedName = input.getStringLine("[A-Za-z]{1,}");

	output.showTextNewLine("Enter unemployed surname:");
	string unemployedSurname = input.getStringLine("[A-Za-z]{1,}");

	int currentUnemployedID = this->unemployedID;

	Unemployed newUnemployed(currentUnemployedID, unemployedName, unemployedSurname);
	unemployedList.push_back(newUnemployed);

	this->unemployedID++;
	cout << endl;
}

void Database::deleteUnemployed()
{	
	output.showTextNewLine("Enter unemployed ID:");
	string stringUnemployedID = input.getIntegerLine();
	int unemployedID = stoi(stringUnemployedID);

	unemployedList.erase(unemployedList.begin() + unemployedID);
}

void Database::changeUnemployed()
{	
	output.showTextNewLine("Enter unemployed ID:");
	string stringUnemployedID = input.getIntegerLine();
	int unemployedID = stoi(stringUnemployedID);

	Unemployed unemployed = this->returnUnemployedFromDatabase(unemployedID);

	output.showTextNewLine("Enter new unemployed name:");
	string unemployedNewName = input.getStringLine("[A-Za-z]{1,}");

	output.showTextNewLine("Enter new unemployed surname:");
	string unemployedNewNameSurname = input.getStringLine("[A-Za-z]{1,}");

	unemployed.setName(unemployedNewName);
	unemployed.setSurname(unemployedNewNameSurname);

	this->changeUnemployedInDatabase(unemployed);
}

void Database::viewUnemployed(int unemployedID)
{
	vector<Unemployed> unemployedList = this->unemployedList;

	for (vector<Unemployed>::iterator it = unemployedList.begin(); it != unemployedList.end(); it++)
	{
		if (it->getID() == unemployedID)
		{
			output.viewUnemployed(it);
		}
	}
}

void Database::sortUnemployedByName()
{
	for (int i = 0; i < unemployedList.size(); i++)
	{
		for (int k = 0; k < unemployedList.size() - 1; k++)
		{
			if (unemployedList.at(k).getName() > unemployedList.at(k + 1).getName())
			{
				Unemployed temp = unemployedList.at(k + 1);
				unemployedList.at(k + 1) = unemployedList.at(k);
				unemployedList.at(k) = temp;
			}
		}
	}
}

void Database::sortUnemployedBySurname()
{
	for (int i = 0; i < unemployedList.size(); i++)
	{
		for (int k = 0; k < unemployedList.size() - 1; k++)
		{
			if (unemployedList.at(k).getSurname() > unemployedList.at(k + 1).getSurname())
			{
				Unemployed temp = unemployedList.at(k + 1);
				unemployedList.at(k + 1) = unemployedList.at(k);
				unemployedList.at(k) = temp;
			}
		}
	}
}

void Database::viewAllUnemployed()
{
	vector<Unemployed> unemployedList = this->unemployedList;

	for (vector<Unemployed>::iterator it = unemployedList.begin(); it != unemployedList.end(); it++)
	{
		{
			output.viewUnemployed(it);
		}
	}
}
// ]



// [ Firm
Firm Database::returnFirmFromDatabase(int firmID)
{
	return (firmList.at(firmID));
}

void Database::changeFirmInDatabase(Firm firm)
{
	for (vector<Firm>::iterator it = this->firmList.begin(); it != this->firmList.end(); it++)
	{
		if (it->getID() == firm.getID())
		{
			*it = firm;
		}
	}
}

////
void Database::addFirm()
{	
	output.showTextNewLine("Enter firm name:");
	string firmName = input.getStringLine("[A-Za-z.]{1,}");

	output.showTextNewLine("Enter firm description:");
	string firmDescription = input.getStringLine("[A-Za-z.]{1,}");

	output.showTextNewLine("Enter firm vacancy count:");
	string stringFirmVacancyCount = input.getIntegerLine();
	int firmVacancyCount = stoi(stringFirmVacancyCount);

	output.showTextNewLine("Enter firm registration number:");
	string stringFirmNumber = input.getIntegerLine();
	int firmNumber = stoi(stringFirmNumber);
	
	int firmID = this->firmID;

	Firm newFirm(firmID, firmName, firmDescription, firmVacancyCount, firmNumber);
	firmList.push_back(newFirm);
	this->firmID++;
	cout << endl;
}

void Database::deleteFirm()
{	
	output.showTextNewLine("Enter firm ID:");
	string stringFirmID = input.getIntegerLine();
	int firmID = stoi(stringFirmID);

	firmList.erase(firmList.begin() + firmID);
}

void Database::changeFirm()
{	
	output.showTextNewLine("Enter firm ID:");
	string stringFirmID = input.getIntegerLine();
	int firmID = stoi(stringFirmID);

	Firm firm = this->returnFirmFromDatabase(firmID);
	
	output.showTextNewLine("Enter new firm name:");
	string firmNewName = input.getStringLine("[A-Za-z]{1,}");
	
	output.showTextNewLine("Enter new firm description:");
	string firmNewDescription = input.getStringLine("[A-Za-z]{1,}");
	
	output.showTextNewLine("Enter new vacancy count:");
	string stringFirmVacancyCount = input.getIntegerLine();
	int firmVacancyCount = stoi(stringFirmVacancyCount);
	
	output.showTextNewLine("Enter new registration number:");
	string stringFirmNumber = input.getStringLine("[A-Za-z]{1,}");
	int firmNumber = stoi(stringFirmNumber);

	firm.setName(firmNewName);
	firm.setDescription(firmNewDescription);
	firm.setVacancyCount(firmVacancyCount);
	firm.setNumber(firmNumber);

	this->changeFirmInDatabase(firm);
}

void Database::viewFirm(int firmID)
{
	vector<Firm> firmList = this->firmList;

	for (vector<Firm>::iterator it = firmList.begin(); it != firmList.end(); it++)
	{
		if (it->getID() == firmID)
		{
			output.viewFirm(it);
		}
	}
}

void Database::sortFirmByName()
{
	for (int i = 0; i < firmList.size(); i++)
	{
		for (int k = 0; k < firmList.size() - 1; k++)
		{
			if (firmList.at(k).getName() > firmList.at(k + 1).getName())
			{
				Firm temp = firmList.at(k + 1);
				firmList.at(k + 1) = firmList.at(k);
				firmList.at(k) = temp;
			}
		}
	}
}

void Database::viewAllFirms()
{
	vector<Firm> firmList = this->firmList;

	for (vector<Firm>::iterator it = firmList.begin(); it != firmList.end(); it++)
	{
		output.viewFirm(it);
	}
}
// ]



// [ Hiring
Hiring Database::returnHiringFromDatabase(int hiringID)
{
	return (hiringList.at(hiringID));	
}

////
void Database::hiringOnVacancy()
{
	int currentHiringID = this->hiringID;

	Date date;
	
	output.showTextNewLine("Enter unemployer ID:");
	string stringCurrentUnemployerID = input.getIntegerLine();
	int currentUnemployerID = stoi(stringCurrentUnemployerID);
	Unemployed unemployed = this->returnUnemployedFromDatabase(currentUnemployerID);
	
	output.showTextNewLine("Enter vacancy ID:");
	string stringCurrentVacancyID = input.getIntegerLine();
	int currentVacancyID = stoi(stringCurrentVacancyID);
	Vacancy vacancy = this->returnVacancyFromDatabase(currentVacancyID);
	
	output.showTextNewLine("Enter firm-employed ID:");
	string stringCurrentFirmEmployedID = input.getIntegerLine();
	int currentFirmEmployerID = stoi(stringCurrentFirmEmployedID);
	Firm currentFirm = this->returnFirmFromDatabase(currentFirmEmployerID);

	Hiring newHiring(currentHiringID, date.getDate(), unemployed.getName(), unemployed.getSurname(), vacancy.getName(), currentFirm.getName()); // Створення нового акту найму

	hiringList.push_back(newHiring); // Додання акту найму в список наймів
	this->hiringID++;

	closedVacancyList.push_back(vacancy); // Додання вакансії в список закритих вакансії
	this->closedVacancyID++;

	hiredList.push_back(unemployed); // Додання непрацюючого в список працюючих
	this->hiredID++;

	// Видалення вакансії із списку вакансії
	vacancyList.erase(vacancyList.begin() + currentVacancyID);
	
	// Видалення непрацюючого із списку непрацюючих
	unemployedList.erase(unemployedList.begin() + currentUnemployerID);
	
	// Зменшуємо кількість вакансій фірми 
	for (vector<Firm>::iterator firmIT = this->firmList.begin(); firmIT != this->firmList.end(); firmIT++)
	{
		if (firmIT->getID() == currentFirmEmployerID)
		{
			int currentVacancyCount = firmIT->getVacancyCount();
			currentFirm.setVacancyCount(currentVacancyCount--);
			this->changeFirmInDatabase(currentFirm);
		}
	}
}

void Database::cancelHiringOnVacancy()
{
	/* Тут ми робимо щось схоже до попереднього пункту, але навпаки */	
	output.showTextNewLine("Enter hiring ID:");
	string stringCurrentHiringID = input.getIntegerLine();
	int currentHiringID = stoi(stringCurrentHiringID);

	Hiring currentHiring = this->returnHiringFromDatabase(currentHiringID);

	string currentNameUnemployed = currentHiring.getNameUnemployed();
	string currentVacancy = currentHiring.getVacancy();
	string currntFirmEmployerName = currentHiring.getNameFirmEmployer();

	for (vector<Unemployed>::iterator unemployedIT = this->hiredList.begin(); unemployedIT != this->hiredList.end(); unemployedIT++)
	{
		if (unemployedIT->getName() == currentNameUnemployed)
		{
			int returnUnemployedID = this->unemployedID;
			string returnUnemployedName = unemployedIT->getName();
			string returnUnemployedSurname = unemployedIT->getSurname();
			Unemployed returnUnemployed(returnUnemployedID, returnUnemployedName, returnUnemployedSurname);
			this->unemployedList.push_back(returnUnemployed);
			this->unemployedID++;

			this->hiredList.erase(unemployedIT);
			this->hiredID--;
			break;
		}
	}

	for (vector<Vacancy>::iterator vacancyIT = this->closedVacancyList.begin(); vacancyIT != this->closedVacancyList.end(); vacancyIT++)
	{
		if (vacancyIT->getName() == currentVacancy)
		{
			int returnVacancyID = this->vacancyID;
			string returnVacancyDescription = vacancyIT->getDescription();
			string returnFirmEmployerName = vacancyIT->getNameFirmEmployer();
			Date date;
			Vacancy returnVacancy(returnVacancyID, currentVacancy, returnVacancyDescription, returnFirmEmployerName, date.getDate());
			this->vacancyList.push_back(returnVacancy);
			this->vacancyID++;

			this->closedVacancyList.erase(vacancyIT);
			this->closedVacancyID--;
			break;
		}
	}

	for (vector<Firm>::iterator firmIT = this->firmList.begin(); firmIT != this->firmList.end(); firmIT++)
	{
		if (firmIT->getName() == currntFirmEmployerName)
		{
			int returnFirmID = firmIT->getID();
			string returnFirmDescription = firmIT->getDescription();
			int currentVacancyCount = firmIT->getVacancyCount();
			int currentFirmNumber = firmIT->getNumber();
			Firm returnFirm(returnFirmID, currntFirmEmployerName, returnFirmDescription, currentVacancyCount++, currentFirmNumber);
			this->changeFirmInDatabase(returnFirm);

			break;
		}
	}

	for (vector<Hiring>::iterator hiringIT = this->hiringList.begin(); hiringIT != this->hiringList.end(); hiringIT++)
	{
		if (hiringIT->getID() == currentHiringID)
		{
			this->hiringList.erase(hiringIT);
			this->hiringID--;
		}
	}
}

void Database::viewHiring(int hiringID)
{
	vector<Hiring> hiringList = this->hiringList;

	for (vector<Hiring>::iterator it = hiringList.begin(); it != hiringList.end(); it++)
	{
		if (it->getID() == hiringID)
		{
			output.viewHiring(it);
		}
	}
}
// ]



// [ Search
void Database::searchVacancy(string searchVacancyKey)
{
	for (vector<Vacancy>::iterator it = this->vacancyList.begin(); it != this->vacancyList.end(); it++)
	{
		if (it->getName() == searchVacancyKey)
		{
			viewVacancy(it->getID());
		}
	}
}

void Database::searchUnemployed(string searchUnemployedKey)
{
	for (vector<Unemployed>::iterator it = this->unemployedList.begin(); it != this->unemployedList.end(); it++)
	{
		if (it->getName() == searchUnemployedKey)
		{
			viewUnemployed(it->getID());
		}
	}
}

void Database::searchFirm()
{
}
// ]

void Database::saveInDatabase()
{
	pugi::xml_document doc;	

	for (int i = 0; i != this->categoryList.size(); i++)
	{
		Category currentCategory = categoryList.at(i);
		pugi::xml_node node = doc.append_child("Category");
		node.append_attribute("Name").set_value(currentCategory.getCategoryName().c_str());
	}
	
	for (int i = 0; i != this->vacancyList.size(); i++)
	{
		Vacancy currentVacancy = vacancyList.at(i);
		pugi::xml_node node = doc.append_child("Vacancy");
		node.append_child("Name").append_attribute("Name").set_value(currentVacancy.getName().c_str());
		node.append_child("Description").append_attribute("Description").set_value(currentVacancy.getDescription().c_str());
		node.append_child("NameFirmEmployer").append_attribute("NameFirmEmployer").set_value(currentVacancy.getNameFirmEmployer().c_str());
		node.append_child("Date").append_attribute("Date").set_value(currentVacancy.getDate().c_str());
	}

	for (int i = 0; i != this->resumeList.size(); i++)
	{
		Resume currentResume = resumeList.at(i);
		pugi::xml_node node  = doc.append_child("Resume");
		node.append_child("Name").append_attribute("Name").set_value(currentResume.getName().c_str());
		node.append_child("Description").append_attribute("Description").set_value(currentResume.getDescription().c_str());
		node.append_child("NameUnemployed").append_attribute("NameUnemmployed").set_value(currentResume.getNameUnemployed().c_str());
		node.append_child("Date").append_attribute("Date").set_value(currentResume.getDate().c_str());
	}

	for (int i = 0; i != this->unemployedList.size(); i++)
	{
		Unemployed currentUnemployed = unemployedList.at(i);
		pugi::xml_node node = doc.append_child("Unemployed");
		node.append_attribute("Name").set_value(currentUnemployed.getName().c_str());
		node.append_attribute("Surname").set_value(currentUnemployed.getSurname().c_str());
	}

	for (int i = 0; i != this->firmList.size(); i++)
	{
		Firm currentFirm = firmList.at(i);
		pugi::xml_node node  = doc.append_child("Firm");
		node.append_child("Name").append_attribute("Name").set_value(currentFirm.getName().c_str());
		node.append_child("Description").append_attribute("Description").set_value(currentFirm.getDescription().c_str());
		node.append_child("VacancyCount").append_attribute("VacancyCount").set_value(to_string(currentFirm.getVacancyCount()).c_str());
		node.append_child("Number").append_attribute("Number").set_value(to_string(currentFirm.getNumber()).c_str());
	}
	
	for (int i = 0; i != this->hiringList.size(); i++)
	{
		Hiring currentHiring = hiringList.at(i);
		pugi::xml_node node = doc.append_child("Hiring");
		node.append_child("Date").append_attribute("Date").set_value(currentHiring.getDate().c_str());
		node.append_child("NameUnemployed").append_attribute("NameUnemployed").set_value(currentHiring.getNameUnemployed().c_str());
		node.append_child("SurnameUnemployed").append_attribute("SurnameUnemployed").set_value(currentHiring.getSurnameUnemployed().c_str());
		node.append_child("Vacancy").append_attribute("Vacancy").set_value(currentHiring.getVacancy().c_str());
		node.append_child("NameFirmEmployer").append_attribute("NameFirmEmployer").set_value(currentHiring.getNameFirmEmployer().c_str());		
	}

	for (int i = 0; i != this->hiredList.size(); i++)
	{
		Unemployed currentHired = hiredList.at(i);
		pugi::xml_node node = doc.append_child("Hired");
		node.append_attribute("Name").set_value(currentHired.getName().c_str());
		node.append_attribute("Surname").set_value(currentHired.getSurname().c_str());
	}

	for (int i = 0; i != this->closedVacancyList.size(); i++)
	{
		Vacancy currentClosedVacancy = closedVacancyList.at(i);
		pugi::xml_node node = doc.append_child("ClosedVacancy");
		node.append_child("Name").append_attribute("Name").set_value(currentClosedVacancy.getName().c_str());
		node.append_child("Description").append_attribute("Description").set_value(currentClosedVacancy.getDescription().c_str());
		node.append_child("NameFirmEmployer").append_attribute("NameFirmEmployer").set_value(currentClosedVacancy.getNameFirmEmployer().c_str());
		node.append_child("Date").append_attribute("Date").set_value(currentClosedVacancy.getDate().c_str());
	}

	doc.save_file(name.c_str());
}

void Database::loadFromDatabase()
{
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(name.c_str());
	
	if (result)
	{
		this->categoryList.clear();
		this->vacancyList.clear();
		this->resumeList.clear();
		this->unemployedList.clear();
		this->firmList.clear();
		this->hiringList.clear();
		this->hiredList.clear();
		this->closedVacancyList.clear();

		this->categoryID = 0;
		this->vacancyID = 0;
		this->resumeID = 0;
		this->unemployedID = 0;
		this->firmID = 0;
		this->hiringID = 0;
		this->hiredID = 0;
		this->closedVacancyID = 0;

		for each (pugi::xml_node element in doc.children())
		{
			if ((string)element.name() == "Category")
			{
				Category currentCategory(this->categoryID++, element.attribute("Name").value());
				this->categoryList.push_back(currentCategory);
			}

			if ((string)element.name() == "Vacancy")
			{
				// Для спрощення
				string vacancyName = element.child("Name").attribute("Name").value();
				string vacancyDescription = element.child("Description").attribute("Description").value();
				string vacancyNameFirmEmployer = element.child("NameFirmEmployer").attribute("NameFirmEmployer").value();
				string vacancyDate = element.child("Date").attribute("Date").value();
				
				Vacancy currentVacancy(this->vacancyID++, vacancyName, vacancyDescription, vacancyNameFirmEmployer, vacancyDate);
				this->vacancyList.push_back(currentVacancy);					   
			}

			if ((string)element.name() == "Resume")
			{
				string resumeName = element.child("Name").attribute("Name").value();
				string resumeDescription = element.child("Description").attribute("Description").value();
				string resumeNameUnemployed = element.child("NameUnemployed").attribute("NameUnemployed").value();
				string resumeDate = element.child("Date").attribute("Date").value();
				
				Resume currentResume(this->resumeID++, resumeName, resumeDescription, resumeNameUnemployed, resumeDate);
				this->resumeList.push_back(currentResume);
			}

			if ((string)element.name() == "Unemployed")
			{
				Unemployed currentUnemployed(this->unemployedID++, element.attribute("Name").value(), element.attribute("Surname").value());
				this->unemployedList.push_back(currentUnemployed);
			}

			if ((string)element.name() == "Firm")
			{
				string firmName = element.child("Name").attribute("Name").value();
				string firmDescription = element.child("Description").attribute("Description").value();
				int firmVacancyCount = element.child("VacancyCount").attribute("VacancyCount").as_int();
				int firmNumber = element.child("Number").attribute("Number").as_int();
				
				Firm currentFirm(this->firmID++, firmName, firmDescription, firmVacancyCount, firmNumber);
				this->firmList.push_back(currentFirm);
			}

			if ((string)element.name() == "Hiring")
			{				
				string hiringDate = element.child("Date").attribute("Date").value();
				string hiringNameUnemployed = element.child("NameUnemployed").attribute("NameUnemployed").value();
				string hiringSurnameUnemployed = element.child("SurnameUnemployed").attribute("SurnameUnemployed").value();
				string hiringDescription = element.child("Vacancy").attribute("Vacancy").value();
				string hiringNumber = element.child("NameFirmEmployer").attribute("NameFirmEmployer").value();
				
				Hiring currentHiring(this->hiringID++, hiringDate, hiringNameUnemployed, hiringSurnameUnemployed, hiringDescription, hiringNumber);
				this->hiringList.push_back(currentHiring);
			}

			if ((string)element.name() == "Hired")
			{				
				Unemployed currentHired(this->hiredID++, element.attribute("Name").value(), element.attribute("Surname").value());
				this->hiredList.push_back(currentHired);
			}

			if ((string)element.name() == "ClosedVacancy")
			{
				string closedVacancyName = element.child("Name").attribute("Name").value();
				string closedVacancyDescription = element.child("Description").attribute("Description").value();
				string closedVacancyNameFirmEmployer = element.child("NameFirmEmployer").attribute("NameFirmEmployer").value();
				string closedVacancyDate = element.child("Date").attribute("Date").value();
				
				Vacancy currentClosedVacancy(this->closedVacancyID++, closedVacancyName, closedVacancyDescription, closedVacancyNameFirmEmployer, closedVacancyDate);
				this->closedVacancyList.push_back(currentClosedVacancy);
			}
		}
	}
	else
		cout << "Error loading file!" << endl;
}