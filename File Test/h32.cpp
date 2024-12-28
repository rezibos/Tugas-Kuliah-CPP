#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <limits>
#include <sstream>

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
    cout << "Masukkan nama barang\t: ";
    getline(cin, barangBaru.nama);
    
    for (const auto & barang : inventaris) {
        if (barang.nama == barangBaru.nama) {
            cout << "Barang dengan nama tersebut sudah ada!\n";
            return;
        }
    }

    cout << "Masukkan harga barang\t: ";
    cin >> barangBaru.harga;
    if (barangBaru.harga < 0) {
        cout << "Harga tidak boleh negatif!\n";
        return;
    }

    cout << "Masukkan stok barang\t: ";
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

    // Menentukan lebar kolom
    const int namWidth = 25;  // Diperlebar untuk nama barang
    const int hargaWidth = 20; // Diperlebar untuk harga
    const int stokWidth = 15;  // Diperlebar untuk stok
    const int totalWidth = namWidth + hargaWidth + stokWidth + 8; // +8 untuk border dan spacing

    // Header tabel
    cout << "\nDaftar Barang:\n";
    cout << "+" << string(namWidth + 2, '-') 
         << "+" << string(hargaWidth + 2, '-')
         << "+" << string(stokWidth + 2, '-') 
         << "+" << endl;
    
    // Header kolom
    cout << "| " << left << setw(namWidth) << "Nama Barang"
         << " | " << setw(hargaWidth) << "Harga (Rp)"
         << " | " << setw(stokWidth) << "Stok"
         << " |" << endl;
    
    cout << "+" << string(namWidth + 2, '-') 
         << "+" << string(hargaWidth + 2, '-')
         << "+" << string(stokWidth + 2, '-') 
         << "+" << endl;

    // Isi tabel
    for (const auto& barang : inventaris) {
        cout << "| " << left << setw(namWidth) << barang.nama
             << " | " << left << setw(hargaWidth) << fixed << setprecision(2) << barang.harga
             << " | " << left << setw(stokWidth) << barang.stok 
             << " |" << endl;
    }

    // Footer tabel
    cout << "+" << string(namWidth + 2, '-') 
         << "+" << string(hargaWidth + 2, '-')
         << "+" << string(stokWidth + 2, '-') 
         << "+" << endl;

    // Menghitung total
    int totalJenis = inventaris.size();
    int totalStok = 0;
    double totalNilai = 0;

    for (const auto& barang : inventaris) {
        totalStok += barang.stok;
        totalNilai += (barang.harga * barang.stok);
    }

    // Menampilkan ringkasan dengan format yang lebih rapi
    const int summaryWidth = 50;
    cout << "\nRingkasan Inventaris:\n";
    cout << string(summaryWidth, '-') << endl;
    cout << left << setw(25) << "Total Jenis Barang" << ": " << totalJenis << endl;
    cout << left << setw(25) << "Total Stok Barang" << ": " << totalStok << endl;
    cout << left << setw(25) << "Total Nilai Barang" << ": Rp " << fixed << setprecision(2) << totalNilai << endl;
    cout << string(summaryWidth, '-') << endl;
}

void eksporDataBarang() {
    if(inventaris.empty()){
        cout << "Tidak dapat mengekspor karena inventaris kosong\n";
        return;
    }

    ofstream file("data_barang.txt");
    try {
        for (const auto& barang : inventaris) {
            file << left << setw(25) << barang.nama << left << setw(25) << barang.harga << left << setw(25) << barang.stok << "\n";
            
            if (file.fail()) {
                throw runtime_error("Gagal menulis ke file");
            }
        }
        
        file.close();
        if (file.fail()) {
            throw runtime_error("Gagal menutup file");
        }
        
        cout << "Data barang berhasil diekspor ke file data_barang.txt!\n";
    }
    catch (const exception& e) {
        cout << "Error saat mengekspor data\t: " << e.what() << endl;
        file.close();
    }
}

