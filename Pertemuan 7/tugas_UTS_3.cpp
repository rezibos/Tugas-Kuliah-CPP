#include <iostream>
using namespace std;

int main()
{
    int menu, s, hasil;
    cout << "\n";
    cout << "Menghitung Luas, Keliling, dan Volume Kubus \n";
    cout << "\n";
    cout << "====================================== \n";
    cout << "1. Luas Kubus\n";
    cout << "2. Keliling Kubus \n";
    cout << "3. Volume Kubus \n";
    cout << "====================================== \n";
    cout << "Pilihan Menu : ";
    cin >> menu;
    cout << "====================================== \n";

    if (menu == 1)
    {
        cout << "\n";
        cout << "Menu Luas \n\n";

        cout << "Masukan Inputan \n";
        cout << "Masukan sisi : ";
        cin >> s;

        // Cara Hitung nya
        hasil = 6 * s * s;

        cout << "Hasil Hitungan : " <<"6 x " << s << " x "<< s << " = " << hasil << endl;
    } else if (menu == 2){
        cout << "\n";
        cout << "Menu Keliling \n\n";

        cout << "Masukan Inputan \n";
        cout << "Masukan sisi : ";
        cin >> s;

        // Cara Hitung nya
        hasil = 12 * s ;

        cout << "Hasil Hitungan : " <<"12 x " << s << " = " << hasil << endl;
    } else if (menu == 3){
        cout << "\n";
        cout << "Menu Volume \n\n";

        cout << "Masukan Inputan \n";
        cout << "Masukan sisi : ";
        cin >> s;

        // Cara Hitung nya
        hasil = s * s * s;

        cout << "Hasil Hitungan : "<< s << " x " << s << " x " << s << " = " << hasil << endl;
    } else {
        cout << "Menu Tidak Tersedia \n";
    }
    

}
