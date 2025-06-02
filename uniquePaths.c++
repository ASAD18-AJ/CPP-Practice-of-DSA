class Solution {
public:
    int uniquePaths(int m, int n,int i=0,int j=0) {
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;

        int v1 = uniquePaths(m,n,i+1,j);
        int v2 = uniquePaths(m,n,i,j+1);

        return v1+v2;
    }
};