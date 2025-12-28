#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>
using namespace std;

struct Node
{
    double data = 0;
    Node* prev = NULL;
};

class LinkedListStack
{
private:
    Node* top;

public:
    void Terminator()
    {
        Node* current = top;
        Node* prevNode = NULL;

        while(current != NULL)
        {
            prevNode = current->prev;
            delete current;
            current = prevNode;
        }
        top = NULL;
        cout << "Linked List Terminated Successfully" << endl;
    }

    LinkedListStack()
    {
        top = NULL;
    }

    ~LinkedListStack()
    {
        Terminator();
    }

    int isEmpty()
    {
        // 1 means emtpty, 0 means full
        if (top == NULL)
            return 1;
        return 0;
    }

    int isFull()
    {
        // 1 means full, 0 means not
        Node* temp = new Node;
        if (temp == NULL)
            return 1;
        delete temp;
        return 0;
    }

    void push(double _data)
    {
        if (isFull() == 1)
        {
            cout << "Stack is Full , can not allocate memory!" << endl;
            return;
        }

        Node* temp = new Node;

        temp->data = _data;

        if (top == NULL)
        {
            top = temp;
            temp->prev = NULL;
        }
        else
        {
            temp->prev = top;
            top = temp;
        }
    }

    double pop()
    {
        if (isEmpty() == 1)
        {
            cout << "Stack is Empty. Cannot pop." << endl;
            return 0;
        }

        double poppedValue = top->data;
        Node* oldTop = top;
        top = top->prev;
        delete oldTop;

        return poppedValue;
    }




    int countNodes()
    {
        int size = 0;
        Node* t = top;
        while(t)
        {
            size++;
            t = t->prev;
        }
        cout << "Linked List size is: " << size << endl;
        return size;
    }

    void printList()
    {
        Node* h = top;
        if (h == NULL)
        {
            cout << "empty Linked List" << endl;
            return;
        }
        else
        {
            cout << "Stack Elements:" << endl;
            while(h)
            {
                cout << h->data << endl;
                h = h->prev;
            }
        }
    }
};

void gotoxy(int column, int line);
void textattr(int i);
void printMenu();
void printOpt(char str[10]);



int highlight = 0, selected = -1, first = 1, size = 1;


int main()
{

    LinkedListStack s;

    int index = 0, ml = 5;
    double t;
    char ch;
    short flag = 0;

    while (flag == 0)
    {
        selected = -1;
        system("cls");
        printMenu();
        ch = getch();
        switch (ch)
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
            ch = getch();
            switch (ch)
            {
            case 71: // Home key
                index = 0;
                printOpt("Home");
                break;
            case 79: // End key
                index = ml;
                printOpt("End");
                break;
            case 72: // Up arrow
                if (index -1 < 0)
                    index = ml;
                else
                    index -= 1;
                printOpt("Up");
                break;
            case 80: // Down arrow
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
        case 0: // push
            system("cls");
            cout << "INPUT VALUE TO PUSH: ";
            cin >> t;
            s.push(t);
            getch();
            break;
        case 1: // pop
            system("cls");
            if (s.isEmpty() == 0) {
                double val = s.pop();
                cout << "Popped value: " << val << endl;
            }
            getch();
            break;
        case 2: // is full
            system("cls");
            if (s.isFull() == 1) {
                cout << "Stack is Full." << endl;
            } else {
                cout << "Stack is Not Full." << endl;
            }
            getch();
            break;
        case 3: // is empty
            system("cls");
            if (s.isEmpty() == 1) {
                cout << "Stack is Empty." << endl;
            } else {
                cout << "Stack is Not Empty. Contains " << s.countNodes() << " elements." << endl;
            }
            getch();
            break;
        case 4: // display
            system("cls");
            s.printList();
            getch();
            break;
        case 5: // Exit
            system("cls");
            flag = 1;
            break;
        default:
            break;
        }
    }
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
    char obtions[6][20] = {"push", "pop", "is full", "is empty", "display", "Exit"};
    for (int i = 0; i< 6; i++)
    {
        gotoxy(2, i);
        if (highlight == i)
            textattr(0x02);
        cout << obtions[i];
        textattr(0x07);
    }
}
