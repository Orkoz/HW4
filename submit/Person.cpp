#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Person.h"
#include "Proj.h"

//*************************************************************************
//* Function name: Person (constructor)
//* Description: creates a person ADT according to the given parameters.
//* Parameters:
//*		-  name – a string of the person name.
//*		-  id – the ID pf the person (unique for each person).
//* Return Value: none.
//*************************************************************************

Person::Person(char *name, int id):id_(id)
{
	name_ = new char[strlen(name) + 1];
	strcpy(name_, name);
}

//*************************************************************************
//* Function name: ~Person (destructor)
//* Description: deletes Person ADT.
//* Parameters: None.
//* Return Value: none.
//*************************************************************************

Person::~Person()
{
	delete[] name_;
}

//*************************************************************************
//* Function name: getID
//* Description: returns the id of the person
//* Parameters: None.
//* Return Value: id of person
//*************************************************************************

int Person::getID() const
{
	return id_;
}

//*************************************************************************
//* Function name: getName
//* Description: returns the name of the person
//* Parameters: None.
//* Return Value: pointer to name string
//*************************************************************************

char* Person::getName() const
{
	return name_;
}
