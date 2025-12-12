#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Nilai
{
    float pancasila, pemdas, imk, etprof, arkom, matematika, aljabar;
};

struct Mahasiswa
{
    string nama;
    string nim;
    Nilai nilai;
    bool adaNilai;
};

const string FILE_NAME = "data_siswa.txt";

int hitungJumlahMahasiswa();
void simpanSemuaData(Mahasiswa *data, int jumlah);
void tambahMahasiswa();
void hapusMahasiswa();
void editDataMahasiswa();
void tampilkanSatuMahasiswa(Mahasiswa *data, int index, int jumlah);
void tampilkanSemuaMahasiswa(Mahasiswa *data, int index, int jumlah);
void tampilkanDataMahasiswa();
Mahasiswa *bacaSemuaData(int &jumlah);

int main()
{
    int pilihan;

    do
    {
        cout << "\n\033[1;32m+--------------------------------------+\033[0m\n";
        cout << "\033[1;37m|        >>   SIMPLE CRUD   <<         |\033[0m\n";
        cout << "\033[1;32m+--------------------------------------+\033[0m\n\n";

        cout << "\033[1;33m[1]\033[0m  Tambah Mahasiswa\n";
        cout << "\033[1;33m[2]\033[0m  Edit Data Mahasiswa\n";
        cout << "\033[1;33m[3]\033[0m  Hapus Mahasiswa\n";
        cout << "\033[1;33m[4]\033[0m  Tampilkan Data Mahasiswa\n";
        cout << "\033[1;33m[5]\033[0m  Keluar\n\n";

        cout << "\033[1;32m+--------------------------------------+\033[0m\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << "\n";

        switch (pilihan)
        {
        case 1:
            tambahMahasiswa();
            break;
        case 2:
            editDataMahasiswa();
            break;
        case 3:
            hapusMahasiswa();
            break;
        case 4:
            tampilkanDataMahasiswa();
            break;
        case 5:
            cout << "\033[1;36mTerima kasih! Program selesai.\033[0m\n";
            break;
        default:
            cout << "\033[1;31m Pilihan tidak valid!\033[0m\n";
        }

    } while (pilihan != 5);

    return 0;
}

int hitungJumlahMahasiswa()
{
    ifstream file(FILE_NAME);
    if (!file.is_open())
        return 0;

    int jumlah = 0;
    string line;

    while (getline(file, line))
    {
        if (!line.empty())
        {
            jumlah++;
            getline(file, line);
            getline(file, line);
            int adaNilai;
            file >> adaNilai;
            file.ignore();
            if (adaNilai)
                getline(file, line);
        }
    }
    file.close();
    return jumlah;
}

Mahasiswa *bacaSemuaData(int &jumlah)
{
    jumlah = hitungJumlahMahasiswa();
    if (jumlah == 0)
        return nullptr;

    Mahasiswa *data = new Mahasiswa[jumlah];
    ifstream file(FILE_NAME);

    for (int i = 0; i < jumlah; i++)
    {
        getline(file, data[i].nama);
        getline(file, data[i].nim);

        int adaNilai;
        file >> adaNilai;
        data[i].adaNilai = (adaNilai == 1);
        file.ignore();

        if (data[i].adaNilai)
        {
            file >> data[i].nilai.pancasila >> data[i].nilai.pemdas >> data[i].nilai.imk >> data[i].nilai.etprof >> data[i].nilai.arkom >> data[i].nilai.matematika >> data[i].nilai.aljabar;
            file.ignore();
        }
        else
        {
            data[i].nilai.pancasila = 0;
            data[i].nilai.pemdas = 0;
            data[i].nilai.imk = 0;
            data[i].nilai.etprof = 0;
            data[i].nilai.arkom = 0;
            data[i].nilai.matematika = 0;
            data[i].nilai.aljabar = 0;
        }
    }

    file.close();
    return data;
}

