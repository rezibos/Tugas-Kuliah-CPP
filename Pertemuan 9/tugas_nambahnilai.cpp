#include <iostream>
using namespace std;

int main()
{
    int tiket;
    string kt;
    double hasil, jam;

    double a1, a2, a3;
    a1 = 20.000;
    a2 = 30.000;
    a3 = 35.000;

    double d1, d2, d3;
    d1 = 40.000;
    d2 = 50.000;
    d3 = 60.000;

    double l1, l2, l3;
    l1 = 15.000;
    l2 = 25.000;
    l3 = 30.000;


    cout << "----- Menu Bioskop ----- \n\n"; 
    cout << "Masukan Beli Berapa Tiket : ";
    cin >> tiket;
    cout << "Masukan Jam Pembelian : ";
    cin >> jam;
    cout << "Masukan Kategori : ";
    cin >> kt;
    cout << "\n" << endl;

    if(kt == "anak") {
        if(jam >= 00.00 && jam < 12.00) {
            hasil = tiket * a1;
            cout << "Jumlah Tiket : " << tiket << endl;
            cout << "Harga tiket jam " << jam  << " untuk kategori anak = Rp. 20.000 " << endl;
            cout << "Jumlah Harga yang dibayar : Rp. " << hasil << ".000" << endl;
        } else if(jam >= 12.00 && jam <= 18.00) {
            hasil = tiket * a2;
            cout << "Jumlah Tiket : " << tiket << endl;
            cout << "Harga tiket jam " << jam << " untuk kategori anak = Rp. 30.000 " << endl;
            cout << "Jumlah Harga yang dibayar : Rp. " << hasil << ".000" << endl;
        } else if(jam > 18.00 && jam <= 24.00 ) {
            hasil = tiket * a3;
            cout << "Jumlah Tiket : " << tiket << endl;
            cout << "Harga tiket jam " << jam << " untuk kategori anak = Rp. 35.000 " << endl;
            cout << "Jumlah Harga yang di bayar : Rp. " << hasil << ".000" << endl;
        } else {
            cout << "Kamu Tinggal Di Pelanet Mana " << endl;
        }
    } else if(kt == "dewasa") {
        if(jam >= 00.00 && jam < 12.00) {
            hasil = tiket * d1;
            cout << "Jumlah Tiket : " << tiket << endl;
            cout << "Harga tiket jam " << jam  << " untuk kategori dewasa = Rp. 40.000 " << endl;
            cout << "Jumlah Harga yang dibayar : Rp. " << hasil << ".000" << endl;
        } else if(jam >= 12.00 && jam <= 18.00) {
            hasil = tiket * d2;
            cout << "Jumlah Tiket : " << tiket << endl;
            cout << "Harga tiket jam " << jam << " untuk kategori dewasa = Rp. 50.000 " << endl;
            cout << "Jumlah Harga yang dibayar : Rp. " << hasil << ".000" << endl;
        } else if(jam > 18.00 && jam <= 24.00 ) {
            hasil = tiket * d3;
            cout << "Jumlah Tiket : " << tiket << endl;
            cout << "Harga tiket jam " << jam << " untuk kategori dewasa = Rp. 60.000 " << endl;
            cout << "Jumlah Harga yang di bayar : Rp. " << hasil << ".000" << endl;
        } else {
            cout << "Kamu Tinggal Di Pelanet Mana " << endl;
        }
    } else if(kt == "lansia") {
        if(jam >= 00.00 && jam < 12.00) {
            hasil = tiket * l1;
            cout << "Jumlah Tiket : " << tiket << endl;
            cout << "Harga tiket jam " << jam  << " untuk kategori lansia = Rp. 15.000 " << endl;
            cout << "Jumlah Harga yang dibayar : Rp. " << hasil << ".000" << endl;
        } else if(jam >= 12.00 && jam <= 18.00) {
            hasil = tiket * l2;
            cout << "Jumlah Tiket : " << tiket << endl;
            cout << "Harga tiket jam " << jam << " untuk kategori lansia = Rp. 25.000 " << endl;
            cout << "Jumlah Harga yang dibayar : Rp. " << hasil << ".000" << endl;
        } else if(jam > 18.00 && jam <= 24.00 ) {
            hasil = tiket * l3;
            cout << "Jumlah Tiket : " << tiket << endl;
            cout << "Harga tiket jam " << jam << " untuk kategori lansia = Rp. 30.000 " << endl;
            cout << "Jumlah Harga yang di bayar : Rp. " << hasil << ".000" << endl;
        } else {
            cout << "Kamu Tinggal Di Pelanet Mana " << endl;
        }
    } else {
        cout << "Kategori Tidak Sesuai" << endl;
    }
}
