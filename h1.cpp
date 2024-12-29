#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct barang 
{
    int id;
    string nama;
    double harga;
    int stok;
};

struct transaksi
{
    int idbarang;
    int jumlah;
    string namabarang;
    string metodepembayaran;
    double totalbarang;
    int tanggal;
    int bulan;
    int tahun;
};

barang inventaris[100];
transaksi Transaksi[100];
int jumlahbarang = 0;
int jumlahtransaksi = 0;

void tambahBarang() {
    cout << "\n";
    cout << "================================================================" << endl;
    cout << "                     = Tambah Barang Baru =                     " << endl;
    cout << "================================================================" << endl;
    if (jumlahbarang < 2) {
        for (int i = 0; i <= jumlahbarang; i++){
            int a = i+1;
            inventaris[jumlahbarang].id = a;
        }
        cout << "Masukkan Nama Barang : ";
        cin >> inventaris[jumlahbarang].nama;
        for (int i = 0; i < jumlahbarang; i++) {
            if (inventaris[i].nama == inventaris[jumlahbarang].nama) {
                cout << "Barang Sudah Ada di Inventaris" << endl;
                return;
            }
        }
        cout << "Masukkan Harga Barang : ";
        cin >> inventaris[jumlahbarang].harga;
        cout << "Masukkan Stok : ";
        cin >> inventaris[jumlahbarang].stok;
        jumlahbarang++;
        cout << "Barang Berhasil Ditambahkan!" << endl;
    } else {
        cout << "Tidak Dapat Menginput Barang, Inventaris Penuh" << endl;
    }
    cout << "================================================================" << endl;
}

void tampilkanBarang() {
    cout << "\n";
    cout << "================================================================" << endl;
    cout << "                    = Lihat Daftar Barang =                     " << endl;
    cout << "================================================================" << endl;
    if (jumlahbarang == 0) {
        cout << "Belum Ada Barang yang Ditambahkan" << endl;
    } else {
        // Atur lebar kolom dengan setw
        cout << left << setw(5)  << "ID" 
             << setw(25) << "Nama Barang" 
             << setw(15) << "Harga" 
             << setw(10) << "Stok" << endl;

        cout << "----------------------------------------------------------------" << endl;
        
        for (int i = 0; i < jumlahbarang; i++) {
            cout << left << setw(5)  << inventaris[i].id 
                 << setw(25) << inventaris[i].nama
                 << setw(15) << inventaris[i].harga 
                 << setw(10) << inventaris[i].stok << endl;   
        }
    }
    cout << "================================================================" << endl;
}


void updateTampilBarang() {
    int Id;
    cout << "\n";
    cout << "================================================================" << endl;
    cout << "                    = Perbarui Data Barang =                    " << endl;
    cout << "================================================================" << endl;
    cout << "Masukkan Id : ";
    cin >> Id;

    if (jumlahbarang < Id) {
        cout << "Barang Tidak Di Temukan" << endl;
    } else {
        cout << "Masukkan Nama Barang : ";
        cin >> inventaris[jumlahbarang-1].nama;
        cout << "Masukkan Harga Barang : ";
        cin >> inventaris[jumlahbarang-1].harga;
        cout << "Masukkan Stok Barang : ";
        cin >> inventaris[jumlahbarang-1].stok;
        cout << "Barang Berhasil Diupdate" << endl;
    }
    cout << "================================================================" << endl;
    
}

void hapusDataBarang() {
    int Id;
    cout << "\n";
    cout << "================================================================" << endl;
    cout << "                      = Hapus Data Barang =                     " << endl;
    cout << "================================================================" << endl;
    cout << "Masukkan ID : ";
    cin >> Id;

    if (jumlahbarang < Id) {
        cout << "ID tidak ditemukan" << endl;
    } else  {
        for (int i = Id-1; i < jumlahbarang; i++) {
            inventaris[i].nama = inventaris[i+1].nama;
            inventaris[i].harga = inventaris[i+1].harga;
            inventaris[i].stok = inventaris[i+1].stok;
        }
    jumlahbarang--;
    cout << "Data Barang Berhasil Dihapus" << endl;    
    }
    cout << "================================================================" << endl;
}

void metodePembayaran(int index) { 
    int metode;
    cout << "\n";
    cout << "----------------------------------------------------------------" << endl;
    cout << "                     = Metode Pembayaran =                      " << endl;
    cout << "                            1. Tunai                            " << endl;
    cout << "                            2. Debit                            " << endl;
    cout << "                           3. E-Wallet                          " << endl;
    cout << "                   Pilih Metode Pembayaran : ";
    cin >> metode;
    if(metode == 1) {
        Transaksi[index].metodepembayaran = "Tunai";
    } else if(metode == 2) {
        Transaksi[index].metodepembayaran = "Debit";
    } else if(metode == 3) {
        Transaksi[index].metodepembayaran = "E-Wallet";
    } else {
        cout << "Pilihan Metode Pembayaran Tidak tersedia\n";
    }
    cout << "----------------------------------------------------------------" << endl;
    cout << "\n";
}


