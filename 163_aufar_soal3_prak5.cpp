#include <iostream>
using namespace std;

bool check(string s, bool *arr);
string toLower(string s);
int main()
{

    string prop, pass;
    cout << "Masukkan kata properti: ";
    cin >> prop;
    cout << "Masukkan password: ";
    cin >> pass;

    string low_prop = toLower(prop);
    string low_pass = toLower(pass);

    bool need[26] = {false};
    for (char c : low_pass)
    {
        need[c - 97] = true;
    }

    if (check(low_prop, need))
    {
        cout << "Semua huruf properti ada di password!";
    }
    else
    {
        cout << "Ada huruf properti yang tidak ada di password!";
    }
}

string toLower(string s)
{
    int n = 0;
    for (char c : s)
    {
        if (c >= 65 && c <= 90)
        {
            s[n] += 32;
        }
        n++;
    }

    return s;
}

bool check(string s, bool *arr)
{
    for (char c : s)
    {
        if (arr[c - 97] == true)
        {
            continue;
        }
        return false;
    }
    return true;
}