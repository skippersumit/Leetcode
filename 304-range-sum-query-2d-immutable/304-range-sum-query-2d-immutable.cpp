    class NumMatrix {
public:
    vector<vector<int>>preMat;
    NumMatrix(vector<vector<int>>& matrix) {
        preMat = matrix;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                preMat[i][j] = preMat[i][j] + preMat[i][j-1]; 
            }
        }
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                preMat[i][j] = preMat[i][j] + preMat[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 and col1 == 0)  
            return preMat[row2][col2];
        else if(row1 == 0)
            return preMat[row2][col2] - preMat[row2][col1-1];
        else if(col1 == 0)
            return preMat[row2][col2] - preMat[row1-1][col2];
        else
            return preMat[row2][col2] - preMat[row1-1][col2] - preMat[row2][col1-1] + preMat[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

