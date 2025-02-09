#include<iostream>
#include"Student.h"
using namespace std;

int main(){
  Subject subjects1[3];
        setSubjectData( subjects1[0], "\n\t\t\t\tOOP", 90);
        setSubjectData( subjects1[1], "\n\t\t\t\tMaths", 100);
        setSubjectData( subjects1[2], "\n\t\t\t\tPhysics", 87);

  Subject subjects2[3];
       setSubjectData(subjects2[0], "\n\t\t\t\tIslamiyat", 92.0);
       setSubjectData(subjects2[1], "\n\t\t\t\tEnglish", 98.0);
       setSubjectData(subjects2[2], "\n\t\t\t\tChemistry", 82.0);

  Student student1;
       setStudentData(student1, "John Doe", 24064, subjects1);
  Student student2;
       setStudentData(student2, "Jane Doe", 24065, subjects2);
       cout<<"\n\t\t=====================Data of student================== "<<endl;

  displayStudentData(student1);
  displayStudentData(student2);

  cout<<"\n\t\t===================Average Marks======================="<<endl;
       cout<<"\n\t\t\tAverage Marks of Student 1: " << calculateAverageMarks(student1)<<endl;
       cout<<"\n\t\t\tAverage Marks of the student 2: "<<calculateAverageMarks(student2)<<endl;
  Student* topStudent = compareStudents(student1, student2);
  cout << "\n\t\tThe student with higher marks is: " << topStudent->StudentName << endl;


  return 0;
  }
