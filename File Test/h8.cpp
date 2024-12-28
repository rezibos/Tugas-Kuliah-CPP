#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;

struct Barang {
    string nama;
    double harga;
    int stok;
};

struct Transaksi {
    vector<string> namaBarang;
    vector<int> jumlahBarang;
    vector<double> hargaBarang;
    double totalHarga;
    string metodePembayaran;
    string waktuTransaksi;
};

vector<Barang> inventaris;
vector<Transaksi> daftarTransaksi;

void tampilHeader(string judul) {
    system("cls");
    cout << "==============================\n";
    cout << "       " << judul << "\n";
    cout << "==============================\n";
}

string waktuSekarang() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char waktu[20];
    strftime(waktu, sizeof(waktu), "%Y-%m-%d %H:%M:%S", ltm);
    return string(waktu);
}

void tambahBarang() {
    tampilHeader("Tambah Barang");
    Barang baru;
    cout << "Nama Barang: ";
    cin.ignore();
    getline(cin, baru.nama);
    cout << "Harga Barang: ";
    cin >> baru.harga;
    cout << "Stok Barang: ";
    cin >> baru.stok;
    inventaris.push_back(baru);
    cout << "Barang berhasil ditambahkan!\n";
    system("pause");
}

void tampilkanBarang() {
    tampilHeader("Daftar Barang");
    if (inventaris.empty()) {
        cout << "Inventaris kosong. Tambahkan barang terlebih dahulu.\n";
    } else {
        cout << setw(5) << "No" 
             << setw(20) << "Nama Barang" 
             << setw(10) << "Harga" 
             << setw(10) << "Stok\n";
        cout << string(45, '-') << endl;
        for (size_t i = 0; i < inventaris.size(); i++) {
            cout << setw(5) << i + 1 
                 << setw(20) << inventaris[i].nama 
                 << setw(10) << fixed << setprecision(2) << inventaris[i].harga 
                 << setw(10) << inventaris[i].stok << endl;
        }
    }
    system("pause");
}

void transaksiPenjualan() {
    tampilHeader("Transaksi Penjualan");
    if (inventaris.empty()) {
        cout << "Tidak ada barang dalam inventaris.\n";
        system("pause");
        return;
    }

    Transaksi transaksi;
    double totalHarga = 0;
    int jumlahTotalBarang = 0;

    while (true) {
        tampilkanBarang();
        cout << "Pilih nomor barang (0 untuk selesai): ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 0) break;
        if (pilihan < 1 || pilihan > inventaris.size()) {
            cout << "Pilihan tidak valid.\n";
            continue;
        }

        Barang &barangDipilih = inventaris[pilihan - 1];

        if (barangDipilih.stok == 0) {
            cout << "Stok barang habis.\n";
            continue;
        }

        cout << "Jumlah yang ingin dibeli: ";
        int jumlah;
        cin >> jumlah;

        if (jumlah > barangDipilih.stok) {
            cout << "Stok tidak mencukupi.\n";
            continue;
        }

        transaksi.namaBarang.push_back(barangDipilih.nama);
        transaksi.hargaBarang.push_back(barangDipilih.harga);
        transaksi.jumlahBarang.push_back(jumlah);

        totalHarga += barangDipilih.harga * jumlah;
        jumlahTotalBarang += jumlah;
        barangDipilih.stok -= jumlah;
    }

    transaksi.totalHarga = totalHarga;
    transaksi.waktuTransaksi = waktuSekarang();

    cout << "\nPilih metode pembayaran:\n";
    cout << "1. Tunai\n2. Debit\n3. Scan\n4. Transfer\n";
    int metode;
    cin >> metode;
    if (metode == 1) transaksi.metodePembayaran = "Tunai";
    else if (metode == 2) transaksi.metodePembayaran = "Debit";
    else if (metode == 3) transaksi.metodePembayaran = "Scan";
    else transaksi.metodePembayaran = "Transfer";

    daftarTransaksi.push_back(transaksi);

    cout << "\n=== Rincian Transaksi ===\n";
    for (size_t i = 0; i < transaksi.namaBarang.size(); i++) {
        cout << "- " << transaksi.namaBarang[i] 
             << " x" << transaksi.jumlahBarang[i] 
             << " = Rp" << fixed << setprecision(2) 
             << transaksi.hargaBarang[i] * transaksi.jumlahBarang[i] << endl;
    }
    cout << "Total Harga: Rp" << fixed << setprecision(2) << totalHarga << endl;
    cout << "Metode Pembayaran: " << transaksi.metodePembayaran << endl;
    cout << "Waktu Transaksi: " << transaksi.waktuTransaksi << endl;

    system("pause");
}

void laporanPenjualan() {
    tampilHeader("Laporan Penjualan");
    if (daftarTransaksi.empty()) {
        cout << "Belum ada transaksi yang tercatat.\n";
    } else {
        for (size_t i = 0; i < daftarTransaksi.size(); i++) {
            cout << "Transaksi " << i + 1 << ":\n";
            for (size_t j = 0; j < daftarTransaksi[i].namaBarang.size(); j++) {
                cout << "- " << daftarTransaksi[i].namaBarang[j] 
                     << " x" << daftarTransaksi[i].jumlahBarang[j] 
                     << " = Rp" << fixed << setprecision(2) 
                     << daftarTransaksi[i].hargaBarang[j] * daftarTransaksi[i].jumlahBarang[j] << endl;
            }
            cout << "Total Harga: Rp" << daftarTransaksi[i].totalHarga << endl;
            cout << "Metode Pembayaran: " << daftarTransaksi[i].metodePembayaran << endl;
            cout << "Waktu Transaksi: " << daftarTransaksi[i].waktuTransaksi << endl;
            cout << string(40, '-') << endl;
        }
    }
    system("pause");
}

void simpanKeFile() {
    tampilHeader("Simpan Laporan ke File");
    ofstream file("laporan_penjualan_alternatif.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file.\n";
        system("pause");
        return;
    }

    for (const auto &transaksi : daftarTransaksi) {
        file << "Transaksi:\n";
        for (size_t j = 0; j < transaksi.namaBarang.size(); j++) {
            file << "- " << transaksi.namaBarang[j] 
                 << " x" << transaksi.jumlahBarang[j] 
                 << " = Rp" << fixed << setprecision(2) 
                 << transaksi.hargaBarang[j] * transaksi.jumlahBarang[j] << endl;
        }
        file << "Total Harga: Rp" << transaksi.totalHarga << endl;
        file << "Metode Pembayaran: " << transaksi.metodePembayaran << endl;
        file << "Waktu Transaksi: " << transaksi.waktuTransaksi << endl;
        file << string(40, '=') << endl;
    }
    cout << "Laporan berhasil disimpan ke file.\n";
    system("pause");
}

int main() {
    while (true) {
        tampilHeader("Program Kasir Alternatif");
        cout << "1. Tambah Barang\n";
        cout << "2. Tampilkan Barang\n";
        cout << "3. Transaksi Penjualan\n";
        cout << "4. Laporan Penjualan\n";
        cout << "5. Simpan Laporan ke File\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahBarang(); break;
            case 2: tampilkanBarang(); break;
            case 3: transaksiPenjualan(); break;
            case 4: laporanPenjualan(); break;
            case 5: simpanKeFile(); break;
            case 6: return 0;
            default: cout << "Pilihan tidak valid.\n"; system("pause");
        }
    }
}