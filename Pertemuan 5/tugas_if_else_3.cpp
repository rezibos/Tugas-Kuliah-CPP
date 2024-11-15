#include <iostream>
using namespace std;

int main(){
    int angka;

    cout << "Masukan angka : ";
    cin >> angka;

    if(angka > 0){
        cout << "Angka" << angka << " adalah positif" << endl;
    } else if(angka < 0){
        cout << "Angka" << angka << " adalah negatif" << endl;
    } else {
        cout << "Angka adalah nol." << endl;
    }
}