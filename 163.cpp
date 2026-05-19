#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_BUKU = 100;
const int SIZE_HASH = 10;
const int JML_RAK = 5;

struct Buku
{
    string judul;
    string penulis;
};

struct Anggota
{
    int id;
    string nama;
    bool terisi;
};

struct NodeKategori
{
    string nama;
    NodeKategori *anak[5];
    int jumlahAnak;
};

Anggota tabelAnggota[SIZE_HASH];
Buku daftarBuku[MAX_BUKU];
int jumlahBuku = 0;
int matriksJalur[JML_RAK][JML_RAK];
string namaRak[JML_RAK] = {"Rak Fiksi", "Rak Sejarah", "Rak Sains", "Rak Komik", "Rak Referensi"};

void tambahBuku(string judul, string penulis);
void tampilBuku();
void cariBuku(string keyword);
void initHashTable();
int hashFunction(int id);
void tambahAnggota(int id, string nama);
void cariAnggota(int id);
NodeKategori *buatNode(string nama);
void tambahSubKategori(NodeKategori *parent, NodeKategori *child);
void tampilTree(NodeKategori *node, int level = 0);
void initGraph();
void hubungkanRak(int asal, int tujuan);
void cariRuteTerdekat(int asal, int tujuan);

int main()
{
    initHashTable();
    initGraph();

    tambahBuku("Bumi Manusia", "Pramoedya Ananta Toer");
    tambahBuku("Struktur Data", "Rinaldi Munir");

    tambahAnggota(101, "Agus");
    tambahAnggota(205, "Beni");

    NodeKategori *rootKategori = buatNode("Kategori Buku");
    NodeKategori *nodeFiksi = buatNode("Fiksi");
    NodeKategori *nodeNovel = buatNode("Novel");
    NodeKategori *nodeMisteri = buatNode("Misteri");
    NodeKategori *nodeNonFiksi = buatNode("Non-Fiksi");

    tambahSubKategori(rootKategori, nodeFiksi);
    tambahSubKategori(rootKategori, nodeNonFiksi);
    tambahSubKategori(nodeFiksi, nodeNovel);
    tambahSubKategori(nodeNovel, nodeMisteri);

    hubungkanRak(0, 1);
    hubungkanRak(0, 2);
    hubungkanRak(1, 3);
    hubungkanRak(2, 4);
    hubungkanRak(3, 4);

    int menu;
    do
    {
        cout << "\n====================================\n";
        cout << " SISTEM PERPUSTAKAAN STRUKTUR DATA\n";
        cout << "====================================\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Buku & Cari Buku (Searching)\n";
        cout << "3. Tambah Anggota\n";
        cout << "4. Cari Anggota (Hash Table)\n";
        cout << "5. Tampilkan Kategori (Tree)\n";
        cout << "6. Cari Rute Terdekat Antar Rak (Graph BFS)\n";
        cout << "7. Keluar\n";
        cout << "------------------------------------\n";
        cout << "Pilih menu: ";
        cin >> menu;
        cin.ignore();

        switch (menu)
        {
        case 1:
        {
            string jdl, pen;
            cout << "Judul Buku: ";
            getline(cin, jdl);
            cout << "Penulis: ";
            getline(cin, pen);
            tambahBuku(jdl, pen);
            break;
        }
        case 2:
        {
            tampilBuku();
            string keyword;
            cout << "\nMasukkan judul/penulis untuk dicari: ";
            getline(cin, keyword);
            cariBuku(keyword);
            break;
        }
        case 3:
        {
            int id;
            string nama;

            cout << "Masukkan ID Anggota: ";
            cin >> id;
            cin.ignore();

            cout << "Masukkan Nama Anggota: ";
            getline(cin, nama);

            tambahAnggota(id, nama);
            break;
        }
        case 4:
        {
            int cariId;
            cout << "Masukkan ID Anggota yang dicari: ";
            cin >> cariId;
            cariAnggota(cariId);
            break;
        }
        case 5:
            cout << "\n=== HIERARKI KATEGORI ===\n";
            tampilTree(rootKategori);
            break;
        case 6:
        {
            int asal, tujuan;
            cout << "\nDaftar Rak:\n";
            for (int i = 0; i < JML_RAK; i++)
            {
                cout << i << ". " << namaRak[i] << endl;
            }
            cout << "Masukkan nomor rak asal (0-4): ";
            cin >> asal;
            cout << "Masukkan nomor rak tujuan (0-4): ";
            cin >> tujuan;

            if (asal >= 0 && asal < JML_RAK && tujuan >= 0 && tujuan < JML_RAK)
            {
                cariRuteTerdekat(asal, tujuan);
            }
            else
            {
                cout << "Nomor rak tidak valid!\n";
            }
            break;
        }
        case 7:
            cout << "Program selesai.\n";
            break;
        default:
            cout << "Pilihan salah.\n";
        }
    } while (menu != 7);

    return 0;
}

void tambahBuku(string judul, string penulis)
{
    if (jumlahBuku < MAX_BUKU)
    {
        daftarBuku[jumlahBuku].judul = judul;
        daftarBuku[jumlahBuku].penulis = penulis;
        jumlahBuku++;
        cout << "Buku berhasil ditambahkan!\n";
    }
    else
    {
        cout << "Kapasitas rak buku penuh!\n";
    }
}
void tampilBuku()
{
    cout << "\n=== DAFTAR BUKU ===\n";
    cout << left << setw(25) << "Judul Buku" << " | " << "Penulis" << endl;
    cout << "----------------------------------------------\n";
    if (jumlahBuku == 0)
    {
        cout << "Belum ada buku.\n";
        return;
    }
    for (int i = 0; i < jumlahBuku; i++)
    {
        cout << left << setw(25) << daftarBuku[i].judul << " | " << daftarBuku[i].penulis << endl;
    }
}

