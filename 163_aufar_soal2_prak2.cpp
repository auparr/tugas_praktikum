#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;

int input_nilai();
int main()
{
    map<int, string> nilai;

    cout << "Masukkan nilai perwakilan TI: ";
    nilai[input_nilai()] = "TI";

    cout << "Masukkan nilai perwakilan SI: ";
    nilai[input_nilai()] = "SI";

    cout << "Masukkan nilai perwakilan PTI: ";
    nilai[input_nilai()] = "PTI";

    string j1, j2, j3;
    int it = 0;
    for (auto p : nilai)
    {
        if (it == 0)
            j3 = p.second;
        if (it == 1)
            j2 = p.second;
        if (it == 2)
            j1 = p.second;

        it++;
    }

    cout << "Urutan Juara: " << j1 << "-" << j2 << "-" << j3;
}

int input_nilai()
{
    int n;
    while (true)
    {
        if (cin >> n)
        {
            break;
        }
        else
        {
            cout << "Invalid input!\nHarap masukkan angka: ";
            cin.clear();
            cin.ignore();
        }
    }
    return n;
}