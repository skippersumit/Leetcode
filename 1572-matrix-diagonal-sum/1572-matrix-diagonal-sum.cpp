class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        // 00 01 02
        // 10 11 12
        // 20 21 22
        int sum = 0,n = mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) sum += mat[i][j];
                else if( i + j == n - 1) sum += mat[i][j];
            }
        }
        return sum;
    }
};