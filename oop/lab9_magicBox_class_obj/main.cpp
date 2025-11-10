#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;


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


class magicBox
{
    int size;
public:
    magicBox(int _size = 3)
    {
        if (_size % 2 == 0 || _size <= 0)
        {
            textattr(0x04);
            cout << "Invalid size, choose an odd positive number:" << endl;
            size = 3;
            textattr(0x0f);
        }
        else
            size = _size;
    }
    void draw()
    {
        int buff = 1, c, l;

        system("cls");
        c = size / 2 + 1;
        l = 1;
        gotoxy((c - 1) * 4, l - 1);
        cout << 1;

        for (int i = 2; i <= size * size; i++)
        {
            if (buff % size == 0)
            {
                if (l + 1 > size)
                    l = 1;
                else
                    l += 1;
                textattr(0x02);
            }
            else
            {
                if (l - 1 < 1)
                    l = size;
                else
                    l -= 1;
                if (c - 1 < 1)
                    c = size;
                else
                    c -= 1;
                textattr(0x05);
            }
            gotoxy((c - 1) * 4, l - 1);
            cout << i;
            buff = i;
            textattr(0x07);
        }
    }
};


int main()
{
    magicBox m1(9);
    m1.draw();
    return 0;
}


