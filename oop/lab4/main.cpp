#include <iostream>
#include <windows.h>
#include <conio.h>


struct student {
    int id;
    float grades;
    int age;
    char name[21];
    char department[21];
};

struct emp {
    int id = -1;
    float salary;
    int age;
    char name[21];
    char department[21];
    short initFlag = 0;
};

emp* employees;

void drawExpression(int cond);

void gotoxy(int column, int line);
void textattr(int i);
void printMenu();
void printOpt(char str[10]);
void factorial();
void power();
void mirror();

void printNewMenu();

// student
student getStdData();
void printStd(student s);

//employee
void printEmp(emp e);
void getEmpData(int idx);

using namespace std;

int highlight = 0, selected = -1, first = 1, size = 1;
int empSize = 0, empFlag = 0;

// enter >> 13, esc >> 27, home special and 71, end >> special and 79
int main()
{


    if (first == 1)
    {
        cout << "inupt employees array size: " << endl;
        while (empFlag == 0)
        {
            cin >> empSize;
            if (empSize < 1)
                cout << "invalid input, try again: " << endl;
            else
                empFlag = 1;
        }
        employees = new emp[empSize];
        if(employees == NULL)
        {
            cout << "could not allocate: " << endl;
            return 1;
        }

    }

    int index = 0, buff, ml = 7, empIdx;
    char input;
    short flag = 0;
    student s1;

    while (flag == 0)
    {
        selected = -1;
        system("cls");
        printMenu();
        input = getch();
        switch (input)
        {
        case 13: //enter
            selected = index;
            printOpt("Enter");
            break;
        case 27: // esc
            flag = 1;
            printOpt("Esc");
            break;
        case -32: // special buttons
            input = getch();
            switch (input)
            {
                case 71: // home
                    index = 0;
                    printOpt("Home");
                    break;
                case 79: // end
                    index = ml;
                    printOpt("End");
                    break;
                case 72: // up arrow
                    if (index -1 < 0)
                        index = ml;
                    else
                        index -= 1;
                    printOpt("Up");
                    break;
                case 80: // down arrow
                    if (index + 1 > ml)
                        index = 0;
                    else
                        index += 1;
                    printOpt("Down");
                    break;
                default:
                    break;
            }


        default:
            break;
        }
        highlight = index;

        // actiosn
        switch (selected)
        {
            case -1:
            break;
            case 0:
                system("cls");
//                cout << "input idx to add to\t";
//                cin >> empIdx;
//                getEmpData(empIdx);
                printNewMenu();

                break;
            case 1:
                system("cls");
                for (int i = 0; i < empSize; i++)
                {
                    if (employees[i].id == -1)
                    {
                        textattr(0x06);
                        cout << "empty index: " << i << endl;
                    }
                    else
                    {
                        textattr(0x06);
                        printEmp(employees[i]);
                    }
                        textattr(0x07);
                }
                getch();
                break;
            case 2:
                system("cls");
                s1 = getStdData();
                printStd(s1);
                break;
            case 3:
                system("cls");
                cout << "input idx to add to\t";
                cin >> empIdx;
                getEmpData(empIdx);
                break;
            case 4:
                system("cls");
                power();
                break;
            case 5:
                system("cls");
                factorial();
                break;
            case 6:
                system("cls");
                mirror();
                break;
            case 7:
                system("cls");
                return 0;

            default:
                break;
        }


    }
    flag = 0;
    return 0;
}

void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord
    );
}

void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void printOpt(char str[10])
{
    gotoxy(100, 1);
    textattr(0x04);
    cout << str;
    textattr(0x07);
}

void printMenu()
{
    int space = 5;
    char obtions[8][20] = {"new", "Display", "Add New Student", "Add Employee", "power", "Factorial", "Mirror|rorriM", "Exit"};
    for (int i = 0; i< 8; i++)
    {
        gotoxy(2, i);
        if (highlight == i)
            textattr(0x02);
        cout << obtions[i];
        textattr(0x07);
    }
}

