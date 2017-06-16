#include "Course.h"
#include "EE_Course.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>


//*************************************************************************
//* Function name: EE_Course (constructor)
//* Description: creates a EE_Course ADT according to the given parameters. Uses Course contractor.
//* Parameters: 
//*		courseNum – the number of the course (unique for each course).
//*		courseName – the name of the course.
//*		hwNum – the number of the homework in the course.
//*		hwWeigh – the weight of the homework at the final grade.
//* Return Value: none.
//*************************************************************************

EE_Course::EE_Course(int courseNum, char* courseName,int hwNum, double hwWeigh)
        :Course(courseNum,courseName,hwNum,hwWeigh), factor_(0){}

		
//*************************************************************************
//* Function name:  EE_Course (destructor)
//* Description: deletes all of the courses parameter.
//* Parameters: None.
//* Return Value: None.
//*************************************************************************

EE_Course::~EE_Course(){}


//*************************************************************************
//* Function name:  getFactor
//* Description: returns the factor in the course
//* Parameters: None.
//* Return Value: integer – the factor of the course.
//*************************************************************************

int EE_Course::getFactor() const { return factor_;};


//*************************************************************************
//* Function name:  setFactor
//* Description: changes the factor of the course by the given parameter.  
//* Parameters:
//*		factor– the factor of the course.
//* Return Value: true is succeeded to change and false otherwise
//*************************************************************************

bool EE_Course::setFactor(int factor) {
    if (factor >= -100 && factor <= 100){
		factor_ = factor;
		return true;
    }

    return false;
}

//*************************************************************************
//* Function name:  getCourseGrade
//* Description: compute the course grade by a set formula. 
//* Parameters: None.
//* Return Value: integer – the course final grade.
//*************************************************************************

int EE_Course::getCourseGrade() const {
	int course_grade = (int)((1 - getHwWeigh())*getExamGrade() + getHwWeigh()*getHwAverage() + factor_ + 0.5);
    return course_grade;
}




