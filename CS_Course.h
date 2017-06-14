#ifndef HW4_CS_COURSE_H
#define HW4_CS_COURSE_H
#include "Course.h"

class  CS_Course: public Course{
public:
    CS_Course(int courseNum, char* courseName, int hwNum, double  hwWeigh, bool takef, char* bookName);
    bool isTakef() const;
    char* getBook() const;
    bool setTakef(bool flag);
    void setBook(char* book_name);
    int getCourseGrade() const;

private:
    bool takef_;
    char* bookName_;

};
#endif //HW4_CS_COURSE_H
