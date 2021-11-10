// Next Permutation by intuition 
/*
Algorithm
1- Traverse from last and get the first index where a[i]<a[i+1] mark as ind1
2- Traverse from last and get the first index where a[i]>a[ind1] in order to swap 
3- swap(a[ind1],a[ind2]);
4- ind1 is settled so reverse later array=> reverse(a.begin()+ind1+1,a.end());
**/
class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n=a.size();
        int i;
        for(i=n-2;i>=0;i--){
            if(a[i]<a[i+1]) break;
        }
        if(i<0){
            reverse(a.begin(),a.end()); // in case of last permutaion 3 2 1 we have to return 1 2 3
        }else{
             for(int l=n-1;l>i;l--){
            if(a[l]>a[i]){
                swap(a[l],a[i]);
                reverse(a.begin()+i+1,a.end());
                break;
            }
        }
        }
       
    }
};