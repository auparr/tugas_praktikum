#include <iostream>
using namespace std;

int main()
{
    int transaksi, nominal, total;
    int uang = 50000;
    cout << "Masukkan Jumlah Transaksi: ";
    cin >> transaksi;

    for (int i = 1; i <= transaksi; i++)
    {
        cout << "Masukkan  harga transaksi ke-" << i << ": ";
        cin >> nominal;
        uang -= nominal;
    }

    if (uang == 0)
    {
        cout << "Uang anda habis." << endl;
    }
    else if (uang < 0)
    {
        cout << "Anda punya hutang sebesar: " << uang << endl;
    }
    else
    {
        cout << "Sisa uang anda: " << uang << endl;
    }
}