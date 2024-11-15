#include <iostream>

using namespace std;

int main()
{
    string nama, as, amt;
    unsigned int nim, umur;

    cout << "\n";
    cout << "---- Masukan Data Diri Anda ----\n\n";

    // Masukan Nama
    cout << "Masukan nama :";
    cin >> nama;

    cout << "Masukan nim :";
    cin >> nim;
    cin.ignore();

    cout << "Masukan umur : ";
    cin >> umur;
    cin.ignore();

    cout << "Masukan asal sekolah : ";
    cin >> as;

    cout << "Masukan alasan masuk ti : ";
    cin >> amt;
    cout << endl;

    cout << "---- Data Diri Anda ----\n\n";
    cout << "Nama Anda : " << nama << endl;
    cout << "Nim Anda : " << nim << endl;
    cout << "Umur Anda : " << umur << endl;
    cout << "Asal Sekolah Anda : " << as << endl;
    cout << "Alasan Masuk TI : " << amt << endl;
}