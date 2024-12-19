#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // Header program
    cout << "Penjumlahan Matriks" << endl;
    cout << "Deskripsi : Menghitung total semua elemen dalam matriks" << endl;
    cout << "===============================================" << endl;

    // Input jumlah baris dan kolom
    cout << "Input jumlah baris = ";
    cin >> rows;
    cout << "Input jumlah kolom = ";
    cin >> cols;

    // Deklarasi matriks
    int matrix[10][10]; // Maksimal ukuran 10x10 untuk kemudahan
    int total = 0;

    // Input elemen matriks
    cout << "Input elemen =" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Elemen matriks [" << i + 1 << "][" << j + 1 << "] = ";
            cin >> matrix[i][j];
            total += matrix[i][j];
        }
    }

    // Footer program
    cout << "===============================================" << endl;
    cout << "Total elemen matriks = " << total << endl;

    return 0;
}
