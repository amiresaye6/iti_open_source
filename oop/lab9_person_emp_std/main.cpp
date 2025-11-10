#include <iostream>
#include <string.h>

using namespace std;

class person
{
    int id;
    int age;
    char name[21];
public:
    person(int _id = 0, int _age = 0, char* _name = "NotSpecified")
    {
        if (_id < 0)
            cout << "invalid id" << endl;
        else
            id = _id;
        if (_age < 0)
            cout << "invalid age" << endl;
        else
            age = _age;
        if (strlen(_name) > 20 || strlen(_name) < 3)
            cout << "incorrect name length [3 -> 20]" << endl;
        else
            strcpy(name, _name);
    }

    void setId(int _id)
    {
        if (_id < 0)
            cout << "invalid id" << endl;
        else
            id = _id;
    }

    void setAge(int _age)
    {
        if (_age < 0)
            cout << "invalid age" << endl;
        else
            age = _age;
    }

    void setName(char* _name)
    {
        if (strlen(_name) > 20 || strlen(_name) < 3)
            cout << "incorrect name length [3 -> 20]" << endl;
        else
            strcpy(name, _name);
    }

    int getId()
    {
        return id;
    }

    int getAge()
    {
        return age;

    }
    char* getName()
    {
        return name;
    }

    void print()
    {
        cout << "id: " << id << ", age: " << age << ", name: " << name;
    }
};

class emp : public person
{
    float salary;
public:
    emp(int _id = 0, int _age = 0, char* _name = "NotSpecified", float _salary = 6000) : person(_id, _age, _name)
    {
        if (_salary < 0)
        {
            cout << "invalid salary number" << endl;
        }
        else
            salary = _salary;
    }
    void setSalary(int _salary)
    {
        if (_salary < 0)
        {
            cout << "invalid salary number" << endl;
        }
        else
            salary = _salary;
    }
    float getSalary()
    {
        return salary;
    }

    void print()
    {
        person::print();
        cout << ", salary: " << salary;
    }
};

class student : public person
{
    float grades;
public:
    student(int _id = 0, int _age = 0, char* _name = "std_name_not_specified", float _grades = 50) : person(_id, _age, _name)
    {
        if (_grades < 0 || _grades > 100)
            cout << "invalid grade [0 => 100]" << endl;
        else
            grades = _grades;

    }

    void setGrades(int _grades)
    {
        if (_grades < 0 || _grades > 100)
            cout << "invalid grade [0 => 100]" << endl;
        else
            grades = _grades;
    }

    float getGrades()
    {
        return grades;
    }

    void print()
    {
        person::print();
        cout << ", grades: " << grades;
    }

};



int main()
{
    person p1;
    emp e1(10, 20, "amir Alsayed", 11500);
    student s1(20, 23, "not amir alsayed", 100);

    cout << "\nperson" << endl;
    p1.print();
    cout << "\nemployee" << endl;
    e1.print();
    cout << "\nstudent" << endl;
    s1.print();
    return 0;
}
