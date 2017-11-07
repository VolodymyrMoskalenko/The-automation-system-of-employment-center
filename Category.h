#include <string>
#include "DatabaseID.h"
#include "Vacancy.h"

#ifndef CATEGORY_H
#define CATEGORY_H
class Category : public DatabaseID
{
private:
	string name;
public:
	Category(int ID, string name);

	string getCategoryName();
	void setCategoryName(string newName);
};

#endif