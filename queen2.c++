#include<iostream>
#include<string>
#include<vector>

using namespace std;


void printBoard(vector<vector<char>> &board) {
    int n = board.size();

    for(int i = 0; i<n; i++) {
        for(int j=0;j<n;j++) {
            cout << board[i][j] << " ";
        }
        cout << "---------------------" << endl;
    }
}

void nQeens(vector<vector<char>> board, int row) {
    int n=board.size();
    if(row == n) {
        printBoard(board);
        return;
    }

    for(int j=0; j<n; j++) {
        board[row][j] = "Q";
        nQeens(board, row + 1);
        board[row][j] = ".";
    }
}
int main() {
    vector<vector<char>> board;
    int n=2;

    for(int i=0; i<n; i++) {
        vector<char> newRow;
        for(int j=0; j<n;j++) {
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    return 0;
}