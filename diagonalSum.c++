#include<iostream>
using namespace std;

int diagonalSum(int i=0;i<n;i++) {
    int sum = 0;

    //O(N)
    for(int i=0;i<n;i++) {
        sum += mat[i][i];
        if(i != n-i-1) {
            sum += mat[i][n-i-1];
        }
    }
    cout << "sum = " << sum << endl;
    return sum;
}

int main() {
    int matrix[4][4] {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    }
    diagonalSum(matrix, 4);
    return 0;
}