void simpanSemuaData(Mahasiswa *data, int jumlah)
{
    ofstream file(FILE_NAME);

    for (int i = 0; i < jumlah; i++)
    {
        file << data[i].nama << endl;
        file << data[i].nim << endl;
        file << data[i].adaNilai << endl;

        if (data[i].adaNilai)
        {
            file << data[i].nilai.pancasila << " " << data[i].nilai.pemdas << " "
                 << data[i].nilai.imk << " " << data[i].nilai.etprof << " "
                 << data[i].nilai.arkom << " " << data[i].nilai.matematika << " "
                 << data[i].nilai.aljabar << endl;
        }
    }

    file.close();
}

void tambahMahasiswa()
{
    Mahasiswa mhs;
    char pilihan;

    cin.ignore();
    cout << "\033[1;36m=== Tambah Mahasiswa Baru ===\033[0m\n\n";

    cout << "Nama Mahasiswa: ";
    getline(cin, mhs.nama);

    cout << "NIM: ";
    getline(cin, mhs.nim);

    cout << "\nApakah ingin menambahkan nilai sekarang? (y/n): ";
    cin >> pilihan;

    if (pilihan == 'y' || pilihan == 'Y')
    {
        mhs.adaNilai = true;
        cout << "\n\033[1;33m--- Input Nilai ---\033[0m\n";
        cout << "Pancasila    : ";
        cin >> mhs.nilai.pancasila;
        cout << "Pemdas       : ";
        cin >> mhs.nilai.pemdas;
        cout << "IMK          : ";
        cin >> mhs.nilai.imk;
        cout << "Etika Profesi: ";
        cin >> mhs.nilai.etprof;
        cout << "Arkom        : ";
        cin >> mhs.nilai.arkom;
        cout << "Matematika   : ";
        cin >> mhs.nilai.matematika;
        cout << "Aljabar      : ";
        cin >> mhs.nilai.aljabar;
    }
    else
    {
        mhs.adaNilai = false;
        mhs.nilai.pancasila = 0;
        mhs.nilai.pemdas = 0;
        mhs.nilai.imk = 0;
        mhs.nilai.etprof = 0;
        mhs.nilai.arkom = 0;
        mhs.nilai.matematika = 0;
        mhs.nilai.aljabar = 0;
    }

    ofstream file(FILE_NAME, ios::app);
    if (file.is_open())
    {
        file << mhs.nama << endl;
        file << mhs.nim << endl;
        file << mhs.adaNilai << endl;

        if (mhs.adaNilai)
        {
            file << mhs.nilai.pancasila << " " << mhs.nilai.pemdas << " "
                 << mhs.nilai.imk << " " << mhs.nilai.etprof << " "
                 << mhs.nilai.arkom << " " << mhs.nilai.matematika << " "
                 << mhs.nilai.aljabar << endl;
        }

        file.close();
        cout << "\n\033[1;32m Data mahasiswa berhasil ditambahkan!\033[0m\n";
    }
    else
    {
        cout << "\n\033[1;31m Gagal membuka file!\033[0m\n";
    }
}

void hapusMahasiswa()
{
    int jumlah;
    Mahasiswa *data = bacaSemuaData(jumlah);

    if (data == nullptr || jumlah == 0)
    {
        cout << "\033[1;31m Belum ada data mahasiswa!\033[0m\n";
        return;
    }

    cout << "\033[1;36m=== Hapus Data Mahasiswa ===\033[0m\n\n";
    cout << "Daftar Mahasiswa:\n";
    cout << "\033[1;33m------------------------------------------------------------\033[0m\n";

    for (int i = 0; i < jumlah; i++)
    {
        cout << "[" << (i + 1) << "] " << data[i].nama << " - " << data[i].nim;
        if (!data[i].adaNilai)
            cout << " \033[1;31m(Belum ada nilai)\033[0m";
        cout << endl;
    }

    cout << "\033[1;33m------------------------------------------------------------\033[0m\n";
    cout << "Pilih nomor mahasiswa yang akan dihapus (0 untuk batal): ";

    int pilihMhs;
    cin >> pilihMhs;

    if (pilihMhs < 1 || pilihMhs > jumlah)
    {
        cout << "\033[1;31m Pilihan dibatalkan!\033[0m\n";
        delete[] data;
        return;
    }

    int index = pilihMhs - 1;

    cout << "\n\033[1;31m PERINGATAN!\033[0m\n";
    cout << "Anda akan menghapus data:\n";
    cout << "  Nama: " << data[index].nama << "\n";
    cout << "  NIM : " << data[index].nim << "\n";
    cout << "\nApakah Anda yakin? (y/n): ";

    char konfirmasi;
    cin >> konfirmasi;

    if (konfirmasi != 'y' && konfirmasi != 'Y')
    {
        cout << "\033[1;33m Penghapusan dibatalkan.\033[0m\n";
        delete[] data;
        return;
    }

    Mahasiswa *dataBaru = new Mahasiswa[jumlah - 1];
    int indexBaru = 0;

    for (int i = 0; i < jumlah; i++)
    {
        if (i != index)
        {
            dataBaru[indexBaru] = data[i];
            indexBaru++;
        }
    }

    simpanSemuaData(dataBaru, jumlah - 1);

    cout << "\n\033[1;32m Data mahasiswa berhasil dihapus!\033[0m\n";

    delete[] data;
    delete[] dataBaru;
}

