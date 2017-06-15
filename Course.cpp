#include "Course.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

Course::Course(int courseNum, char* courseName,int hwNum, double hwWeigh):
        courseNum_(courseNum), hwNum_(hwNum), hwWeigh_(hwWeigh),hwSum_(0), examGrade_(0){
    courseName_ = new char[strlen(courseName)+1];
    strcpy(courseName_,courseName);
    hwGrade_ = new int[hwNum_];
    for (int i = 0; i < hwNum_; i++) {
        hwGrade_[i] = 0;
    }
}

Course::~Course() {
    delete [] courseName_;
    delete  [] hwGrade_;
}

int Course::getNum() const {return courseNum_; }

char* Course::getName() const {
    char* name = new char[strlen(courseName_)+1];
    strcpy(name,courseName_);
    return name;
}

int Course::getExamGrade() const { return  examGrade_;}

int Course::getHwGrade(int hwNum) const {
    return (hwGrade_[hwNum]>=0 ? hwGrade_[hwNum]:-1);
}

int Course::getHwNum() const {return hwNum_;};

double Course::getHwWeigh() const {return  hwWeigh_;};

double Course::getHwAverage() const {
    if (hwNum_==0){
        return 0;
    }
    return double(hwSum_/hwNum_);
}

int Course::getCourseGrade() const {
    //return (int)round((1 - getHwWeigh()) * getExamGrade() + getHwWeigh() * getHwAverage());
	return (int)((1 - getHwWeigh()) * getExamGrade() + getHwWeigh() * getHwAverage() + 0.5);
}

void Course::printCourse() const
{
	int grade = getCourseGrade();
	printf("%d %s: %d\n", courseNum_, courseName_, grade);
}

bool Course::setExamGrade(int exam_grade) {
    if ((exam_grade >=0) && (exam_grade<=100)){
        examGrade_ = exam_grade;
        return true;
    }
        return false;
}

bool Course::setHwGrade(int hwNum, int hw_grade) {
    if ((hwNum>=0 && hwNum<=hwNum_) && ((hw_grade >=0) && (hw_grade<=100))){
        //hwSum_ = hwSum_ - hwGrade_[hwNum_]; // What is this line?
        hwGrade_[hwNum_] = hw_grade; // unclear whats going on
        hwSum_ = hwSum_ + hw_grade;
        return true;
    }

    return false;
}