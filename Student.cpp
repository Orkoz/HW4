#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Student.h"
#include "Proj.h"
#include <math.h>

//*************************************************************************
//* Function name: Student (constructor)
//* Description: creates a Student ADT according to the given parameters
//*              and sends them to person constructor. Creates arrays
//*              for CS and EE courses.
//* Parameters:
//* Return Value: none.
//*************************************************************************

Student::Student(char *name, int id) :Person(name, id), ee_count_(0), cs_count_(0)
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		ee_course_[i] = NULL;
		cs_course_[i] = NULL;
	}
}

//*************************************************************************
//* Function name: Student (destructor)
//* Description: deletes all of the courses one by one.
//* Parameters:
//* Return Value: none.
//*************************************************************************

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

//*************************************************************************
//* Function name: getCourseCnt
//* Description: returns the total amount of courses
//* Parameters:
//* Return Value: int with total amount of courses.
//*************************************************************************

int Student::getCourseCnt() const
{
	return (ee_count_ + cs_count_);
}

//*************************************************************************
//* Function name: addEE_Course
//* Description: gets a new_course pointing to EE course and adds it to the
//*              first free place in the array.
//* Parameters:
//*              EE_Course* new_course - pointer to new course.
//* Return Value: true if succeeds, false if not.
//*************************************************************************

bool Student::addEE_Course(EE_Course* new_course)
{
    int course_index = 0;
    bool first_index_found = false;
    for (int i = 0; i < MAX_COURSE_NUM; i++)
    {
        if (ee_course_[i] == NULL && !first_index_found)
        {
            course_index = i;
            first_index_found = true;

        }
        if (ee_course_[i] != NULL && ee_course_[i]->getNum() == new_course->getNum()){
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

//*************************************************************************
//* Function name: addCS_Course
//* Description: gets a new_course pointing to CS course and adds it to the
//*              first free place in the array.
//* Parameters:
//*              EE_Course* new_course - pointer to new course.
//* Return Value: true if succeeds, false if not.
//*************************************************************************

bool Student::addCS_Course(CS_Course* new_course) 
{
    int course_index = 0;
    bool first_index_found = false;
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (cs_course_[i] == NULL && !first_index_found)
		{
            course_index = i;
            first_index_found = true;

		}
        if (cs_course_[i] != NULL && cs_course_[i]->getNum() == new_course->getNum()){
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

//*************************************************************************
//* Function name: remCourse
//* Description: searches for the course_num and deletes it from the array
//* Parameters:
//*             int course_num - course id to delete.
//* Return Value: true if succeeds, false if not.
//*************************************************************************

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

//*************************************************************************
//* Function name: getEE_Course
//* Description: searches for the course_num and returns a pointer to it, 
//*              only if it is a EE course.
//* Parameters:
//*             int course_num - course id to delete.
//* Return Value: pointer to course
//*************************************************************************

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

//*************************************************************************
//* Function name: getCS_Course
//* Description: searches for the course_num and returns a pointer to it, 
//*              only if it is a CS course.
//* Parameters:
//*             int course_num - course id to delete.
//* Return Value: pointer to course
//*************************************************************************

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

//*************************************************************************
//* Function name: getAvg
//* Description: calculates the average of a students and returns it.
//* Parameters:
//* Return Value: avg as an int.
//*************************************************************************

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
			sum = sum + ee_course_[i]->getCourseGrade();
		}

		if (cs_course_[i] != NULL)
		{
			sum = sum + cs_course_[i]->getCourseGrade();
		}
	}


	int avg = (int) (((double) sum / (double) count)+0.5);
	return avg;

}
//*************************************************************************
//* Function name: print
//* Description: prints the student info.
//* Parameters:
//* Return Value: none.
//*************************************************************************

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

