#include <iostream>
using namespace std;

void bintang(){
    for(int i = 1; i <= 6; i++) {
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    bintang();
}