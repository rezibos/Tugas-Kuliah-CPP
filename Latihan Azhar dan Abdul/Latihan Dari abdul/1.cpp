#include <iostream>
using namespace std;

int main()
{
    int jumlahl;
    long long hl, total, spajak, hasil, diskon,  h2, h3;
    long long tsd;
    long long pajak;
    hl = 10000000;
    h2 = 9700000;
    h3 = 9400000;

    cout << "Jumlah laptop yang mau di beli : ";
    cin >> jumlahl;
    

    if(jumlahl == 1){
        cout << "Inputan unit laptop yang dibeli : "<< jumlahl << endl;
        cout << "Pajak yang didapat  : " << "0%" << endl;
        cout << "Diskon yang didapat  : " << "0%" << endl;
        cout << "Total harga laptop : " << hl << endl;
    } else if(jumlahl > 1 && jumlahl <= 3){
        total = jumlahl * hl;
        pajak = total * 0.05;
        hasil = total + pajak;
        
        cout << "Inputan unit laptop yang dibeli : "<< jumlahl << endl;
        cout << "Pajak yang didapat  : " << "5%" << endl;
        cout << "Diskon yang didapat  : " << "0%" << endl;
        cout << "Total harga laptop : " << hasil << endl; 
    } else if(jumlahl > 3 && jumlahl <= 10){
        total = jumlahl * hl;
        diskon = total * 0.08;
        tsd = total - diskon;
        pajak = tsd * 0.10;
        hasil = tsd + pajak;

        cout << "Inputan unit laptop yang dibeli : "<< jumlahl << endl;
        cout << "Pajak yang didapat  : " << "10%" << endl;
        cout << "Diskon yang didapat  : " << "8%" << endl;
        cout << "Total harga laptop : " << hasil << endl; 
        
    } else if(jumlahl > 10 && jumlahl < 13){
        total = jumlahl * hl;
        diskon = total * 0.12;
        tsd = total - diskon;
        pajak = tsd * 0.15;
        hasil = tsd + pajak;

        cout << "Inputan unit laptop yang dibeli : "<< jumlahl << endl;
        cout << "Pajak yang didapat  : " << "15%" << endl;
        cout << "Diskon yang didapat  : " << "12%" << endl;
        cout << "Total harga laptop : " << hasil << endl;
        cout << "Selamat Anda Mendapatkan Printer : 3 unit" << endl;
    } else if(jumlahl >= 13 && jumlahl <= 20){
        total = jumlahl * h2;
        pajak = total * 0.15;
        hasil = total + pajak;

        cout << "Inputan unit laptop yang dibeli : "<< jumlahl << endl;
        cout << "Pajak yang didapat  : " << "15%" << endl;
        cout << "Diskon yang didapat  : " << "0%" << endl;
        cout << "Total harga laptop : " << hasil << endl;
    } else if(jumlahl > 20){
        total = jumlahl * h3;
        pajak = total * 0.20;
        hasil = total + pajak;

        cout << "Inputan unit laptop yang dibeli : "<< jumlahl << endl;
        cout << "Pajak yang didapat  : " << "20%" << endl;
        cout << "Diskon yang didapat  : " << "0%" << endl;
        cout << "Total harga laptop : " << hasil << endl;
    }
}
