#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>
using namespace std;

struct Node
{
    double data = 0;
    Node* next = NULL;
};

class LinkedListQueue
{
private:
    Node* front;
    Node* rear;

public:
    void Terminator()
    {
        Node* current = front;
        Node* nextNode = NULL;

        while(current != NULL)
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        front = NULL;
        rear = NULL;
    }

    LinkedListQueue()
    {
        front = NULL;
        rear = NULL;
    }

    ~LinkedListQueue()
    {
        Terminator();
    }

    int isEmpty()
    {
        // 1 means empty, 0 means not empty
        if (front == NULL)
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

    void enqueue(double _data)
    {
        if (isFull() == 1)
        {
            cout << "Queue is Full , can not allocate memeory!" << endl;
            return;
        }

        Node* temp = new Node;
        temp->data = _data;
        temp->next = NULL;

        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    double dequeue()
    {
        if (isEmpty() == 1)
        {
            cout << "Queue is Empty. Cannot dequeue." << endl;
            return 0.0;
        }

        Node* oldFront = front;
        double dequeuedValue = oldFront->data;

        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete oldFront;
        return dequeuedValue;
    }


    void Terminator()

    int countNodes()
    {
        int size = 0;
        Node* t = front;
        while(t)
        {
            size++;
            t = t->next;
        }
        cout << "Linked List size is: " << size << endl;
        return size;
    }

    void printList()
    {
        Node* h = front;
        if (h == NULL)
        {
            cout << "empty Linked List" << endl;
            return;
        }
        else
        {
            cout << "Queue Elements (Front to Rear):" << endl;
            while(h)
            {
                cout << h->data << endl;
                h = h->next;
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

    LinkedListQueue q;

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
        case 0: // Enqueue
            system("cls");
            cout << "INPUT VALUE TO ENQUEUE: ";
            cin >> t;
            q.enqueue(t);
            getch();
            break;
        case 1: // Dequeue
            system("cls");
            if (q.isEmpty() == 0)
            {
                double val = q.dequeue();
                cout << "Dequeued value: " << val << endl;
            }
            getch();
            break;
        case 2: // is full
            system("cls");
            if (q.isFull() == 1)
            {
                cout << "Queue is Full." << endl;
            }
            else
            {
                cout << "Queue is Not Full." << endl;
            }
            getch();
            break;
        case 3: // is empty
            system("cls");
            if (q.isEmpty() == 1)
            {
                cout << "Queue is Empty." << endl;
            }
            else
            {
                cout << "Queue is Not Empty. Contains " << q.countNodes() << " elements." << endl;
            }
            getch();
            break;
        case 4: // display
            system("cls");
            q.printList();
            getch();
            break;
        case 5: // Exit
            system("cls");
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
    char obtions[6][20] = {"enqueue", "dequeue", "is full", "is empty", "display", "Exit"};
    for (int i = 0; i< 6; i++)
    {
        gotoxy(2, i);
        if (highlight == i)
            textattr(0x02);
        cout << obtions[i];
        textattr(0x07);
    }
}
