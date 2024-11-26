#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    for( i; i <= 10; i++){
        if(i == 5){
            continue;
        } else if(i == 8) {
            break;
        }
        cout << i << endl;
    }
    
    for( i; i <= 10; i++){
        cout << i << endl;
    }
}
