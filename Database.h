#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

#include "Category.h"
#include "Vacancy.h"
#include "Firm.h"
#include "Hiring.h"
#include "Resume.h"
#include "Unemployed.h"
#include "DatabaseID.h"
#include "Main.h"
#include "Search.h"

#include "InputData.h"
#include "Output.h"

#include "pugixml.hpp"

class Database
{
private:
	string name;

	int categoryID;
	int vacancyID;
	int resumeID;
	int firmID;
	int unemployedID;
	int hiringID;

	int hiredID;
	int closedVacancyID;

	vector<Category> categoryList;
	vector<Vacancy> vacancyList;
	vector<Resume> resumeList;
	vector<Unemployed> unemployedList;
	vector<Firm> firmList;
	vector<Hiring> hiringList;

	vector<Unemployed> hiredList;
	vector<Vacancy> closedVacancyList;

	InputData input;
	Output output;
public:
	Database(string name);
	~Database();

	// [Category
	Category returnCategoryFromDatabase(int categoryID);
	void changeCategoryInDatabase(Category category);

	void addCategory();
	void deleteCategory();
	void changeCategory();
	void viewCategory(int categoryID);	
	void viewAllCategories();
	// ]

	// [Vacancy
	Vacancy returnVacancyFromDatabase(int vacancyID);
	void changeVacancyInDatabase(Vacancy vacancy);

	void addVacancy();
	void deleteVacancy();
	void changeVacancy();
	void viewVacancy(int vacancyID);
	void sortVacancyByName();
	void viewAllVacancies();
	// ]

	// [Resume
	Resume returnResumeFromDatabase(int resumeID);
	void changeResumeInDatabase(Resume resume);

	void addResume();
	void deleteResume();
	void changeResume();
	void viewResume(int resumeID);
	void sortResumeByName();
	void viewAllResumies();
	// ]

	// [ Unemployed
	Unemployed returnUnemployedFromDatabase(int unemployedID);
	void changeUnemployedInDatabase(Unemployed unemployed);

	void addUnemployed();
	void deleteUnemployed();
	void changeUnemployed();
	void viewUnemployed(int unemployedID);
	void sortUnemployedByName();
	void sortUnemployedBySurname();
	void viewAllUnemployed();
	// ]

	// [ Firm
	Firm returnFirmFromDatabase(int firmID);
	void changeFirmInDatabase(Firm firm);

	void addFirm();
	void deleteFirm();
	void changeFirm();
	void viewFirm(int FirmID);
	void sortFirmByName();
	void viewAllFirms();
	// ]

	// [Hiring
	Hiring returnHiringFromDatabase(int hiringID);

	void hiringOnVacancy();
	void cancelHiringOnVacancy();
	void viewHiring(int ID);
	//

	// [Search
	void searchVacancy(string searchVacancyKey);
	void searchUnemployed(string searchUnemployedKey);
	void searchFirm();
	// ]

	void loadFromDatabase();
	void saveInDatabase();
};
#endif