#include <iostream>
using namespace std;

int main()
{
    int angka1, angka2, hasil;
    char ar;

    cout << "Masukan angka pertama : ";
    cin >> angka1;
    cout << "Masukan angka pertama : ";
    cin >> ar;
    cout << "Masukan angka pertama : ";
    cin >> angka2;

    if(ar == '+'){
        hasil = angka1 + angka2;
        cout << "Jumlah hitungan : " << hasil << endl;
    } else if(ar == '-'){
        hasil = angka1 - angka2;
        cout << "Jumlah hitungan : " << hasil << endl;
    } else if(ar == '*'){
        hasil = angka1 * angka2;
        cout << "Jumlah hitungan : " << hasil << endl;
    } else if(ar == '/'){
        hasil = angka1 / angka2;
        cout << "Jumlah hitungan : " << hasil << endl;
    }
}
