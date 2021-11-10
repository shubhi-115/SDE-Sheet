//Set Matrix Zeroes
class Solution {
public:
// we have kept the record of first row to first col and the record of first column to the cols variable 
    void setZeroes(vector<vector<int>>& mat) {
        int cols=true, col=mat[0].size(), row=mat.size();
        for(int i=0;i<row;i++){
            if(mat[i][0]==0) cols=false;
            for(int j=1;j<col;j++){
                if(mat[i][j]==0) {
                    mat[0][j]=0;
                    mat[i][0]=0;
                }
            }
        }
       for(int i=row-1;i>=0;i--){
           for(int j=col-1; j>=1; j--)
               if(mat[i][0]==0 || mat[0][j]==0)
                   mat[i][j]=0;
               if(cols==false) mat[i][0]=0;
       } 
    }
};