#include <iostream>
#include <fstream>
using namespace std;

class Barang {
    public :
        string id_barang;
        string nama_barang;
        string harga_barang;
        string stock_barang;

        Barang( string id_barang, string nama_barang, string harga_barang, string stock_barang){ 
            Barang::id_barang = id_barang;
            Barang::nama_barang = nama_barang;
            Barang::harga_barang = harga_barang;
            Barang::stock_barang = stock_barang;
        }

        string stringify(){
            return "\n" +  id_barang + " " + nama_barang + " " + harga_barang + " " + stock_barang;
        }
};

class DBase {
    public :
        ifstream in;
        ofstream out;
        string fileName;

        DBase(const char* fileName){
            DBase::fileName = fileName;
        }

        void save(Barang data){
            DBase::out.open(DBase::fileName,ios::app);
            DBase::out << data.stringify();
            DBase::out.close();
        }
        
        void showAll(){
            DBase::in.open(DBase::fileName,ios::in);
            string id_barang, nama_barang, harga_barang, stock_barang;
            int index = 1;

            while (!DBase::in.eof())
            {
                DBase::in >> id_barang;
                DBase::in >> nama_barang;
                DBase::in >> harga_barang;
                DBase::in >> stock_barang;
                
                cout << index++ << ".\t";
                cout << id_barang << "\t";
                cout << nama_barang << "\t";
                cout << harga_barang << "\t";
                cout << stock_barang << endl;
            }
            
            DBase::in.close();
        }

};

int main()
{
    string id_barang;
    string nama_barang;
    string harga_barang;
    string stock_barang;

    cout << "Masukan ID Barang : ";
    cin >> id_barang;
    cout << "Masukan Nama Barang : ";
    cin >> nama_barang;
    cout << "Masukan Harga Barang : ";
    cin >> harga_barang;
    cout << "Masukan Stock Barang : ";
    cin >> stock_barang;

    Barang dataBarang = Barang(id_barang, nama_barang, harga_barang, stock_barang);
    DBase dataBase = DBase("data.xls");

    dataBase.save(dataBarang);
    
    dataBase.showAll();
}
