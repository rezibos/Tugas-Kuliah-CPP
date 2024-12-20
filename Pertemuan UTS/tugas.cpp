#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

struct Item {
    string id_barang;
    string nama_barang;
    double harga_barang;
    string stok_barang;
};

vector<Item> inventaris;

void tambahBarang(){
    Item barang;
    char pilihan;

    do{

        cout << "====================================\n";
        cout << "Masukkan ID Barang : ";
        cin >> barang.id_barang;
        cout << "Masukkan Nama Barang : ";
        cin >> barang.nama_barang;
        cout << "Masukkan Harga Barang : ";
        cin >> barang.harga_barang;
        cout << "Masukkan Stok Barang : ";
        cin >> barang.stok_barang;

        cout << "\n";
        inventaris.push_back(barang);
        cout << "Barang Berhasil Ditambahkan !\n";

        cout << "====================================\n";
        cout << "Apakah Anda Ingin Menambahkan Barang (y/n) : ";
        cin >> pilihan;
        cout << "====================================\n";

    } while (pilihan == 'Y' || pilihan == 'y');
    
}

void tampilkanSemuaBarang(){
    cout << "" << endl;
}

void ProsesTransaksi(){
    cout << "" << endl;
}

void TampilkanMetodePembayaran(){
    cout << "" << endl;
}

void BuatLaporanPenjualan(){
    cout << "" << endl;
}


void SimpanTransaksikeFile(){
    cout << "" << endl;
}

int main()
{
    int pilihan;

    do{
        cout << "====================================\n";
        cout << "  Aplikasi Kasir Suka Maju Bersama  \n";
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

        switch (pilihan) {
            case 1: tambahBarang(); 
                    break;
            case 2: tampilkanSemuaBarang(); 
                    break;
            case 3: ProsesTransaksi(); 
                    break;
            case 4: TampilkanMetodePembayaran(); 
                    break;
            case 5: BuatLaporanPenjualan(); 
                    break;
            case 6: SimpanTransaksikeFile(); 
                    break;
            case 7: return 0;
                    break;
            default: cout << "Pilihan tidak valid. Coba lagi.\n";
                    break;
        }

    } while (pilihan != 7);

    cout << "Anda Keluar Dari Program\n";
}
