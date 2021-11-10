//Pascal's Triangles
// Approach 1 by formula
class Solution {
public:
    int calc(int n,int r){
        if(r==0) return 1;
        int ans=1;
        for(int i=1;i<=r;i++){
            ans*=n;
            n--;
            ans/=i;
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        // formula - (r-1)C(c-1)
        vector<vector<int>> ans;
        ans.push_back({1});
       for(int i=2;i<=numRows;i++){
           vector<int> res;
           for(int j=1;j<=i;j++){
               // i-1Cj-1
               int x=calc(i-1,j-1);
               res.push_back(x);
           }
           ans.push_back(res);
       }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // second approach is by real intuition
        vector<vector<int>> ans(numRows);// have decided row number
        for(int i=0;i<numRows;i++){
            ans[i].resize(i+1);
            ans[i][0]=1, ans[i][i]=1;// first col and last col is 1 
            for(int j=1;j<i;j++){
                ans[i][j]= ans[i-1][j-1]+ans[i-1][j];
            }
            
        }
        return ans;
    }
};