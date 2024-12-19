#include <iostream>
using namespace std;

void tambahBarang(){

}

void tampilkanSemuaBarang(){
    
}

void tampilkanSemuaBarang(){
    
}

void tampilkanSemuaBarang(){
    
}


void prosesTransaksi(){
    
}

void tampilkanMetodePembayaran(){
    
}

void buatLaporan(){
    
}

void simpanTransaksiKeFile(){
    
}

int main()
{
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
            case 2: tampilkanSemuaBarang(); 
                    break;
            case 3: prosesTransaksi(); 
                    break;
            case 4: tampilkanMetodePembayaran(); 
                    break;
            case 5: buatLaporan(); 
                    break;
            case 6: simpanTransaksiKeFile(); 
                    break;
            case 7: return 0;

            default: cout << "Pilihan tidak valid. Coba lagi.\n";
                    break;
        }
    } while (pilihan != 7);

    cout << "Anda Keluar Dari Program\n";
}