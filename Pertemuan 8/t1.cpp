#include <iostream>
using namespace std;

int main()
{
    int pk, ml;
    long long diskon, total, hasil;
    long kms, kmd, kms1;
    kms = 300000;
    kmd = 500000;
    kms1 = 750000;

    cout << "Menu" << endl;
    cout << "1. Kamar Standar : Rp.300.000" << endl;
    cout << "2. Kamar Deluxe : Rp.500.000" << endl;
    cout << "3. Kamar Suite : Rp.750.000" << endl;
    cout << "Pilih Kamar (1-3) : ";
    cin >> pk;

    if(pk == 1){
        
        cout << "Masukan Berapa Malam Penginapan : " ;
        cin >> ml;

        if(ml >= 3 && ml <= 5){
            total = kms * ml;
            diskon = total * 0.10;
            hasil = total - diskon;

            cout << "Berapa malam menghinap : " << ml << endl;
            cout << "Total sebelum diskon : " << total << endl;
            cout << "Diskon yang di dapatkan : 10%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Jumlah Harga nya adalah : " << hasil << endl;
        } else if (ml >= 6 && ml <= 10) {
            total = kms * ml;
            diskon = total * 0.15;
            hasil = total - diskon;

            cout << "Berapa malam menghinap : " << ml << endl;
            cout << "Total sebelum diskon : " << total << endl;
            cout << "Diskon yang di dapatkan : 15%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Jumlah Harga nya adalah : " << hasil << endl;
        } else if (ml > 10) {
            total = kms * ml;
            diskon = total * 0.20;
            hasil = total - diskon;

            cout << "Berapa malam menghinap : " << ml << endl;
            cout << "Total sebelum diskon : " << total << endl;
            cout << "Diskon yang di dapatkan : 20%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Jumlah Harga nya adalah : " << hasil << endl;
        } else {
            hasil = kms * ml;

            cout << "Berapa malam menghinap : " << ml << endl;
            cout << "Total sebelum diskon : " << hasil << endl;
            cout << "Diskon yang di dapatkan : 0%" << endl;
            cout << "Jumlah Harga nya adalah : " << hasil << endl;
        }

    } else if(pk == 2){

        cout << "Masukan Berapa Malam Penginapan : " ;
        cin >> ml;

        if(ml >= 3 && ml <= 5){
            total = kmd * ml;
            diskon = total * 0.10;
            hasil = total - diskon;

            cout << "Berapa malam menghinap : " << ml << endl;
            cout << "Total sebelum diskon : " << total << endl;
            cout << "Diskon yang di dapatkan : 10%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Jumlah Harga nya adalah : " << hasil << endl;
        } else if (ml >= 6 && ml <= 10) {
            total = kmd * ml;
            diskon = total * 0.15;
            hasil = total - diskon;

            cout << "Berapa malam menghinap : " << ml << endl;
            cout << "Total sebelum diskon : " << total << endl;
            cout << "Diskon yang di dapatkan : 15%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Jumlah Harga nya adalah : " << hasil << endl;
        } else if (ml > 10) {
            total = kmd * ml;
            diskon = total * 0.20;
            hasil = total - diskon;

            cout << "Berapa malam menghinap : " << ml << endl;
            cout << "Total sebelum diskon : " << total << endl;
            cout << "Diskon yang di dapatkan : 20%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Jumlah Harga nya adalah : " << hasil << endl;
        } else {
            hasil = kmd * ml;

            cout << "Berapa malam menghinap : " << ml << endl;
            cout << "Total sebelum diskon : " << hasil << endl;
            cout << "Diskon yang di dapatkan : 0%" << endl;
            cout << "Jumlah Harga nya adalah : " << hasil << endl;
        }

    } else if(pk == 3){

        cout << "Masukan Berapa Malam Penginapan : " ;
        cin >> ml;

        if(ml >= 3 && ml <= 5){
            total = kms1 * ml;
            diskon = total * 0.10;
            hasil = total - diskon;

            cout << "Berapa malam menghinap : " << ml << endl;
            cout << "Total sebelum diskon : " << total << endl;
            cout << "Diskon yang di dapatkan : 10%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Jumlah Harga nya adalah : " << hasil << endl;
        } else if (ml >= 6 && ml <= 10) {
            total = kms1 * ml;
            diskon = total * 0.15;
            hasil = total - diskon;

            cout << "Berapa malam menghinap : " << ml << endl;
            cout << "Total sebelum diskon : " << total << endl;
            cout << "Diskon yang di dapatkan : 15%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Jumlah Harga nya adalah : " << hasil << endl;
        } else if (ml > 10) {
            total = kms1 * ml;
            diskon = total * 0.20;
            hasil = total - diskon;

            cout << "Berapa malam menghinap : " << ml << endl;
            cout << "Total sebelum diskon : " << total << endl;
            cout << "Diskon yang di dapatkan : 20%" << endl;
            cout << "Jadi anda mendapat potongan harga : " << diskon << endl;
            cout << "Jumlah Harga nya adalah : " << hasil << endl;
        } else {
            hasil = kms1 * ml;

            cout << "Berapa malam menghinap : " << ml << endl;
            cout << "Total sebelum diskon : " << hasil << endl;
            cout << "Diskon yang di dapatkan : 0%" << endl;
            cout << "Jumlah Harga nya adalah : " << hasil << endl;
        } 

    } else {
            cout << "Pilihan Anda Engak Sesuai (1-3)" << endl;
    }
    
}



        