#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Person.h"
#include "Proj.h"

Person::Person(char *name, int id):id_(id)
{
	name_ = new char[strlen(name) + 1];
	strcpy(name_, name);
}
Person::~Person()
{
	delete[] name_;
}
int Person::getID() const
{
	return id_;
}
char* Person::getName() const
{
	return name_;
}
