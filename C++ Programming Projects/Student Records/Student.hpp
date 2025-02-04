#include <string>
using namespace std;

class Student
{
private:
    string name;
    int id;
    double gpa;
    string major;
public:
    Student();
    Student(string name, int id, double gpa, string major);

    void setName(string n);
    string getName();
    void setId (int i);
    int getId();
    void setGpa(double g);
    double getGpa();
    void setMajor(string m);
    string getMajor();
};

Student::Student(/* args */)
{
}

Student::~Student()
{
}
