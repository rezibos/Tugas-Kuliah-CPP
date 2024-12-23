#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

struct Item {
    string nama;
    double harga;
    int stok;
};

struct Transaksi {
    vector<Item> barang;
    double total;
    string metodePembayaran;
    string waktu;
};

vector<Item> inventaris;
vector<Transaksi> penjualan;

void tambahBarang() {
    Item barang;
    cout << "Masukkan nama barang: ";
    cin >> barang.nama;
    cout << "Masukkan harga barang: ";
    cin >> barang.harga;
    cout << "Masukkan stok barang: ";
    cin >> barang.stok;
    inventaris.push_back(barang);
    cout << "Barang berhasil ditambahkan!\n";
}

void tampilkanInventaris() {
    cout << left << setw(15) << "Nama" << setw(10) << "Harga" << "Stok\n";
    cout << "-------------------------------------\n";
    for (const auto &barang : inventaris) {
        cout << left << setw(15) << barang.nama << setw(10) << barang.harga << barang.stok << "\n";
    }
}

void tampilkanMetodePembayaran() {
    cout << "Metode pembayaran yang tersedia:\n";
    cout << "1. Tunai\n2. Kartu Kredit\n3. Dompet Digital\n";
}

string dapatkanWaktuSekarang() {
    time_t sekarang = time(0);
    tm *ltm = localtime(&sekarang);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
    return string(buffer);
}

void prosesTransaksi() {
    Transaksi transaksi;
    double total = 0;
    while (true) {
        string namaBarang;
        int jumlah;
        cout << "Masukkan nama barang (atau 'selesai' untuk mengakhiri): ";
        cin >> namaBarang;
        if (namaBarang == "selesai") break;
        
        bool ditemukan = false;
        for (auto &barang : inventaris) {
            if (barang.nama == namaBarang) {
                ditemukan = true;
                cout << "Masukkan jumlah: ";
                cin >> jumlah;
                if (jumlah > barang.stok) {
                    cout << "Stok tidak mencukupi.\n";
                } else {
                    barang.stok -= jumlah;
                    Item barangTerjual = barang;
                    barangTerjual.stok = jumlah;
                    transaksi.barang.push_back(barangTerjual);
                    total += barangTerjual.harga * jumlah;
                }
                break;
            }
        }
        if (!ditemukan) cout << "Barang tidak ditemukan.\n";
    }

    cout << "Pilih metode pembayaran:\n";
    tampilkanMetodePembayaran();
    int pilihan;
    cin >> pilihan;
    switch (pilihan) {
        case 1: transaksi.metodePembayaran = "Tunai"; 
                break;
        case 2: transaksi.metodePembayaran = "Kartu Kredit"; 
                break;
        case 3: transaksi.metodePembayaran = "Dompet Digital"; 
                break;
        default: transaksi.metodePembayaran = "Tidak Diketahui"; 
                break;
    }

    transaksi.total = total;
    transaksi.waktu = dapatkanWaktuSekarang();
    penjualan.push_back(transaksi);

    cout << "Transaksi selesai!\n";
    cout << "Total: " << total << "\nMetode Pembayaran: " << transaksi.metodePembayaran << "\n";
}

void buatLaporan(string jenis) {
    cout << "Laporan Penjualan - " << jenis << "\n";
    cout << left << setw(25) << "Waktu" << setw(10) << "Total" << "Metode Pembayaran\n";
    cout << "---------------------------------------------\n";
    for (const auto &transaksi : penjualan) {
        cout << left << setw(25) << transaksi.waktu << setw(10) << transaksi.total << transaksi.metodePembayaran << "\n";
    }
}

void simpanTransaksiKeFile() {
    ofstream file("transaksi.txt");
    if (!file) {
        cout << "Gagal menyimpan transaksi.\n";
        return;
    }
    for (const auto &transaksi : penjualan) {
        file << transaksi.waktu << "\t" << transaksi.total << "\t" << transaksi.metodePembayaran << "\t" << "\n";
    }
    file.close();
    cout << "Transaksi berhasil disimpan ke file.\n";
}

int main() {
    int pilihan;
    do{
        cout << "====================================\n";
        cout << "\nAplikasi Kasir Suka Maju Bersama\n";
        cout << "====================================\n";
        cout << "1. Tambah Barang Baru\n";
        cout << "2. Tampilkan Semua Barang\n";
        cout << "3. Proses Transaksi\n";
        cout << "4. Tampilkan Metode Pembayaran\n";
        cout << "5. Buat Laporan Penjualan\n";
        cout << "6. Simpan Transaksi ke File\n";
        cout << "7. Keluar\n";
        cout << "====================================\n";
        cout << "Masukkan pilihan Anda : ";
        cin >> pilihan;
        cout << "====================================\n";

        switch (pilihan) {
            case 1: tambahBarang(); 
                    break;
            case 2: tampilkanInventaris(); 
                    break;
            case 3: prosesTransaksi(); 
                    break;
            case 4: tampilkanMetodePembayaran(); 
                    break;
            case 5: buatLaporan("Semua"); 
                    break;
            case 6: simpanTransaksiKeFile(); 
                    break;
            case 7: cout << "Anda Keluar Dari Program\n";
                    return 0;
            default: cout << "Pilihan tidak valid. Coba lagi.\n";
                    break;
        }
    } while (pilihan != 7);

    return 0;
}
