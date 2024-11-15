#include <iostream>
using namespace std;

int main()
{
    int usia;

    cout << "Masukan usia anda : ";
    cin >> usia;

    if(usia <= 12){
        cout << "Anda adalah anak-anak" << endl;
    } else if(usia <= 18){
        cout << "Anda adalah remaja" << endl;
    } else if(usia <= 60){
        cout << "Anda adalah dewasa" << endl;
    } else {
        cout << "Anda adalah lansia" << endl;
    }
}
