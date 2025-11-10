#include <iostream>

using namespace std;


    int main()
    {
        // limit
        int input, first = 0, second = 1, result = 0;

        cout << "factorial" << endl;
        while(true)
        {
            cin >> input;
            if (input < 0)
                cout << "invalid value, try agian\n";
            else
                break;
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
        return 0;
    }
