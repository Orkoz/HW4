#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Student.h"

Student::Student() :ee_count_(0), cs_count_(0)
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		ee_course_[i] = NULL;
		cs_course_[i] = NULL;
	}
}
// We need to define and create the array for ee_course_ and cs_course_