void transaksiPenjualan() {
    int id = 0, jumlah = 0;
    char tambahLagi;
    int currentIndex = jumlahtransaksi; // Simpan index awal transaksi
    
    cout << "\n";
    cout << "================================================================" << endl;
    cout << "                      = Layanan Transaksi =                     " << endl;
    cout << "================================================================" << endl;
    cout << "Masukkan Tanggal (dd mm yyyy) : ";
    cin >> Transaksi[currentIndex].tanggal 
        >> Transaksi[currentIndex].bulan 
        >> Transaksi[currentIndex].tahun;

    double totalHargaTransaksi = 0.0;

    do {
        cout << "Masukkan Id Barang : ";
        cin >> id;

        if (id > jumlahbarang) {
            cout << "Barang dengan Id Tersebut Tidak Ditemukan" << endl;
            continue;
        }

        int indeks_barang = id - 1;
        cout << "Nama Barang : " << inventaris[indeks_barang].nama << endl;
        cout << "Masukkan Jumlah : ";
        cin >> jumlah;

        if (inventaris[indeks_barang].stok >= jumlah) {
            inventaris[indeks_barang].stok -= jumlah;

            // Gunakan index yang berbeda untuk setiap item dalam transaksi
            Transaksi[jumlahtransaksi].idbarang = id;
            Transaksi[jumlahtransaksi].namabarang = inventaris[indeks_barang].nama;
            Transaksi[jumlahtransaksi].jumlah = jumlah;
            Transaksi[jumlahtransaksi].totalbarang = jumlah * inventaris[indeks_barang].harga;
            // Salin tanggal dari transaksi pertama
            Transaksi[jumlahtransaksi].tanggal = Transaksi[currentIndex].tanggal;
            Transaksi[jumlahtransaksi].bulan = Transaksi[currentIndex].bulan;
            Transaksi[jumlahtransaksi].tahun = Transaksi[currentIndex].tahun;
            
            double totalBarang = jumlah * inventaris[indeks_barang].harga;
            totalHargaTransaksi += totalBarang;

            cout << "Subtotal untuk barang ini: " << inventaris[indeks_barang].harga << " x " << jumlah << " = " << Transaksi[jumlahtransaksi].totalbarang << endl;
            jumlahtransaksi++; // Increment setelah setiap item ditambahkan
        } else {
            cout << "Stok Tidak Mencukupi untuk barang ini.\n";
        }

        cout << "Apakah Anda ingin menambahkan barang lain? (Y/N): ";
        cin >> tambahLagi;

    } while (tambahLagi == 'Y' || tambahLagi == 'y');

    metodePembayaran(jumlahtransaksi);
    if (totalHargaTransaksi > 0) {
        cout << "Total harga untuk semua barang dalam transaksi ini: " << totalHargaTransaksi << endl;
    } else {
        cout << "Transaksi dibatalkan karena tidak ada barang yang ditambahkan." << endl;
    }

    cout << "================================================================" << endl;
}


