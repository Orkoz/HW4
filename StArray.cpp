#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "StArray.h"
#include "Proj.h"
#include "Student.h"

StArray::StArray():student_count_(0)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		students_[i] = NULL;
	}
}

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

bool StArray::addStudent(int id, char * name)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (students_[i] == NULL)
		{
			students_[i] = new Student(char *name, int id);
			student_count_++;
			return true;
		}
	}
	
	return false;
}

bool StArray::addEE_Course(int student_id, int course_id, char * course_name, int hm_count, double hm_weight)
{
	// not sure if we need to chk if id's already exists
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (students_[i].getId() == student_id)
		{
			char* name_copy = new char[strlen(course_name) + 1];
			strcpy(name_copy, course_name);

			EE_Course* new_course = new EE_Course(course_id, name_copy, hm_count, hm_weight);
			
			delete name_copy;

			return students_[i].addEE_Course(new_course);
		}
	}
	return false;
}

bool StArray::addCS_Course(int student_id, int course_id, char * course_name, int hm_count, double hm_weight, bool takef, char * book)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if (students_[i].getId() == student_id)
		{
			char* name_copy = new char[strlen(course_name) + 1];
			strcpy(name_copy, course_name);

			char* book_copy = new char[strlen(book) + 1];
			strcpy(book_copy, book);

			CS_Course* new_course = new CS_Course(course_id, name_copy, hm_count, hm_weight, takef, book_copy);

			delete name_copy;
			delete book_copy;

			return students_[i].addCS_Course(new_course);
		}
	}
	return false;
}
