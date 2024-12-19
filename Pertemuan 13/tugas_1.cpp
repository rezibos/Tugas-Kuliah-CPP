#include <iostream>
using namespace std;

int main() {
    string countries[10] = {"Indonesia", "Malaysia", "Singapura", "Thailand", "Vietnam", "Filipina", "Kamboja", "Laos", "Myanmar", "Brunei"};

    cout << "Negara dengan indeks ke-2: " << countries[1] << endl;
    cout << "Negara dengan indeks ke-5: " << countries[4] << endl;
    cout << "Negara dengan indeks ke-7: " << countries[6] << endl;
    cout << "Negara dengan indeks ke-10: " << countries[9] << endl;

    cout << "\nMasukkan 10 nama negara baru:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Negara ke-" << (i + 1) << ": ";
        cin >> countries[i];
    }

    cout << "\nList nama negara yang telah dimasukkan:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Negara ke-" << (i + 1) << ": " << countries[i] << endl;
    }

    return 0;
}