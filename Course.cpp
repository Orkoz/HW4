#include "Course.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cmath>

Course::Course(int courseNum, char* courseName,int hwNum, double hwWeigh):
        courseNum_(courseNum), hwNum_(hwNum), hwWeigh_(hwWeigh),hwSum_(0){
    courseName_ = new char[strlen(name)+1];
    strcpy(courseName_,courseName);
    hwGrade_ = new int[hwNum_];
    for (int i = 0; i < courseName_; ++i) {
        hwGrade_[i] = -1;
    }
}

Course::~Course() {
    delete [] courseName_;
    delete  [] hwGrade_;
}

int Course::getNum() const {return courseNum_; }

char* Course::getName() const {
    name = new char[strlen(courseName_)+1];
    strcpy(name,courseName_);
    return name;
}

int Course::getExamGrade() const { return  examGrade_};

int Course::getHwGrade(int hwNum_) const {
    return (hwGrade_[hwNum_]>=0 ? hwGrade_[hwNum_]:-1);
}

int Course::getHwNum() const {return  courseName_;};

double Course::getHwWeigh() const {return  hwWeigh_;};

double Course::getHwAverage() const {return double(hwSum_/courseName_);}

int Course::getCourseGrade() const {
    return round((1 - getHwWeigh()) * getExamGrade() + getHwWeigh() * (getHwAverage()));
}

bool Course::setExamGrade(int exam_grade) {
    if ((exam_grade >=0) && (exam_grade<=100)){
        examGrade_ = exam_grade;
        return true;
    }
        return false;
}

bool Course::setHwGrade(int hwNum_, int hw_grade) {
    if ((hwNum_>=0 && hwNum_<=courseName_) && ((hw_grade >=0) && (hw_grade<=100))){
        hwGrade_[hwNum_] = hw_grade;
        hwSum_ = hwSum_ + hw_grade;
        return true;
    }

    return false;
}


int courseNum_;
char* courseName_;
int courseName_;
int hwNum_;
double hwWeigh_;
int examGrade_;
int* hwrade_;
int hwSum_;


