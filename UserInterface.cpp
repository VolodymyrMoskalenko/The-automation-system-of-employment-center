#include "UserInterface.h"

UserInterface::UserInterface()
{}

UserInterface::~UserInterface()
{}

void UserInterface::show()
{
	Database dataBase("Database.xml");

	string answer;
	output.showTextNewLine("Welcome to the Automation System of Employment Center!");
	help.showAllHelp();

	dataBase.loadFromDatabase();

	do
	{
		output.showText(">>");
		answer = input.getLine();

		// [ Category
		if (answer == "add category")
		{
			dataBase.addCategory();
		}

		if (answer == "delete category")
		{
			dataBase.deleteCategory();
		}

		if (answer == "change category")
		{
			dataBase.changeCategory();
		}
		
		if (answer == "view category")
		{
			
			output.showTextNewLine("Enter ID:");
			string stringID = input.getIntegerLine();
			int ID = stoi(stringID);
			dataBase.viewCategory(ID);
		}
		
		if (answer == "view all categories")
		{
			dataBase.viewAllCategories();
		}
		// ]
		
		// [ Vacancy
		if (answer == "add vacancy")
		{
			dataBase.addVacancy();
		}
		
		if (answer == "delete vacancy")
		{
			dataBase.deleteVacancy();
		}
		
		if (answer == "change vacancy")
		{
			dataBase.changeVacancy();
		}
		
		if (answer == "view vacancy")
		{			
			output.showTextNewLine("Enter ID:");
			string stringID = input.getIntegerLine();
			int ID = stoi(stringID);
			dataBase.viewVacancy(ID);
		}
		
		if (answer == "view all vacancies")
		{
			dataBase.viewAllVacancies();
		}
		// ]
		
		// [ Resume		
		if (answer == "add resume")
		{
			dataBase.addResume();
		}
		
		if (answer == "delete resume")
		{
			dataBase.deleteResume();
		}
		
		if (answer == "change resume")
		{
			dataBase.changeResume();
		}
		
		if (answer == "view resume")
		{			
			output.showTextNewLine("Enter ID:");
			string stringID = input.getIntegerLine();
			int ID = stoi(stringID);
			dataBase.viewResume(ID);
		}
		
		if (answer == "view all resumies")
		{
			dataBase.viewAllResumies();
		}
		// ]
		
		// [ Unemployed
		if (answer == "add unemployed")
		{
			dataBase.addUnemployed();
		}
		
		if (answer == "delete unemployed")
		{
			dataBase.deleteUnemployed();
		}

		if (answer == "change unemployed")
		{
			dataBase.changeUnemployed();
		}
		
		if (answer == "view unemployed")
		{			
			output.showTextNewLine("Enter ID:");
			string stringID = input.getIntegerLine();
			int ID = stoi(stringID);
			dataBase.viewUnemployed(ID);
		}
		
		if (answer == "view all unemployedies")
		{
			dataBase.viewAllUnemployed();
		}
		// ]
		
		// [ Firm
		if (answer == "add firm")
		{
			dataBase.addFirm();
		}
		
		if (answer == "delete firm")
		{
			dataBase.deleteFirm();
		}
		
		if (answer == "change firm")
		{
			dataBase.changeFirm();
		}
		
		if (answer == "view firm")
		{			
			output.showTextNewLine("Enter ID:");
			string stringID = input.getIntegerLine();
			int ID = stoi(stringID);
			dataBase.viewFirm(ID);
		}
		
		if (answer == "view all firms")
		{
			dataBase.viewAllFirms();
		}
		// ]
		
		// [Hiring
		if (answer == "hiring on vacancy")
		{
			dataBase.hiringOnVacancy();
		}
		
		if (answer == "cancel hiring on vacancy")
		{
			dataBase.cancelHiringOnVacancy();
		}
		
		if (answer == "view hiring on vacancy")
		{
			output.showTextNewLine("Enter ID:");
			string stringID = input.getIntegerLine();
			int ID = stoi(stringID);
			dataBase.viewHiring(ID);
		}
		//
		
		// [ Search
		if (answer == "search on the vacancies")
		{			
			output.showTextNewLine("Enter name vacancy to found:");
			string nameFoundingVacancy = input.getStringLine("[A-Za-z]{1,}");
			dataBase.searchVacancy(nameFoundingVacancy);
		}
		
		if (answer == "search on the uneployed")
		{
			
			output.showTextNewLine("Enter name unemployed to found:");
			string nameFoundingUnemployed = input.getStringLine("[A-Za-z]{1,}");
			dataBase.searchUnemployed(nameFoundingUnemployed);
		}
		
		if (answer == "search on the firm")
		{
			dataBase.searchFirm();
		}
		// ]
		
		// [ Sort
		if (answer == "sort vacancies by name")
		{
			dataBase.sortVacancyByName();
		}

		if (answer == "sort resumes by name")
		{
			dataBase.sortResumeByName();
		}

		if (answer == "sort unemployed by name")
		{
			dataBase.sortUnemployedByName();
		}

		if (answer == "sort unemployed by surname")
		{
			dataBase.sortUnemployedBySurname();
		}

		if (answer == "sort firms by name")
		{
			dataBase.sortFirmByName();
		}
		// ]

		if (answer == "help")
		{
			help.showAllHelp();
		}
	} while (answer != "exit");

	if (answer == "exit")
	{
		dataBase.saveInDatabase();
	}
}