#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>
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
    system("cls");
    char pilihan;

    do {
        if (jumlah_barang >= MAX) {
            cout << "Data Penuh! Tidak dapat menambahkan barang baru.\n";

            cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
            system("pause > null");
            return;
        } else {
            cout << "====================================\n";
            cout << "            Tambah Barang           \n";
            cout << "====================================\n";

            cout << "Masukkan ID Barang : ";
            cin >> inventaris[jumlah_barang].id_barang;
            for (int i = 0; i < jumlah_barang; i++) {
                if (inventaris[i].id_barang == inventaris[jumlah_barang].id_barang) {
                    cout << "ID Tersebut Sudah Ada!\n";

                    cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
                    system("pause > null");
                    return;
                }
            }

            cout << "Masukkan Nama Barang : ";
            cin >> inventaris[jumlah_barang].nama_barang;
            for (int i = 0; i < jumlah_barang; i++) {
                if (inventaris[i].nama_barang == inventaris[jumlah_barang].nama_barang) {
                    cout << "Nama Barang Tersebut Sudah Ada!\n";

                    cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
                    system("pause > null");
                    return;
                }
            }

            cout << "Masukkan Harga Barang : ";
            cin >> inventaris[jumlah_barang].harga_barang;
            if (inventaris[jumlah_barang].harga_barang < 0) {
                cout << "Harga Tidak Boleh Negatif!\n";

                cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
                system("pause > null");
                return;
            }

            cout << "Masukkan Stok Barang : ";
            cin >> inventaris[jumlah_barang].stok_barang;
            if (inventaris[jumlah_barang].stok_barang < 0) {
                cout << "Stok Tidak Boleh Negatif!\n";

                cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
                system("pause > null");
                return;
            }

            jumlah_barang++;

            cout << "\nBarang Berhasil Ditambahkan!\n";
        }
        
        cout << "====================================\n";
        cout << "Apakah Anda Ingin Menambahkan Barang Lagi (y/n) : ";
        cin >> pilihan;
        
    } while (pilihan == 'Y' || pilihan == 'y');
    
}

void editBarang() {
    system("cls");
    string id_barang;
    int harga_baru;
    string nama_baru;
    int stok_baru;

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

            cout << "Masukkan Nama Barang Baru : ";
            cin >> nama_baru;

            for (int j = 0; j < jumlah_barang; j++) {
                if (inventaris[j].nama_barang == nama_baru && inventaris[j].id_barang != id_barang) {
                    cout << "Nama Barang Tersebut Sudah Ada!\n";

                    cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
                    system("pause > null");
                    return;
                }
            }
            inventaris[i].nama_barang = nama_baru;

            cout << "Masukkan Harga Barang Baru : ";
            cin >> harga_baru;

            if (harga_baru < 0) {
                cout << "Harga tidak boleh negatif!\n";

                cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
                system("pause > null");
                return;
            }
            inventaris[i].harga_barang = harga_baru;

            cout << "Masukkan Stok Barang Baru : ";
            cin >> stok_baru;

            if (stok_baru < 0) {
                cout << "Stok tidak boleh negatif!\n";

                cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
                system("pause > null");
                return;
            }
            inventaris[i].stok_barang = stok_baru;

            cout << "====================================\n";
            cout << "\nBarang berhasil diperbarui!\n";

            cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
            system("pause > null");
            return;
        }
    }

    cout << "ID Barang tidak ditemukan.\n";
    system("pause > null");
}


void hapusBarang(){
    system("cls");
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

            cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
            system("pause > null");
            return;
        }
    }

    cout << "ID Barang tidak ditemukan.\n";

    cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
    system("pause > null");
}

void tampilkanSemuaBarang(){
    system("cls");
    if (jumlah_barang == 0) {
        cout << "====================================\n";
        cout << "         Tidak Ada Barang           \n";
        cout << "====================================\n";

        cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
        system("pause > null");
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
        cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
        system("pause > null");
    }
}

