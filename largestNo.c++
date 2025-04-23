#include<iostream>
using namespace std;

int largestNo(int a,int b, int c) {
    if( a>=b && a>=c) {
        return a;
    } else if(b>=c) {
        return b;
    } else {
        return c;
    }
}
int main() {
    // largestNo(10,20,30);
    // cout << "largest number is: " << largestNo(10,20,30) << endl;

    // int cnt=0;
    // do{
    //     cout<< "aad\n";
    //     cnt++;
    // } while(cnt < 10);
    // return 0;

    // if(1+1 == 2) {
    //     cout << "true" << endl;
    // } else {
    //     cout << "false" << endl;
    // }

    // int i;
    // for(i=1;i<6;i++) {
    //     if(i >3) continue;
    // }
    // cout << i << endl;

    int ++a=10;
    cout << a << endl;
}