void transaksi() {
    if (inventaris.empty()) {
        cout << "Inventaris kosong!\n";
        return;
    }

    string namaBarang;
    int jumlah;
    cin.ignore(); // Menghindari sisa input
    cout << "Masukkan nama barang\t: ";
    getline(cin, namaBarang);

    bool ditemukan = false;
    for (auto& barang : inventaris) {
        if (barang.nama == namaBarang) {
            ditemukan = true;
            cout << "Masukkan jumlah\t\t: ";
            cin >> jumlah;

            // Cek apakah jumlah yang diminta melebihi stok
            if (jumlah > barang.stok) {
                cout << "Stok tidak mencukupi!\n";
                return;
            }

            // Cek apakah jumlah yang dimasukkan valid (lebih dari 0)
            if (jumlah <= 0) {
                cout << "Jumlah harus lebih dari 0!\n";
                return;
            }

            double totalHarga = jumlah * barang.harga;
            string metodePembayaran;
            cout << "Pilih metode pembayaran (cash/kartu)\t: ";
            cin >> metodePembayaran;

            // Cek apakah metode pembayaran valid
            if (metodePembayaran != "cash" && metodePembayaran != "kartu") {
                cout << "Metode pembayaran tidak valid!\n";
                return;
            }

            // Input manual tanggal, bulan, dan tahun transaksi
            int tanggal, bulan, tahun;
            cout << "Masukkan tanggal (1-31)\t: ";
            cin >> tanggal;
            cout << "Masukkan bulan (1-12)\t: ";
            cin >> bulan;
            cout << "Masukkan tahun\t\t: ";
            cin >> tahun;

            // Validasi input tanggal, bulan, dan tahun (untuk kesederhanaan, validasi sangat dasar)
            if (tanggal < 1 || tanggal > 31 || bulan < 1 || bulan > 12 || tahun < 1000) {
                cout << "Input tanggal, bulan, atau tahun tidak valid!\n";
                return;
            }

            // Format tanggal transaksi menjadi string "DD/MM/YYYY"
            string tanggalTransaksi = to_string(tanggal) + "/" + to_string(bulan) + "/" + to_string(tahun);

            // Jika semua input valid, baru kurangi stok dan simpan transaksi
            barang.stok -= jumlah;

            // Simpan transaksi ke dalam riwayat transaksi
            riwayatTransaksi.push_back({namaBarang, jumlah, totalHarga, metodePembayaran, tanggalTransaksi});
            cout << "Total harga\t\t: " << fixed << setprecision(2) << totalHarga << endl;
            cout << "Transaksi berhasil!\n";
            return;
        }
    }

    if (!ditemukan) {
        cout << "Barang tidak ditemukan!\n";
    }
}

