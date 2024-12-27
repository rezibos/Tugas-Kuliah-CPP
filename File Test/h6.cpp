#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <limits>

using namespace std;

struct Barang {
    string nama;
    double harga;
    int stok;
};

struct Transaksi {
    string namaBarang;
    int jumlah;
    double totalHarga;
    string metodePembayaran;
    string waktu;
};

vector<Barang> inventaris;
vector<Transaksi> riwayatTransaksi;

void tambahBarang() {
    Barang barangBaru;
    cin.ignore(); // Menghindari sisa input
    cout << "Masukkan nama barang: ";
    getline(cin, barangBaru.nama);
    
    for (const auto & barang : inventaris) {
        if (barang.nama == barangBaru.nama) {
            cout << "Barang dengan nama tersebut sudah ada!\n";
            return;
        }
    }

    cout << "Masukkan harga barang: ";
    cin >> barangBaru.harga;
    if (barangBaru.harga < 0) {
        cout << "Harga tidak boleh negatif!\n";
        return;
    }

    cout << "Masukkan stok barang: ";
    cin >> barangBaru.stok;
    if (barangBaru.stok < 0) {
        cout << "Stok tidak boleh negatif!\n";
        return;
    }

    inventaris.push_back(barangBaru);
    cout << "Barang berhasil ditambahkan!\n";
}

void tampilkanBarang() {
    if (inventaris.empty()) {
        cout << "Inventaris kosong!\n";
        return;
    }

    cout << "\nDaftar Barang:\n";
    cout << left << setw(15) << "Nama" << setw(10) << "Harga" << setw(10) << "Stok" << endl;
    for (const auto& barang : inventaris) {
        cout << left << setw(15) << barang.nama << setw(10) << fixed << setprecision(2) << barang.harga << setw(10) << barang.stok << endl;
    }
}

void eksporDataBarang() {
    if(inventaris.empty()){
        cout << "gagal databarang\n";
    } else {
        ofstream file("data_barang.txt");
        if (!file.is_open()) {
            cout << "Gagal membuka file untuk ekspor data barang!\n";
            return;
        }

        for (const auto& barang : inventaris) {
            file << barang.nama << "\n";
            file << fixed << setprecision(2) << barang.harga << " " << barang.stok << "\n";
        }

        file.close();
        cout << "Data barang berhasil diekspor ke file data_barang.txt!\n";
    }
}

void transaksi() {
    if (inventaris.empty()) {
        cout << "Inventaris kosong!\n";
        return;
    }

    string namaBarang;
    int jumlah;
    cin.ignore();
    cout << "Masukkan nama barang: ";
    getline(cin, namaBarang);

    bool ditemukan = false;
    for (auto& barang : inventaris) {
        if (barang.nama == namaBarang) {
            ditemukan = true;
            cout << "Masukkan jumlah: ";
            cin >> jumlah;

            if (jumlah > barang.stok) {
                cout << "Stok tidak mencukupi!\n";
                return;
            }

            if (jumlah <= 0) {
                cout << "Jumlah harus lebih dari 0!\n";
                return;
            }

            barang.stok -= jumlah;

            double totalHarga = jumlah * barang.harga;
            string metodePembayaran;
            cout << "Pilih metode pembayaran (cash/kartu): ";
            cin >> metodePembayaran;

            if (metodePembayaran != "cash" && metodePembayaran != "kartu") {
                cout << "Metode pembayaran tidak valid!\n";
                return;
            }

            // Input manual tanggal, bulan, dan tahun transaksi
            int tanggal, bulan, tahun;
            cout << "Masukkan tanggal (1-31): ";
            cin >> tanggal;
            cout << "Masukkan bulan (1-12): ";
            cin >> bulan;
            cout << "Masukkan tahun (YYYY): ";
            cin >> tahun;

            // Validasi input tanggal, bulan, dan tahun (untuk kesederhanaan, validasi sangat dasar)
            if (tanggal < 1 || tanggal > 31 || bulan < 1 || bulan > 12 || tahun < 1000) {
                cout << "Input tanggal, bulan, atau tahun tidak valid!\n";
                return;
            }

            // Format tanggal transaksi menjadi string "DD/MM/YYYY"
            string tanggalTransaksi = to_string(tanggal) + "/" + to_string(bulan) + "/" + to_string(tahun);

            // Simpan transaksi
            riwayatTransaksi.push_back({namaBarang, jumlah, totalHarga, metodePembayaran, tanggalTransaksi});
            cout << "Total harga: " << fixed << setprecision(2) << totalHarga << endl;
            cout << "Transaksi berhasil!\n";
            return;
        }
    }

    if (!ditemukan) {
        cout << "Barang tidak ditemukan!\n";
    }
}

