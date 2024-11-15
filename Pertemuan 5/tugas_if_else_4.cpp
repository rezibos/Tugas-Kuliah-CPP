#include <iostream>
using namespace std;

int main()
{
    double sku, harga, jumlah, diskon, hasil;
    string nama_barang, yt;

    cout << "Masukan Nama Barang : ";
    cin >> nama_barang;

    cout << "Masukan Harang : Rp. ";
    cin >> harga;

    cout << "Apakah Anda Member (ya/tidak) :";
    cin >> yt;

    if(yt == "ya"){
        jumlah = harga * sku;
        diskon = jumlah * 0.15;
        hasil = jumlah - diskon;
        cout << "Nama Barang Anda : " << nama_barang << endl;
        cout << "Harga Awal : " << jumlah << endl;
        cout << "Harga Setelah Diskon : " << hasil << endl;
    } else if (yt == "tidak"){
        jumlah = harga * sku;
        cout << "Nama Barang Anda : " << nama_barang << endl;
        cout << "Harga Awal : " << jumlah << endl;
        cout << "Anda Tidak Mendapatkan Diskon Karena Anda Bukan Member" << endl;
    }
}
