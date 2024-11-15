#include <iostream>
using namespace std;

int main()
{
    int i = 1;

    while (i <= 100)
    {
        if(i % 2 == 0){
            cout << i << ". Anggka Genap" << endl;
        } else {
            cout << i << ". Anggka Ganjil" << endl;
        }

        i++;
    }
    
}
