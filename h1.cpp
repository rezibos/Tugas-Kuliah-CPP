#include <iostream>
using namespace std;

int main()
{
    int pilih;
    string data[10];
    
    do{
        cout << "===== Menu ===== \n";
        cout << "1. Masukan Data \n";
        cout << "2. Tampilkan Poin A \n";
        cout << "3. Tampil Semua Poin C \n";
        cout << "Pilih (1-3) : ";
        cin >> pilih;

        if(pilih = 3){
            for(int i = 2; i <= 10; i + 2){
                cout << data[i] << endl;
            }
        } else if(pilih == 2){
            cout << "Data Ke - 2 = " << data[1] << endl;
            cout << "Data Ke - 5 = " << data[4] << endl;
            cout << "Data Ke - 7 = " << data[6] << endl;
            cout << "Data Ke - 10 = " << data[9] << endl;
        } else if(pilih == 1){
            for(int a = 1; a <= 10; a++)
            {
                cout << "Masukan data ke -" << a << " : ";
                cin >> a[data];
            }
        }
    } while (pilih != 4);
    
    
    
}