void TampilkanMetodePembayaran(){
    system("cls");
    cout << "====================================\n";
    cout << "   Metode pembayaran yang tersedia  \n";
    cout << "====================================\n";
    cout << "1. Tunai\n";
    cout << "2. Kartu Kredit\n";
    cout << "3. Dompet Digital\n";
    cout << "====================================\n";
    cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
    system("pause > null");
}

void TampilkanMetodePembayaranProses(){
    cout << "====================================\n";
    cout << "   Metode pembayaran yang tersedia  \n";
    cout << "====================================\n";
    cout << "1. Tunai\n";
    cout << "2. Kartu Kredit\n";
    cout << "3. Dompet Digital\n";
    cout << "====================================\n";
}

string dapatkanWaktuSekarang() {
    time_t sekarang = time(0);
    tm *ltm = localtime(&sekarang);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", ltm);
    return string(buffer);
}

void ProsesTransaksi(){
    system("cls");
    string namaBarang;
    int jumlah;
    char pilihan;
    Transaksi transaksi;

    double total_barang;
    int total_jumlah_barang = 0;
    double total = 0;

    string barang_belian[MAX];
    int jumlah_belian[MAX];

    if (jumlah_barang == 0) {
        cout << "====================================\n";
        cout << "         Tidak Ada Barang           \n";
        cout << "====================================\n";

        cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
        system("pause > null");
        return;
    } else {
        cout << "====================================\n";
        cout << "           Proses Transaksi         \n";
        cout << "====================================\n";

        bool transaksiPenuh = false;
        while (transaksiPenuh == false) {
            
            cout << "Masukkan Nama Barang (Atau 'sudah' Untuk Mengakhiri) : ";
            cin >> namaBarang;
            
            if (namaBarang == "sudah"){
                break;
            } else {
                bool ada_tidak = false;
                for (int i = 0; i < jumlah_barang; i++) {
                    if (inventaris[i].nama_barang == namaBarang) {                        
                        ada_tidak = true;
                        cout << "Masukkan Jumlah Barang : ";
                        cin >> jumlah;

                        if (jumlah > inventaris[i].stok_barang) {
                            cout << "Stok Tidak Mencukupi \n";
                        } else {
                            inventaris[i].stok_barang = inventaris[i].stok_barang - jumlah;
                            Item barangTerjual = inventaris[i];
                            barangTerjual.stok_barang = jumlah; 
                            transaksi.barang[transaksi.jumlah_barang++] = barangTerjual;
                            total += barangTerjual.harga_barang * jumlah;

                            if (transaksi.jumlah_barang >= MAX) {
                                cout << "Tidak Dapat Menambahkan Lebih Banyak Barang\n";
                                transaksiPenuh = true;
                                break;
                            }
                        }
                        break;
                    }
                }
                    if (ada_tidak == false) {
                        cout << "Nama Barang tidak ditemukan \n";
                    }
            }
        }
        cout << "\n\nTekan Tombol Apapun Untuk Melanjutkan : ";
        system("pause > null");
        system("cls");
        
        bool inputValid = false;
        do {
        system("cls");
        TampilkanMetodePembayaranProses();
        cout << "Pilih metode pembayaran (1-3) : ";
        cin >> pilihan;
        cout << "====================================\n";

        switch (pilihan) {
            case '1':
                transaksi.metodePembayaran = "Tunai";
                inputValid = true;
                break;
            case '2':
                transaksi.metodePembayaran = "Kartu Kredit";
                inputValid = true;
                break;
            case '3':
                transaksi.metodePembayaran = "Dompet Digital";
                inputValid = true;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
                cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
                system("pause > null");
                break;
        }
    } while (inputValid == false);

        transaksi.total = total;
        transaksi.waktu = dapatkanWaktuSekarang();

        if (jumlah_transaksi < MAX) {
            penjualan[jumlah_transaksi++] = transaksi;

            cout << "\n====================================\n";
            cout << "           Transaksi selesai!       \n";
            cout << "====================================\n";

            cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
            system("pause > null");
            system("cls");

            cout << "=============================================================================================\n";
            cout << "                                    Hasil Dari Belanjaan Anda                                \n";
            cout << "=============================================================================================\n\n";

            cout << "=============================================================================================\n";
            cout << "| " << setw(20) << left << "Nama Barang" 
                << " | " << setw(20) << left << "Jumlah Barang" 
                << " | " << setw(20) << left << "Harga Barang Satuan" 
                << " | " << setw(20) << left << "Subtotal Barang" << " |\n";
            cout << "=============================================================================================\n";

            for (int i = 0; i < transaksi.jumlah_barang; i++) {
            total_barang = transaksi.barang[i].harga_barang * transaksi.barang[i].stok_barang;
            total_jumlah_barang += transaksi.barang[i].stok_barang;
            cout << "| " << setw(20) << left << transaksi.barang[i].nama_barang 
                    << " | " << setw(20) << left << transaksi.barang[i].stok_barang
                    << " | " << setw(20) << left << transaksi.barang[i].harga_barang 
                    << " | " << setw(20) << left << total_barang <<  " |\n";
            }
            cout << "=============================================================================================\n\n";

            cout << "Metode Pembayaran : " << transaksi.metodePembayaran << "\n";
            cout << "Total Keseluruhan Item Yang Dibeli : " << transaksi.jumlah_barang << "\n";
            cout << "Total Keseluruhan Jumlah Barang Yang Dibeli : " << total_jumlah_barang << "\n";
            cout << "Total Keseluruhan Harga Barang Yang Di Beli : Rp. " << total << "\n";
        } else {
            cout << "Maaf, Jumlah Transaksi Telah Penuh \n";
        }
        
        cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
        system("pause > null");
    }
}


