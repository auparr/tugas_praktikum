#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> bilangan;
    int limit, n;

    cout << "Masukkan bilangan batas: ";
    cin >> limit;

    for (int i = 0; i < limit; i++)
    {
        cout << "Masukkan bilangan ke " << i + 1 << " :";
        cin >> n;
        bilangan[n]++;
    }

    for (auto p : bilangan)
    {
        cout << p.first << " muncul sebanyak " << p.second << " kali" << endl;
    }
}