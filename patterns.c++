// star pattern

// 1) outer loop -> rows
// 2) inner loop -> columns/ each rows

#include<iostream>
using namespace std;

// int main() {
//     int n=4;

//     for(int i=1; i<=n;i++) {
//         for(int j=1; j<=i;j++) {
//             cout << "*"<<" ";
//         }
//         cout << endl;
//     }
//     return 0;
// }


// Inverted star pattern

// 1) outer loop -> rows
//    (1 TO N)
// 2) inner loop -> columns/ each rows
//  (1 to n-i+1)

// *  *  *  *  
// *  *  *
// *  *
// *

// int main() {
//     int n=4;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n-i+1;j++) {
//             cout << "* "<<" ";
//         }
//         cout << endl;
//     }

//     return 0;
// }


// half pyramid pattern

// 1) outer loop -> rows
//    (1 TO N)

// 2) inner loop -> columns/ each rows
//    (1 to i) -> j

// 3) print j

// 1 
// 1 2
// 1 2 3
// 1 2 3 4

// int main() {
//     int n=4;
//     for(int i =0;i<=n;i++) {
//         for(int j=1;j<=i;j++) {
//             cout << j<<" ";
//         }
//         cout << endl;
//     }
//     return 0;
// }



// Character pyramid pattern

// (1) Outer loop(row)
//  1-n
// (2) Inner loop(column/each row)

// (3) print character


// int main() {
//     int n=4;
//     char ch='A';

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=i;j++) {
//             // cout << ch<<" ";
//             // ch++;
//             cout << ch<<" ";
//         }
//         cout << endl;
//     }
//     return 0;
// }


// Hollow reactangle pattern

// * * * * * 
// *       * 
// *       *
// * * * * *

// int main() {
//     int n=4;

//     for(int i=1;i<=n;i++) {
//         cout<< "* ";
//         for(int j=1;j<=n-1;j++) {
//             if(i==1 || i==n) {
//                 cout<< "* ";
//             } else {
//                 cout<< "  ";
//             }
//         }
//         cout<< "* "<<endl;
//     }
//     return 0;
// }


// inverted & rotated half pyramid pattern
// i) outer loop -> rows
//     (1 TO N)

// ii) inner loop -> columns/ each rows
//     a)spaces(1 to n-i)
//     b)stars(1 to i)

// ____*
// ___**
// __***
// _****
// *****

// int main() {
//     int n=4;
     
//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n-i;j++) {
//             cout << "  ";
//         }
//         for(int j=1;j<=i;j++) {
//             cout << "* ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// Floyd's triangle pattern


// int main() {
//     int n=15;
//     int num=1;
//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=i;j++) {
//             cout << num++ << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// Diamond Pattern

// ___*
// __***
// _*****
// *******
// _*****
// __***
// ___*

// step-1 (upper half)
// 1) outer loop -> rows
// (1 to n)
// 2) inner loop -> columns/ each rows
// a)spaces(1 to n-i) cout<< " ";
// b)stars(1 to 2*i-1) cout<< "* ";

// i=1 -> 1     2*i-1 =1
// i=2 -> 3     2*i-1=3
// i=3 -> 5     2*i-1=5


// int main() {
//     int n=4;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n-i;j++) {
//             cout << " ";
//         }

//         for(int j=1;j<=2*i-1;j++) {
//             cout << "*";
//         }
//         cout << endl;
//     }

//     // step-2 (lower half)
//     // 1) outer loop -> rows
//     //    (n to 1)
//     // 2) inner loop -> columns/ each rows
//     //    a)spaces(1 to i-1) cout<< " ";
//     //    b)stars(1 to 2*i-1) cout<< "* ";


//     for(int i=n;i>=1;i--) {
//         for(int j=1;j<=n-i;j++) {
//             cout << " ";
//         }

//         for(int j=1;j<=2*i-1;j++) {
//             cout << "*";
//         }
//         cout << endl;
//     }
// }


// print Butterfly pattern

// (1) outer loop -> rows
// (1 to n)
// (2) inner loop -> columns/ each rows
//     a)stars(1 to i)
//     b)spaces(1 to 2*(n-i))
//     c)stars(1 to i)
// lower half
    // (3) outer loop -> rows
//     (n to 1)
//     (4) inner loop -> columns/ each rows
//         a)stars(1 to i)
//         b)spaces(1 to 2*(n-i))
//         c)stars(1 to i)


// int main() {
//     int n=4;

//     //upper half

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=i;j++) {
//             cout << "*";
//         }
//         for(int j=1;j<=2*(n-i);j++) {
//             cout << " ";
//         }
//         for(int j=1;j<=i;j++) {
//             cout << "*";
//         }
//         cout << endl;
//     }
    
//     for(int i=n;i>=1;i--) {
//         for(int j=1;j<=i;j++) {
//             cout << "*";
//         }
//         for(int j=1;j<=2*(n-i);j++) {
//             cout << " ";
//         }
//         for(int j=1;j<=i;j++) {
//             cout << "*";
//         }
//         cout << endl;
//     }

//     return 0;
// }



// assignment questions

// 1) print the 0-1 triangle pattern
// int main() {
//     int n=5;
//     bool val=true;

//     for(int i=0;i<=n;i++) {
//         for(int j=0;j<=i;j++) {
//             cout<<val<<" ";
//             val=!val;
//         }
//         cout<<endl;
//     }
// }


// 4 spaces 5stars
// 3 spaces 5stars
// 2 spaces 5stars
// 1 spaces 5stars
// 0 spaces 5stars

int main() {
    int n=5;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--) {
            cout << " ";
        }
        // for(int j=1;j<=n-i;j++) {
        //     cout << " ";
        // }
        for(int j=1;j<=n;j++) {
            cout << "* ";
        }
        cout << endl;
    }
}