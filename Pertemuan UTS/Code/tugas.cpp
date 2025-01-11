#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <string>
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
    string waktu;
    string metodePembayaran;
    double total;
    double uangDibayar;
    double kembalian;
};

Item inventaris[MAX];
Transaksi penjualan[MAX];

int jumlah_barang = 0;
int jumlah_transaksi = 0;

void simpanBarangKeFile() {
    ofstream file("databarang.doc");
    if (file.is_open()) {
        for (int i = 0; i < jumlah_barang; i++) {
            file << inventaris[i].id_barang << ","
                << inventaris[i].nama_barang << ","
                << inventaris[i].harga_barang << ","
                << inventaris[i].stok_barang << "\n";
        }
        file.close();
    } else {
        cout << "Gagal menyimpan data ke file!\n";
    }
}

void bacaBarangDariFile() {
    ifstream file("databarang.doc");

    if (!file) {
        cout << "File data_barang.doc tidak ditemukan.\n";
        return;
    }

    jumlah_barang = 0;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, nama, harga, stok;

        getline(ss, id, ',');
        getline(ss, nama, ',');
        getline(ss, harga, ',');
        getline(ss, stok, ',');

        id = id.erase(0, id.find_first_not_of(" "));
        nama = nama.erase(0, nama.find_first_not_of(" "));
        harga = harga.erase(0, harga.find_first_not_of(" "));
        stok = stok.erase(0, stok.find_first_not_of(" "));

        inventaris[jumlah_barang].id_barang = id;
        inventaris[jumlah_barang].nama_barang = nama;
        inventaris[jumlah_barang].harga_barang = stod(harga);
        inventaris[jumlah_barang].stok_barang = stoi(stok);

        jumlah_barang++;
        if (jumlah_barang >= MAX) {
            cout << "Inventaris penuh, beberapa data tidak dimuat.\n";
            break;
        }
    }

    file.close();
}

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
            cin.ignore();

            for (int i = 0; i < jumlah_barang; i++) {
                if (inventaris[i].id_barang == inventaris[jumlah_barang].id_barang) {
                    cout << "ID Tersebut Sudah Ada!\n";
                    cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
                    system("pause > null");
                    return;
                }
            }

            cout << "Masukkan Nama Barang : ";
            std::getline(cin, inventaris[jumlah_barang].nama_barang);

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
            simpanBarangKeFile();
            cout << "\nBarang Berhasil Ditambahkan!\n";
        }
        
        cout << "====================================\n";
        cout << "Apakah Anda Ingin Menambahkan Barang Lagi (y/n) : ";
        cin >> pilihan;
        cin.ignore();
        
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
    cin.ignore();

    for (int i = 0; i < jumlah_barang; i++) {
        if (inventaris[i].id_barang == id_barang) {
            cout << "====================================\n";
            cout << "Barang ditemukan : \n";
            cout << "ID Barang    : " << inventaris[i].id_barang << "\n";
            cout << "Nama Barang  : " << inventaris[i].nama_barang << "\n";
            cout << "Harga Barang : " << inventaris[i].harga_barang << "\n";
            cout << "Stok Barang  : " << inventaris[i].stok_barang << "\n";
            cout << "====================================\n";

            cout << "Masukkan Nama Barang Baru : ";
            getline(cin, nama_baru);

            for (int j = 0; j < jumlah_barang; j++) {
                if (inventaris[j].nama_barang == nama_baru && j != i) {
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

            simpanBarangKeFile();
            cout << "====================================\n";
            cout << "\nBarang berhasil diperbarui!\n";

            cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
            system("pause > null");
            return;
        }
    }

    cout << "ID Barang tidak ditemukan.\n";
    cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
    system("pause > null");
}

void hapusBarang() {
    system("cls");
    string id_barang;

    cout << "====================================\n";
    cout << "             Hapus Barang           \n";
    cout << "====================================\n";

    cout << "Masukkan ID Barang yang ingin dihapus: ";
    cin >> id_barang;

    for (int i = 0; i < jumlah_barang; i++) {
        if (inventaris[i].id_barang == id_barang) {
            cout << "\nBarang dengan ID " << id_barang << " ditemukan dan akan dihapus.\n";

            for (int j = i; j < jumlah_barang - 1; j++) {
                inventaris[j] = inventaris[j + 1];
            }

            jumlah_barang--;
            simpanBarangKeFile();
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
        cout << "========================================================================\n";
        cout << "| " << setw(12) << left << "ID Barang" << " | "
                << setw(18) << left << "Nama Barang" << " | "
                << setw(15) << left << "Harga Barang" << " | "
                << setw(14) << left << "Stok Barang" << " |\n";
        cout << "========================================================================\n";

        for (int i = 0; i < jumlah_barang; i++) {
            cout << "| " << setw(12) << left << inventaris[i].id_barang << " | "
                    << setw(18) << left << inventaris[i].nama_barang << " | "
                    << setw(15) << left << inventaris[i].harga_barang << " | "
                    << setw(14) << left << inventaris[i].stok_barang << " |\n";
            cout << "========================================================================\n";
        }
        cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
        system("pause > null");
    }
}

void cariBarang() {
    system("cls");
    string id_barang;

    cout << "====================================\n";
    cout << "            Cari Barang             \n";
    cout << "====================================\n";

    cout << "Masukkan ID Barang yang dicari: ";
    cin >> id_barang;

    bool ditemukan = false;
    for (int i = 0; i < jumlah_barang; i++) {
        if (inventaris[i].id_barang == id_barang) {
            cout << "\nBarang Ditemukan!\n";
            cout << "====================================\n";
            cout << "ID Barang     : " << inventaris[i].id_barang << "\n";
            cout << "Nama Barang   : " << inventaris[i].nama_barang << "\n";
            cout << "Harga Barang  : Rp. " << inventaris[i].harga_barang << "\n";
            cout << "Stok Barang   : " << inventaris[i].stok_barang << "\n";
            cout << "====================================\n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "\nBarang dengan ID " << id_barang << " tidak ditemukan.\n";
        cout << "====================================\n";
    }

    cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
    system("pause > null");
}

void TampilkanMetodePembayaranProses(){
    cout << "====================================\n";
    cout << "   Metode pembayaran yang tersedia  \n";
    cout << "====================================\n";
    cout << "1. Tunai\n";
    cout << "2. Debit\n";
    cout << "3. QR\n";
    cout << "====================================\n";
}

string dapatkanWaktuSekarang() {
    time_t sekarang = time(0);
    tm *ltm = localtime(&sekarang);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", ltm);
    return string(buffer);
}

void BuatStrukPenjualan(const Transaksi& transaksi) {
    system("cls");
    ofstream struk("struk_penjualan.doc");
    double total_barang;
    int total_jumlah_barang = 0;

    string header = 
    "====================================================\n"
    "                SUKA MAJU BERSAMA\n"
    "    Jl. HangLengkir No. 19, Kota Tanjung Pinang\n"
    "            Telp: +6282130354176\n"
    "====================================================\n";

    cout << header;
    struk << header;

    string info = 
    "Tanggal: " + transaksi.waktu + "\n"
    "No. Transaksi: TRX" + to_string(jumlah_transaksi) + "\n"
    "Metode Pembayaran: " + transaksi.metodePembayaran + "\n"
    "====================================================\n";
    
    cout << info;
    struk << info;

    string tableHeader = 
    "Nama Barang          Qty    Harga     Subtotal\n"
    "====================================================\n";
    
    cout << tableHeader;
    struk << tableHeader;

    for (int i = 0; i < transaksi.jumlah_barang; i++) {
        total_barang = transaksi.barang[i].harga_barang * transaksi.barang[i].stok_barang;
        total_jumlah_barang += transaksi.barang[i].stok_barang;

        stringstream ss;
        ss << left << setw(20) << transaksi.barang[i].nama_barang.substr(0, 19)
           << left << setw(7) << transaksi.barang[i].stok_barang
           << right << setw(10) << fixed << setprecision(0) << transaksi.barang[i].harga_barang
           << right << setw(12) << total_barang << "\n";

        cout << ss.str();
        struk << ss.str();
    }

    string footer = 
    "====================================================\n"
    "Total Item: " + to_string(transaksi.jumlah_barang) + "\n"
    "Total Qty: " + to_string(total_jumlah_barang) + "\n"
    "Total Pembayaran: Rp. " + to_string(static_cast<int>(transaksi.total)) + "\n";

    if (transaksi.metodePembayaran == "Tunai") {
        footer += "Tunai: Rp. " + to_string(static_cast<int>(transaksi.uangDibayar)) + "\n"
                "Kembalian: Rp. " + to_string(static_cast<int>(transaksi.kembalian)) + "\n";
    }

    footer += "====================================================\n\n"
              "        Terima Kasih Atas Kunjungan Anda\n"
              "          Selamat Datang Kembali :)\n"
              "====================================================\n";
    
    cout << footer;
    struk << footer;

    struk.close();
    cout << "\nStruk telah disimpan dan dicetak!\n";
}

void ProsesTransaksi() {
    system("cls");
    bacaBarangDariFile();
    string namaBarang;
    int jumlah;
    char pilihan;
    Transaksi transaksi;
    transaksi.jumlah_barang = 0;

    double total_barang;
    int total_jumlah_barang = 0;
    double total = 0;

    if (jumlah_barang == 0) {
        cout << "====================================\n";
        cout << "         Tidak Ada Barang           \n";
        cout << "====================================\n";

        cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
        system("pause > null");
        return;
    }

    cout << "====================================\n";
    cout << "           Proses Transaksi         \n";
    cout << "====================================\n";

    bool transaksiPenuh = false;
    while (!transaksiPenuh) {
        cout << "Masukkan Nama Barang (Atau 'sudah' Untuk Mengakhiri) : ";
        cin.ignore();
        getline(cin, namaBarang);
        
        if (namaBarang == "sudah") {
            break;
        }

        bool ada_tidak = false;
        for (int i = 0; i < jumlah_barang; i++) {
            if (inventaris[i].nama_barang == namaBarang) {                        
                ada_tidak = true;
                cout << "Masukkan Jumlah Barang : ";
                cin >> jumlah;

                if (jumlah > inventaris[i].stok_barang) {
                    cout << "Stok Tidak Mencukupi \n";
                } else {
                    inventaris[i].stok_barang -= jumlah;
                    Item barangTerjual = inventaris[i];
                    barangTerjual.stok_barang = jumlah; 
                    transaksi.barang[transaksi.jumlah_barang++] = barangTerjual;
                    total += barangTerjual.harga_barang * jumlah;
                    simpanBarangKeFile();

                    if (transaksi.jumlah_barang >= MAX) {
                        cout << "Tidak Dapat Menambahkan Lebih Banyak Barang\n";
                        transaksiPenuh = true;
                        break;
                    }
                }
                break;
            }
        }
        if (!ada_tidak) {
            cout << "Nama Barang tidak ditemukan \n";
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
                transaksi.metodePembayaran = "Debit";
                inputValid = true;
                break;
            case '3':
                transaksi.metodePembayaran = "QR";
                inputValid = true;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
                cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
                system("pause > null");
                break;
        }
    } while (!inputValid);

    transaksi.total = total;
    transaksi.waktu = dapatkanWaktuSekarang();

    if (transaksi.metodePembayaran == "Tunai") {
        do {
            cout << "\nTotal Pembayaran: Rp. " << total << endl;
            cout << "Masukkan jumlah uang: Rp. ";
            cin >> transaksi.uangDibayar;
            
            if (transaksi.uangDibayar < total) {
                cout << "Uang yang dibayarkan kurang!" << endl;
                cout << "\nTekan Tombol Apapun Untuk Mencoba Lagi : ";
                system("pause > null");
                system("cls");
            }
        } while (transaksi.uangDibayar < total);

        transaksi.kembalian = transaksi.uangDibayar - total;
        cout << "\nKembalian: Rp. " << transaksi.kembalian << endl;
    }

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
        
        if (transaksi.metodePembayaran == "Tunai") {
            cout << "Uang Dibayar : Rp. " << transaksi.uangDibayar << "\n";
            cout << "Kembalian : Rp. " << transaksi.kembalian << "\n";
        }
    } else {
        cout << "Maaf, Jumlah Transaksi Telah Penuh \n";
    }
    
    simpanBarangKeFile();
    cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
    system("pause > null");
    
    BuatStrukPenjualan(transaksi);
    cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
    system("pause > null");
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
        ofstream file("datatransaksi.doc", ios::app);

        if (!file) {
            cout << "Gagal Membuka File Untuk Menyimpan Transaksi.\n";

            cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
            system("pause > null");
            return;
        } else {
            for (int i = 0; i < jumlah_transaksi; i++) {
                for (int j = 0; j < penjualan[i].jumlah_barang; j++) {
                    file << "| " << setw(20) << left << penjualan[i].barang[j].nama_barang << " | "
                        << setw(15) << left << penjualan[i].barang[j].stok_barang << " | "
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
    ifstream file("datatransaksi.doc");

    if (!file) {
        cout << "====================================\n";
        cout << "         Tidak Ada Transaksi        \n";
        cout << "====================================\n";
        cout << "Tidak ada transaksi yang dapat ditampilkan.\n";

        cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
        system("pause > null");
        return;
    } 

    int pilihan, filter_hari = 0, filter_bulan = 0, filter_tahun = 0;
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

    if (pilihan == 1) {
        cout << "Masukkan tanggal (DD): ";
        cin >> filter_hari;
    }
    if (pilihan <= 2) {
        cout << "Masukkan bulan (MM): ";
        cin >> filter_bulan;
    }
    cout << "Masukkan tahun (YYYY): ";
    cin >> filter_tahun;

    cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
    system("pause > null");
    system("cls");

    cout << "\n========================================================================================================\n";
    cout << "                                       Data Transaksi Yang Tersimpan                                      \n";
    cout << "========================================================================================================\n\n";

    cout << "========================================================================================================\n";
    cout << "| " << setw(20) << left << "Nama Barang" << " | "
        << setw(15) << left << "Jumlah Barang" << " | "
        << setw(15) << left << "Total Harga" << " | "
        << setw(18) << left << "Metode Bayar" << " | "
        << setw(20) << left << "Waktu Transaksi" << " |\n";
    cout << "========================================================================================================\n";

    string line;
    int jumlah = 0;
    
    while (getline(file, line)) {
        if (line.empty() || line.find('|') == string::npos) continue;
        
        stringstream ss(line);
        string temp, nama_barang, jumlah_barang, total_harga, metode, tanggal;
        
        getline(ss, temp, '|');
        getline(ss, nama_barang, '|');
        getline(ss, jumlah_barang, '|');
        getline(ss, total_harga, '|');
        getline(ss, metode, '|');
        getline(ss, tanggal, '|');

        auto trim = [](string &s) {
            s.erase(0, s.find_first_not_of(" \t\n\r"));
            s.erase(s.find_last_not_of(" \t\n\r") + 1);
        };

        trim(nama_barang);
        trim(jumlah_barang);
        trim(total_harga);
        trim(metode);
        trim(tanggal);

        int hari, bulan, tahun;
        if (sscanf(tanggal.c_str(), "%d-%d-%d", &hari, &bulan, &tahun) != 3) {
            continue;
        }

        bool tampilkan_data = false;
        switch (pilihan) {
            case 1 : tampilkan_data = (hari == filter_hari && bulan == filter_bulan && tahun == filter_tahun);
                    break;
            case 2 : tampilkan_data = (bulan == filter_bulan && tahun == filter_tahun);
                break;
            case 3: tampilkan_data = (tahun == filter_tahun);
                break;
            default:
                tampilkan_data = true;
        }

        if (tampilkan_data) {
            cout << "| " << setw(20) << left << nama_barang << " | "
                << setw(15) << left << jumlah_barang << " | "
                << setw(15) << left << total_harga << " | "
                << setw(18) << left << metode << " | "
                << setw(20) << left << tanggal << " |\n";
            jumlah++;
        }
    }

    if (jumlah == 0) {
        cout << "Tidak ada transaksi untuk periode yang dipilih.\n";
    }

    cout << "========================================================================================================\n";
    cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
    system("pause > null");
    file.close();
}

int main()
{
    bacaBarangDariFile();
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
        cout << "5. Cari Barang\n";
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
            case '5': cariBarang();
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