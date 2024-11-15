#include <iostream>
using namespace std;

int main()
{
    int nilai;
    int pilih;

    cout << "Masukan Anggka : ";
    cin >> nilai;

    cout << "Mau Metode Apa (1/2): ";
    cin >> pilih;


    switch (pilih)
    {
    case 1 :
        cout << "Metode Standar \n";
        if (nilai >= 80 && nilai <= 100){
        cout << "Nilai Adalah A" << endl;
        } else if (nilai >= 65 && nilai <= 79){
        cout << "Nilai Adalah B" << endl;
        } else if (nilai >= 50 && nilai <= 64){
        cout << "Nilai Adalah C" << endl;
        } else if (nilai >= 35 && nilai <= 49){
        cout << "Nilai Adalah D" << endl;
        } else if (nilai >= 0 && nilai <= 34) {
        cout << "Nilai Adalah E" << endl;
        } else {
        cout << "Nilai Yang Dimasukan Tidak Valid" << endl;
        }
        break;
    
    case 2 :
        cout << "Metode Alternatif \n";
        if (nilai >= 85 && nilai <= 100){
        cout << "Nilai Adalah A" << endl;
        } else if (nilai >= 70 && nilai <= 84){
        cout << "Nilai Adalah B" << endl;
        } else if (nilai >= 55 && nilai <= 69){
        cout << "Nilai Adalah C" << endl;
        } else if (nilai >= 40 && nilai <= 54){
        cout << "Nilai Adalah D" << endl;
        } else if (nilai >= 0 && nilai <= 39) {
        cout << "Nilai Adalah E" << endl;
        } else {
        cout << "Nilai Yang Dimasukan Tidak Valid" << endl;
        }
        break;
    
    default:
        cout <<  "Metode Tidak Valid" << endl;
    }
    return 0;
}
