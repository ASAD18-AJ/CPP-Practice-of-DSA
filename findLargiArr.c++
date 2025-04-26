#include<iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max = arr[0];

    for(int i=0;i<n;i++) {
        if(arr[i] > max) {
            max = arr[i];
            cout << "assigning val " << arr[i] << " to max\n";
        }
    }
    cout<< "Max =" << max << endl;
    return 0;
}