#ifndef STUDENT_H
#define STUDENT_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Person.h"
#include "Proj.h"
#include "EE_Course.h"
#include "CS_Course.h"

class Student : public Person {
public:
	Student();
	~Student();
	int getCourseCnt();
	bool addEE_Course(EE_Course* new_course);
	bool addCS_Course(CS_Course* new_course);
	bool remCourse(int course_num);
	EE_Course* getEE_Course(int course_num);
	CS_Course* getCS_Course(int course_num);
	int getAvg();
	void print();

private:
	EE_Course* ee_course_;
	int ee_count;
	CS_Course* cs_course_;
	int cs_count;
};


#endif //STUDENT_H