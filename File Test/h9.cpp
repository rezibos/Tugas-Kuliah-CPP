#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

struct Barang {
    int id;
    string nama;
    double harga;
    int stok;
};

struct Transaksi {
    int idBarang;
    string namaBarang, metodePembayaran;
    double harga;
    int jumlah;
    double subtotal;
    int tanggal, bulan, tahun;
};

vector<Barang> daftarBarang;
vector<Transaksi> daftarTransaksi;

// Fungsi validasi input angka positif
int inputAngkaPositif(const string &angkaPositif) {
    int angka;
    do {
        cout << angkaPositif;
        cin >> angka;
        if (angka <= 0) {
            cout << "Input harus angka positif!\n";
        }
    } while (angka <= 0);
    return angka;
}

double inputHargaPositif(const string &hargaPositif) {
    double harga;
    do {
        cout << hargaPositif;
        cin >> harga;
        if (harga <= 0) {
            cout << "Harga harus positif!\n";
        }
    } while (harga <= 0);
    return harga;
}

// Fungsi untuk menampilkan menu utama
void tampilkanMenu() {
    cout << "===== Sistem Manajemen Kasir =====\n";
    cout << "1. Tambah Barang\n";
    cout << "2. Daftar Barang\n";
    cout << "3. Edit Barang\n";
    cout << "4. Hapus Barang\n";
    cout << "5. Transaksi\n";
    cout << "6. Laporan Penjualan\n";
    cout << "7. Simpan Data\n";
    cout << "8. Muat Data\n";
    cout << "9. Keluar\n";
    cout << "Pilihan Anda: ";
}

// Fungsi untuk menambah barang
void tambahBarang() {
    Barang barangBaru;

    cout << "Masukkan ID barang: ";
    cin >> barangBaru.id;

    // Validasi agar ID tidak duplikat
    auto it = find_if(daftarBarang.begin(), daftarBarang.end(),
        [&barangBaru](const Barang &barang) { return barang.id == barang.id; });
    if (it != daftarBarang.end()) {
        cout << "ID barang sudah ada!\n";
        return;
    }

    cout << "Masukkan nama barang: ";
    cin.ignore();
    getline(cin, barangBaru.nama);

    barangBaru.harga = inputHargaPositif("Masukkan harga barang: ");
    barangBaru.stok = inputAngkaPositif("Masukkan stok barang: ");

    daftarBarang.push_back(barangBaru);
    cout << "Barang berhasil ditambahkan!\n";
}

// Fungsi untuk melihat barang yang tersedia
void lihatBarang() {
    cout << "\n===== Daftar Barang =====\n";
    cout << setw(5) << "ID" << setw(20) << "Nama" << setw(15) << "Harga" << setw(10) << "Stok" << "\n";
    for (const auto &barang : daftarBarang) {
        cout << setw(5) << barang.id << setw(20) << barang.nama << setw(15) << barang.harga << setw(10) << barang.stok << "\n";
    }
}

void editBarang() {
    int id;
    cout << "Masukkan ID Barang yang ingin diedit: ";
    cin >> id;

    auto it = find_if(daftarBarang.begin(), daftarBarang.end(),
        [id](const Barang& barangEdit) { return barangEdit.id == id; });

    if (it != daftarBarang.end()) {
        cout << "Masukkan nama baru: ";
        cin.ignore();
        getline(cin, it->nama);
        cout << "Masukkan harga baru: ";
        cin >> it->harga;
        cout << "Masukkan stok baru: ";
        cin >> it->stok;
        cout << "Barang berhasil diedit!\n";
    } else {
        cout << "Barang dengan ID tersebut tidak ditemukan!\n";
    }
};

