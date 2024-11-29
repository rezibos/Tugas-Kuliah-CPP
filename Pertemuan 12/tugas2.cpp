#include <iostream>
using namespace std;

void lp(){
    char ulang;
    double diameter, jari, hasil;
    do{
        cout << "=========================================" << endl;
        cout << "Menu Luas Permukaan Bola" << endl;
        cout << "Input diameter = ";
        cin >> diameter;
        jari = diameter / 2;
        hasil = 4 * 3.14 * jari * jari;
        cout << "Hasil hitung jari-jari = " << jari << endl;
        cout << "Luas permukaan bola = " << hasil << endl;
        cout << "=========================================" << endl;
        cout << "Apakah ingin mencoba lagi? (Y/N) : ";
        cin >> ulang;
    } while (ulang == 'Y' || ulang == 'y');
}

void vb(){
    char ulang;
    double diameter, jari, hasil;
    do{
        cout << "=========================================" << endl;
        cout << "Menu Volume Bola" << endl;
        cout << "Input diameter = ";
        cin >> diameter;
        jari = diameter / 2;
        hasil = (4.0 / 3.0) * 3.14 * jari * jari * jari;
        cout << "Hasil hitung jari-jari = " << jari << endl;
        cout << "Volume bola = " << hasil << endl;
        cout << "=========================================" << endl;
        cout << "Apakah ingin mencoba lagi? (Y/N) : ";
        cin >> ulang;
        cout << "=========================================" << endl;
    } while (ulang == 'Y' || ulang == 'y');
}

void kb(){
    char ulang;
    double diameter, jari, hasil;
    do{
        cout << "=========================================" << endl;
        cout << "Menu Keliling" << endl;
        cout << "Input diameter = ";
        cin >> diameter;
        jari = diameter / 2;
        hasil = 2 * 3.14 * jari;
        cout << "Hasil hitung jari-jari = " << jari << endl;
        cout << "Keliling bola = " << hasil << endl;
        cout << "=========================================" << endl;
        cout << "Apakah ingin mencoba lagi? (Y/N) : ";
        cin >> ulang;
    } while (ulang == 'Y' || ulang == 'y');
}

int main() {
    int pilihan;
    
    do {
        cout << "=========================================" << endl;
        cout << "Menu" << endl;
        cout << "=========================================" << endl;
        cout << "1. Luas Permukaan Bola" << endl;
        cout << "2. Volume Bola" << endl;
        cout << "3. Keliling Bola" << endl;
        cout << "=========================================" << endl;
        cout << "Pilih Menu (1-3) : ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                lp();
                break;
            case 2:
                vb();
                break;
            case 3:
                kb();
                break;
            default:
                cout << "Menu Tidak Tersedia" << endl;
                break;
        }
    } while (pilihan == 1,2,3);
    cout << "Program selesai. Terima kasih!\n";
    return 0;
}