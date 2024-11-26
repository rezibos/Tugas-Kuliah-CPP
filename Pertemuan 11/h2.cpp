#include <iostream>
using namespace std;

int tambah(int a , int b , int c){
    int hasil = a + b + c;
    return hasil;
}

int kurang(int a, int b, int c){
    int hasil = a - b - c;
    return hasil;
}

int bagi(int a, int b, int c){
    int hasil = a / b / c;
    return hasil;
}

int kali(int a, int b, int c){
    int hasil = a * b * c;
    return hasil;
}

int main()
{
    int i;
    int n1, n2, n3;

    cout << "Pilih Menu" << endl;
    cout << "1. Operasi Tambah" << endl;
    cout << "2. Operasi Kurang" << endl;
    cout << "3. Operasi Bagi" << endl;
    cout << "4. Operasi Kali" << endl;
    cout << "Masukan Pilihan (1-4) : ";
    cin >> i;

    if(i == 1){
        cout << "Masukan Nilai Pertama : "; cin >> n1;
        cout << "Masukan Nilai Kedua : "; cin >> n2;
        cout << "Masukan Nilai Ketiga : "; cin >> n3;
        cout << "\n";
        cout << n1 << " + " << n2 << " + " << n3 << " = " << tambah(n1, n2, n3);
    } else if(i == 2){
        cout << "Masukan Nilai Pertama : "; cin >> n1;
        cout << "Masukan Nilai Kedua : "; cin >> n2;
        cout << "Masukan Nilai Ketiga : "; cin >> n3;
        cout << "\n";
        cout << n1 << " - " << n2 << " - " << n3 << " = " << kurang(n1, n2, n3);
    } else if(i == 3){
        cout << "Masukan Nilai Pertama : "; cin >> n1;
        cout << "Masukan Nilai Kedua : "; cin >> n2;
        cout << "Masukan Nilai Ketiga : "; cin >> n3;
        cout << "\n";
        cout << n1 << " / " << n2 << " / " << n3 << " = " << bagi(n1, n2, n3);
    } else if(i == 4){
        cout << "Masukan Nilai Pertama : "; cin >> n1;
        cout << "Masukan Nilai Kedua : "; cin >> n2;
        cout << "Masukan Nilai Ketiga : "; cin >> n3;
        cout << "\n";
        cout << n1 << " x " << n2 << " x " << n3 << " = " << kali(n1, n2, n3);
    } else {
        cout << "Data Yang Dimasukin Tidak Di Temukan" << endl;
    }
}
