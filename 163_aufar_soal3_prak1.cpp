#include <iostream>
using namespace std;

char input_ch();
int main()
{
    cout << "Masukkan sebuah karakter: ";
    char ch1 = input_ch();
    cout << "Masukkan sebuah karakter: ";
    char ch2 = input_ch();
    char result = ch1 ^ ch2;
    cout << result << endl;
    cout << (int)result << endl;
}

char input_ch()
{
    string input;
    while (true)
    {
        cin >> input;
        if (input.length() == 1)
        {
            return input[0];
        }
        else
        {
            cout << "Masukkan SEBUAH karakter ASCII!\n";
            cout << "Masukkan karakter: ";
            cin.clear();
            cin.ignore();
        }
    }
}