void cariBuku(string keyword)
{
    cout << "\n=== HASIL PENCARIAN ===\n";
    bool ketemu = false;
    for (int i = 0; i < jumlahBuku; i++)
    {
        if (daftarBuku[i].judul == keyword || daftarBuku[i].penulis == keyword)
        {
            cout << "- " << daftarBuku[i].judul << " (Penulis: " << daftarBuku[i].penulis << ")\n";
            ketemu = true;
        }
    }
    if (!ketemu)
    {
        cout << "Buku tidak ditemukan.\n";
    }
}

void initHashTable()
{
    for (int i = 0; i < SIZE_HASH; i++)
    {
        tabelAnggota[i].terisi = false;
    }
}

int hashFunction(int id)
{
    return id % SIZE_HASH;
}

void tambahAnggota(int id, string nama)
{

    for (int i = 0; i < SIZE_HASH; i++)
    {
        if (tabelAnggota[i].terisi && tabelAnggota[i].id == id)
        {
            cout << "ID sudah digunakan!\n";
            return;
        }
    }

    int index = hashFunction(id);
    int step = 0;

    while (tabelAnggota[(index + step) % SIZE_HASH].terisi && step < SIZE_HASH)
    {
        step++;
    }

    if (step < SIZE_HASH)
    {
        int finalIndex = (index + step) % SIZE_HASH;
        tabelAnggota[finalIndex].id = id;
        tabelAnggota[finalIndex].nama = nama;
        tabelAnggota[finalIndex].terisi = true;
        cout << "Anggota " << nama << " berhasil didaftarkan.\n";
    }
    else
    {
        cout << "Memori anggota penuh!\n";
    }
}

void cariAnggota(int id)
{
    int index = hashFunction(id);
    int step = 0;

    while (tabelAnggota[(index + step) % SIZE_HASH].terisi && step < SIZE_HASH)
    {
        int currentIndex = (index + step) % SIZE_HASH;
        if (tabelAnggota[currentIndex].id == id)
        {
            cout << "=> Ditemukan: " << tabelAnggota[currentIndex].nama << " (ID: " << id << ")\n";
            return;
        }
        step++;
    }
    cout << "=> Anggota dengan ID " << id << " tidak ditemukan.\n";
}

NodeKategori *buatNode(string nama)
{
    NodeKategori *baru = new NodeKategori;
    baru->nama = nama;
    baru->jumlahAnak = 0;
    for (int i = 0; i < 5; i++)
    {
        baru->anak[i] = NULL;
    }
    return baru;
}

void tambahSubKategori(NodeKategori *parent, NodeKategori *child)
{
    if (parent->jumlahAnak < 5)
    {
        parent->anak[parent->jumlahAnak] = child;
        parent->jumlahAnak++;
    }
}

void tampilTree(NodeKategori *node, int level)
{
    if (node == NULL)
        return;

    for (int i = 0; i < level; i++)
        cout << "    ";
    if (level > 0)
        cout << "|-> ";
    cout << node->nama << endl;

    for (int i = 0; i < node->jumlahAnak; i++)
    {
        tampilTree(node->anak[i], level + 1);
    }
}

void initGraph()
{
    for (int i = 0; i < JML_RAK; i++)
    {
        for (int j = 0; j < JML_RAK; j++)
        {
            matriksJalur[i][j] = 0;
        }
    }
}

void hubungkanRak(int asal, int tujuan)
{
    matriksJalur[asal][tujuan] = 1;
    matriksJalur[tujuan][asal] = 1;
}

void cariRuteTerdekat(int asal, int tujuan)
{
    bool dikunjungi[JML_RAK] = {false};
    int parent[JML_RAK];
    for (int i = 0; i < JML_RAK; i++)
        parent[i] = -1;

    int queue[100];
    int depan = 0, belakang = 0;

    queue[belakang++] = asal;
    dikunjungi[asal] = true;

    bool ketemu = false;

    while (depan < belakang)
    {
        int sekarang = queue[depan++];

        if (sekarang == tujuan)
        {
            ketemu = true;
            break;
        }

        for (int i = 0; i < JML_RAK; i++)
        {
            if (matriksJalur[sekarang][i] == 1 && !dikunjungi[i])
            {
                dikunjungi[i] = true;
                parent[i] = sekarang;
                queue[belakang++] = i;
            }
        }
    }

    if (ketemu)
    {
        cout << "\nRute Terdekat dari " << namaRak[asal] << " ke " << namaRak[tujuan] << ":\n";

        int jalur[100];
        int hitungJalur = 0;
        int current = tujuan;

        while (current != -1)
        {
            jalur[hitungJalur++] = current;
            current = parent[current];
        }

        for (int i = hitungJalur - 1; i >= 0; i--)
        {
            cout << "[" << namaRak[jalur[i]] << "]";
            if (i > 0)
                cout << " -> ";
        }
        cout << endl;
    }
    else
    {
        cout << "Tidak ada rute yang menghubungkan kedua rak tersebut.\n";
    }
}