void editDataMahasiswa()
{
    int jumlah;
    Mahasiswa *data = bacaSemuaData(jumlah);

    if (data == nullptr || jumlah == 0)
    {
        cout << "\033[1;31m Belum ada data mahasiswa!\033[0m\n";
        return;
    }

    cout << "\033[1;36m=== Edit Nilai Mahasiswa ===\033[0m\n\n";
    cout << "Daftar Mahasiswa:\n";
    cout << "\033[1;33m------------------------------------------------------------\033[0m\n";

    for (int i = 0; i < jumlah; i++)
    {
        cout << "[" << (i + 1) << "] " << data[i].nama << " - " << data[i].nim;
        if (!data[i].adaNilai)
            cout << " \033[1;31m(Belum ada nilai)\033[0m";
        cout << endl;
    }

    cout << "\033[1;33m------------------------------------------------------------\033[0m\n";
    cout << "Pilih nomor mahasiswa yang akan diedit (0 untuk batal): ";

    int pilihMhs;
    cin >> pilihMhs;

    if (pilihMhs < 1 || pilihMhs > jumlah)
    {
        cout << "\033[1;31m Pilihan dibatalkan!\033[0m\n";
        delete[] data;
        return;
    }

    int index = pilihMhs - 1;

    cout << "\n\033[1;36mMahasiswa terpilih: " << data[index].nama << " (" << data[index].nim << ")\033[0m\n\n";

    if (data[index].adaNilai)
    {
        cout << "Nilai saat ini:\n";
        cout << "  Pancasila     : " << data[index].nilai.pancasila << endl;
        cout << "  Pemdas        : " << data[index].nilai.pemdas << endl;
        cout << "  IMK           : " << data[index].nilai.imk << endl;
        cout << "  Etika Profesi : " << data[index].nilai.etprof << endl;
        cout << "  Arkom         : " << data[index].nilai.arkom << endl;
        cout << "  Matematika    : " << data[index].nilai.matematika << endl;
        cout << "  Aljabar       : " << data[index].nilai.aljabar << endl;
    }
    else
    {
        cout << "\033[1;31mMahasiswa ini belum memiliki nilai.\033[0m\n";
    }

    cout << "\n\033[1;33mPilih mode edit:\033[0m\n";
    cout << "[1] Edit 1 mata kuliah saja\n";
    cout << "[2] Edit beberapa mata kuliah\n";
    cout << "[3] Edit semua mata kuliah\n";
    cout << "Pilihan: ";

    int modeEdit;
    cin >> modeEdit;

    data[index].adaNilai = true;

    if (modeEdit == 1)
    {
        cout << "\n\033[1;36mPilih mata kuliah yang akan diedit:\033[0m\n";
        cout << "[1] Pancasila\n";
        cout << "[2] Pemdas\n";
        cout << "[3] IMK\n";
        cout << "[4] Etika Profesi\n";
        cout << "[5] Arkom\n";
        cout << "[6] Matematika\n";
        cout << "[7] Aljabar\n";
        cout << "Pilihan: ";

        int pilihMatkul;
        cin >> pilihMatkul;

        cout << "Masukkan nilai baru: ";
        float nilaiBaru;
        cin >> nilaiBaru;

        if (pilihMatkul == 1)
            data[index].nilai.pancasila = nilaiBaru;
        else if (pilihMatkul == 2)
            data[index].nilai.pemdas = nilaiBaru;
        else if (pilihMatkul == 3)
            data[index].nilai.imk = nilaiBaru;
        else if (pilihMatkul == 4)
            data[index].nilai.etprof = nilaiBaru;
        else if (pilihMatkul == 5)
            data[index].nilai.arkom = nilaiBaru;
        else if (pilihMatkul == 6)
            data[index].nilai.matematika = nilaiBaru;
        else if (pilihMatkul == 7)
            data[index].nilai.aljabar = nilaiBaru;
        else
        {
            cout << "\033[1;31m Pilihan tidak valid!\033[0m\n";
            delete[] data;
            return;
        }
    }
    else if (modeEdit == 2)
    {
        cout << "\n\033[1;36mPilih mata kuliah yang akan diedit (pisahkan dengan spasi, contoh: 1 3 5):\033[0m\n";
        cout << "[1] Pancasila\n";
        cout << "[2] Pemdas\n";
        cout << "[3] IMK\n";
        cout << "[4] Etika Profesi\n";
        cout << "[5] Arkom\n";
        cout << "[6] Matematika\n";
        cout << "[7] Aljabar\n";
        cout << "Pilihan: ";

        cin.ignore();
        string pilihan;
        getline(cin, pilihan);

        cout << "\n";

        for (int i = 0; i < pilihan.length(); i++)
        {
            if (pilihan[i] >= '1' && pilihan[i] <= '7')
            {
                int matkul = pilihan[i] - '0';
                float nilaiBaru;

                if (matkul == 1)
                {
                    cout << "Nilai Pancasila baru    : ";
                    cin >> nilaiBaru;
                    data[index].nilai.pancasila = nilaiBaru;
                }
                else if (matkul == 2)
                {
                    cout << "Nilai Pemdas baru       : ";
                    cin >> nilaiBaru;
                    data[index].nilai.pemdas = nilaiBaru;
                }
                else if (matkul == 3)
                {
                    cout << "Nilai IMK baru          : ";
                    cin >> nilaiBaru;
                    data[index].nilai.imk = nilaiBaru;
                }
                else if (matkul == 4)
                {
                    cout << "Nilai Etika Profesi baru: ";
                    cin >> nilaiBaru;
                    data[index].nilai.etprof = nilaiBaru;
                }
                else if (matkul == 5)
                {
                    cout << "Nilai Arkom baru        : ";
                    cin >> nilaiBaru;
                    data[index].nilai.arkom = nilaiBaru;
                }
                else if (matkul == 6)
                {
                    cout << "Nilai Matematika baru   : ";
                    cin >> nilaiBaru;
                    data[index].nilai.matematika = nilaiBaru;
                }
                else if (matkul == 7)
                {
                    cout << "Nilai Aljabar baru      : ";
                    cin >> nilaiBaru;
                    data[index].nilai.aljabar = nilaiBaru;
                }
            }
        }
    }
    else if (modeEdit == 3)
    {
        cout << "\n\033[1;33m--- Input Nilai Baru (Semua Mata Kuliah) ---\033[0m\n";
        cout << "Pancasila    : ";
        cin >> data[index].nilai.pancasila;
        cout << "Pemdas       : ";
        cin >> data[index].nilai.pemdas;
        cout << "IMK          : ";
        cin >> data[index].nilai.imk;
        cout << "Etika Profesi: ";
        cin >> data[index].nilai.etprof;
        cout << "Arkom        : ";
        cin >> data[index].nilai.arkom;
        cout << "Matematika   : ";
        cin >> data[index].nilai.matematika;
        cout << "Aljabar      : ";
        cin >> data[index].nilai.aljabar;
    }
    else
    {
        cout << "\033[1;31m Pilihan tidak valid!\033[0m\n";
        delete[] data;
        return;
    }

    simpanSemuaData(data, jumlah);
    cout << "\n\033[1;32m Data nilai berhasil diupdate!\033[0m\n";

    delete[] data;
}

