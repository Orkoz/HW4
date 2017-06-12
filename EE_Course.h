#ifndef HW4_EE_COURSE_H
#define HW4_EE_COURSE_H

#include "Course.h"

class EE_Course: public Course{

public:
    EE_Course(int factor);
    ~EE_Course();
    int getFactor() const;
    bool setFactor(int factor);
    int getCourseGrade() const;

private:
    int factor_;
};
#endif //HW4_EE_COURSE_H
