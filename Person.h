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
	int getID() const;
	char* getName() const;

private:
	const char* name_;
	const int id_;
};


#endif //PERSON_H