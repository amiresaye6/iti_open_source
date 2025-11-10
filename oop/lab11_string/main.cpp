#include <iostream>
using namespace std;

class MyString
{
    char* str;

    int length(char* s)
    {
        int len = 0;
        while (s[len] != '\0')
        {
            len++;
        }
        return len;
    }

    void copyStr(char* dest, char* src)
    {
        int i = 0;
        while (src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    int compareStr(char* s1, char* s2)
    {
        int i = 0;
        while (s1[i] != '\0' && s2[i] != '\0')
        {
            if (s1[i] != s2[i])
                return s1[i] - s2[i];
            i++;
        }
        return s1[i] - s2[i];
    }

public:
    MyString()
    {
        str = new char[1];
        str[0] = '\0';
    }

    MyString(char* s)
    {
        int len = length(s);
        str = new char[len + 1];
        copyStr(str, s);
    }

    MyString(MyString& s)
    {
        int len = length(s.str);
        str = new char[len + 1];
        copyStr(str, s.str);
    }

    ~MyString()
    {
        delete[] str;
    }

    MyString& operator=(MyString& s)
    {
        if (this != &s)
        {
            delete[] str;
            int len = length(s.str);
            str = new char[len + 1];
            copyStr(str, s.str);
        }
        return *this;
    }

    MyString operator+(MyString& s)
    {
        int len1 = length(str);
        int len2 = length(s.str);
        char* temp = new char[len1 + len2 + 1];

        for (int i = 0; i < len1; i++)
        {
            temp[i] = str[i];
        }
        for (int j = 0; j < len2; j++)
        {
            temp[len1 + j] = s.str[j];
        }
        temp[len1 + len2] = '\0';

        MyString result(temp);
        delete[] temp;
        return result;
    }

    bool operator==(MyString& s)
    {
        return compareStr(str, s.str) == 0;
    }

    bool operator<(MyString& s)
    {
        return compareStr(str, s.str) < 0;
    }

    bool operator>(MyString& s)
    {
        return compareStr(str, s.str) > 0;
    }

    void toUpper()
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - 32;
            }
        }
    }

    void toLower()
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = str[i] + 32;
            }
        }
    }

    void display()
    {
        cout << str;
    }
};

int main()
{
    MyString s1("Hello");
    MyString s2("World");

    cout << "s1: ";
    s1.display();
    cout << "\ns2: ";
    s2.display();

    MyString s3 = s1;
    cout << "\ns3 (after s3 = s1): ";
    s3.display();

    MyString s4 = s1 + s2;
    cout << "\ns4 (s1 + s2): ";
    s4.display();

    cout << "\n\nComparison results:";
    cout << "\ns1 == s2: " << (s1 == s2);
    cout << "\ns1 < s2: " << (s1 < s2);
    cout << "\ns1 > s2: " << (s1 > s2);

    s1.toUpper();
    cout << "\n\ns1 to upper: ";
    s1.display();

    s2.toLower();
    cout << "\ns2 to lower: ";
    s2.display();

    cout << endl;
    return 0;
}
