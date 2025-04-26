# Tugas Kelompok LAB Kelompok 1

## 👨‍💼 Program Penggajian Bulanan Karyawan

Program ini dibuat untuk menghitung gaji bulanan karyawan berdasarkan golongan dan jam lembur.

### 📁 Struktur Direktori

```
LAB Team Assignment 1/
├── src/            # File sumber (.c)
├── include/        # File header (.h)
├── build/          # File objek (.o)
├── bin/            # Executable program
├── docs/           # Dokumen soal dan referensi
├── Makefile        # File konfigurasi kompilasi
└── README.md       # Dokumentasi
```

### 👥 Anggota Kelompok
1. ANDREAS ARNOL - 2802631564
2. JESSICA FREZA KUMALA - 2802642776
3. SAFIRA TAFANI CHOLISI - 2802647000
4. SHANIA ASTI MAFAZA - 2802638860
5. WAHYU ARDANI SETIAWAN - 2802634862

### 🔹 Input 1: Data Karyawan

- ID Pegawai (NIP)
- Nama
- Alamat
- Nomor Telepon
- Jabatan
- Golongan

Berdasarkan golongan yang dipilih, sistem akan otomatis menentukan **gaji pokok**.

#### 💰 Gaji Pokok berdasarkan Golongan:

| Golongan | Gaji Pokok  |
|----------|-------------|
| D1       | Rp2.500.000 |
| D2       | Rp2.000.000 |
| D3       | Rp1.500.000 |

---

### 🕐 Upah Lembur:

| Golongan | Tarif Lembur (per jam) |
|----------|------------------------|
| D1       | Rp10.000               |
| D2       | Rp5.000                |
| D3       | Rp2.500                |

---

### 🔸 Input 2: Data Lembur

Untuk menghitung total gaji setelah mempertimbangkan lembur, program akan meminta:

- ID Pegawai
- Golongan
- Jam Lembur

---

### 📋 Input 3: Daftar Pegawai

Fitur ini menampilkan daftar semua karyawan yang telah diinput sebelumnya dengan informasi:

- NIP
- Nama
- Jabatan
- Golongan
- Gaji Pokok
- Jam Lembur
- Total Gaji

---

### 🛠️ Cara Kompilasi Program

Untuk mengkompilasi program, gunakan perintah make berikut:

```bash
make
```

### 🛠️ Cara Menjalankan Program

Setelah dikompilasi, Anda dapat menjalankan program dengan:

```bash
./bin/program
```

### 🧹 Membersihkan File Kompilasi

Untuk membersihkan file objek dan executable:

```bash
make clean
```

---

### 🚀 Alur Program

1. Saat program dijalankan, akan muncul menu pilihan.
2. Pilihan pertama memungkinkan Anda memasukkan data karyawan (termasuk golongan).
3. Pilihan kedua untuk memasukkan data lembur dan kemudian menghitung gaji.
4. Pilihan ketiga untuk melihat daftar karyawan yang sudah diinput.
5. Berdasarkan input, program akan menghitung dan menampilkan gaji pokok, upah lembur, dan total gaji karyawan.
6. Setelah menyelesaikan satu tugas, menu akan muncul kembali sampai pengguna memilih keluar (opsi 0).
