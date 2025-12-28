#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>
using namespace std;

struct Data
{
    int id = 0;
    char name[100] = "emp name";
    int age = 18;
};
struct Node
{
    Data* data;
    Node* next = NULL;
    Node* prev = NULL;
};

class LinkedList
{
private:
    Node* head;
    Node* tail;

    void copyList(const LinkedList& other)
    {
        head = tail = NULL;
        Node* current = other.head;
        while (current != NULL)
        {
            Data* newData = new Data;
            newData->id = current->data->id;
            newData->age = current->data->age;
            strcpy(newData->name, current->data->name);

            insertNode(newData->id, newData->age, newData->name);
            delete newData;

            current = current->next;
        }
    }

    void cleanup()
    {
        Node* current = head;
        Node* nextNode = NULL;

        while(current != NULL)
        {
            nextNode = current->next;
            delete current->data;
            delete current;
            current = nextNode;
        }
        head = NULL;
        tail = NULL;
    }

    Node* searchP(int _id)
    {
        Node* h = head;
        while(h)
        {
            if (h->data->id == _id)
            {
                return h;
            }
            h = h->next;
        }
        return NULL;
    }

    Node* searchP(char* _name)
    {
        Node* h = head;
        while(h)
        {
            if (strcmp(h->data->name, _name) == 0)
            {
                return h;
            }
            h = h->next;
        }
        return NULL;
    }

public:
    LinkedList()
    {
        head = tail = NULL;
    }

    ~LinkedList()
    {
        cleanup();
    }

    LinkedList(const LinkedList& other) : head(NULL), tail(NULL)
    {
        copyList(other);
    }

    LinkedList& operator=(const LinkedList& other)
    {
        if (this != &other)
        {
            cleanup();
            copyList(other);
        }
        return *this;
    }

