#include "Course.h"
#include "EE_Course.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>


EE_Course::EE_Course(int courseNum, char* courseName,int hwNum, double hwWeigh)
        :Course(courseNum,courseName,hwNum,hwWeigh), factor_(0){};

int EE_Course::getFactor() const { return factor_;};

bool EE_Course::setFactor(int factor) {
    if (factor >= -100 && factor <= 100){
		factor_ = factor;
		return true;
    }

    return false;
}

int EE_Course::getCourseGrade() const {
    //int course_grade = (int)(round((1-getHwWeigh())*getExamGrade() + getHwWeigh()*getHwAverage()) + factor_);
	int course_grade = (int)((1 - getHwWeigh())*getExamGrade() + getHwWeigh()*getHwAverage() + factor_ + 0.5);
    return course_grade;
}