void BuatLaporanPenjualan(){
    system("cls");
    if (jumlah_transaksi == 0) {
        cout << "====================================\n";
        cout << "         Tidak Ada Transaksi        \n";
        cout << "====================================\n";

        cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
        system("pause > null");
        return;
    } else {
        cout << "===========================================================================================================\n";
        cout << "| " << setw(5) << left << "No" << " | "
                << setw(20) << left << "Nama Barang" << " | "
                << setw(10) << left << "Jumlah" << " | "
                << setw(15) << left << "Total Harga" << " | "
                << setw(18) << left << "Metode Pembayaran" << " | "
                << setw(20) << left << "Waktu Transaksi" << " |\n";
        cout << "===========================================================================================================\n";

        for (int i = 0; i < jumlah_transaksi; i++) {
            for (int j = 0; j < penjualan[i].jumlah_barang; j++) {
                cout << "| " << setw(5) << left << i + 1 << " | "
                        << setw(20) << left << penjualan[i].barang[j].nama_barang << " | "
                        << setw(10) << left << penjualan[i].barang[j].stok_barang << " | "
                        << setw(15) << left << penjualan[i].barang[j].harga_barang * penjualan[i].barang[j].stok_barang << " | "
                        << setw(18) << left << penjualan[i].metodePembayaran << " | "
                        << setw(20) << left << penjualan[i].waktu << " |\n";
            }
            cout << "===========================================================================================================\n";
        }
        cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
        system("pause > null");
    }
}

void SimpanTransaksikeFile(){
    system("cls");
    if (jumlah_transaksi == 0) {
        cout << "====================================\n";
        cout << "         Tidak Ada Transaksi        \n";
        cout << "====================================\n";
        cout << "Tidak ada transaksi untuk disimpan.\n";

        cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
        system("pause > null");
        return;
    } else {
        ofstream file("datatransaksi.txt", ios::app);

        if (!file) {
            cout << "Gagal Membuka File Untuk Menyimpan Transaksi.\n";

            cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
            system("pause > null");
            return; 
        } else {
            for (int i = 0; i < jumlah_transaksi; i++) {
                for (int j = 0; j < penjualan[i].jumlah_barang; j++) {
                    file << "| " << setw(15) << left << penjualan[i].barang[j].stok_barang << " | "
                        << setw(15) << left  << penjualan[i].barang[j].harga_barang * penjualan[i].barang[j].stok_barang << " | "
                        << setw(18) << left  << penjualan[i].metodePembayaran << " | "
                        << setw(20) << left  << penjualan[i].waktu << " |\n";
                }
            }
        }

        file.close();
        cout << "\nTransaksi Berhasil Disimpan\n";
        cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
        system("pause > null");
    }
}

