#include "Category.h"

Category::Category(int ID, string name) : DatabaseID(ID)
{
	this->name = name;
}

string Category::getCategoryName()
{
	return (this->name);
}

void Category::setCategoryName(string newName)
{
	this->name = newName;
}