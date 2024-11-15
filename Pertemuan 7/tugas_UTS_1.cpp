#include <iostream>
using namespace std;

int main()
{
    int bulan;
    cout << "Masukan Bulan : ";
    cin >> bulan;

    switch(bulan){
        case 1 :
                cout << "Januari Dengan Jumlah Hari 31" << endl;
                break;
        case 2 :
                cout << "Februari Dengan Jumlah Hari 28" << endl;
                break;
        case 3 :
                cout << "Maret Dengan Jumlah Hari 31" << endl;
                break;
        case 4 :
                cout << "April Dengan Jumlah Hari 30" << endl;
                break;
        case 5 :
                cout << "Mei Dengan Jumlah Hari 31" << endl;
                break;
        case 6 :
                cout << "Juni Dengan Jumlah Hari 30" << endl;
                break;
        case 7 :
                cout << "Juli Dengan Jumlah Hari 31" << endl;
                break;
        case 8 :
                cout << "Agustus Dengan Jumlah Hari 31" << endl;
                break;
        case 9 :
                cout << "September Dengan Jumlah Hari 30" << endl;
                break;
        case 10 :
                cout << "Oktober Dengan Jumlah Hari 31" << endl;
                break;
        case 11 :
                cout << "November Dengan Jumlah Hari 30" << endl;
                break;
        case 12 :
                cout << "Desember Dengan Jumlah Hari 31" << endl;
                break;

        default :
                cout << "Bulan Tidak Diketahui" << endl;
                break;
    }

}
