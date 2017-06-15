#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Student.h"
#include "Proj.h"
#include <math.h>


Student::Student(char *name, int id) :Person(name, id), ee_count_(0), cs_count_(0)
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
    int course_index = 0;
    bool first_index_found = false;
    for (int i = 0; i < MAX_COURSE_NUM; i++)
    {
        if (ee_course_[i] == NULL and !first_index_found)
        {
            course_index = i;
            first_index_found = true;

        }
        if (ee_course_[i] != NULL and ee_course_[i]->getNum() == new_course->getNum()){
            return false;
        }

    }
    if (first_index_found){
        ee_course_[course_index] = new_course;
        ee_count_++;
        return true;
    }

    return false; //error
}

bool Student::addCS_Course(CS_Course* new_course) 
{
    int course_index = 0;
    bool first_index_found = false;
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (cs_course_[i] == NULL and !first_index_found)
		{
            course_index = i;
            first_index_found = true;

		}
        if (cs_course_[i] != NULL and cs_course_[i]->getNum() == new_course->getNum()){
            return false;
        }

	}
    if (first_index_found){
        cs_course_[course_index] = new_course;
        cs_count_++;
        return true;
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
	if (count == 0){
		return 0;
	}
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


	int avg = (int) round(((sum / count)));
	return avg;

}
void Student::print() const
{
	printf("Student Name: %s\n", getName());
	printf("Student ID: %d\n", getID());
	int avg = getAvg();
	printf("Average Grade: %d\n", avg);
	printf("\n");
	printf("EE Courses:\n");
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (ee_course_[i] != NULL)
			ee_course_[i]->printCourse();
	}
	printf("\n");
	printf("CS Courses:\n");
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (cs_course_[i] != NULL)
			cs_course_[i]->printCourse();
	}
	printf("\n");
}

