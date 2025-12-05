#include <iostream>
using namespace std;

int input_jarak();
int main()
{

    cout << "Berapa jarak Naruto dari Hinata(m): ";
    int jarak = input_jarak();

    if (jarak < 10 && jarak >= 0)
    {
        cout << "Hinata malu-malu" << endl;
    }
    else if (jarak >= 10 && jarak <= 50)
    {
        cout << "Hinata biasa saja" << endl;
    }
    else
    {
        cout << "Hinata sedih" << endl;
    }
    return 0;
}

int input_jarak()
{
    int n;
    while (true)
    {
        if (cin >> n && n >= 0)
        {
            break;
        }
        else
        {
            cout << "Invalid input!\nHarap masukkan angka yang tidak lebih kecil dari 0: ";
            cin.clear();
            cin.ignore();
        }
    }
    return n;
}