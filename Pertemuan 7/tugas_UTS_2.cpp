#include <iostream>
using namespace std;

int main()
{
    double ipk;
    
    cout << "Masukan IPK : ";
    cin >> ipk;

        if(ipk >= 4.00 ){
            cout << "Semua Nilai Mata Kuliah : A" << endl;
            cout << "Predikat lulusan : Summa Cumlaude" << endl;
        } else if(ipk >= 3.80 ){
            cout << "Ada Nilai Mata Kuliah : B" << endl;
            cout << "Predikat lulusan : Magna Cumlaude" << endl;
        } else if(ipk >= 3.51 ){
            cout << "Ada Nilai Mata Kuliah : C" << endl;
            cout << "Predikat lulusan : Cumlaude" << endl;
        }  else if(ipk >= 2.75 ){
            cout << "Beberapa Nilai Mata Kuliah : C" << endl;
            cout << "Predikat lulusan : Sangat Memuaskan" << endl;
        } else {
            cout << "Rata-Rata Nilai Mata Kuliah : C" << endl;
            cout << "Predikat lulusan : Memuaskan";
        }
}
