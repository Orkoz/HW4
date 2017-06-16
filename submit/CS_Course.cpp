#include "Course.h"
#include "CS_Course.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>


//*************************************************************************
//* Function name: CS_Course (constructor)
//* Description: creates a CS_Course ADT according to the given parameters. Uses Course contractor.
//* Parameters: 
//*		courseNum – the number of the course (unique for each course).
//*		courseName – the name of the course.
//*		hwNum – the number of the homework in the course.
//*		hwWeigh – the weight of the homework at the final grade.
//*		takef– a flag which indicate if the homeworks are takef.
//*		bookName– the book of the course.
//* Return Value: none.
//*************************************************************************

CS_Course::CS_Course(int courseNum, char *courseName, int hwNum, double hwWeigh, bool takef,
                     char *bookName): Course(courseNum,courseName,hwNum,hwWeigh), takef_(takef)
{
	bookName_ = new char[strlen(bookName) + 1];
	strcpy(bookName_, bookName);
}


//*************************************************************************
//* Function name:  CS_Course (destructor)
//* Description: deletes all of the courses parameters (the array).
//* Parameters: None.
//* Return Value: None.
//*************************************************************************

CS_Course::~CS_Course()
{
	delete[] bookName_;
}


//*************************************************************************
//* Function name:  isTakef
//* Description: returns if the homework in the course are takef or not.
//* Parameters: None.
//* Return Value: true if they are and false otherwise.
//*************************************************************************

bool CS_Course::isTakef() const {return takef_;}


//*************************************************************************
//* Function name:  getBook
//* Description: returns the name of the course book (a copy string).
//* Parameters: None.
//* Return Value: char pointer – the name of the book.
//*************************************************************************

char* CS_Course::getBook() const {
    char* course_book = new char[strlen(bookName_)+1];
    strcpy(course_book,bookName_);
    return course_book;
}


//*************************************************************************
//* Function name:  setTakef
//* Description: changes the takef flag of the course by the given parameter.  
//* Parameters:
//*		flag– the takef flag of the course.
//* Return Value: true is succeeded to change and false otherwise
//*************************************************************************

bool CS_Course::setTakef(bool flag) {
    takef_=flag;
    return true;
}


//*************************************************************************
//* Function name:  setBook
//* Description: changes the course book of the course by the given parameter.  
//* Parameters:
//*		book_name– a string of the course book name.
//* Return Value: None.
//*************************************************************************

void CS_Course::setBook(char *book_name) {
    delete [] bookName_;
    bookName_ = new char[strlen(book_name)+1];
    strcpy(bookName_,book_name);
}


//*************************************************************************
//* Function name:  getCourseGrade
//* Description: compute the course grade by a set formula . 
//* Parameters: None.
//* Return Value: integer – the course final grade.
//*************************************************************************

 int CS_Course::getCourseGrade() const{
    if (takef_){
		return (int)(((1 - getHwWeigh())*getExamGrade() + getHwWeigh()*getHwAverage())+0.5);
    }

	int course_grade1 = (int)(((1 - getHwWeigh())*getExamGrade() + getHwWeigh()*getHwAverage())+0.5);
    int course_grade2= getExamGrade();

    return (course_grade1>course_grade2 ? course_grade1:course_grade2);
}




