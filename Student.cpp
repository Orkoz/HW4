#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Student.h"
#include "Proj.h"


Student::Student() :ee_count_(0), cs_count_(0)
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		ee_course_[i] = NULL;
		cs_course_[i] = NULL;
	}
}

// We need to define and create the array for ee_course_ and cs_course_

Student::~Student()
{
	// deleting courses
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (ee_course_[i] != NULL)
		{
			delete ee_course_[i];
			ee_course_[i] = NULL;
		}
		if (cs_course_[i] != NULL)
		{
			delete cs_course_[i];
			cs_course_[i] = NULL;
		}
	}
}

int Student::getCourseCnt() const
{
	return (ee_count_ + cs_count_);
}


// needs to be changed to enter course in first free space!!!!
//
//
//

bool Student::addEE_Course(EE_Course* new_course)
{
	if (ee_course_[ee_count_] == NULL)
	{
		ee_course_[ee_count_] = new_course;
		ee_count_++;
		return true;
	}
	else
	{
		return false; //error
	}
}

bool Student::addCS_Course(CS_Course* new_course) 
{
	if (cs_course_[cs_count_] == NULL)
	{
		cs_course_[cs_count_] = new_course;
		cs_count_++;
		return true;
	}
	else
	{
		return false; //error
	}
}

bool Student::remCourse(int course_num)
{
	void* course_to_remove = NULL;
	course_to_remove = getEE_Course(course_num); // not sure this is how to write
	if (course_to_remove == NULL)
		course_to_remove = getCS_Course(course_num);
	if (course_to_remove == NULL)
		return false;
	// needs to be changed so it is easy to decide which one to delete!
	// and which counter to change
	// maybe easier to divide to two functions
	// or two if's
	

}

EE_Course* Student::getEE_Course(int course_num)
{

}

CS_Course* Student::getCS_Course(int course_num)
{

}
int Student::getAvg() const
{

}
void Student::print() const
{

}

