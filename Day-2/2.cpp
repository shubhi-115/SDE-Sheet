//Merged Intervals
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        //we got the consecutive intervals that need to be merged
        vector<vector<int>> ans;
        vector<int> temp= a[0];
        for(auto x: a){
            if(x[0] <=temp[1])
            {
               temp[1]=max(temp[1],x[1]);
            }
           else{
               ans.push_back(temp);
               temp=x;
           }
        }
        ans.push_back(temp);
        return ans;
    }
};