    void insertNode(int _id = 0, int _age = 18, char* _name = "emp_name")
    {
        Node* temp = new Node;
        Data* data = new Data;
        data->id = _id;
        data->age = _age;
        strcpy(data->name, _name);
        temp->data = data;
        if (head == NULL) // first node
        {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void insertBefore(int _targetId, int _id = 0, int _age = 18, char* _name = "emp_name")
    {
        Node* target = searchP(_targetId);
        if (target == NULL)
        {
            cout << "Target node with ID " << _targetId << " not found. Insertion failed." << endl;
            return;
        }

        Node* newNode = new Node;
        Data* data = new Data;
        data->id = _id;
        data->age = _age;
        strcpy(data->name, _name);
        newNode->data = data;

        newNode->next = target;
        newNode->prev = target->prev;

        if (target->prev != NULL) //  target is first node
        {
            target->prev->next = newNode;
        }
        else
        {
            head = newNode;
        }
        target->prev = newNode;
        cout << "Node inserted before ID " << _targetId << " successfully." << endl;
    }

    Data* search(int _id)
    {
        Data* t = new Data;
        Node* n;
        n = searchP(_id);
        if(n)
        {
            t->id = n->data->id;
            t->age = n->data->age;
            strcpy(t->name, n->data->name);
            return t;
        }
        else
        {
            t->id = -1;
            return t;
        }
    }

    Data* search(char* _name)
    {
        Data* t = new Data;
        Node* n;
        n = searchP(_name);
        if(n)
        {
            t->id = n->data->id;
            t->age = n->data->age;
            strcpy(t->name, n->data->name);
            return t;
        }
        else
        {
            t->id = -1;
            return t;
        }
    }

    void deleteNode(int _id)
    {
        Node* nodeToDelete = searchP(_id);
        if (nodeToDelete == NULL)
        {
            cout << "Node with ID " << _id << " not found. Deletion failed." << endl;
            return;
        }

        if (nodeToDelete->prev != NULL)
        {
            nodeToDelete->prev->next = nodeToDelete->next;
        }
        else
        {
            head = nodeToDelete->next;
        }

        if (nodeToDelete->next != NULL)
        {
            nodeToDelete->next->prev = nodeToDelete->prev;
        }
        else
        {
            tail = nodeToDelete->prev;
        }

        delete nodeToDelete->data;
        delete nodeToDelete;
        cout << "Node with ID " << _id << " deleted successfully." << endl;
    }

    void deleteNode(char* _name)
    {
        Node* nodeToDelete = searchP(_name);
        if (nodeToDelete == NULL)
        {
            cout << "Node with name " << _name << " not found. Deletion failed." << endl;
            return;
        }

        if (nodeToDelete->prev != NULL)
        {
            nodeToDelete->prev->next = nodeToDelete->next;
        }
        else
        {
            head = nodeToDelete->next;
        }

        if (nodeToDelete->next != NULL)
        {
            nodeToDelete->next->prev = nodeToDelete->prev;
        }
        else
        {
            tail = nodeToDelete->prev;
        }

        delete nodeToDelete->data;
        delete nodeToDelete;
        cout << "Node with name " << _name << " deleted successfully." << endl;
    }

    void Terminator()
    {
        cleanup();
        cout << "Linked List Terminated Successfully"  << endl;
    }

    int countNodes()
    {
        int size = 0;
        Node* t = head;
        while(t)
        {
            size++;
            t = t->next;
        }
        cout << "Linked List size is: " << size << endl;
        return size;
    }

    void print(Data* n)
    {
        cout << "ID: " << n->id << endl;
        cout << "Name: " << n->name << endl;
        cout << "Age: " << n->age <<endl;
        cout << "========================" << endl;
    }

    void printList()
    {
        Node* h = head;
        if (h == NULL)
        {
            cout << "empty Linked List" << endl;
            return;
        }
        else
        {
            while(h)
            {
                print(h->data);
                h = h->next;
            }
        }
    }

    void printListReverse()
    {
        Node* t = tail;
        if (t == NULL)
        {
            cout << "empty Linked List" << endl;
            return;
        }
        else
        {
            while(t)
            {
                print(t->data);
                t = t->prev;
            }
        }
    }
};

void gotoxy(int column, int line);
void textattr(int i);
void printMenu();
void printOpt(char str[10]);

Data* getNodeData();
void SearchUser(LinkedList l);
void DeleteUser(LinkedList &l);
void InsertUser(LinkedList &l);


int highlight = 0, selected = -1, first = 1, size = 1;


int main()
{
    LinkedList l;
    Data* tempd;

    int index = 0, buff, ml = 8;
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
        case 0:
            system("cls");
            tempd = getNodeData();
            l.insertNode(tempd->id, tempd->age, tempd->name);
            delete tempd;
            getch();
            break;
        case 1:
            system("cls");
            l.printList();
            getch();
            break;
        case 2:
            system("cls");
            l.printListReverse();
            getch();
            break;
        case 3:
            system("cls");
            SearchUser(l);
            getch();
            break;
        case 4:
            system("cls");
            DeleteUser(l);
            getch();
            break;
        case 5:
            system("cls");
            InsertUser(l);
            getch();
            break;
        case 6:
            system("cls");
            l.countNodes();
            getch();
            break;

        case 7:
            system("cls");
            l.Terminator();
            getch();
            break;
        case 8:
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
    char obtions[9][20] = {"new", "Display", "Reverse", "Search", "Delete", "Insert", "Count", "Delete All", "Exit"};
    for (int i = 0; i< 9; i++)
    {
        gotoxy(2, i);
        if (highlight == i)
            textattr(0x02);
        cout << obtions[i];
        textattr(0x07);
    }
}

Data* getNodeData()
{
    Data* d = new Data;
    int id, age;
    int flag = 0;
    char name[100];
    cout << "Inserting User Data" << endl;
    cout << "====================" << endl;
    while(flag == 0)
    {
        cout << "ID: ";
        cin >> id;
        if (id < 0)
        {
            system("cls");
            cout << "invalid id, Id must be greater thatn 0, press any key to try again" << endl;
        }
        else
        {
            flag = 1;
            d->id = id;
        }
    }
    flag = 0;
    while(flag == 0)
    {
        cout << "Age: ";
        cin >> age;
        if (age < 0)
        {
            system("cls");

            cout << "invalid age, you must be 18 or older in order to register, press any key to try again." << endl;
            getch();
        }
        else
        {
            flag = 1;
            d->age= age;
        }
    }

    cout << "Name: ";
    cin >> name;
    strcpy(d->name, name);

    return d;
}

void SearchUser(LinkedList l)
{
    int flag = 0;
    int id;
    char name[100];
    Data* d = new Data;
    char op;
    cout << "please input the id or the name of the user to search for, (i >> search by id, n >> search by name" << endl;
    while(flag == 0)
    {
        cin >> op;
        if (op != 'i' && op != 'n')
        {
            cout << "invalid option, (i, n) only" << endl;
        }
        else
        {
            flag = 1;
        }

    }
    switch(op)
    {
    case 'i':
        cout << "input user id: ";
        cin >> id;
        d = l.search(id);
        if (d->id == -1)
        {
            cout << "could not find any user with this id" << endl;
        }
        else
        {
            l.print(d);
        }
        break;

    case 'n':
        cout << "input user name: ";
        cin >> name;
        d = l.search(name);
        if (d->id == -1)
        {
            cout << "could not find any user with this name" << endl;
        }
        else
        {
            l.print(d);
        }

        break;
    }
    delete d;
}

void DeleteUser(LinkedList &l)
{
    int flag = 0;
    int id;
    char name[100];
    char op;
    cout << "please input the id or the name of the user to delete, (i >> delete by id, n >> delete by name" << endl;
    while(flag == 0)
    {
        cin >> op;
        if (op != 'i' && op != 'n')
        {
            cout << "invalid option, (i, n) only" << endl;
        }
        else
        {
            flag = 1;
        }

    }
    switch(op)
    {
    case 'i':
        cout << "input user id: ";
        cin >> id;
        l.deleteNode(id);
        break;

    case 'n':
        cout << "input user name: ";
        cin >> name;
        l.deleteNode(name);
        break;
    }
}

void InsertUser(LinkedList &l)
{
    int targetId;
    Data* tempd;
    cout << "Insert a new node before which ID?" << endl;
    cout << "Target ID: ";
    cin >> targetId;
    system("cls");
    tempd = getNodeData();
    l.insertBefore(targetId, tempd->id, tempd->age, tempd->name);
    delete tempd;
}
