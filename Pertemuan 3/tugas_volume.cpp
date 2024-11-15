#include <iostream>
#define phi 3.14
#define jari_jari 7
#define tinggi 24

using namespace std;

int main ()
{
    float volume = phi*jari_jari*jari_jari*tinggi;

    cout << "Phi :" << phi << endl;
    cout << "Jari-jari :" << jari_jari << endl;
    cout << "Tinggi :" << tinggi << endl;
    cout << "Volume Tabung :" << volume << endl;

    return 0;
}