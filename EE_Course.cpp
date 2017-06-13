#include "Course.h"
#include "EE_Course.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cmath>


EE_Course::EE_Course(int stID, int courseNum, char* courseName,int hwNum, double hwWeigh)
        :Course(courseNum,courseName,hwNum,hwWeigh), factor_(0){};

int EE_Course::getFactor() const { return factor_;};

bool EE_Course::setFactor(int factor) {
    if (factor.fail()){
        return false;
    }

    factor_=factor;
    return true;
}

int EE_Course::getCourseGrade() const {
    int course_grade = round((1-hw_weigh)*exam_grade + hw_weigh*hw_average) + factor;
    return (course_grade>100 ? 100:course_grade);
}




