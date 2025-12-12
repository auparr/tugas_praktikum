# Sistem Manajemen Data Mahasiswa

Aplikasi CRUD (Create, Read, Update, Delete) sederhana untuk mengelola data mahasiswa dan nilai mata kuliah menggunakan bahasa pemrograman C++.

## 📋 Informasi Proyek

**Proyek UAS - Kelompok 3 TID**

### 👥 Anggota Kelompok

| Nama | NIM |
|------|-----|
| Ahmad Jouwdad Aufa Robbani | 25051204163 |
| Kobayashi Kawasena | 25051204122 |
| Rirzki Ardian | 25051204111 |
| Momo Jiji | 25051204164 |
| Aditya Firman Ardiansyah | 25051204777 |

## 🎯 Fitur Utama

1. **Tambah Mahasiswa**
   - Menambahkan data mahasiswa baru (Nama dan NIM)
   - Opsi untuk menambahkan nilai mata kuliah saat pendaftaran

2. **Edit Data Mahasiswa**
   - Edit nilai satu mata kuliah
   - Edit beberapa mata kuliah sekaligus
   - Edit semua mata kuliah

3. **Hapus Mahasiswa**
   - Menghapus data mahasiswa dengan konfirmasi
   - Menampilkan daftar mahasiswa sebelum penghapusan

4. **Tampilkan Data Mahasiswa**
   - Tampilkan data satu mahasiswa (dengan detail nilai dan rata-rata)
   - Tampilkan semua data mahasiswa menggunakan fungsi rekursif

## 📚 Mata Kuliah yang Dicatat

- Pancasila
- Pemdas (Pemrograman Dasar)
- IMK (Interaksi Manusia Komputer)
- Etika Profesi
- Arkom (Arsitektur Komputer)
- Matematika
- Aljabar

## 🛠️ Teknologi yang Digunakan

- **Bahasa**: C++
- **Compiler**: GCC/G++ (atau compiler C++ lainnya)
- **Library**: 
  - `iostream` - Input/output
  - `fstream` - File handling
  - `string` - String manipulation

## 📁 Struktur Data

### Struct Nilai
Menyimpan nilai-nilai mata kuliah mahasiswa:
```cpp
struct Nilai {
    float pancasila, pemdas, imk, etprof, arkom, matematika, aljabar;
}
```

### Struct Mahasiswa
Menyimpan informasi lengkap mahasiswa:
```cpp
struct Mahasiswa {
    string nama;
    string nim;
    Nilai nilai;
    bool adaNilai;
}
```

## 🚀 Cara Menjalankan Program

### Persiapan
1. Pastikan sudah menginstall compiler C++ (GCC/MinGW)
2. Clone atau download repository ini

### Kompilasi
```bash
g++ main.cpp -o program_mahasiswa
```

### Menjalankan
**Linux/Mac:**
```bash
./program_mahasiswa
```

**Windows:**
```bash
program_mahasiswa.exe
```

## 📖 Cara Penggunaan

1. Jalankan program
2. Pilih menu yang diinginkan (1-5)
3. Ikuti instruksi yang muncul di layar
4. Data akan tersimpan otomatis di file `data_siswa.txt`

### Menu Utama
```
+--------------------------------------+
|        >>   SIMPLE CRUD   <<         |
+--------------------------------------+

[1]  Tambah Mahasiswa
[2]  Edit Data Mahasiswa
[3]  Hapus Mahasiswa
[4]  Tampilkan Data Mahasiswa
[5]  Keluar
```

## 💾 Penyimpanan Data

Data mahasiswa disimpan dalam file `data_siswa.txt` dengan format:
```
[Nama Mahasiswa]
[NIM]
[Status Nilai: 0/1]
[Nilai1] [Nilai2] [Nilai3] ... (jika ada nilai)
```

## ✨ Fitur Khusus

- **Interface Berwarna**: Menggunakan ANSI color codes untuk tampilan yang menarik
- **Validasi Input**: Konfirmasi sebelum menghapus data
- **Perhitungan Otomatis**: Total nilai dan rata-rata dihitung otomatis
- **Rekursif**: Fungsi tampilkan semua data menggunakan metode rekursif
- **Fleksibel**: Mahasiswa bisa ditambahkan tanpa nilai terlebih dahulu

## 📝 Catatan

- Program menggunakan dynamic memory allocation untuk efisiensi
- Data persisten disimpan dalam file text
- Input validation untuk mencegah error
- Warning sebelum operasi penghapusan data

## 🔧 Troubleshooting

**Program tidak bisa dikompilasi:**
- Pastikan compiler C++ sudah terinstall dengan benar
- Cek apakah semua library tersedia

**File data tidak terbaca:**
- Pastikan file `data_siswa.txt` berada di direktori yang sama dengan executable
- Jika file belum ada, program akan membuatnya otomatis saat menambah data pertama kali

**Warna tidak muncul di Windows:**
- Gunakan Windows Terminal atau terminal yang support ANSI color codes

---
