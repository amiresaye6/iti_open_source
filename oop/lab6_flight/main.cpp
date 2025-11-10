#include <iostream>
#include <string.h>
using namespace std;

class Flight{
    int flightNumber = 1;
    int seatsAvailable = 50;

public:
    void SetSeats(int _seats)
    {
        if (_seats > 100 || _seats < 0)
            cout << "invalid input [1 to 100] allowed" << endl;
        else
            seatsAvailable = _seats;
    }
    void SetFlightNumber(int _flight)
    {
        if (_flight < 0)
            cout << "invalid input [number > 0] allowed" << endl;
        else
            flightNumber = _flight;
    }

    int GetSeatsAvailable()
    {
        return seatsAvailable;
    }
    int GetFlightNumber()
    {
        return flightNumber;
    }

    void BookSeat()
    {
        if(seatsAvailable - 1 < 0)
            cout << "no seats available";
        else
            seatsAvailable--;

    }

    void Print()
    {
        cout << "Seats available are :" << seatsAvailable << endl << "Flight number : " << flightNumber << endl;
    }

};

int main()
{
    Flight f1;

    int s, n;

    f1.SetSeats(31312);
    f1.SetSeats(60);
    f1.SetFlightNumber(-11);
    f1.SetFlightNumber(1000);


    f1.Print();

    f1.BookSeat();
    f1.BookSeat();
    f1.BookSeat();

    f1.Print();


    return 0;
}
