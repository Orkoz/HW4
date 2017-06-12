#include "Course.h"
#include <string.h>

Course::Course( int num,  char *name,  int num_of_hw, double hw_wight):
        num_(num), num_of_hw_(num_of_hw), hw_wight_(hw_wight),hw_sum_(0){
    name_ = new char[strlen(name)+1];
    strcpy(name_,name);
    hw_grade_ = new int[num_of_hw_];
    for (int i = 0; i < num_of_hw_; ++i) {
        hw_grade_[i] = -1;
    }
}

Course::~Course() {
    delete [] name_;
    delete  [] hw_grade_;
}

int Course::getNum() const {return num_; }

char* Course::getName() const {
    name = new char[strlen(name_)+1];
    strcpy(name,name_);
    return name;
}

int Course::getExamGrade() const { return  test_grade_};

int Course::getHwGrade(int hw_num) const {
    return (hw_grade_[hw_num]>=0 ? hw_grade_[hw_num]:-1);
}

int Course::getHwNum() const { return  num_of_hw_};

double Course::getHwWeigh() const { return  hw_wight_};

double Course::getHwAverage() const {return double(hw_sum_/num_of_hw_); }


