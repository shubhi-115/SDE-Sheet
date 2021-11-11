//Buy sell stock
class Solution {
public:
    // We have assumed that we are selling the stock at each day starting from the second
    // day and have purchased it at the cheapest price ...... 
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int pro=0;
        int cheapest=a[0];
        for(int i=1;i<n;i++){
            pro=max(pro,a[i]-cheapest);
            cheapest = min(cheapest,a[i]);
        }
        return pro;
    }
};