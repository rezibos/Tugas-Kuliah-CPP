#include <iostream>
using namespace std;

int main()
{
    for(int i = 1; i <= 10; i++){
        if(i == 5){
            continue;
        } else if(i == 8){
            break;
        } else if (i <= 7){
            cout << i << endl;
        }
    }

    for(int i = 9; i <= 10; i++){
        cout << i << endl;
    }
}
