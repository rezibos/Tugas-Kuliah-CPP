#include <iostream>
using namespace std;

int main()
{
    int pm, pb;
    long long total, tsd, hasil, diskon;
    long long pl,ps,bt,png;
    pl = 3000;
    ps = 2000;
    bt = 5000;
    png = 1500;

    cout << "Menu" << endl;
    cout << "1. Pulpen : Rp 3.000 perbuah" << endl;
    cout << "2. Pensil : Rp 2.000 perbuah" << endl;
    cout << "3. Buku Tusil : Rp 5.000 perbuah" << endl;
    cout << "4. Penggaris : Rp 1.500 perbuah" << endl;
    cout << "Masukan mau beli apa (1-4) : ";
    cin >> pm;

    if(pm == 1){

        cout << "Masukan mau beli berapa : ";
        cin >> pb;
        total = pb * pl;

        if(total >= 50000 && total <= 100000){
            diskon = total * 0.05;
            tsd = total - diskon;

            cout << "Harga awal pembelian : " << total << endl;
            cout << "Anda Mendapatkan diskon : 5%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Harga sesudah diskon : " << tsd << endl;
        } else if(total > 100000 && total <= 150000){
            diskon = total * 0.10;
            tsd = total - diskon;

            cout << "Harga awal pembelian : " << total << endl;
            cout << "Anda Mendapatkan diskon : 10%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Harga sesudah diskon : " << tsd << endl;
        } else if(total > 150000){
            diskon = total * 0.15;
            tsd = total - diskon;

            cout << "Harga awal pembelian : " << total << endl;
            cout << "Anda Mendapatkan diskon : 15%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Harga sesudah diskon : " << tsd << endl;
        } else {
            cout << "Harga awal pembelian : " << total << endl;
            cout << "Anda Mendapatkan diskon : 0%" << endl;
            cout << "Harga sesudah diskon : " << total << endl;
        }

    }else if(pm == 2){
        cout << "Masukan mau beli berapa : ";
        cin >> pb;
        total = pb * ps;

        if(total >= 50000 && total <= 100000){
            diskon = total * 0.05;
            tsd = total - diskon;

            cout << "Harga awal pembelian : " << total << endl;
            cout << "Anda Mendapatkan diskon : 5%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Harga sesudah diskon : " << tsd << endl;
        } else if(total > 100000 && total <= 150000){
            diskon = total * 0.10;
            tsd = total - diskon;

            cout << "Harga awal pembelian : " << total << endl;
            cout << "Anda Mendapatkan diskon : 10%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Harga sesudah diskon : " << tsd << endl;
        } else if(total > 150000){
            diskon = total * 0.15;
            tsd = total - diskon;

            cout << "Harga awal pembelian : " << total << endl;
            cout << "Anda Mendapatkan diskon : 15%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Harga sesudah diskon : " << tsd << endl;
        } else {
            cout << "Harga awal pembelian : " << total << endl;
            cout << "Anda Mendapatkan diskon : 0%" << endl;
            cout << "Harga sesudah diskon : " << total << endl;
        }

    }else if(pm == 3){
        cout << "Masukan mau beli berapa : ";
        cin >> pb;
        total = pb * bt;

        if(total >= 50000 && total <= 100000){
            diskon = total * 0.05;
            tsd = total - diskon;

            cout << "Harga awal pembelian : " << total << endl;
            cout << "Anda Mendapatkan diskon : 5%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Harga sesudah diskon : " << tsd << endl;
        } else if(total > 100000 && total <= 150000){
            diskon = total * 0.10;
            tsd = total - diskon;

            cout << "Harga awal pembelian : " << total << endl;
            cout << "Anda Mendapatkan diskon : 10%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Harga sesudah diskon : " << tsd << endl;
        } else if(total > 150000){
            diskon = total * 0.15;
            tsd = total - diskon;

            cout << "Harga awal pembelian : " << total << endl;
            cout << "Anda Mendapatkan diskon : 15%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Harga sesudah diskon : " << tsd << endl;
        } else {
            cout << "Harga awal pembelian : " << total << endl;
            cout << "Anda Mendapatkan diskon : 0%" << endl;
            cout << "Harga sesudah diskon : " << total << endl;
        }

    }else if(pm == 4){
        cout << "Masukan mau beli berapa : ";
        cin >> pb;

        total = pb * png;

        if(total >= 50000 && total <= 100000){
            diskon = total * 0.05;
            tsd = total - diskon;

            cout << "Harga awal pembelian : " << total << endl;
            cout << "Anda Mendapatkan diskon : 5%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Harga sesudah diskon : " << tsd << endl;
        } else if(total > 100000 && total <= 150000){
            diskon = total * 0.10;
            tsd = total - diskon;

            cout << "Harga awal pembelian : " << total << endl;
            cout << "Anda Mendapatkan diskon : 10%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Harga sesudah diskon : " << tsd << endl;
        } else if(total > 150000){
            diskon = total * 0.15;
            tsd = total - diskon;

            cout << "Harga awal pembelian : " << total << endl;
            cout << "Anda Mendapatkan diskon : 15%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Harga sesudah diskon : " << tsd << endl;
        } else {
            cout << "Harga awal pembelian : " << total << endl;
            cout << "Anda Mendapatkan diskon : 0%" << endl;
            cout << "Harga sesudah diskon : " << total << endl;
        }

    } else {
        cout << "Pilihan anda tidak sesuai (1-4)" << endl;
    }

}
