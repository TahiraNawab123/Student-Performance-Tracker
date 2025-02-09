#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
using namespace std;

struct Subject{
  string SubjectName;
  float marks;
  };

struct Student{
  int rollNumber;
  string StudentName;
  Subject * subjects[3];
  };

void setSubjectData(Subject & subject, string subjectName, float marks);
void setStudentData(Student& student, string name, int roll, Subject* subjects);
void displayStudentData(const Student& student);
float calculateAverageMarks(Student& student);
Student* compareStudents(Student& student1, Student& student2);
#endif //STUDENT_H
