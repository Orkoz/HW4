#ifndef HW4_COURSE_H
#define HW4_COURSE_H
class Course{

public:
    Course(int num, char* name,int num_of_hw, double hw_wight);
    ~Course();
    int getNum() const;
    char* getName() const;
    int getExamGrade() const;
    int getHwGrade(int hw_num) const;
    int getHwNum() const;
    double getHwWeigh() const;
    double getHwWeigh() const;
    int getCourseGrade() const;
    bool setExamGrade(int exam_grade);
    bool setHwGrade(int hw_num, int hw_grade);

private:
    int num_;
    char* name_;
    int num_of_hw_;
    double hw_wight_;
    int test_grade_;
    int* hw_grade_;
};
#endif //HW4_COURSE_H
