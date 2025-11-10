#include <iostream>
using namespace std;

class operandsStack
{
    float* arr;
    int size;
    int tos;

public:
    operandsStack(int _size = 5)
    {
        if (_size <= 0)
        {
            cout << "size must be positive greater than 0" << endl;
        }
        else
        {
            size = _size;
            arr = new float[size];
            if (arr == NULL)
            {
                cout << "failed to allocate the stack" << endl;
            }
        }
        tos = -1;
    }
    ~operandsStack()
    {
        cout << "your operandsStack of size " << size << " is deleted" << endl;
        delete[] arr;
    }

    // lab 8 udpate, adding copy construcuor
    operandsStack(operandsStack& cs)
    {
        tos = cs.tos;
        size = cs.size;
        arr = new float[size];
        for (int i = 0; i <= tos; i++)
        {
            arr[i] = cs.arr[i];
        }
        cout << "deep copy completed" << endl;

    }
    int push(float _val)
    {
        if (tos + 1 == size)
        {
            cout << "your stack is full" << endl;
            return 0;
        }
        else
        {
            tos++;
            arr[tos] = _val;
            cout << "pushed operand " << _val << endl;
        }
        return 1;
    }

    int pop(float& data)
    {
        if (tos == -1)
        {
            cout << "your stack is empty" << endl;
            return 0;
        }
        else
        {
            data = arr[tos];
            tos--;
        }
        return 1;
    }
    void clearStask()
    {
        while(tos != -1)
            arr[tos--]  = 0;

    }
    float peak()
    {
        return arr[tos];
    }
// update from lab 8
    void print()
    {
        for (int i = 0; i <= tos; i++)
            cout << "idx " << i << ", val: " << arr[i] << endl;
    }

};


class operatorsStack
{
    char* arr;
    int size;
    int tos;

public:
    operatorsStack(int _size = 5)
    {
        if (_size <= 0)
        {
            cout << "size must be positive greater than 0" << endl;
        }
        else
        {
            size = _size;
            arr = new char[size];
            if (arr == NULL)
            {
                cout << "failed to allocate the stack" << endl;
            }
        }
        tos = -1;
    }
    ~operatorsStack()
    {
        cout << "your operatorsStack of size " << size << " is deleted" << endl;
        delete[] arr;
    }

    // lab 8 udpate, adding copy construcuor
    operatorsStack(operatorsStack& cs)
    {
        tos = cs.tos;
        size = cs.size;
        arr = new char[size];
        for (int i = 0; i <= tos; i++)
        {
            arr[i] = cs.arr[i];
        }
        cout << "deep copy completed" << endl;

    }
    int push(char _val)
    {
        if (tos + 1 == size)
        {
            cout << "your stack is full" << endl;
            return 0;
        }
        else
        {
            tos++;
            arr[tos] = _val;
            cout << "pushed operator " << _val << endl;
        }
        return 1;
    }

    int pop(char& data)
    {
        if (tos == -1 )
        {
            cout << "your stack is empty" << endl;
            return 0;
        }
        else
        {
            data = arr[tos];
            tos--;
        }
        return 1;
    }
    void clearStask()
    {
        while(tos != -1)
            arr[tos--]  = 0;

    }
    char peak()
    {
        if (tos == -1)
            return 'e';
        return arr[tos];
    }
// update from lab 8
    void print()
    {
        for (int i = 0; i <= tos; i++)
            cout << "idx " << i << ", val: " << arr[i] << endl;
    }

};

bool calc(float x, char op, float y, float& res);
int precedence(char op);
int main()
{
    int ss = 100, i = 0;
    float buff = 0, flag = 0;
    float numBuff = 0;
    float num1, num2, res = 0;
    char op;
    string eq;
    cout << "input your equation, constraints => [int values only, +, - /, *] less than 100 characters" << endl;
    cin >> eq;
    operandsStack operands(ss);
    operatorsStack operators(ss);
    if (eq[0] == '-')
    {
        eq = "0" + eq;
    }
    while (eq[i] != '\0')
    {

        // handling numbers part.
        while(eq[i] >= '0' && eq[i] <= '9')
        {
            // convert string number into int number to be inputed to the stack correclty
            numBuff *= 10;
            numBuff += eq[i] - '0';
            i++;
            flag = 1;
        }
        if (flag)
        {
            operands.push(numBuff);
            numBuff = 0;
            flag = 0;
        }

        // handling operators
        if (eq[i] == '+' || eq[i] == '-' || eq[i] == '*' || eq[i] == '/')
        {
            // While stack not empty AND top has higher or equal precedence
            while (operators.peak() != 'e' && precedence(operators.peak()) >= precedence(eq[i]))
            {
                operands.pop(num1);
                operands.pop(num2);
                operators.pop(op);
                calc(num2, op, num1, res);
                operands.push(res);
            }
            // Push the current operator after handling higher-precedence ones
            operators.push(eq[i]);
        }
        else if (eq[i] == '(')
        {
            operators.push('(');
        }
        else if (eq[i] == ')')
        {
            char temp;
            while (operators.peak() != 'e' && operators.peak() != '(')
            {
                operands.pop(num1);
                operands.pop(num2);
                operators.pop(op);
                calc(num2, op, num1, res);
                operands.push(res);
            }
            if (operators.peak() == '(')
            {
                operators.pop(temp); // remove '(' from stack
            }
            else
            {
                cout << "Mismatched parentheses!" << endl;
                return 1;
            }
        }

        i++;
    }

    while(operators.peak() != 'e')
    {
        operands.pop(num1);
        operands.pop(num2);
        operators.pop(op);
        if (calc(num2, op, num1, res))
        {
            operands.push(res);
        }
        else
        {
            cout << "something went wrong :__:" << endl;
            return 1;
        }
    }


    operators.print();
    operands.print();
    return 0;
}

bool calc(float x, char op, float y, float& res)
{
    switch (op)
    {
    case '+':
        res = x + y;
        return true;
        break;
    case '-':
        res = x - y;
        return true;
        break;
    case '*':
        res = x * y;
        return true;
        break;
    case '/':
        if (y == 0)
            return false;
        res = x / y;
        return true;
        break;
    default:
        cout << "invalid operator[+, -, *, /]" << endl;
        return false;
    }

}

int precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
