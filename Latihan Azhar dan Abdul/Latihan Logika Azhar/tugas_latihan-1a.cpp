#include <iostream>
using namespace std;

int main()
{
    int jam, hasil, hasil_jam;
    string motor, mobil, kendaraan;

    cout << "Masukan Jam : ";
    cin >> jam;

    if (jam < 1) {
        cout <<  "masukan kendaraan (motor/mobil) : ";
        cin >> kendaraan;

        if(kendaraan == "motor"){
            cout << "Harga yang harus di bayar : 2.000" << endl;
        } else if(kendaraan == "mobil"){
            cout << "Harga yang harus di bayar : 5.000" << endl;
        }
    } else if(jam >= 1 && jam <= 3) {
        cout <<  "masukan kendaraan (motor/mobil) : ";
        cin >> kendaraan;

        if(kendaraan == "motor"){
            hasil = 7 * jam;
            cout << "Harga yang harus di bayar : " << hasil << ".000" << endl;
        } else if(kendaraan == "mobil"){
            hasil = 10 * jam;
            cout << "Harga yang harus di bayar : " << hasil << ".000" << endl;
        }
    } else if(jam > 3) {
        cout <<  "masukan kendaraan (motor/mobil) : ";
        cin >> kendaraan;

        if(kendaraan == "motor"){
            if(jam == 6){
                hasil =  15 * jam + 2;
                cout << "Harga yang harus di bayar : " << hasil << ".000" << endl;
            } else {
                cout << "Harga yang harus di bayar : 15.000" << endl;
            }
        } else if(kendaraan == "mobil"){
            if(jam == 6){
                hasil =  30 * jam + 5;
                cout << "Harga yang harus di bayar : " << hasil << ".000" << endl;
            } else {
                cout << "Harga yang harus di bayar : 30.000" << endl;
            }
        }
    }
    
}


