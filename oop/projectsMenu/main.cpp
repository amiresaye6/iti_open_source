#include <iostream>
#include <conio.h>

using namespace std;

void fibonacci ()
{
    // limit
    int input;
    long long int result = 0, first = 0, second = 1;
    short flag = 0;

    cout << "input an int index between [1,93] included, to get its fibonacci" << endl;
    while(flag == 0)
    {
        cin >> input;
        if (input < 0 || input > 93)
            cout << "invalid value, try agian\n";
        else
            flag = 1;
    }
    if (input == 0)
        cout << first << endl;
    else if (input == 1)
        cout << second << endl;
    else {
        for (int i = 0; i < input; i++)
        {
            result = first + second;
            first = second;
            second = result;
        }
        cout << second << endl;
    }
}

void evenOdd()
{
    // task 1
    long long int num;

    cout << "input number to check (even, odd) in range: +/- (2^63 − 1)\n";
    cin >> num;

    if (num % 2 == 0)
        cout << "number is even\n";
    else if (num == 0)
        cout << "number is 0 :)";
    else
        cout << "number is odd\n";
}

void menu()
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
        default:
            cout << "invalid option, plz try again:" << endl;
        }
        getch();
        system("cls");


    }
}

void mirror()
{
    // limit
    long long int input, mirror, pow = 1;
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
    while (input % pow != input)
    {
        pow *= 10;
    }

    pow /= 10;

    while (input != 0)
    {
        mirror += (input % 10) * pow;
        input /= 10;
        pow /= 10;
    }

    cout << mirror;


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
}

void factorial()
{
    int input;
    unsigned long long int result = 1;
    cout << "input a +ve number <= 20" << endl;
    while (true)
    {
        cin >> input;
        if (input < 0)
            cout << "plz input valid number +ve / 0" << endl;
        else
            break;
    }
    for (int i = input; i > 0; i--)
    {
        result *= i;
    }

    cout << "Factorial of " << input << " is " << result << endl;
}

void wordsAndLetterscount()
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

}

void sum5()
{
    long double sum = 0, input;

    cout << "input 5 numbers to calc its sum:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "input number " << i + 1 << endl;
        cin >> input;
        sum += input;
    }

    cout << "Your Sum is: " << sum;
}

void DegreeToGrade()
{
    // task 2
    int degree;

    cout << "enter student degree in range [0, 100] included, to get its grade:\n";
    do {
        cin >> degree;
        if (degree < 0)
            cout << "Degree must be +ve or 0:\n";
        else if (degree > 100)
            cout << "Degree must be less than or equal 100\n";
        else
            break;
    } while( degree < 0 || degree > 100);
    if (degree >= 85)
        cout << "Student Grade is: Excellent\n";
    else if(degree >= 75)
        cout << "Student Grade is: Very Good\n";
    else if(degree >= 65)
        cout << "Student Grade is: Good\n";
    else if(degree >= 50)
        cout << "Student Grade is: Acceptable\n";
    else
        cout << "student Grade is: Failed\n";
}


int main()
{
    int flag = 1;
    char op;
    while (flag != 0)
    {

        cout << "1 ==> Even or odd" << endl;
        cout << "2 ==> Grades" << endl;
        cout << "3 ==> sum 5 nums" << endl;
        cout << "4 ==> count words and letters" << endl;
        cout << "5 ==> Calculate Factorial" << endl;
        cout << "6 ==> calculate power" << endl;
        cout << "7 ==> mirror|rorrim" << endl;
        cout << "8 ==> menu app" << endl;
        cout << "9 ==> fibonatchi in index" << endl;
        cout << "0 ==> Exit" << endl;
        cout << "M ==> Menu" << endl;
        op = getch();

        switch (op)
        {
            // escape flags
            case 'm':
            case 'M':
                break;
            case 27:
            case '0':
                flag = 0;
            // options flags
            case '1':
                system("cls");
                cout << "================Even or odd===============" << endl;
                evenOdd();
                break;
            case '2':
                system("cls");
                cout << "================Grades===============" << endl;
                DegreeToGrade();
                break;
            case '3':
                system("cls");
                cout << "================Sum 5 Numbers===============" << endl;
                sum5();
                break;
            case '4':
                system("cls");
                cout << "================Count Words and Letters===============" << endl;
                wordsAndLetterscount();
                break;
            case '5':
                system("cls");
                cout << "================Calculate Factorial===============" << endl;
                factorial();
                break;
            case '6':
                system("cls");
                cout << "================Calculate Power===============" << endl;
                power();
                break;
            case '7':
                system("cls");
                cout << "================Mirror | rorrim===============" << endl;
                mirror();
                break;
            case '8':
                system("cls");
                cout << "================Menu App===============" << endl;
                menu();
                break;
            case '9':
                system("cls");
                cout << "================Fibonacci (by index)===============" << endl;
                fibonacci();
                break;
            // fall back flag
           default:
                system("cls");
                cout << "invalid option, please chose a correct one, type any key to see the menu" << endl;
        }
        getch();
        system("cls");

    }
    return 0;
}
