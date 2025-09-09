#include <iostream>
using namespace std;

int input_jarak();
int calculate(int j, int j1, int j2, int p1, int p2);

int main()
{
    cout << "Masukkan jarak nyata: ";
    int J = input_jarak();

    cout << "Masukkan jarak minimum nyata: ";
    int J1 = input_jarak();
    cout << "Masukkan jarak maksimum nyata: ";
    int J2 = input_jarak();

    cout << "Masukkan jarak minimum peta: ";
    int P1 = input_jarak();
    cout << "Masukkan jarak Maksikum peta: ";
    int P2 = input_jarak();
    
    try
    {
        int jp = calculate(J, J1, J2, P1, P2);
        cout << "Jarak di peta adalah: " << jp << endl;
    }

    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

}

int input_jarak()
{
    int jarak;
    while (true)
    {
        if (cin >> jarak)
        {
            break;
        }
        else
        {
            cout << "Tolong masukkan angka!\n";
            cout << "Masukkan angka: ";
            cin.clear();
            cin.ignore();
        }
    }
    return jarak;
}

int calculate(int j, int j1, int j2, int p1, int p2)
{
    if (j2 - j1 != 0 && p2 - p1 != 0)
    {
        return ((j - j1) * (p2 - p1)) / (j2 - j1);
    }
    else
        throw runtime_error("jarak maksimum dan minimum nyata tidak boleh sama!");
}