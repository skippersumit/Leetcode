class Solution {
public:
     int getMinVal(vector<int> &nextRow, int &col, int &n){

        if( col == 0 ){
            return n==1? nextRow[col] : min(nextRow[col], nextRow[col+1]);
        }
        else if( col == n-1 ){
            return min(nextRow[col], nextRow[col-1]);
        }
        return min(nextRow[col], min(nextRow[col-1], nextRow[col+1]));
    }

    int minFallingPathSum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                mat[i][j] += getMinVal(mat[i+1], j, n);
            }
        }
        return *min_element(mat[0].begin(), mat[0].end());
    }
};