void historiPenjualan() {
    cout << "\n";
    cout << "================================================================" << endl;
    cout << "                      = Histori Penjualan =                     " << endl;
    cout << "================================================================" << endl;
    int pilihan, Tanggal, bulan, tahun;
    do {
        double totalkeseluruhan = 0.0;
        cout << "Histori Penjualan\n";
        cout << "1. Harian\n";
        cout << "2. Bulanan\n";
        cout << "3. Tahunan\n";
        cout << "4. Menu\n";
        cout << "Pilih Filter Penjualan : ";
        cin >> pilihan;
        cout << "----------------------------------------------------------------" << endl;     

        switch (pilihan) {
        case 1:
            cout << "Masukkan Tanggal (dd mm yyyyy) : ";
            cin >> Tanggal >> bulan >> tahun;
            cout << left 
                << setw(20) << "Nama Barang" 
                << setw(10) << "Jumlah" 
                << setw(10) << "Total" 
                << setw(20) << "Metode Pembayaran" 
                << "Tanggal" 
                << endl;

            for (int i = 0; i < jumlahtransaksi; i++) {
                if (Transaksi[i].tanggal == Tanggal) {
                    if (Transaksi[i].bulan == bulan) {
                        if (Transaksi[i].tahun == tahun) {
                            cout << left 
                                << setw(20) << Transaksi[i].namabarang 
                                << setw(10) << Transaksi[i].jumlah 
                                << setw(10) << Transaksi[i].totalbarang 
                                << setw(20) << Transaksi[i].metodepembayaran 
                                << Transaksi[i].tanggal << "-" 
                                << Transaksi[i].bulan << "-" 
                                << Transaksi[i].tahun 
                                << endl;
                            totalkeseluruhan += Transaksi[i].totalbarang;
                        }
                    }
                }   
            }
            cout << "Total Keseluruhan : " << totalkeseluruhan << endl;
            break;
        case 2: 
            cout << "Masukkan Bulan dan Tahun (mm yyyyy) : ";
            cin >> Tanggal >> bulan >> tahun;
             cout << left 
                << setw(20) << "Nama Barang" 
                << setw(10) << "Jumlah" 
                << setw(10) << "Total" 
                << setw(20) << "Metode Pembayaran" 
                << "Tanggal" 
                << endl;

            for (int i = 0; i < jumlahtransaksi; i++) {
                if (Transaksi[i].bulan == bulan) {
                    if (Transaksi[i].tahun == tahun) {
                        cout << left 
                            << setw(20) << Transaksi[i].namabarang 
                            << setw(10) << Transaksi[i].jumlah 
                            << setw(10) << Transaksi[i].totalbarang 
                            << setw(20) << Transaksi[i].metodepembayaran 
                            << Transaksi[i].tanggal << "-" 
                            << Transaksi[i].bulan << "-" 
                            << Transaksi[i].tahun 
                            << endl;
                        totalkeseluruhan += Transaksi[i].totalbarang;
                    }
                }   
            }
            cout << "Total Keseluruhan : " << totalkeseluruhan << endl;
            break;
        case 3:
            cout << "Masukkan Tahun (yyyy) : ";
            cin >> tahun;
             cout << left 
                << setw(20) << "Nama Barang" 
                << setw(10) << "Jumlah" 
                << setw(10) << "Total" 
                << setw(20) << "Metode Pembayaran" 
                << "Tanggal" 
                << endl;

            for (int i = 0; i < jumlahtransaksi; i++) {
                if (Transaksi[i].tahun == tahun) {
                     cout << left 
                        << setw(20) << Transaksi[i].namabarang 
                        << setw(10) << Transaksi[i].jumlah 
                        << setw(10) << Transaksi[i].totalbarang 
                        << setw(20) << Transaksi[i].metodepembayaran 
                        << Transaksi[i].tanggal << "-" 
                        << Transaksi[i].bulan << "-" 
                        << Transaksi[i].tahun 
                        << endl;
                    totalkeseluruhan += Transaksi[i].totalbarang;
                }       
            }
            cout << "Total Keseluruhan : " << totalkeseluruhan << endl;
            break;
        
        default:
            break;
        }
    } while (pilihan != 4);        
}

void simpanDataTransaksiKeFile() {
    ofstream file("transaksi.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file untuk menyimpan data transaksi." << endl;
        return;
    }

    file << left 
         << setw(10) << "ID" 
         << setw(20) << "Nama Barang" 
         << setw(10) << "Jumlah" 
         << setw(15) << "Total Barang" 
         << setw(20) << "Metode Pembayaran" 
         << "Tanggal" 
         << endl;

    for (int i = 0; i < jumlahtransaksi; i++) {
        file << left 
             << setw(10) << Transaksi[i].idbarang
             << setw(20) << Transaksi[i].namabarang
             << setw(10) << Transaksi[i].jumlah
             << setw(15) << Transaksi[i].totalbarang
             << setw(20) << Transaksi[i].metodepembayaran
             << Transaksi[i].tanggal << "-" 
             << Transaksi[i].bulan << "-" 
             << Transaksi[i].tahun
             << endl;
    }

    file.close();
    cout << "Data transaksi berhasil disimpan ke file 'transaksi.txt'." << endl;
}

int main() {
    int pilihan;
    do {
        cout << "\n";
        cout << "================================================================" << endl;
        cout << "                            = Menu =                            " << endl;
        cout << "================================================================" << endl;
        cout << "1. Tambah Barang Baru" << endl;
        cout << "2. Lihat Daftar Barang" << endl;
        cout << "3. Perbarui Data Barang" << endl;
        cout << "4. Update Data Barang" << endl;
        cout << "5. Layanan Transaksi" << endl;
        cout << "6. Histori Penjualan" << endl;
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;
        cout << "================================================================" << endl;
        cout << "\n";

        switch (pilihan)
        {
        case 1:
            tambahBarang();
            break;
        case 2: 
            tampilkanBarang();
            break;
        case 3:
            updateTampilBarang();
            break;
        case 4:
            hapusDataBarang();
            break;
        case 5:
            transaksiPenjualan();
            break;
        case 6:
            historiPenjualan();
            break;
        case 7:
            simpanDataTransaksiKeFile();
            break;
        default:
            cout << "pilihan Tidak Valid\n";
            break;
        } 
    } while (pilihan != 8);
    return 0;
}