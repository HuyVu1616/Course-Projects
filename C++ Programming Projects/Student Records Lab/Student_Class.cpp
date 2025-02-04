// Student_Class.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Student.hpp"
using namespace std;

// define an array of students
Student CIS054[] = {
    Student ("Joe Williams", 44536, 3.4, "English"),
    Student ("Sally Washington", 55458, 3.7, "Programming"),
    Student ("Fred MacIntosh", 66587, 2.9, "Math"),
    Student ("Jose De La Cruz", 67892, 3.5, "Criminology"),
    Student ("777 Dan McElroy", 77777, 4.0, "Psychology"),
    Student ("Thinh Nguyen", 73657, 3.6, "Business Administration")
};


int main(int argc, char* argv[])
{
    int NumberOfStudents = sizeof(CIS054)/sizeof(Student);

    // Display the header line
    printf("%3s %-25s %-40.40s\n", "ID #", " NAME", " MAJOR");
    printf("===============================================");
    // List all the students in the course
    cout <<"\n"<<endl;
    for (int i = 0; i < NumberOfStudents; i++) {
    printf("%3d %-25s %-40.40s\n", CIS054[i].getIdNumber(), CIS054[i].getName().c_str(), CIS054[i].getMajor().c_str());
}
    cout << endl;   // blank line after displaying the student names
    
    // compute the average gpa of all the students
    double total=0;
    for (int i=0; i<NumberOfStudents; i++)
        total += CIS054[i].getGpa();
    double average = total / NumberOfStudents;
    cout << "  " << "The average GPA of all the students is " << average << endl << endl;
	return 0;
}