#include <iostream>
using namespace std;

void tambahBarang(){
    system("cls");
    cout << "abc" << endl;
    cout << "\nTekan Tombol Apapun Untuk Melanjutkan : ";
    system("pause  > null");
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
            case '0': break;
            default: break;
        }
    } while (pilihan != '0');
}
