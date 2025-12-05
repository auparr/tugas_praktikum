#include <iostream>

using namespace std;

int main()
{
    string n;
    cout << "Masukkan sebuah bilangan positif: ";
    cin >> n;
    int digit = 0;
    while (n[digit] != '\0')
    {
        digit++;
    }

    for (int i = digit - 1; i >= 0; i--)
    {
        int n_bulat = n[i] - '0';
        int sementara = n_bulat;
        for (int j = 0; j < digit - 1; j++)
        {
            sementara *= n_bulat;
        }
        cout << n_bulat << "^" << digit << " = " << sementara << endl;
    }

    cout << n << endl;
}