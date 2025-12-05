#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct User
{
    string usn;
    string pass;
};

bool validate(User u);
User login();
User registration();
int main()
{
    int pilih;
    cout << "------Selamat Datang!------" << endl
         << "Pilih Menu: " << endl
         << "1. Registrasi" << endl
         << "2. Login" << endl
         << "Pilihan: ";
    cin >> pilih;

    User user;

    string file = "database.txt";

    switch (pilih)
    {
    case 1:
    {
        user = registration();
        if (validate(user))
        {
            ofstream append(file, ios::app);
            string userAppend = user.usn + " " + user.pass + "\n";
            append << userAppend;
            append.close();
            cout << "Akun berhasil didaftarkan!";
        }
        else
        {
            cout << "Akun sudah ada, Coba gunakan username lain";
        }
        break;
    }
    case 2:
    {
        user = login();
        ifstream read(file);
        string line;
        string loginUser = user.usn + " " + user.pass;
        while (getline(read, line))
        {
            if (line == loginUser)
            {
                cout << "Login berhasil!";
                return 0;
            }
        }
        cout << "Username atau password salah!";
        read.close();
        break;
    }
    default:
        cout << "Pilihan tidak valid.";
        break;
    };
}

User registration()
{
    User *user = new User;
    cout << "------Registrasi Akun------" << endl;
    cout << "Masukkan username: ";
    cin.ignore();
    getline(cin, user->usn);
    cout << "Masukkan pass: ";
    cin >> user->pass;

    return *user;
}

User login()
{
    User *user = new User;
    cout << "------Login------" << endl;
    cout << "Masukkan username: ";
    cin.ignore();
    getline(cin, user->usn);
    cout << "Masukkan pass: ";
    cin >> user->pass;

    return *user;
}

bool validate(User u)
{
    ifstream file("database.txt");
    string line;
    string user = u.usn + " " + u.pass;
    while (getline(file, line))
    {
        if (user == line)
        {
            return false;
        }
    }
    file.close();
    return true;
}