void laporanPenjualan() {
    if (riwayatTransaksi.empty()) {
        cout << "Belum ada transaksi!\n";
        return;
    }

    int pilihanFilter;
    cout << "\nPilih Laporan Penjualan Berdasarkan:\n";
    cout << "1. Harian\n";
    cout << "2. Bulanan\n";
    cout << "3. Tahunan\n";
    cout << "Pilih filter: ";
    cin >> pilihanFilter;

    int tanggalFilter = 0, bulanFilter = 0, tahunFilter = 0;

    if (pilihanFilter == 1) {
        cout << "Masukkan tanggal (1-31): ";
        cin >> tanggalFilter;
    } else if (pilihanFilter == 2) {
        cout << "Masukkan bulan (1-12): ";
        cin >> bulanFilter;
    } else if (pilihanFilter == 3) {
        cout << "Masukkan tahun (YYYY): ";
        cin >> tahunFilter;
    }

    cout << "\nLaporan Penjualan:\n";
    cout << left << setw(15) << "Nama Barang" << setw(10) << "Jumlah" << setw(15) << "Total Harga" << setw(20) << "Metode Pembayaran" << setw(20) << "Waktu" << endl;

    for (const auto& transaksi : riwayatTransaksi) {
        // Memisahkan tanggal, bulan, dan tahun dari waktu transaksi
        int t, b, y;
        sscanf(transaksi.waktu.c_str(), "%d/%d/%d", &t, &b, &y);

        bool tampilkan = false;
        if (pilihanFilter == 1 && t == tanggalFilter) {
            tampilkan = true;
        } else if (pilihanFilter == 2 && b == bulanFilter) {
            tampilkan = true;
        } else if (pilihanFilter == 3 && y == tahunFilter) {
            tampilkan = true;
        }

        if (tampilkan) {
            cout << left << setw(15) << transaksi.namaBarang
                << setw(10) << transaksi.jumlah
                << setw(15) << fixed << setprecision(2) << transaksi.totalHarga
                << setw(20) << transaksi.metodePembayaran
                << setw(20) << transaksi.waktu << endl;
        }
    }
}

void simpanTransaksiKeFile() {
    if (inventaris.empty()){
        eksporDataBarang();
    } else {
        ofstream file("transaksi.txt", ios::app); // Membuka file dalam mode append
        if (file.is_open()) {
            cout << "Gagal menyimpan file!\n";
            for (const auto& transaksi : riwayatTransaksi) {
                file << left << setw(15) << transaksi.namaBarang
                        << setw(10) << transaksi.jumlah
                        << setw(15) << fixed << setprecision(2) << transaksi.totalHarga
                        << setw(20) << transaksi.metodePembayaran
                        << setw(20) << transaksi.waktu << endl;
            }
            file.close();
            eksporDataBarang();
            cout << "Data transaksi berhasil disimpan ke file transaksi.txt!\n";
        } else {
            cout << "Gagal membuka file!\n";
        }
    }
    
}

void bacaDataDariFile() {
    ifstream file("data_barang.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file data_barang.txt!\n";
        return;
    }

    Barang barangBaru;
    while (file >> ws && getline(file, barangBaru.nama)) {
        file >> barangBaru.harga >> barangBaru.stok;
        file.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan sisa baris
        inventaris.push_back(barangBaru);
    }

    file.close();
    cout << "Data barang berhasil dimuat dari file data_barang.txt!\n";
}

int main() {
    bacaDataDariFile();
    char pilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Tampilkan Barang\n";
        cout << "3. Transaksi\n";
        cout << "4. Laporan Penjualan\n";
        cout << "5. Simpan Data Transaksi ke File\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case '1':
                tambahBarang();
                break;
            case '2':
                tampilkanBarang();
                break;
            case '3':
                transaksi();
                break;
            case '4':
                laporanPenjualan();
                break;
            case '5':
                simpanTransaksiKeFile();
                break;
            case '6':
                cout << "Keluar program. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 6);

    return 0;
}