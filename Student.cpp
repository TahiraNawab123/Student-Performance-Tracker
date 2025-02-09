#include<iostream>
#include"Student.h"
using namespace std;

// task 2
void setSubjectData(Subject & subject, string subjectName, float marks){
      subject.SubjectName = subjectName;
      subject.marks = marks;
  }

// task 3
void setStudentData(Student& student, string name, int roll, Subject* subjects){
    student.StudentName = name;
    student.rollNumber = roll;
    for (int i = 0; i < 3; ++i) {
        student.subjects[i] = &subjects[i];
    }
}

//task 4
void displayStudentData(const Student& student) {
    cout << "\n\t\tRoll Number: " << student.rollNumber << endl;
    cout << "\n\t\tName: " << student.StudentName << endl;
    cout << "\n\t\t\tSubjects and Marks:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout<<"" << student.subjects[i]->SubjectName << ": " << student.subjects[i]->marks << endl;
    }
}

// task5
float calculateAverageMarks(Student& student) {
    float total = 0;
    for (int i = 0; i < 3; ++i) {
        total += student.subjects[i]->marks;
        }
    return total / 3;
}

//task 6
Student* compareStudents(Student& student1, Student& student2){
    float total1=0, total2=0;
    for(int i=0; i<3;i++){
        total1 += student1.subjects[i]->marks;
        total2 += student2.subjects[i]->marks;
    }
    if(total2 > total1){
        return &student2;
    }else
        return &student1;
}