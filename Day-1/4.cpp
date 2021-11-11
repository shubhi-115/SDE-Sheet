//Kandane Algorithm ---- for case -1 i stuck 
//Only considering the positive sum forward 
class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int sum=0, maxi= INT_MIN;
        for(int x: a){
            sum+=x;
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        return maxi;
    }
};
// DP Approach
class Solution {
public:
    int maxSubArray(vector<int>& a) {
        vector<int> dp(a.size());
        dp[0]=a[0];
        for(int i=1;i<a.size();i++){
            dp[i]=max(0,dp[i-1])+a[i];
          
        }
        return *max_element(dp.begin(),dp.end());
    }
};