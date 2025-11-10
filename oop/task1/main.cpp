#include <iostream>

using namespace std;

int main()
{
    // update >> made the data type long double to return
    long double num1, num2, num3, num4 ;
    char char1;

    // task 2
    cout << "please input first number: " << endl;
    cin >> num1;

    cout << "please input second number: " << endl;
    cin >> num2;

    //update >> make sure second number not 0 "division by 0 exception"

    while (num2 == 0)
    {
        cout << "division by 0 is not allowed, please input valid number"  << endl;
        cin >> num2;
    }

    cout << "sum is : " << num1 + num2 << endl;
    cout << "subtract is : " << num1 - num2 << endl;
    cout << "multiplication is : " << num1 * num2 << endl;
    cout << "division is : " << num1 / num2 << endl;
    cout << "Hello world!" << endl;

    // task 3
    cout << "input a character to convert to ASCII: " << endl;
    cin >> char1;
    num3 = char1;
    cout << "ASCII number is: " << num3 << endl;

    // task 4
    cout << "input a number to convert to a character" << endl;
    cin >> num4;
    char1 = num4;
    cout << "character is : " << char1 << endl;

    /*
    task 5
    first we check the case of the char if it is >= 65 and <= 90 then it is upper case
    and if it is >= 97 and <= 122 then it is lower case so
    we can convert from lower to upper case by subtracting 32
    and to convert from upper case to lower case by adding 32
    then cast the output to char
    */
    return 0;
}
