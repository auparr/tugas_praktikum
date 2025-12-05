#include <iostream>
#include <string>
using namespace std;

string toVaporWave(string s);
string toUpper(string s);
int main()
{
    string text;
    cout << "Masukkan string: ";
    getline(cin, text);

    cout << toVaporWave(text) << endl;
}

string toUpper(string s)
{
    int n = 0;
    for (char c : s)
    {
        if (c >= 97 && c <= 122)
        {
            s[n] -= 32;
        }
        n++;
    }

    return s;
}

string toVaporWave(string s)
{
    s = toUpper(s);
    string vaporWave;
    int i = 0;
    while (s[i] != '\0')
    {
        vaporWave += s[i];
        if (s[i + 1] != '\0')
        {
            vaporWave += ' ';
        }
        i++;
    }
    return vaporWave;
}