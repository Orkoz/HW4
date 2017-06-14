#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Student.h"
#include "Proj.h"


Student::Student(char *name, int id) :ee_count_(0), cs_count_(0), Person(name, id)
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



bool Student::addEE_Course(EE_Course* new_course)
{
	
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (ee_course_[i] == NULL)
		{
			ee_course_[i] = new_course;
			ee_count_++;
			return true;
		}
	}

	return false; //error
}

bool Student::addCS_Course(CS_Course* new_course) 
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (cs_course_[i] == NULL)
		{
			cs_course_[i] = new_course;
			cs_count_++;
			return true;
		}
	}
	return false; //error
}

bool Student::remCourse(int course_num)
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (ee_course_[i] != NULL && ee_course_[i]->getNum() == course_num)
		{
			delete ee_course_[i];
			ee_course_[i] = NULL;
			ee_count_--;
			return true;
		}
		else if (cs_course_[i] != NULL && cs_course_[i]->getNum() == course_num)
		{
			delete cs_course_[i];
			cs_course_[i] = NULL;
			cs_count_--;
			return true;
		}
	}
	return false;
}

EE_Course* Student::getEE_Course(int course_num)
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (ee_course_[i] != NULL && ee_course_[i]->getNum() == course_num)
		{
			return ee_course_[i];
		}
	}
	return NULL;
}

CS_Course* Student::getCS_Course(int course_num)
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (cs_course_[i] != NULL && cs_course_[i]->getNum() == course_num)
		{
			return cs_course_[i];
		}
	}
	return NULL;
}

int Student::getAvg() const
{
	int count = getCourseCnt();
	int sum = 0;

	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (ee_course_[i] != NULL)
		{
			sum = sum + ee_course_[i]->getExamGrade();
		}

		if (cs_course_[i] != NULL)
		{
			sum = sum + cs_course_[i]->getExamGrade();
		}
	}

	int avg = (int)((sum / count) + 0.5);
	return avg;

}
void Student::print() const
{
	printf("Student Name: %s/n", name_);
	printf("Student ID: %d/n", id_);
	int avg = getAvg();
	printf("Average Grade: %d/n", avg);
	printf("/n");
	printf("EE Courses:/n");
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (ee_course_[i] != NULL)
			ee_course_[i]->printCourse();
	}
	printf("/n");
	printf("CS Courses:/n");
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (cs_course_[i] != NULL)
			cs_course_[i]->printCourse();
	}
	printf("/n");
}
