#ifndef HW4_COURSE_H
#define HW4_COURSE_H
class Course{

public:
    // Constructor
    Course( int num,  char* name, int num_of_hw, double hw_wight);
    ~Course();

    // Methods to access data
    int getNum() const;
    char* getName() const;
    int getExamGrade() const;
    int getHwGrade(int hw_num) const;
    int getHwNum() const;
    double getHwWeigh() const;
    double getHwAverage() const;
    int getCourseGrade() const;

	void printCourse() const;

    // Methods to change data
    bool setExamGrade(int exam_grade);
    bool setHwGrade(int hw_num, int hw_grade);

private:
    int courseNum_;
    char* courseName_;
    int hwNum_;
    double hwWeigh_;
    int examGrade_;
    int* hwGrade_;
    int hwSum_;
};
#endif //HW4_COURSE_H