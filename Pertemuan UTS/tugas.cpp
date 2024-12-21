#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

struct Item {
    string id_barang;
    string nama_barang;
    string harga_barang;
    string stok_barang;
};

const int MAX_INVENTARIS = 100;
Item inventaris[MAX_INVENTARIS];

int jumlah_barang = 0;

void tambahBarang() {
    char pilihan;

    do {
        if (jumlah_barang >= MAX_INVENTARIS) {
            cout << "Inventaris penuh! Tidak dapat menambahkan barang baru.\n";
            return;
        } else {
                cout << "====================================\n";
                cout << "            Tambah Barang           \n";
                cout << "====================================\n";

                cout << "Masukkan ID Barang : ";
                cin >> inventaris[jumlah_barang].id_barang;
                cout << "Masukkan Nama Barang : ";
                cin >> inventaris[jumlah_barang].nama_barang;
                cout << "Masukkan Harga Barang : ";
                cin >> inventaris[jumlah_barang].harga_barang;
                cout << "Masukkan Stok Barang : ";
                cin >> inventaris[jumlah_barang].stok_barang;
                jumlah_barang++;

                cout << "\nBarang Berhasil Ditambahkan!\n";
        }
        
        cout << "====================================\n";
        cout << "Apakah Anda Ingin Menambahkan Barang Lagi (y/n) : ";
        cin >> pilihan;

    } while (pilihan == 'Y' || pilihan == 'y');

}

void editBarang() {
    string id_barang;

    cout << "====================================\n";
    cout << "             Edit Barang            \n";
    cout << "====================================\n";

    cout << "Masukkan ID Barang yang ingin diubah: ";
    cin >> id_barang;

    for (int i = 0; i < jumlah_barang; i++) {
        if (inventaris[i].id_barang == id_barang) {
            cout << "Barang ditemukan : \n";
            cout << "Nama Barang  : " << inventaris[i].nama_barang << "\n";
            cout << "Harga Barang : " << inventaris[i].harga_barang << "\n";
            cout << "Stok Barang  : " << inventaris[i].stok_barang << "\n";
            cout << "====================================\n";

            cout << "Masukkan Nama Barang : ";
            cin >> inventaris[i].stok_barang;
            cout << "Masukkan jumlah stok baru : ";
            cin >> inventaris[i].stok_barang;
            cout << "Masukkan jumlah stok baru : ";
            cin >> inventaris[i].stok_barang;
            cout << "Masukkan jumlah stok baru : ";
            cin >> inventaris[i].stok_barang;

            cout << "\nStok barang berhasil diperbarui!\n";
            return;
        }
    }
    
    cout << "ID Barang tidak ditemukan.\n";
    
}

void hapusBarang(){
    
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
    char pilihan;

    do{
        cout << "====================================\n";
        cout << "  Aplikasi Kasir Suka Maju Bersama  \n";
        cout << "====================================\n";
        cout << "1. Tambah Barang \n";
        cout << "2. Edit Barang \n";
        cout << "3. Hapus Barang \n";
        cout << "4. Tampilkan Semua Barang\n";
        cout << "5. Proses Transaksi\n";
        cout << "6. Tampilkan Metode Pembayaran\n";
        cout << "7. Buat Laporan Penjualan\n";
        cout << "8. Simpan Transaksi ke File\n";
        cout << "9. Keluar\n";
        cout << "====================================\n";
        cout << "Masukkan pilihan Anda : ";
        cin >> pilihan;

        switch (pilihan) {
            case '1': tambahBarang(); 
                    break;
            case '2': editBarang();
                    break;
            case '3': hapusBarang();
                    break;
            case '4': tampilkanSemuaBarang(); 
                    break;
            case '5': ProsesTransaksi(); 
                    break;
            case '6': TampilkanMetodePembayaran(); 
                    break;
            case '7': BuatLaporanPenjualan(); 
                    break;
            case '8': SimpanTransaksikeFile(); 
                    break;
            case '9': break;
                    break;
            default: cout << "Pilihan tidak valid. Coba lagi.\n";
                    break;
        }

    } while (pilihan != 9);

    cout << "====================================\n";
    cout << "Anda Keluar Dari Program\n";
    cout << "====================================\n";
}
