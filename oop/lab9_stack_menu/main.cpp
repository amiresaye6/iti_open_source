#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;


struct emp
{
    int id = -1;
    float salary;
    int age;
    char name[21];
    char department[21];
    short initFlag = 0;
};


class Stack
{
    emp* arr;
    int size;
    int tos;

public:
    Stack(int _size = 5)
    {
        if (_size <= 0)
        {
            cout << "size must be positive greater than 0" << endl;
        }
        else
        {
            size = _size;
            arr = new emp[size];
            if (arr == NULL)
            {
                cout << "failed to allocate the stack" << endl;
            }
            cout << "stack created successfully, press any key to continue" << endl;
            getch();
        }
        tos = -1;
    }
    ~Stack()
    {
        cout << "your Stack of size " << size << " is deleted" << endl;
        delete[] arr;
    }

    Stack(Stack& cs)
    {
        tos = cs.tos;
        size = cs.size;
        arr = new emp[size];
        for (int i = 0; i <= tos; i++)
        {
            arr[i] = cs.arr[i];
        }
        cout << "deep copy completed" << endl;

    }
    int push(emp _val)
    {
        if (tos + 1 == size)
        {
            cout << "your stack is full" << endl;
            return 0;
        }
        else
        {
            tos++;
            arr[tos] = _val;
            cout << "pushed value " << endl;
        }
        return 1;
    }

    int pop(emp& data)
    {
        if (tos - 1 == -2 )
        {
            cout << "your stack is empty" << endl;
            return 0;
        }
        else
        {
            data = arr[tos];
            tos--;
        }
        return 1;
    }

    int peak(emp& e)
    {
        if (tos == -1)
        {
            cout << "stack is empty" << endl;
            return 0;

        }
        else
        {
            e = arr[tos];
            return 1;
        }
    }

    bool isFull()
    {
        return tos + 1 == size ? true : false;
    }
    bool isEmpty()
    {
        return tos == -1? true : false;
    }
    void clearStask()
    {
        tos = -1;
    }
// update from lab 8
//    void print()
//    {
//        for (int i = 0; i <= tos; i++)
//            cout << "idx " << i << ", val: " << arr[i] << endl;
//    }

};

void drawExpression(int cond);

void gotoxy(int column, int line);
void textattr(int i);
void printMenu();
void printOpt(char str[10]);

//employee
void printEmp(emp e);
void getEmpData(emp& puffer);

int highlight = 0, selected = -1, first = 1, size = 1;
int empSize = 0, empFlag = 0;

// enter >> 13, esc >> 27, home special and 71, end >> special and 79
int main()
{
    Stack* employees;
    emp puffer,test;
    if (first == 1)
    {
        cout << "inupt employees array size: " << endl;
        while (empFlag == 0)
        {
            cin >> empSize;
            if (empSize < 1)
                cout << "invalid size, try again: " << endl;
            else
                empFlag = 1;
        }
        employees = new Stack(empSize);


    }


    int index = 0, buff, ml = 5, empIdx;
    char size;
    short flag = 0;

    while (flag == 0)
    {
        selected = -1;
        system("cls");
        printMenu();
        size = getch();
        switch (size)
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
            size = getch();
            switch (size)
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
        case 0:  // new >>  push to the stack
            system("cls");
            getEmpData(puffer);
            employees->push(puffer);
            getch();
            break;
        case 1:
            system("cls");
            if (employees->pop(test) == 1)
                printEmp(test);
            getch();
            break;
        case 2:  // peak logic
            system("cls");
            if (employees->peak(test) == 1)
                printEmp(test);
            getch();
            break;
        case 3: // isFull logic
            system("cls");
            employees->isFull() ? cout << "STACK IS FULL" << endl: cout << "STACK IS NOT FULL" << endl;
            getch();
            break;
        case 4: // isEmpty logic
            system("cls");
            employees->isEmpty() ? cout << "STACK IS Empty" << endl: cout << "STACK IS NOT Empty" << endl;
            getch();
            break;
        case 5:
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
    char obtions[8][20] = {"new", "Display", "Peak", "Is Full?", "Is Empty", "Exit"};
    for (int i = 0; i< 6; i++)
    {
        gotoxy(2, i);
        if (highlight == i)
            textattr(0x02);
        cout << obtions[i];
        textattr(0x07);
    }
}

void getEmpData(emp& puffer)
{

    cout << "Employee Id from 0 to 1000: \t\t";
    cin >> puffer.id;

    cout << "Employee Name: \t\t";
    cin >> puffer.name;

    cout << "Employee Age: \t\t";
    cin >> puffer.age;

    cout << "Employee Department: \t\t";
    cin >> puffer.department;

    cout << "Employee Salary: \t\t";
    cin >> puffer.salary;

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



void drawExpression(int cond)
{
    const int N = 15, SPACE = 5;

    int smile[15][15] =
    {
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




    int angry[15][15] =
    {
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
