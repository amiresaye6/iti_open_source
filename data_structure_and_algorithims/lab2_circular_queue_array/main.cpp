#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>
using namespace std;



class Queue
{
    int* arr;
    int size;
    int in, out;

public:
    Queue(int _size = 5)
    {
        if (_size <= 0)
        {
            cout << "size must be positive greater than 0" << endl;
        }
        else
        {
            size = _size + 1;
            arr = new int[size];
            if (arr == NULL)
            {
                cout << "failed to allocate the queue" << endl;
            }
        }
        in = out = 0;
    }
    ~Queue()
    {
        cout << "your queue of size " << size << " is deleted" << endl;
        delete[] arr;
    }

    int enqueue(int _val)
    {
        if ((in + 1) % size == out)
        {
            cout << "queue is full" << endl;
            return 0;
        }
        else
        {
            arr[in] = _val;
            in = (in + 1) % size;

            cout << "input value " << _val << endl;
        }
        return 1;
    }

    int dequeue(int& data)
    {
        if (out == in)
        {
            cout << "queue is empty" << endl;
            return 0;
        }
        else
        {
            data = arr[out];
            out = (out + 1) % size;

        }
        return 1;
    }

    int isEmpty()
    {
        return in == out;
    }

    int isFull()
    {
        return (in + 1) % size == out;
    }


};


void gotoxy(int column, int line);
void textattr(int i);
void printMenu();
void printOpt(char str[10]);



int highlight = 0, selected = -1, first = 1, size = 1;


int main()
{
    Queue q;

    int index = 0, buff, err, ml = 4;
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
        case 13:
            selected = index;
            printOpt("Enter");
            break;
        case 27:
            flag = 1;
            printOpt("Esc");
            break;
        case -32:
            size = getch();
            switch (size)
            {
            case 71:
                index = 0;
                printOpt("Home");
                break;
            case 79:
                index = ml;
                printOpt("End");
                break;
            case 72:
                if (index -1 < 0)
                    index = ml;
                else
                    index -= 1;
                printOpt("Up");
                break;
            case 80:
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

        switch (selected)
        {
        case -1:
            break;
        case 0:// inqueue
            system("cls");
            cout << "input value to enqueue: ";
            cin >> buff;
            q.enqueue(buff);
            getch();
            break;
        case 1: // dequeue
            system("cls");
            err = q.dequeue(buff);
            if (err)
            {
                cout << "dequeuing value: " << buff << endl;
            }
            getch();
            break;
        case 2: // is empty
            system("cls");
            buff = q.isEmpty();
            if (buff)
                cout << "queue is empty" << endl;
            else
                cout << "queue is not emtpy" << endl;
            getch();
            break;
        case 3: // is full
            system("cls");
            buff = q.isFull();
            if (buff)
                cout << "queue is full" << endl;
            else
                cout << "queue is not full" << endl;
            getch();
            break;
        case 4:
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
    char obtions[5][20] = {"Inqueue", "Dequeue", "Is Empty?", "Is Full", "Exit"};
    for (int i = 0; i< 5; i++)
    {
        gotoxy(2, i);
        if (highlight == i)
            textattr(0x02);
        cout << obtions[i];
        textattr(0x07);
    }
}
