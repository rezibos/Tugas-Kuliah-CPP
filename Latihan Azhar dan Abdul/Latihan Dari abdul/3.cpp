#include <iostream>
using namespace std;

int main()
{
    int menu,top, hasil;

    cout <<  "Menu Pizza" << endl;
    cout <<  "1. Kecil (Rp.50.000)" << endl;
    cout <<  "2. Sedang (Rp.75.000)" << endl;
    cout <<  "3. Kecil (Rp.100.000)" << endl;
    cout << "Pemesanan Pizza (1-3) : ";
    cin >> menu;

    cout << "Toping Tambahan" << endl;
    cout <<  "1. Pepperoni" << endl;
    cout <<  "2. Jamur" << endl;
    cout <<  "3. Keju" << endl;
    cout << "Pemesanan Toping (1-3) : ";
    cin >> top;

    if(menu == 1){
        if(top == 1){
            hasil = 50 + 10;
            cout << "Total Harga : " << hasil << ".000" << endl;
        } else {
            cout << "Total Harga : Rp 50.000 " << endl;
        }
    } else if(menu == 2){
        if(top == 2){
            hasil = 75 + 10;
            cout << "Total Harga : " << hasil << ".000" << endl;
        } else {
            cout << "Total Harga : Rp 75.000 " << endl;
        }
    }   else if(menu == 3){
        if(top == 3){
            hasil = 100 + 10;
            cout << "Total Harga : " << hasil << ".000" << endl;
        } else {
            cout << "Total Harga : Rp 100.000 " << endl;
        }
    }



}
