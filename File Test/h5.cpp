#include <iostream>
#include <iomanip>
using namespace std;

// RP

struct Barang {
    double harga;
    int stok;
};

int main() {
    Barang barang = {2000.111, 10};

    cout << fixed << setprecision(3) << barang.harga << " " << barang.stok << "\n";
    return 0;
}
