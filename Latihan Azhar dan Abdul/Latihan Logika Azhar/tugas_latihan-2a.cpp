#include <iostream>
using namespace std;

int main()
{
    long long  jumlah, hasil; // 7jt
    long long  st = 7000000;
    long long  po = 6500000;

    cout << "Jumlah Laptop : ";
    cin >> jumlah;

    if(jumlah == 15){
        hasil = 15 * st;
        cout << "Harga laptop yang di beli : " << hasil << endl;
        cout << "stock cukup";
    } else if(jumlah <= 3 ){
        hasil = jumlah * st;
        cout << "Harga laptop yang di beli : " << hasil << endl;
    } else if (jumlah >= 10 && jumlah <= 15){
        hasil = jumlah * st * 0.15 + 0.15;
        cout << "Harga laptop yang di beli : " << hasil << endl;
        cout << "Dapat 2 buah printer" << endl;
    } else if (jumlah >= 16 && jumlah < 20 ){
        cout << "Stock Tidak Cukup" << endl;
    } else if (jumlah >= 20){
        hasil = jumlah * po + 0.15;
        cout << "Harga laptop yang di beli : " << hasil << endl;
    }
}
