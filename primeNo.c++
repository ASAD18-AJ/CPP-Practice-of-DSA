#include <iostream>
using namespace std;

int main()
{
    int n=7;
    bool isPrime = true;

    for(int i=2; i<n; i++) {
        if(n%i==0) {
            isPrime = false;
            break;
        }
    }

    if(isPrime) {
        cout << "number is prime" << endl;
    } else {
        cout << "number is not prime" << endl;
    }
    

    return 0;
}