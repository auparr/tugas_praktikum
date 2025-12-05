#include <iostream>
using namespace std;

bool cek_palindrom(string s);
int main()
{
    string s;
    cout << "masukkan sebuah kata: ";
    cin >> s;

    if (cek_palindrom(s))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not a Palindrome" << endl;
    }
}

bool cek_palindrom(string s)
{
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }

    for (int i = 0; i < len; i++)
    {
        if (!(s[i] == s[len - i - 1]))
        {
            return false;
        }
    }
    return true;
}