void laporanPenjualan() {
    // Baca data dari file terlebih dahulu
    ifstream file("transaksi.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file transaksi.txt!\n";
        return;
    }

    // Tampung data dari file ke vector temporary
    vector<Transaksi> dataTransaksi;
    string line;
    Transaksi temp;
    
    // Baca data dari file
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> temp.namaBarang;
        ss >> temp.jumlah;
        ss >> temp.totalHarga;
        ss >> temp.metodePembayaran;
        ss >> temp.waktu;
        dataTransaksi.push_back(temp);
    }
    file.close();

    if (dataTransaksi.empty() && riwayatTransaksi.empty()) {
        cout << "Belum ada transaksi!\n";
        return;
    }

    // Gabungkan data dari file dengan data di memori
    for (const auto& trans : riwayatTransaksi) {
        dataTransaksi.push_back(trans);
    }

    int pilihanFilter;
    cout << "\nPilih Laporan Penjualan Berdasarkan\n" <<endl;
    cout << "1. Harian\n";
    cout << "2. Bulanan\n";
    cout << "3. Tahunan\n";
    cout << "4. Semua Transaksi\n";
    cout << "Pilih Menu\t: ";
    cin >> pilihanFilter;

    if (pilihanFilter < 1 || pilihanFilter > 4) {
        cout << "Pilihan tidak valid!\n";
        return;
    }

    int tanggalFilter = 0, bulanFilter = 0, tahunFilter = 0;
    double totalPendapatan = 0;
    int totalTransaksi = 0;

    if (pilihanFilter == 1) {
        cout << "Masukkan tanggal (1-31)\t: ";
        cin >> tanggalFilter;
        if (tanggalFilter < 1 || tanggalFilter > 31) {
            cout << "Tanggal tidak valid!\n";
            return;
        }
    } else if (pilihanFilter == 2) {
        cout << "Masukkan bulan (1-12)\t: ";
        cin >> bulanFilter;
        if (bulanFilter < 1 || bulanFilter > 12) {
            cout << "Bulan tidak valid!\n";
            return;
        }
    } else if (pilihanFilter == 3) {
        cout << "Masukkan tahun (YYYY)\t: ";
        cin >> tahunFilter;
        if (tahunFilter < 1000) {
            cout << "Tahun tidak valid!\n";
            return;
        }
    }

    cout << "\nLaporan Penjualan:\n";
    cout << string(80, '=') << endl;
    cout << left << setw(15) << "Nama Barang" 
         << setw(10) << "Jumlah" 
         << setw(15) << "Total Harga" 
         << setw(20) << "Metode Pembayaran" 
         << setw(20) << "Waktu" << endl;
    cout << string(80, '-') << endl;

    for (const auto& transaksi : dataTransaksi) {
        int t, b, y;
        sscanf(transaksi.waktu.c_str(), "%d/%d/%d", &t, &b, &y);

        bool tampilkan = false;
        if (pilihanFilter == 1 && t == tanggalFilter) {
            tampilkan = true;
        } else if (pilihanFilter == 2 && b == bulanFilter) {
            tampilkan = true;
        } else if (pilihanFilter == 3 && y == tahunFilter) {
            tampilkan = true;
        } else if (pilihanFilter == 4) {
            tampilkan = true;
        }

        if (tampilkan) {
            cout << left << setw(15) << transaksi.namaBarang
                 << setw(10) << transaksi.jumlah
                 << setw(15) << fixed << setprecision(2) << transaksi.totalHarga
                 << setw(20) << transaksi.metodePembayaran
                 << setw(20) << transaksi.waktu << endl;
            
            totalPendapatan += transaksi.totalHarga;
            totalTransaksi++;
        }
    }

    cout << string(80, '=') << endl;
    cout << "Total Transaksi\t: " << totalTransaksi << endl;
    cout << "Total Pendapatan\t: Rp " << fixed << setprecision(2) << totalPendapatan << endl;
}

void simpanTransaksiKeFile() {
    if (inventaris.empty()) {
        cout << "Tidak ada data untuk disimpan karena inventaris kosong\n";
        return;
    }

    if (riwayatTransaksi.empty()) {
        cout << "Tidak ada transaksi untuk disimpan\n";
        return;
    }

    ofstream file("transaksi.txt", ios::app); // Membuka file dalam mode append
    if (!file.is_open()) {
        cout << "Gagal membuka file untuk menyimpan transaksi!\n";
        return;
    }

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
}

void bacaDataDariFile() {
    ifstream file("data_barang.txt");
    Barang barangBaru;
    while (file >> ws && getline(file, barangBaru.nama)) {
        file >> barangBaru.harga >> barangBaru.stok;
        file.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan sisa baris
        inventaris.push_back(barangBaru);
    }
    file.close();

}

int main() {
    bacaDataDariFile();
    char pilihan;
    do {
        cout << "--------------------------------------------------" << endl;
        cout << "             MENU SISTEM KASIR                  \n";
        cout << "--------------------------------------------------" << endl;
        cout << "1. Tambah Barang\n";
        cout << "2. Tampilkan Barang\n";
        cout << "3. Transaksi\n";
        cout << "4. Laporan Penjualan\n";
        cout << "5. Simpan Data Transaksi ke File\n";
        cout << "6. Keluar\n";
        cout << "--------------------------------------------------" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;
        cout << "--------------------------------------------------" << endl;

        switch (pilihan) {
            case '1':
                tambahBarang();
                cout << "--------------------------------------------------" << endl;
                break;
            case '2':
                tampilkanBarang();
                break;
            case '3':
                transaksi();
                cout << "--------------------------------------------------" << endl;
                break;
            case '4':
                laporanPenjualan();
                cout << "--------------------------------------------------" << endl;
                break;
            case '5':
                simpanTransaksiKeFile();
                cout << "--------------------------------------------------" << endl;
                break;
            case '6':
                cout << "Keluar program. Terima kasih!\n";
                cout << "--------------------------------------------------" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != '6');

    return 0;
}