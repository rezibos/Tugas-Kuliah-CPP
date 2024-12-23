#include <iostream>
using namespace std;

string dapatkanWaktuSekarang() {
    time_t sekarang = time(0);
    tm *ltm = localtime(&sekarang);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", ltm);
    return string(buffer);
}

int main()
{
    cout << dapatkanWaktuSekarang();
}
