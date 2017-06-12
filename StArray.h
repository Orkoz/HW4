#ifndef STARRAY_H
#define STARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
//#include "Person.h"
#include "Proj.h"
//#include "EE_Course.h"
//#include "CS_Course.h"
#include "Student.h"

class StArray {
public:
	StArray();
	~StArray();
	bool addStudent(int id, char* name);
	bool addEE_Course(int student_id, int course_id, char* course_name, int hm_count, float hm_weight);
	bool addCS_Course(int student_id, int course_id, char* course_name, int hm_count, float hm_weight, bool takef, char* book);
	bool setHwGrade(int student_id, int course_id, int hm_id, int hm_grade);
	bool setExamGrade(int student_id, int course_id, int grade);
	bool setFactor(int course_id, int factor);
	bool printStudent(int student_id);
	void printAll();
	void resetStArray();

private:
	Student* students;
	int student_count;

};


#endif //STARRAY_H