void tampilkanDataMahasiswa()
{
    int jumlah;
    Mahasiswa *data = bacaSemuaData(jumlah);

    if (data == nullptr || jumlah == 0)
    {
        cout << "\033[1;31m Belum ada data mahasiswa!\033[0m\n";
        return;
    }

    cout << "\033[1;36m=== Tampilkan Data Mahasiswa ===\033[0m\n\n";
    cout << "\033[1;33mPilih opsi:\033[0m\n";
    cout << "[1] Tampilkan satu mahasiswa\n";
    cout << "[2] Tampilkan semua mahasiswa (menggunakan rekursif)\n";
    cout << "Pilihan: ";

    int pilihan;
    cin >> pilihan;
    cout << "\n";

    if (pilihan == 1)
    {
        cout << "Daftar Mahasiswa:\n";
        cout << "\033[1;33m------------------------------------------------------------\033[0m\n";
        for (int i = 0; i < jumlah; i++)
        {
            cout << "[" << (i + 1) << "] " << data[i].nama << " - " << data[i].nim;
            if (!data[i].adaNilai)
                cout << " \033[1;31m(Belum ada nilai)\033[0m";
            cout << endl;
        }
        cout << "\033[1;33m------------------------------------------------------------\033[0m\n";
        cout << "Pilih nomor mahasiswa yang ingin ditampilkan: ";

        int pilihMhs;
        cin >> pilihMhs;

        if (pilihMhs < 1 || pilihMhs > jumlah)
        {
            cout << "\033[1;31m Pilihan tidak valid!\033[0m\n";
        }
        else
        {
            cout << "\n";
            tampilkanSatuMahasiswa(data, pilihMhs - 1, jumlah);
        }
    }
    else if (pilihan == 2)
    {
        cout << "\033[1;36m=== Data Semua Mahasiswa (Rekursif) ===\033[0m\n\n";

        tampilkanSemuaMahasiswa(data, 0, jumlah);

        cout << "\033[1;32mTotal: " << jumlah << " mahasiswa\033[0m\n";
    }
    else
    {
        cout << "\033[1;31m Pilihan tidak valid!\033[0m\n";
    }

    delete[] data;
}

