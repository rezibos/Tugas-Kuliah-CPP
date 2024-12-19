#include <iostream>
using namespace std;

float cf() {
    float cel, far;
    char ulang;

    do{
        cout << " Menu Celcius Ke Farenheit " << endl;
        cout << "Input suhu = ";
        cin >> cel;
        far = (cel * 9.0/ 5.0) + 32;
        cout << "Hasil Konversi Ke farenheit = " << far << endl;
        cout << "=========================================" << endl;
        cout << "Apakah ingin Mencoba lagi ? (Y/N) = ";
        cin >> ulang;
        cout << "=========================================" << endl;
    } while (ulang == 'Y' || ulang == 'y');

    return 0;
}

float fc () {
    float cel, far;
    char ulang;

    do{
        cout << " Menu Farenheit Ke Celcius " << endl;
        cout << "Input suhu = ";
        cin >> far;
        cel = (far - 32) * 5.0/ 9.0;
        cout << "Hasil Konversi Ke celcius = " << cel << endl;
        cout << "=========================================" << endl;
        cout << "Apakah ingin Mencoba lagi ? (Y/N) = ";
        cin >> ulang;
        cout << "=========================================" << endl;
    } while (ulang == 'Y' || ulang == 'y');

    return 0;
}

int main (){
    float cel, far;
    int pilihan;
    char cobalagi;

do {
    cout << " Konversi Suhu Celcius Ke Farenheit " << endl;
    cout << "=========================================" << endl;
    cout << " 1. Celcius Ke Farenheit " << endl;
    cout << " 2. Farenheit Ke Celcius " << endl;
    cout << "=========================================" << endl;
    cout << " Pilih Menu : ";
    cin >> pilihan;
    cout << "=========================================" << endl;

    if (pilihan == 1) {
        cf();
    } else if (pilihan == 2) {
        fc();
    } else {
        cout << "Menu Tidak Tersedia" << endl;
    }

    cout << "=========================================" << endl;
    cout << "Apakah ingin Mencoba lagi ? (Y/N) = ";
    cin >> cobalagi;
    cout << "=========================================" << endl;

} while (cobalagi =='Y' || cobalagi =='y');
return 0;
}