#include <iostream>
using namespace std;

double luas(double k){
    int hasil = 6 * (k * k);
    return hasil;
}

double keliling(double k){
    int hasil = 12 * k;
    return hasil;
}

int main()
{
    int sisi,i;

    cout << "Pilih Menu" << endl;
    cout << "1. Hitung Luas Kubus" << endl;
    cout << "2. Hitung Keliling Kubus" << endl;
    cout << "Masukan Pilihan (1/2) : ";
    cin >> i;

    if(i == 1){
        cout << "Masukan Anggka : ";
        cin >> sisi;
        cout << "Hasil adalah : " << luas(sisi);
    } else if(i == 2){
        cout << "Masukan Anggka : ";
        cin >> sisi;
        cout << "Hasil adalah : " << keliling(sisi);
    } else {
        cout << "Data Yang Dimasukin Tidak Di Temukan" << endl;
    }
}
