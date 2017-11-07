#include "Help.h"

Help::Help()
{}

void Help::showAllHelp()
{
	output.showTextNewLine("Enter command:");
	output.showTextNewLine("'add category' - adds category");
	output.showTextNewLine("'delete category' - deletes category");
	output.showTextNewLine("'change category' - changes category");
	output.showTextNewLine("'view category' - displays info about category");
	output.showTextNewLine("'view all categories' - shows all categories");

	output.showTextNewLine("'add vacancy' - adds vacancy");
	output.showTextNewLine("'delete vacancy' - deletes vacancy");
	output.showTextNewLine("'change vacancy' - changes vacancy");
	output.showTextNewLine("'view vacancy' - displays info about vacancy");
	output.showTextNewLine("'sort vacancies by name' - sort vacancies by name");
	output.showTextNewLine("'view all vacancies' - shows all vacancies");
   
	output.showTextNewLine("'add resume' - adds resume");
	output.showTextNewLine("'delete resume' - deletes resume");
	output.showTextNewLine("'change resume' - changes resume");
	output.showTextNewLine("'view resume' - displays info about resume");
	output.showTextNewLine("'sort resumes by name' - sort resumes by name");
	output.showTextNewLine("'view all resumes' - shows all resumes");

	output.showTextNewLine("'add unemployed' - adds unemployed");
	output.showTextNewLine("'delete unemployed' - deletes unemployed");
	output.showTextNewLine("'change unemployed' - changes unemployed");
	output.showTextNewLine("'view unemployed' - displays info about unemployed");
	output.showTextNewLine("'sort unemployed by name' - sort unemployed by name");
	output.showTextNewLine("'sort unemployed by surname' - sort unemployed by surname");
	output.showTextNewLine("'view all unemployed' - shows all unemployed");

	output.showTextNewLine("'add firm' - adds firm");
	output.showTextNewLine("'delete firm' - deletes firm");
	output.showTextNewLine("'change firm' - changes firm");
	output.showTextNewLine("'view firm' - displays info about firm");
	output.showTextNewLine("'sort firms by name' - sort firms by name");
	output.showTextNewLine("'view all firms' - shows all firms");

	output.showTextNewLine("'hiring on vacancy' - hire unemployed on vacancy");
	output.showTextNewLine("'cancel hiring on vacancy' - cancel hiring unemployed on vacancy");
	output.showTextNewLine("'view hiring on vacancy' - displays info about hiring");

	output.showTextNewLine("'search on the vacancies' - search on the vacancies");
	output.showTextNewLine("'search on the uneployed' - search on the uneployed");
	output.showTextNewLine("'search on the firm' - search on the firm");
}