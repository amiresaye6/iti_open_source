#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;


void gotoxy(int column, int line);
void textattr(int i);
void printMenu();
void printOpt(char str[10]);


int highlight = 0, selected = -1, first = 1, size = 1;

// enter >> 13, esc >> 27, home special and 71, end >> special and 79
int main()
{
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
            getch();
            break;
        case 1:
            system("cls");
            getch();
            break;
        case 2:  // peak logic
            system("cls");
            getch();
            break;
        case 3: // isFull logic
            system("cls");
            getch();
            break;
        case 4: // isEmpty logic
            system("cls");
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
