#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int flag = 1;
    char op;
    while (flag != 0)
    {

        cout << "New\nDisplay\nExit\n";
        op = getch();

        switch (op)
        {
        case 'n':
        case 'N':
            cout << "You chosed New \n";
            break;
        case 'd':
        case 'D':
            cout << "You chosed Display \n";
            break;
        case 'e':
        case 'E':
            cout << "You chosed Exit\n";
            flag = 0;
            break;
        case 27:
            flag = 0;
        }
        getch();
        system("cls");

    }
    return 0;
}
