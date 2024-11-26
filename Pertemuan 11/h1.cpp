#include <iostream>
using namespace std;

string nm, nim, jk, ak;
string jr, sm, ti;

void profil(){
    cout << "===== PROFILE =====" << endl;
    cout << "Nama : " << nm << endl;
    cout << "Nim : " << nim << endl;
    cout << "Jenis Kelamin : " << jk << endl;
    cout << "Asal Kampus : " << ak << endl;
}

void mahasiswa(){
    cout << "===== MAHASISWA =====" << endl;
    cout << "Jurusan : " << jr << endl;
    cout << "Semester : " << sm << endl;
    cout << "Target IPK : " << ti << endl;
}

int main()
{
    int i;

    cout << "Pilih Menu" << endl;
    cout << "1. Profile" << endl;
    cout << "2. Mahasiswa" << endl;
    cout << "Masukan Pilihan (1/2) : ";
    cin >> i;

    if(i == 1){
        cout << "Masukan Nama : "; cin >> nm;
        cout << "Masukan Nim : "; cin >> nim;
        cout << "Masukan Jenis Kelamin : "; cin >> jk;
        cout << "Masukan Asal Kampus : "; cin >> ak;
        cout << "\n";
        profil();
    } else if(i == 2){
        cout << "Masukan Jurusan : "; cin >> jr;
        cout << "Masukan Semester : "; cin >> sm;
        cout << "Masukan Target IPK : "; cin >> ti;
        cout << "\n";
        mahasiswa();
    } else {
        cout << "Data Yang Dimasukin Tidak Di Temukan" << endl;
    }
}
