#include <iostream>

using namespace std;

string rotasi(string s, int len);
bool cek_rotasi(string s1, string s2, int len);
int main()
{
    string s1, s2;

    cout << "masukkan string pertama: ";
    cin >> s1;
    cout << "masukkan string kedua: ";
    cin >> s2;

    int len = 0;
    while (s1[len] != '\0')
    {
        len++;
    }

    for (int i = 0; i < len; i++)
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
        {
            s1[i] += 32;
        }
    }

    if (cek_rotasi(s1, s2, len))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

string rotasi(string s, int len)
{
    char pertama = s[0];

    for (int i = 0; i < len; i++)
    {
        s[i] = s[i + 1];
    }
    s[len - 1] = pertama;

    return s;
}

bool cek_rotasi(string s1, string s2, int len)
{

    for (int i = 0; i < len; i++)
    {
        s1 = rotasi(s1, len);
        if (s1 == s2)
        {
            return true;
        }
    }
    return false;
}