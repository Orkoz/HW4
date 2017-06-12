#ifndef HW4_CS_COURSE_H
#define HW4_CS_COURSE_H
#include "Course.h"

class  CS_Course: public Course{
public:
    CS_Course(bool hw_takef_flag, char* course_book);
    ~CS_Course();
    bool isTakef() const;
    int getBook() const;
    bool setTakef(bool flag);
    void setBook(char* book_name);
    int getCourseGrade() const;

private:

    bool hw_takef_flag_;
    char* course_book_;

};
#endif //HW4_CS_COURSE_H
