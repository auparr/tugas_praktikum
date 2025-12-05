#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Masukkan batas angka: ";
    cin >> a;
    cout << "cari kelipatan dari angka: ";
    cin >> b;

    for (int i = 1; i <= a; i++)
    {
        if (i % b == 0)
        {
            cout << "*";
        }
        else
        {
            cout << i;
        }
        cout << " ";
    }

    cout << endl;
}