void printNewMenu()
{
    int index = 0, ml = 2;
    char input;
    short flag = 0;
    int space = 5;
    char obtions[3][20] = {"Add New Student", "Add Employee", "Exit"};

    while (flag == 0)
    {
        system("cls");
        for (int i = 0; i < 3; i++)
        {
            gotoxy(2 + space, i);
            if (index == i)
                textattr(0x05);
            cout << obtions[i];
            textattr(0x07);
        }

        input = getch();
        switch (input)
        {
        case 13:
            switch (index)
            {
            case 2:
                flag = 1;
                break;
            case 0:
                system("cls");
                {
                    student s1 = getStdData();
                    printStd(s1);
                }
                getch();
                break;
            case 1:
                system("cls");
                {
                    int empIdx;
                    cout << "input idx to add to\t";
                    cin >> empIdx;
                    getEmpData(empIdx);
                }
                getch();
                break;
            }
            break;
        case 27:
            flag = 1;
            break;
        case -32:
            input = getch();
            switch (input)
            {
            case 72:
                if (index - 1 < 0)
                    index = ml;
                else
                    index -= 1;
                break;
            case 80:
                if (index + 1 > ml)
                    index = 0;
                else
                    index += 1;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void factorial()
{
    int input = 0, flag = 0;
    unsigned long long int result = 1;
    cout << "input a +ve number <= 20" << endl;
    while (flag == 0)
    {
        cin >> input;
        if (input < 0 || input > 20)
            cout << "plz input valid number +ve / 0 less than 20" << endl;
        else
            flag = 1;
    }
    for (int i = input; i > 0; i--)
    {
        result *= i;
    }

    cout << "Factorial of " << input << " is " << result << endl;
    cout << "press any key to return to menu:" << endl;
    getch();
}


void power()
{
    float base, power, sign = 1;
    long double result;
    cout << "Input base and power to calculate" << endl;
    cin >> base >> power;

    if (power < 0)
    {
        sign = -1;
        power *= -1;
    }
    result = base;
    for (int i = 0; i < power - 1; i++)
    {
        result *= base;
    }
    if (sign < 0)
        result = 1 / result;
    if (power == 0)
        result = 1;
    cout << "result of " << base << " power " << power * sign << " is " << result;
    cout << "press any key to return to menu:" << endl;
    getch();
}

void mirror()
{
    // limit
    long long int input = 0, mirror = 0, pow = 1;
    short flag = 0;
    cout << "input a +ve number <= 2^63 − 1" << endl;

    while (flag == 0)
    {
        cin >> input;
        if (input < 0)
            cout << "invalid value, try again:" << endl;
        else
            flag = 1;
    }
    //calc pow
    long long int temp = input;

    while (temp >= 10)
    {
        pow *= 10;
        temp /= 10;
    }

    while (input != 0)
    {
        mirror += (input % 10) * pow;
        input /= 10;
        pow /= 10;
    }

    cout << mirror << endl;
    cout << "press any key to return to menu:" << endl;
    getch();
}




student getStdData()
{
    student s;
    cout << "\ninput student data" << endl;

    cout << "Student Id from 0 to 1000: \t\t";
    cin >> s.id;

    cout << "Student Name: \t\t";
    cin >> s.name;

    cout << "Student Age: \t\t";
    cin >> s.age;

    cout << "Student Department: \t\t";
    cin >> s.department;

    cout << "Student Grades: \t\t";
    cin >> s.grades;

    return s;
}

void printStd(student s)
{
    cout << "\nStudent Data" << endl;
    cout << "Id\t\t" << s.id << endl;
    cout << "Name\t\t" << s.name << endl;
    cout << "Age\t\t" << s.age << endl;
    cout << "Department\t" << s.department << endl;
    cout << "Grades\t\t" << s.grades << endl;

    cout << "press any key to return to menu:" << endl;
    getch();
}


void getEmpData(int idx)
{
    short idxFlag = 0;
    char op;
        cout << "\nadding new employee" << endl;
        if (idx > empSize || idx < 0)
            cout << "out of scope idx [0 => " << empSize << "]:\n";
        if (employees[idx].id != -1 && employees[idx].initFlag != 0)
        {
        cout << "this place is occupied, what do you want to do? \n";

            while (idxFlag == 0)
            {
                cout << "press [r] to replace or [e] to exit: \n";
                op = getch();
                switch (op)
                {
                case 'e':
                case 'E':
                    return;
                case 'r':
                case 'R':
                    idxFlag = 1;
                    break;

                default:
                    cout << "invalid obtion";
                    break;
                }

            }

        }
    cout << "input Employee " << idx << " data" << endl;

    cout << "Employee Id from 0 to 1000: \t\t";
    cin >> employees[idx].id;

    cout << "Employee Name: \t\t";
    cin >> employees[idx].name;

    cout << "Employee Age: \t\t";
    cin >> employees[idx].age;

    cout << "Employee Department: \t\t";
    cin >> employees[idx].department;

    cout << "Employee Salary: \t\t";
    cin >> employees[idx].salary;

}

void printEmp(emp s)
{
    system("cls");
    gotoxy(0,0);
    cout << "\nEmployee Data" << endl;
    cout << "Id\t\t" << s.id << endl;
    cout << "Name\t\t" << s.name << endl;
    cout << "Age\t\t" << s.age << endl;
    cout << "Department\t" << s.department << endl;
    cout << "Salary\t\t" << s.salary << endl;
    cout << "Flag\t\t" << s.initFlag<< endl;
}




/*
    cond:   int parameter with 0 or 1 values
            0 represents error so it will draw angry face
            1 means correct so it will draw smiley face.
    return: nothing /void function.

*/
void drawExpression(int cond)
{
    const int N = 15, SPACE = 5;

int smile[15][15] = {
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,1,1,0,0,0,0,0,1,1,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {1,0,0,0,1,0,0,0,0,0,1,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,0,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,1,1,0,0,0,0,0,1,1,0,0,1},
    {1,0,0,0,1,1,1,1,1,1,1,0,0,0,1},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};




int angry[15][15] = {
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,1,1,0,0,0,0,0,1,1,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {1,0,0,0,1,0,0,0,0,0,1,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,0,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,1,1,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,0,1,0,0,0,1},
    {0,1,0,1,0,0,0,0,0,0,0,1,0,1,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};



    switch (cond)
    {
    case 1:
            for (int y = 0; y < N; y++)
            {
                for (int x = 0; x < N; x++)
                {
                    gotoxy(x + SPACE, y + SPACE);
                    if (smile[y][x] == 1)
                        textattr(0x66);
                    else
                        textattr(0x22);
                    cout << ' ';
                }
            }
        break;
    case 0:
            for (int y = 0; y < N; y++)
            {
                for (int x = 0; x < N; x++)
                {
                    gotoxy(x + SPACE, y + SPACE);
                    if (angry[y][x] == 1)
                        textattr(0x44);
                    else
                        textattr(0x22);
                    cout << ' ';
                }
            }
        break;

    default:
        break;
    }
    textattr(0x07);
    getch();
    system("cls");

}
