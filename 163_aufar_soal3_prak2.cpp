#include <iostream>
using namespace std;

string input_string();
int main()
{
    double ipk;
    cout << "Masukkan nama kandidat: ";
    string nama = input_string();
    cout << "Alumni: ";
    string alumni = input_string();
    cout << "IPK: ";
    cin >> ipk;
    if (nama == "Agus" || nama == "agus")
    {
        cout << "Menghapus kandidat dari database...";
        return 0;
    }
    else if (nama[0] == 'A' || nama[0] == 'a')
    {
        char lolos;
        cout << "kandidat diloloskan atau tidak (y/n): ";
        cin >> lolos;
        if (lolos == 'y' || lolos == 'y')
        {
            cout << "kandidat " << nama << " lolos..." << endl;
        }
        else if (lolos == 'n' || lolos == 'n')
        {
            cout << "kandidat " << nama << " tidak lolos..." << endl;
        }
        else

        {
            cout << "invalid input." << endl;
        }
    }
    else
    {
        cout << "Kandidat " << nama << " lolos..." << endl;
    }
}

string input_string()
{
    string s;
    while (true)
    {
        if (cin >> s)
        {
            break;
        }
        else
        {
            cout << "Input invalid.\nMasukkan nama sekali lagi: ";
            cin.clear();
            cin.ignore();
        }
    }
    return s;
}