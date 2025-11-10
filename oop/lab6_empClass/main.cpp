#include <iostream>
#include <string.h>

using namespace std;

class employee
{
    int id;
    int age;
    double salary;
    char name[21];
public:
    employee()
    {
        id = 0;
        age = 30;
        salary = 6000;
        strcpy(name, "emp");
    }
    employee(int _id)
    {
        if (_id < 0 || _id > 100000)
            cout << "invalid id, values [0-100000]"<< endl;
        else
            id = _id;
        age = 30;
        salary = 6000;
        strcpy(name, "emp");

    }
    employee(int _id, int _age)
    {
        if (_id < 0 || _id > 100000)
            cout << "invalid id, values [0-100000]"<< endl;
        else
            id = _id;
        if (_age < 20 || _age > 50)
            cout << "invalid age, values [20-50]" << endl;
        else
            age = _age;
        salary = 6000;
        strcpy(name, "emp");

    }
    employee(int _id, int _age, int _salary)
    {
        if (_id < 0 || _id > 100000)
            cout << "invalid id, values [0-100000]"<< endl;
        else
            id = _id;
        if (_age < 20 || _age > 50)
            cout << "invalid age, values [20-50]" << endl;
        else
            age = _age;
        if (_salary < 6000)
            cout << "you are a slave bro :__:" << endl;
        else
            salary = _salary;
        strcpy(name, "emp");

    }
    employee(int _id, int _age, int _salary, char* _name)
    {
        if (_id < 0 || _id > 100000)
            cout << "invalid id, values [0-100000]"<< endl;
        else
            id = _id;
        if (_age < 20 || _age > 50)
            cout << "invalid age, values [20-50]" << endl;
        else
            age = _age;
        if (_salary < 6000)
            cout << "you are a slave bro :__:" << endl;
        else
            salary = _salary;
        if(strlen(_name) < 3 || strlen(_name) > 20)
            cout << "invalid length: input more than 3 characters and less than 20" << endl;
        else
            strcpy(name, _name);
    }
    void SetId(int _id)
    {
        if (_id < 0 || _id > 100000)
            cout << "invalid id, values [0-100000]"<< endl;
        else
            id = _id;
    }
    void SetAge(int _age)
    {
        if (_age < 20 || _age > 50)
            cout << "invalid age, values [20-50]" << endl;
        else
            age = _age;
    }
    void SetName(char* _name)
    {
        if(strlen(_name) < 3 || strlen(_name) > 20)
            cout << "invalid length: input more than 3 characters and less than 20" << endl;
        else
            strcpy(name, _name);
    }
    void SetSalary(double _salary)
    {
        if (_salary < 6000)
            cout << "you are a slave bro :__:" << endl;
        else
            salary = _salary;
    }

    int GetId()
    {
        return id;
    }
    char* GetName()
    {
        return name;
    }
    double GetSalary()
    {
        return salary;
    }
    int GetAge()
    {
        return age;
    }

    void Print()
    {
        cout << "Id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main()
{
    employee e1;
    int id, age;
    double salary;
    char name[20];

    cout << "input employee data" << endl<< endl;

    cout << "Employee Id" << endl;
    cin >> id;
    cout << "Employee Name" << endl;
    cin >> name;
    cout << "Employee Age" << endl;
    cin >> age;
    cout << "Employee Salary" << endl;
    cin >> salary;

    e1.SetId(id);
    e1.SetName(name);
    e1.SetAge(age);
    e1.SetSalary(salary);

    cout << "Employee data: " << endl;
    e1.Print();


    cout << "==============================" << endl;

    employee e11(10), e2(20, 23), e3(30, 23, 11500), e4(40, 23, 11500, "Amir Alsayed");

    e11.Print();
    e2.Print();
    e3.Print();
    e4.Print();
    return 0;
}
