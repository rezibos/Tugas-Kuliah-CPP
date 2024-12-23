#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

const int MAX = 100;

struct Item {
    string id_barang;
    string nama_barang;
    double harga_barang;
    int stok_barang;
};

struct Transaksi {
    Item barang[MAX];
    int jumlah_barang;
    double total;
    string metodePembayaran;
    string waktu;
};

Item inventaris[MAX];
Transaksi penjualan[MAX];
int jumlah_barang = 0;
int jumlah_transaksi = 0;

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
    cout << "   Metode pembayaran yang tersedia  \n";
    cout << "====================================\n";
    cout << "1. Tunai\n";
    cout << "2. Kartu Kredit\n";
    cout << "3. Dompet Digital\n";
}

string dapatkanWaktuSekarang() {
    time_t sekarang = time(0);
    tm *ltm = localtime(&sekarang);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", ltm);
    return string(buffer);
}

void ProsesTransaksi(){
    string namaBarang;
    int jumlah;
    int pilihan;
    Transaksi transaksi;
    double total = 0;

    string barang_belian[MAX];
    int jumlah_belian[MAX];

    if (jumlah_barang == 0) {
        cout << "====================================\n";
        cout << "         Tidak Ada Barang           \n";
        return;
    } else {
        cout << "====================================\n";
        cout << "            Proses Transaksi        \n";
        cout << "====================================\n";

        while (true) {
            cout << "Masukkan nama barang (atau 'selesai / keluar / 0' untuk mengakhiri): ";
            cin >> namaBarang;

            if (namaBarang == "selesai" || namaBarang == "keluar" || namaBarang == "0"){
                break;
            }

            bool ada_tidak = false;

            for (int i = 0; i < jumlah_barang; i++) {
                if (inventaris[i].nama_barang == namaBarang) {
                    
                    ada_tidak = true;

                    cout << "Masukkan jumlah : ";
                    cin >> jumlah;

                    if (jumlah > inventaris[i].stok_barang) {
                        cout << "Stok tidak mencukupi \n";
                    } else {
                        inventaris[i].stok_barang = inventaris[i].stok_barang - jumlah;
                        Item barangTerjual = inventaris[i];
                        barangTerjual.stok_barang = jumlah; 
                        transaksi.barang[transaksi.jumlah_barang++] = barangTerjual;
                        total += barangTerjual.harga_barang * jumlah;
                        barang_belian[transaksi.jumlah_barang - 1] = inventaris[i].nama_barang;
                        jumlah_belian[transaksi.jumlah_barang - 1] = jumlah;
                    }
                    break;
                }
            }

            if (ada_tidak == false) {
                cout << "Barang tidak ditemukan \n";
            }

        }

        TampilkanMetodePembayaran();
        cout << "Pilih metode pembayaran : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: transaksi.metodePembayaran = "Tunai"; 
                    break;
            case 2: transaksi.metodePembayaran = "Kartu Kredit"; 
                    break;
            case 3: transaksi.metodePembayaran = "Dompet Digital"; 
                    break;
            default: transaksi.metodePembayaran = "Pilihan Tidak Ditemukan";
                    break;
        }

        transaksi.total = total;
        transaksi.waktu = dapatkanWaktuSekarang();

        if (jumlah_transaksi < MAX) {
            penjualan[jumlah_transaksi++] = transaksi;
        } else {
            cout << "Maaf, jumlah transaksi telah penuh \n";
        }

        cout << "\nTransaksi selesai!\n";

        cout << "====================================\n";
        cout << "      Hasil Dari Belanjaan Anda     \n";
        cout << "====================================\n";
        cout << "| " << setw(15) << left << "Nama Barang" << " | " << setw(14) << left << "Jumlah Barang" << " |\n";
        cout << "====================================\n";

        for(int i = 0; i < jumlah_barang; i++){
            cout << "| " << setw(15) << left << barang_belian[i] << " | " << setw(14) << left << jumlah_belian[i] << " |\n";
            cout << "====================================\n";
        }
        cout << "Total Keseluruhan Barang Yang Di Beli : " << total << "\n";
        cout << "Metode Pembayaran : " << transaksi.metodePembayaran << "\n";
        
    }
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
    cout << "      Anda Keluar Dari Program      \n";
    cout << "====================================\n";

}
