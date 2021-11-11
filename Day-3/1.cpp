// Search in a 2d matrix
/* 
linearly search 0(n*m) 
binary search on each row 0(n mlogm)
using two pointer

**/
class Solution {
public:
    // starting from upper right corner , Go left when target is smaller and down when target is greater
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size(),m= mat[0].size();
        int i=0,j=m-1;
        while(i<n && j>=0){
            if(mat[i][j]==target)
                return true;
             else if (mat[i][j]<target)
                 i++;
            else j--;
        }
        return false;
    }
};