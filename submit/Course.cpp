#include "Course.h"
#include "Proj.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>


//*************************************************************************
//* Function name: Course (constructor)
//* Description: creates a Course ADT according to the given parameters.
//* Parameters: 
//*		courseNum – the number of the course (unique for each course).
//*		courseName – the name of the course.
//*		hwNum – the number of the homeworks in the course.
//*		hwWeigh – the weight of the homework at the final grade.
//* Return Value: none.
//*************************************************************************

Course::Course(int courseNum, char* courseName,int hwNum, double hwWeigh):
        courseNum_(courseNum), hwNum_(hwNum), hwWeigh_(hwWeigh),hwSum_(0), examGrade_(0){
    courseName_ = new char[strlen(courseName)+1];
    strcpy(courseName_,courseName);
    hwGrade_ = new int[hwNum];
    for (int i = 0; i < hwNum; i++) {
        hwGrade_[i] = 0;
    }
}


//*************************************************************************
//* Function name:  Course (destructor)
//* Description: deletes all of the courses parameters (the arrays).
//* Parameters: None.
//* Return Value: none.
//*************************************************************************

Course::~Course() {
    delete[] courseName_;
    delete[] hwGrade_;
}


//*************************************************************************
//* Function name:  getNum
//* Description: returns the number of the course.
//* Parameters: None.
//* Return Value: integer - the number of the course.
//*************************************************************************

int Course::getNum() const {return courseNum_; }


//*************************************************************************
//* Function name:  getName
//* Description: returns a copy string of the name of the course.
//* Parameters: None.
//* Return Value: char pointer – the name of the course.
//*************************************************************************

char* Course::getName() const {
    char* name = new char[strlen(courseName_)+1];
    strcpy(name,courseName_);
    return name;
}


//*************************************************************************
//* Function name:  getExamGrade
//* Description: returns the exam grade of the course.
//* Parameters: None.
//* Return Value: integer - the exam grade of the course.
//*************************************************************************

int Course::getExamGrade() const { return  examGrade_;}


//*************************************************************************
//* Function name:  getHwGrade
//* Description: returns the homework grade of the given homework number.
//* Parameters:
//*		hwNum – the number of the homework.
//* Return Value: integer - the homework grade.
//*************************************************************************

int Course::getHwGrade(int hwNum) const {return hwGrade_[hwNum];}


//*************************************************************************
//* Function name:  getHwNum
//* Description: returns the number of homeworks in the course.
//* Parameters: None.
//* Return Value: integer - the number of homeworks in the course.
//*************************************************************************

int Course::getHwNum() const {return hwNum_;};


//*************************************************************************
//* Function name:  getHwWeigh
//* Description: returns the homeworks weight in the course.
//* Parameters: None.
//* Return Value: integer - the homeworks weight in the course.
//*************************************************************************

double Course::getHwWeigh() const {return  hwWeigh_;};


//*************************************************************************
//* Function name:  getHwAverage
//* Description: returns the average grade of the homeworks in the course.
//* Parameters: None.
//* Return Value: double - the average grade of the homeworks in the course.
//*************************************************************************

double Course::getHwAverage() const {
    if (hwNum_==0){
        return 0;
    }
    return double(hwSum_)/(double)hwNum_;
}


//*************************************************************************
//* Function name:  getCourseGrade
//* Description: compute the course grade by a set formula  
//* Parameters: None.
//* Return Value: integer – the course final grade.
//*************************************************************************

int Course::getCourseGrade() const {
	return (int)((1 - getHwWeigh()) * (double) getExamGrade() + getHwWeigh() * getHwAverage() + 0.5);
}


//*************************************************************************
//* Function name:  printCourse
//* Description: prints to the screen the course details.  
//* Parameters: None.
//* Return Value: None.
//*************************************************************************

void Course::printCourse() const
{
	int grade = getCourseGrade(); 
	printf("%d %s: %d\n", courseNum_, courseName_, grade);
}


//*************************************************************************
//* Function name:  setExamGrade
//* Description: changes the exam grade of the course by the given parameter.  
//* Parameters:
//*		exam_grade – the new exam grade.
//* Return Value: true is succeeded to change and false otherwise
//*************************************************************************

bool Course::setExamGrade(int exam_grade) {
    if ((exam_grade >=0) && (exam_grade<=100)){
        examGrade_ = exam_grade;
        return true;
    }
        return false;
}



//*************************************************************************
//* Function name:  setHwGrade
//* Description: changes the homework grade by the given parameter and updates the homworks sum accordingly 
//* Parameters:
//*		hw_grade– the grade of the homework.
//*		hwNum – the number of the homework.
//* Return Value: true is succeeded to change and false otherwise
//*************************************************************************

bool Course::setHwGrade(int hwNum, int hw_grade) {
    if ((hwNum>=0 && hwNum<=hwNum_) && ((hw_grade >=0) && (hw_grade<=100))){
		hwSum_ = hwSum_ - hwGrade_[hwNum];
		hwGrade_[hwNum] = hw_grade;
        hwSum_ = hwSum_ + hw_grade;
        return true;
    }

    return false;
}