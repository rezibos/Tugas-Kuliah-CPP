#include <iostream>
using namespace std;

void menu1() {
    double celcius, fahrenheit;
    char ulang;
    do {
        cout << "\nMenu Celcius ke Fahrenheit\n";
        cout << "Input suhu (Celcius) = ";
        cin >> celcius;
        fahrenheit = (celcius * 9.0 / 5.0) + 32;
        cout << "Hasil konversi ke Fahrenheit = " << fahrenheit << " F\n";
        cout << "Apakah ingin mencoba lagi? (Y/N): ";
        cin >> ulang;
    } while (ulang == 'Y' || ulang == 'y');
}

void menu2() {
    double fahrenheit, celcius;
    char ulang;
    do {
        cout << "\nMenu Fahrenheit ke Celcius\n";
        cout << "Input suhu (Fahrenheit) = ";
        cin >> fahrenheit;
        celcius = (fahrenheit - 32) * 5.0 / 9.0;
        cout << "Hasil konversi ke Celcius = " << celcius << " C\n";
        cout << "Apakah ingin mencoba lagi? (Y/N): ";
        cin >> ulang;
    } while (ulang == 'Y' || ulang == 'y');
}

int main() {
    int menu;
    
    do {
        cout << "\nKonversi Suhu Celcius ke Fahrenheit\n";
        cout << "=====================================\n";
        cout << "1. Celcius ke Fahrenheit\n";
        cout << "2. Fahrenheit ke Celcius\n";
        cout << "3. Keluar\n";
        cout << "=====================================\n";
        cout << "Pilih Menu (1/2) : ";
        cin >> menu;

        switch (menu) {
            case 1:
                menu1();
                break;
            case 2:
                menu2();
                break;
            default:
                cout << "Menu Tidak Tersedia\n";
        }
    } while (menu == 1,2);
    cout << "Program selesai. Terima kasih!\n";
}