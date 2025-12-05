#include <iostream>
using namespace std;

bool unik(int num);
bool ganjil(int num);
bool dibagiTiga(int num);
int main()
{
    int N;
    cout << "Masukkan sebuah integer: ";
    cin >> N;

    int ans = N + 1;
    while (true)
    {
        if (unik(ans) && ganjil(ans) && dibagiTiga(ans))
        {
            break;
        };
        ans++;
    }
    cout << ans << endl;
}

bool unik(int num)
{
    bool cek[10] = {false};
    while (num > 0)
    {
        int n = num % 10;
        if (cek[n] == false)
        {
            cek[n] = true;
        }
        else
        {
            return false;
        }
        num /= 10;
    }
    return true;
}

bool dibagiTiga(int num)
{
    return num % 3 == 0;
}

bool ganjil(int num)
{
    return num % 2 == 1;
}