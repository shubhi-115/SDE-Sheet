//Finding duplicate Number 
// Approach ...... sort or count array of element or linked list 
class Solution {
public:
    // Linked list method ...... 
    /*
    Go to the first index and then go to the index of its element and so on 
    take fp and sp ... move by 2 and 1 when they meet 
    fp ko first index p rakho phir dono by 1 move krro and then slow gives you the answer
    **/
    int findDuplicate(vector<int>& a) {
        int slow=a[0],fast=a[0];
        do{
            slow=a[slow];
            fast=a[a[fast]];
        }while(slow!=fast);
            fast=a[0];
        while(slow!=fast){
            slow=a[slow];
            fast=a[fast];
        }
        return slow;
    }
};