void hapusBarang() {
    int id;
    cout << "Masukkan ID Barang yang ingin dihapus: ";
    cin >> id;

    auto it = find_if(daftarBarang.begin(), daftarBarang.end(),
        [id](const Barang& barangHapus) { return barangHapus.id == id; });

    if (it != daftarBarang.end()) {
        daftarBarang.erase(it);
        cout << "Barang berhasil dihapus!\n";
    } else {
        cout << "Barang dengan ID tersebut tidak ditemukan!\n";
    }
}

// Fungsi untuk transaksi
void transaksi() {
    int id, jumlah, tanggal, bulan, tahun;
    double totalHarga = 0.0;
    string metodePembayaran;
    bool validInput = false;

    cout << "\n===== Transaksi =====\n";
    cout << "Masukkan tanggal transaksi (DD-MM-YYYY): ";
    cin >> tanggal >> bulan >> tahun;

    while (true) {
        cout << "Masukkan ID barang (0 untuk selesai): ";
        cin >> id;

        if (id == 0) {
            
        if (totalHarga == 0) {
            cout << "Tidak ada transaksi yang dilakukan. Keluar dari program.\n";
            return;
        }
        break;
    }

        if (id == 0) break;

        auto it = find_if(daftarBarang.begin(), daftarBarang.end(),
            [id](const Barang &barangDaftar) { return barangDaftar.id == id; });

        if (it != daftarBarang.end()) {
            cout << "Masukkan jumlah: ";
            cin >> jumlah;

            if (jumlah > 0 && jumlah <= it->stok) {
                it->stok -= jumlah;
                double subtotal = it->harga * jumlah;
                totalHarga += subtotal;
                cout << "Subtotal: " << subtotal << endl;

                Transaksi data;
                data.idBarang = it->id;
                data.namaBarang = it->nama;
                data.harga = it->harga;
                data.jumlah = jumlah;
                data.subtotal = subtotal;
                data.tanggal = tanggal;
                data.bulan = bulan;
                data.tahun = tahun;

                daftarTransaksi.push_back(data);

            } else {
                cout << "Jumlah tidak valid atau stok tidak cukup!\n";
            }
        } else {
            cout << "Barang tidak ditemukan!\n";
        }
    }

    while (!validInput) {
    cout << "Pilih metode pembayaran (cash/transfer): ";
    cin >> metodePembayaran;

    // Ubah input menjadi huruf kecil (jika ingin mempermudah validasi)
    transform(metodePembayaran.begin(), metodePembayaran.end(), metodePembayaran.begin(), ::tolower);

    // Cek apakah input valid
    if (metodePembayaran == "cash" || metodePembayaran == "transfer") {
        validInput = true; // Input valid, keluar dari loop
    } else {
        cout << "Metode pembayaran tidak valid! Harap masukkan 'cash' atau 'transfer'.\n";
    }

    for (auto &transaksi : daftarTransaksi) {
        transaksi.metodePembayaran = metodePembayaran;
    }

    cout << "Total harga: " << totalHarga << "\n";
}
}

