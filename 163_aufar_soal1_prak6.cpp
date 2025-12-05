#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Buku
{
    string judul;
    string penulis;
    int tahun;
};

Buku *arsipBuku(int n);
int main()
{
    int n;
    cout << "Jumlah buku yang mau disimpan: ";
    cin >> n;
    Buku *listBuku = arsipBuku(n);
    cout << "Data Berhasil disimpan ke file database_buku.txt";
}

Buku *arsipBuku(int n)
{
    Buku *listBuku = new Buku[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan data buku (Judul Penulis Tahun):";
        cin >> listBuku[i].judul >> listBuku[i].penulis >> listBuku[i].tahun;
        cout << "-------------------------------------------\n";

        ofstream file("database_buku.txt", ios::app);
        file << "Judul: " << listBuku[i].judul << endl;
        file << "Penulis: " << listBuku[i].penulis << endl;
        file << "Tahun: " << listBuku[i].tahun << endl;
        file << "--------------------------------------" << endl;

        file.close();
    }

    return listBuku;
}