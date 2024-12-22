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

const int MAX = 100;
Item inventaris[MAX];

int jumlah_barang = 0;

void tambahBarang() {
    char pilihan;

    do {
        if (jumlah_barang >= MAX) {
            cout << "Data Penuh! Tidak dapat menambahkan barang baru.\n";
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
            cout << "====================================\n";
            cout << "Barang ditemukan : \n";
            cout << "Nama Barang  : " << inventaris[i].nama_barang << "\n";
            cout << "Harga Barang : " << inventaris[i].harga_barang << "\n";
            cout << "Stok Barang  : " << inventaris[i].stok_barang << "\n";
            cout << "====================================\n";

            cout << "Masukkan Nama Barang : ";
            cin >> inventaris[i].stok_barang;
            cout << "Masukkan Harga Barang : ";
            cin >> inventaris[i].harga_barang;
            cout << "Masukkan Stok Barang : ";
            cin >> inventaris[i].stok_barang;
            cout << "====================================\n";

            cout << "\nBarang berhasil diperbarui!\n";
            return;
        }
    }
    
    cout << "ID Barang tidak ditemukan.\n";
    
}

void hapusBarang(){
    string id_barang;

    cout << "====================================\n";
    cout << "             Hapus Barang           \n";
    cout << "====================================\n";

    cout << "Masukkan ID Barang yang ingin dihapus: ";
    cin >> id_barang;

    for (int i = 0; i < jumlah_barang; i++) {
        if (inventaris[i].id_barang == id_barang) {
            cout << "Barang dengan ID " << id_barang << " ditemukan dan akan dihapus.\n";

            for (int j = i; j < jumlah_barang - 1; j++) {
                inventaris[j] = inventaris[j + 1];
            }

            jumlah_barang--;
            cout << "Barang berhasil dihapus!\n";
            return;
        }
    }

    cout << "ID Barang tidak ditemukan.\n";

}

void tampilkanSemuaBarang(){
    if (jumlah_barang == 0) {
        cout << "====================================\n";
        cout << "         Tidak Ada Barang           \n";
        cout << "====================================\n";
        return;
    } else {
        cout << "==========================================================================\n";
        cout << "| " << setw(12) << left << "ID Barang" << " | "
                << setw(18) << left << "Nama Barang" << " | "
                << setw(15) << left << "Harga Barang" << " | "
                << setw(14) << left << "Stok Barang" << " |\n";
        cout << "==========================================================================\n";

        for (int i = 0; i < jumlah_barang; i++) {
            cout << "| " << setw(12) << left << inventaris[i].id_barang << " | "
                    << setw(18) << left << inventaris[i].nama_barang << " | "
                    << setw(15) << left << inventaris[i].harga_barang << " | "
                    << setw(14) << left << inventaris[i].stok_barang << " |\n";
            cout << "==========================================================================\n";
        }
    }
}

void TampilkanMetodePembayaran(){
    cout << "====================================\n";
    cout << "Metode pembayaran yang tersedia:\n";
    cout << "1. Tunai\n2. Kartu Kredit\n3. Dompet Digital\n";
    cout << "====================================\n";
}

void ProsesTransaksi(){
    cout << "" << endl;
}

void BuatLaporanPenjualan(){
    cout << "" << endl;
}


void SimpanTransaksikeFile(){
    cout << "" << endl;
}

void laporanTransaksi(){
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
        cout << "5. Tampilkan Metode Pembayaran\n";
        cout << "6. Proses Transaksi\n";
        cout << "7. Buat Laporan Penjualan\n";
        cout << "8. Simpan Transaksi ke File\n";
        cout << "9. Tampil Semua Laporan Transaksi\n";
        cout << "0. Keluar\n";
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
            case '5': TampilkanMetodePembayaran();
                    break;
            case '6': ProsesTransaksi();
                    break;
            case '7': BuatLaporanPenjualan(); 
                    break;
            case '8': SimpanTransaksikeFile(); 
                    break;
            case '9': laporanTransaksi();
                    break;
            case '0': break;
            default: cout << "Pilihan tidak valid. Coba lagi.\n";
                    break;
        }

    } while (pilihan != '0');

    cout << "====================================\n";
    cout << "Anda Keluar Dari Program\n";
    cout << "====================================\n";
}
