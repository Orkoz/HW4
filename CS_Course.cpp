#include "Course.h"
#include "CS_Course.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
//#include <ntdef.h>

CS_Course::CS_Course(int courseNum, char *courseName, int hwNum, double hwWeigh, bool takef,
                     char *bookName): Course(courseNum,courseName,hwNum,hwWeigh), takef_(takef)
{
	bookName_ = new char[strlen(bookName) + 1];
	strcpy(bookName_, bookName);
}

CS_Course::~CS_Course()
{
	delete[] bookName_;
}

bool CS_Course::isTakef() const {return takef_;}

char* CS_Course::getBook() const {
    char* course_book = new char[strlen(bookName_)+1];
    strcpy(course_book,bookName_);
    return course_book;
}

bool CS_Course::setTakef(bool flag) {
    takef_=flag;
    return true;
}

void CS_Course::setBook(char *book_name) {
    delete [] bookName_;
    bookName_ = new char[strlen(book_name)+1];
    strcpy(bookName_,book_name);
}

 int CS_Course::getCourseGrade() const{
    if (takef_){
        //return int(round((1-getHwWeigh())*getExamGrade() + getHwWeigh()*getHwAverage()));
		return (int)(((1 - getHwWeigh())*getExamGrade() + getHwWeigh()*getHwAverage())+0.5);
    }

    //int course_grade1 = (int)(round((1-getHwWeigh())*getExamGrade() + getHwWeigh()*getHwAverage()));
	int course_grade1 = (int)(((1 - getHwWeigh())*getExamGrade() + getHwWeigh()*getHwAverage())+0.5);
    int course_grade2= getExamGrade();

    return (course_grade1>course_grade2 ? course_grade1:course_grade2);
}




