#include <iostream>
#include <cmath>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    cout << "Enter some text: ";

    string Sentense;
    getline(cin, Sentense);

    Sentense.front() = ' ';
    Sentense.back() = '.';
    cout << Sentense << endl;


    _getch;
}
