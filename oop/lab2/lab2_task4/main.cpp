#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    char buffer = ' ', input;
    int wordsCount = 0, lettersCount = 0;
    short wordFlag = 1;
    cout << "Let's count words and letters :__:" << endl;

    while (true)
    {
        if (wordFlag == 2)
        {
            wordsCount++;
            wordFlag = 0;
        }

        input = getche();

        if (input == 13)
        {
            break;
        }
        lettersCount++;

        if ((input == ' ' && buffer != ' ') || (input != ' ' && buffer == ' '))
        {
            wordFlag++;

        }

        buffer = input;
    }
        system("cls");

        cout << "Letters Count is: " << lettersCount << endl;
        cout << "Words Count is: " << wordsCount << endl;

    return 0;
}
