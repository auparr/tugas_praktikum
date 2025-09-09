#include <iostream>
using namespace std;

int input_integer();
int main()
{

    cout << "Masukkan angka dari 100 - 999: ";
    int n = input_integer();

    string str_n = to_string(n);
    int total = 0;
    for (char ch : str_n)
    {
        total += ch - '0';
    }
    cout << "Penjumlahan tiap digit dari " << n << " adalah: " << total << endl;
}

int input_integer()
{
    int n;
    while (true)
    {
        bool isValid = n >= 100 && n <= 999;
        if (cin >> n && isValid)
        {
            break;
        }
        else
        {
            cout << "Syarat: masukan harus berupa angka & nilainya tidak boleh diluar ketentuan!\n";
            cout << "Masukkan angka dari 100 - 999: ";
            cin.clear();
            cin.ignore();
        }
    }
    return n;
}