void tampilkanSatuMahasiswa(Mahasiswa *data, int index, int jumlah)
{
    if (index >= jumlah)
        return;

    cout << "\033[1;33m--- Mahasiswa " << (index + 1) << " ---\033[0m\n";
    cout << "Nama: " << data[index].nama << "\n";
    cout << "NIM : " << data[index].nim << "\n";

    if (data[index].adaNilai)
    {
        cout << "\nNilai:\n";
        cout << "  Pancasila      : " << data[index].nilai.pancasila << "\n";
        cout << "  Pemdas         : " << data[index].nilai.pemdas << "\n";
        cout << "  IMK            : " << data[index].nilai.imk << "\n";
        cout << "  Etika Profesi  : " << data[index].nilai.etprof << "\n";
        cout << "  Arkom          : " << data[index].nilai.arkom << "\n";
        cout << "  Matematika     : " << data[index].nilai.matematika << "\n";
        cout << "  Aljabar        : " << data[index].nilai.aljabar << "\n";

        float total = data[index].nilai.pancasila + data[index].nilai.pemdas +
                      data[index].nilai.imk + data[index].nilai.etprof +
                      data[index].nilai.arkom + data[index].nilai.matematika +
                      data[index].nilai.aljabar;
        float rataRata = total / 7.0;

        cout << "\n  Total Nilai    : " << total << "\n";
        cout << "  Rata-rata      : " << rataRata << "\n";
    }
    else
    {
        cout << "\n\033[1;31mBelum ada nilai\033[0m\n";
    }

    cout << "\n";
}

void tampilkanSemuaMahasiswa(Mahasiswa *data, int index, int jumlah)
{
    if (index >= jumlah)
        return;

    tampilkanSatuMahasiswa(data, index, jumlah);
    tampilkanSemuaMahasiswa(data, index + 1, jumlah);
}
