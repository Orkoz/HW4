#ifndef PERSON_H
#define PERSON_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

class Person {
public:

	Person(char *name, int id);
	~Person();
	int getID();
	char* getName();

private:
	char* name;
	int id;
};


#endif //PERSON_H