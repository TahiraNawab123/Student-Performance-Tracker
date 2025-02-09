#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Student.h"

TEST_CASE("Initialization of Subject") {
    Subject subject;
    setSubjectData(subject, "Mathematics", 85.5);
    
    REQUIRE(subject.SubjectName == "Mathematics");
    REQUIRE(subject.marks == 85.5);
}

TEST_CASE("Initialization of Student") {
    Subject subjects[3];
    setSubjectData(subjects[0], "Mathematics", 85.5);
    setSubjectData(subjects[1], "Science", 90.0);
    setSubjectData(subjects[2], "English", 80.0);
    
    Student student;
    setStudentData(student, "John Doe", 101, subjects);
    
    REQUIRE(student.StudentName == "John Doe");
    REQUIRE(student.rollNumber == 101);
    REQUIRE(student.subjects[0]->SubjectName == "Mathematics");
    REQUIRE(student.subjects[0]->marks == 85.5);
    REQUIRE(student.subjects[1]->SubjectName == "Science");
    REQUIRE(student.subjects[1]->marks == 90.0);
    REQUIRE(student.subjects[2]->SubjectName == "English");
    REQUIRE(student.subjects[2]->marks == 80.0);
}

TEST_CASE("Calculate Average Marks") {
    Subject subjects[3];
    setSubjectData(subjects[0], "Mathematics", 85.5);
    setSubjectData(subjects[1], "Science", 90.0);
    setSubjectData(subjects[2], "English", 80.0);

    Student student;
    setStudentData(student, "John Doe", 101, subjects);

    float average = calculateAverageMarks(student);
    
    REQUIRE(average == Approx(85.17).epsilon(0.01));  // Allow small floating point difference
}

TEST_CASE("Compare Students") {
    Subject subjects1[3], subjects2[3];
    
    setSubjectData(subjects1[0], "Mathematics", 85.5);
    setSubjectData(subjects1[1], "Science", 90.0);
    setSubjectData(subjects1[2], "English", 80.0);

    setSubjectData(subjects2[0], "Mathematics", 90.0);
    setSubjectData(subjects2[1], "Science", 80.0);
    setSubjectData(subjects2[2], "English", 85.0);

    Student student1, student2;
    setStudentData(student1, "John Doe", 101, subjects1);
    setStudentData(student2, "Jane Doe", 102, subjects2);

    Student* topStudent = compareStudents(student1, student2);
    
    REQUIRE( topStudent->StudentName == "John Doe" );   // student1 has a higher total score
}
