#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "StArray.h"
#include "Proj.h"
#include "Student.h"
#include "Person.h"
#include "Course.h"
#include "CS_Course.h"
#include "EE_Course.h"

//*************************************************************************
//* Function name: StArray (constructor)
//* Description: creates a the students_ array to hold pointers to every
//*              student.
//* Parameters:
//* Return Value: none.
//*************************************************************************

StArray::StArray():student_count_(0)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		students_[i] = NULL;
	}
}

//*************************************************************************
//* Function name: ~StArray (destructor)
//* Description: calls the destructor for every student in the array.
//* Parameters:
//* Return Value: none.
//*************************************************************************

StArray::~StArray()
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (students_[i] != NULL)
		{
			delete students_[i];
		}
	}
}

//*************************************************************************
//* Function name: addStudent
//* Description: creates a new student ADT and adds it to students array.
//* Parameters:
//*              int id - passes id to student constructor
//*              char * name - passes name to student constructor
//* Return Value: true if succeeds or false if not.
//*************************************************************************

bool StArray::addStudent(int id, char * name)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (students_[i] == NULL)
		{
			students_[i] = new Student(name, id);
			student_count_++;
			return true;
		}
	}
	
	return false;
}

//*************************************************************************
//* Function name: addEE_Course
//* Description: creates a new EE course ADT, and adds it to student.
//* Parameters:
//*              int student_id - id of student to add course to
//*              int course_id - id of course
//*              char * course_name - course name string
//*              int hm_count - how many homework assigments in the course
//*              double hm_weight - weight of HM from total grade.
//* Return Value: true if succeeds or false if not.
//*************************************************************************

bool StArray::addEE_Course(int student_id, int course_id, char * course_name, int hm_count, double hm_weight)
{
	// not sure if we need to chk if id's already exists
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (students_[i] != NULL && students_[i]->getID() == student_id)
		{
			char* name_copy = new char[strlen(course_name) + 1];
			strcpy(name_copy, course_name);

			EE_Course* new_course = new EE_Course(course_id, name_copy, hm_count, hm_weight);
			
			delete name_copy;

			return students_[i]->addEE_Course(new_course);
		}
	}
	return false;
}

//*************************************************************************
//* Function name: addCS_Course
//* Description: creates a new CS course ADT, and adds it to student.
//* Parameters:
//*              int student_id - id of student to add course to
//*              int course_id - id of course
//*              char * course_name - course name string
//*              int hm_count - how many homework assigments in the course
//*              double hm_weight - weight of HM from total grade.
//*              bool takef - false if hw are not takef and true otherwise
//*              char * book - book of the course name string
//* Return Value: true if succeeds or false if not.
//*************************************************************************

bool StArray::addCS_Course(int student_id, int course_id, char * course_name, int hm_count, double hm_weight, bool takef, char * book)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (students_[i] != NULL && students_[i]->getID() == student_id)
		{
			char* name_copy = new char[strlen(course_name) + 1];
			strcpy(name_copy, course_name);

			char* book_copy = new char[strlen(book) + 1];
			strcpy(book_copy, book);

			CS_Course* new_course = new CS_Course(course_id, name_copy, hm_count, hm_weight, takef, book_copy);

			delete name_copy;
			delete book_copy;

			return students_[i]->addCS_Course(new_course);
		}
	}
	return false;
}

//*************************************************************************
//* Function name: setHwGrade
//* Description: sets a specific grade for an homework assignment.
//* Parameters:
//*              int student_id - id of student to add course to
//*              int course_id - id of course
//*              int hm_id - id of the homework assignment
//*              int hm_grade - grade of specific assignment
//* Return Value: true if succeeds or false if not.
//*************************************************************************

bool StArray::setHwGrade(int student_id, int course_id, int hm_id, int hm_grade)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (students_[i] != NULL && students_[i]->getID() == student_id)
		{
			EE_Course* ee_course = students_[i]->getEE_Course(course_id);
			CS_Course* cs_course = students_[i]->getCS_Course(course_id);
			if (ee_course != NULL)
			{
				return ee_course->setHwGrade(hm_id, hm_grade);
			} else if (cs_course != NULL)
			{
				return cs_course->setHwGrade(hm_id, hm_grade);
			}
		}
	}
	return false;
}

//*************************************************************************
//* Function name: setExamGrade
//* Description: sets a specific grade for a test.
//* Parameters:
//*              int student_id - id of student to add course to
//*              int course_id - id of course
//*              int grade- grade of test
//* Return Value: true if succeeds or false if not.
//*************************************************************************

bool StArray::setExamGrade(int student_id, int course_id, int grade)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (students_[i] != NULL && students_[i]->getID() == student_id)
		{
			EE_Course* ee_course = students_[i]->getEE_Course(course_id);
			CS_Course* cs_course = students_[i]->getCS_Course(course_id);
			if (ee_course != NULL)
			{
				return ee_course->setExamGrade(grade);
			}
			else if (cs_course != NULL)
			{
				return cs_course->setExamGrade(grade);
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}

//*************************************************************************
//* Function name: setFactor
//* Description: sets a Factor to EE course for all students that took course
//* Parameters:
//*              int course_id - id of course
//*              int factor - factor of test
//* Return Value: true if succeeds or false if not EE course, or not found.
//*************************************************************************

bool StArray::setFactor(int course_id, int factor)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (students_[i] != NULL)
		{
			EE_Course* ee_course = students_[i]->getEE_Course(course_id);
			if (ee_course != NULL)
			{
				if (!(ee_course->setFactor(factor)))
					return false;
			}
		}
	}
	return true;
}

//*************************************************************************
//* Function name: printStudent
//* Description: prints the data of a students using the print from class student
//* Parameters:
//*              int student_id - id of student
//* Return Value: true if succeeds or false if cant find student.
//*************************************************************************

bool StArray::printStudent(int student_id) const
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (students_[i] != NULL && students_[i]->getID() == student_id)
		{
			students_[i]->print();
			return true;
		}
	}
	return false;
}

//*************************************************************************
//* Function name: printAll
//* Description: goes through all students and prints them using print from
//*              class student.
//* Parameters:
//* Return Value: none.
//*************************************************************************

void StArray::printAll() const
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (students_[i] != NULL)
		{
			students_[i]->print();
		}
	}
}

//*************************************************************************
//* Function name: resetStArray
//* Description: goes through all students and removes them from memory.
//* Parameters:
//* Return Value: none.
//*************************************************************************

void StArray::resetStArray()
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (students_[i] != NULL)
		{
			delete students_[i];
			student_count_--;
			students_[i] = NULL;
		}
	}
}