// Fungsi untuk laporan
void laporan() {
    if (daftarTransaksi.empty())
    {
        cout << "\n===== Laporan Penjualan =====\n";
        cout << "Tidak ada transaksi yang tersedia untuk ditampilkan!\n";
        return; 
    }
    

    int pilihan;
    cout << "\n===== Laporan Penjualan =====\n";
    cout << "1. Harian\n";
    cout << "2. Bulanan\n";
    cout << "3. Tahunan\n";
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1: {
            int tanggal, bulan, tahun;
            cout << "Masukkan tanggal (DD-MM-YYYY): ";
            cin >> tanggal >> bulan >> tahun;
            cout << "\nLaporan Penjualan Harian:\n";
            for (const auto &transaksi : daftarTransaksi) {
                if (transaksi.tanggal == tanggal && transaksi.bulan == bulan && transaksi.tahun == tahun) {
                    cout << "ID Barang: " << transaksi.idBarang
                         << " | Nama: " << transaksi.namaBarang
                         << " | Harga: " << transaksi.harga
                         << " | Jumlah: " << transaksi.jumlah
                         << " | Subtotal: " << transaksi.subtotal << "\n";
                }
            }
            break;
        }
        case 2: {
            int bulan, tahun;
            cout << "Masukkan bulan dan tahun (MM-YYYY): ";
            cin >> bulan >> tahun;
            cout << "\nLaporan Penjualan Bulanan:\n";
            for (const auto &transaksi : daftarTransaksi) {
                if (transaksi.bulan == bulan && transaksi.tahun == tahun) {
                    cout << "ID Barang: " << transaksi.idBarang
                         << " | Nama: " << transaksi.namaBarang
                         << " | Harga: " << transaksi.harga
                         << " | Jumlah: " << transaksi.jumlah
                         << " | Subtotal: " << transaksi.subtotal << "\n";
                }
            }
            break;
        }
        case 3: {
            int tahun;
            cout << "Masukkan tahun (YYYY): ";
            cin >> tahun;
            cout << "\nLaporan Penjualan Tahunan:\n";
            for (const auto &transaksi : daftarTransaksi) {
                if (transaksi.tahun == tahun) {
                    cout << "ID Barang: " << transaksi.idBarang
                         << " | Nama: " << transaksi.namaBarang
                         << " | Harga: " << transaksi.harga
                         << " | Jumlah: " << transaksi.jumlah
                         << " | Subtotal: " << transaksi.subtotal << "\n";
                }
            }
            break;
        }
        default:
            cout << "Pilihan tidak valid!\n";
    }
}

void simpanDataBarang() {
    ofstream file("data_barang.txt");
    for (const auto &barang : daftarBarang) {
        file << barang.id << " " << barang.nama << " " << barang.harga << " " << barang.stok << "\n";
    }
    file.close();
    cout << "Data barang berhasil disimpan!\n";
}

void simpanDataTransaksi() {
    ofstream file("data_transaksi.txt");
    for (const auto &transaksi : daftarTransaksi) {
        file << transaksi.idBarang << " " << transaksi.namaBarang << " " << transaksi.harga << " "
             << transaksi.jumlah << " " << transaksi.subtotal << " " << transaksi.tanggal << " "
             << transaksi.bulan << " " << transaksi.tahun << " " << transaksi.metodePembayaran << "\n";
    }
    file.close();
    cout << "Data transaksi berhasil disimpan!\n";
}

void muatDataBarang() {
    ifstream file("data_barang.txt");
    if (file.is_open()) {
        daftarBarang.clear();
        Barang muat;
        while (file >> muat.id >> muat.nama >> muat.harga >> muat.stok) {
            daftarBarang.push_back(muat);
        }
        file.close();
        cout << "Data barang berhasil dimuat!\n";
    } else {
        cout << "File data_barang.txt tidak ditemukan!\n";
    }
}

// Fungsi untuk memuat data transaksi dari file
void muatDataTransaksi() {
    ifstream file("data_transaksi.txt");
    if (file.is_open()) {
        daftarTransaksi.clear();
        Transaksi temp;
        while (file >> temp.idBarang >> temp.namaBarang >> temp.harga >> temp.jumlah >> temp.subtotal
                    >> temp.tanggal >> temp.bulan >> temp.tahun >> temp.metodePembayaran) {
            daftarTransaksi.push_back(temp);
        }
        file.close();
        cout << "Data transaksi berhasil dimuat!\n";
    } else {
        cout << "File data_transaksi.txt tidak ditemukan!\n";
    }
}

int main() {
    char pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case '1':
                tambahBarang();
                break;
            case '2':
                lihatBarang();
                break;
            case '3':
                editBarang();
                break;
            case '4':
                hapusBarang();
                break;
            case '5':
                transaksi();
                break;
            case '6':
                laporan();
                break;
            case '7':
                simpanDataBarang();
                simpanDataTransaksi();
                break;
            case '8':
                muatDataBarang();
                muatDataTransaksi();
                break;
            case '9':
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != '9');

    return 0;
}