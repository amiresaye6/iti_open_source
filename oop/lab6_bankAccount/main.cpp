#include <iostream>
#include <string.h>

using namespace std;

class BankAccount{
    int id = 0;
    char name[21];
    double balance = 0;
public:
    void SetId(int _id){
        if (_id < 0 || _id > 100000)
            cout << "invalid id, values [0-100000]"<< endl;
        else
            id = _id;
    }
    void SetName(char* _name){
        if(strlen(_name) < 3 || strlen(_name) > 20)
            cout << "invalid length: input more than 3 characters and less than 20" << endl;
        else
            strcpy(name, _name);
    }
    void Deposit(double _amount){
        if (_amount < 0)
            cout << "invalid value, must be positive" << endl;
        balance += _amount;
    }
    void Withdraw(double _amount){
        if (_amount < 0)
            cout << "invalid value, must be positive" << endl;
        if (balance - _amount <= 0 )
            cout << "your balance is 0, you can not withdraw" << endl;
        else
            balance -= _amount;
    }

    int GetId(){
        return id;
    }
    char* GetName(){
        return name;
    }
    double GetBalance(){
        return balance;
    }

    void Print(){
        cout << "Id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << balance << endl;
    }
};

int main()
{
    BankAccount b1;
    int id, wAmount, dAmount;
    char name[20];

    cout << "input Bank Account data" << endl<< endl;

    cout << "User Id" << endl;
    cin >> id;
    cout << "User Name" << endl;
    cin >> name;
    cout << "User amount to Deposit" << endl;
    cin >> dAmount;
    cout << "User amount to withdraw" << endl;
    cin >> wAmount;

    b1.SetId(id);
    b1.SetName(name);
    b1.Deposit(dAmount);
    b1.Withdraw(wAmount);

    cout << "Bank User data: " << endl;
    b1.Print();
    return 0;
}