void laporanTransaksi() {
    system("cls");
    ifstream file("datatransaksi.txt");

    if (!file) {
        cout << "====================================\n";
        cout << "         Tidak Ada Transaksi        \n";
        cout << "====================================\n";
        cout << "Tidak ada transaksi yang dapat ditampilkan.\n";

        cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
        system("pause > null");
        return;
    } 

    int pilihan, filter_hari, filter_bulan, filter_tahun;
    cout << "=================================================================================\n";
    cout << "                           Filter Laporan Transaksi                              \n";
    cout << "=================================================================================\n";
    cout << "1. Laporan Harian\n";
    cout << "2. Laporan Bulanan\n";
    cout << "3. Laporan Tahunan\n";
    cout << "=================================================================================\n";
    cout << "Pilih filter (1-3): ";
    cin >> pilihan;
    cout << "=================================================================================\n";
    
    switch(pilihan) {
        case 1:
            cout << "Masukkan tanggal (DD): ";
            cin >> filter_hari;
            cout << "Masukkan bulan (MM): ";
            cin >> filter_bulan;
            cout << "Masukkan tahun (YYYY): ";
            cin >> filter_tahun;
            break;
        case 2:
            filter_hari = 0;
            cout << "Masukkan bulan (MM): ";
            cin >> filter_bulan;
            cout << "Masukkan tahun (YYYY): ";
            cin >> filter_tahun;
            break;
        case 3:
            filter_hari = 0;
            filter_bulan = 0;
            cout << "Masukkan tahun (YYYY): ";
            cin >> filter_tahun;
            break;
    }

    cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
    system("pause > null");
    system("cls");
    
    cout << "\n=================================================================================\n";
    cout << "                    Data Transaksi Yang Tersimpan                                \n";
    cout << "=================================================================================\n\n";

    cout << "=================================================================================\n";
    cout << "| " << setw(15) << left << "Jumlah Barang" << " | "
        << setw(15) << left << "Total Harga" << " | "
        << setw(18) << left << "Metode Bayar" << " | "
        << setw(20) << left << "Waktu Transaksi" << " |\n";
    cout << "=================================================================================\n";

    string baris;
    int jumlah = 0;
    char pemisah;

    while (getline(file, baris)) {
        stringstream ss(baris);
        string jumlah_barang, total_harga, metode, tanggal;
        
        ss >> pemisah;
        ss >> jumlah_barang;
        ss >> pemisah;
        ss >> total_harga;
        ss >> pemisah;
        ss >> metode;
        ss >> pemisah;
        ss >> tanggal;

        int hari, bulan, tahun;
        sscanf(tanggal.c_str(), "%d-%d-%d", &hari, &bulan, &tahun);

        bool tampilkan_data = false;
        switch (pilihan) {
            case 1:
                if (hari == filter_hari && bulan == filter_bulan && tahun == filter_tahun) {
                    tampilkan_data = true;
                }
                break;
            case 2:
                if (bulan == filter_bulan && tahun == filter_tahun) {
                    tampilkan_data = true;
                }
                break;
            case 3:
                if (tahun == filter_tahun) {
                    tampilkan_data = true;
                }
                break;
        }

        if (tampilkan_data) {
            cout << "| " << setw(15) << left << jumlah_barang << " | "
                << setw(15) << left << total_harga << " | "
                << setw(18) << left << metode << " | "
                << setw(20) << left << tanggal << " |\n";
            jumlah++;
        }
    }

    if (jumlah == 0) {
        cout << "Tidak ada transaksi untuk periode yang dipilih.\n";
    }

    cout << "=================================================================================\n";
    cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
    system("pause > null");
    file.close();
}

int main()
{
    char pilihan;

    do{
        system("cls");
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
                    cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
                    system("pause > null");
                    break;
        }
    } while (pilihan != '0');

    system("cls");
    cout << "====================================\n";
    cout << "      Anda Keluar Dari Program      \n";
    cout << "====================================\n";
}