// Repeating and Missing Number
/*
first find the sum of n natural number and sum of 1^2 + 2^2+ ....... 
then substract it with current array sum 
you will observe that x = missing number y= repeating number
x-y =  sum of n natural number - current array sum
x^2-y^2 =  sum of 1^2 + ... - current array sum with squaring elements
then cal x+y and then value of x and y 
you should know matrix exponentation in order to cal the squares because its TLE

// Another approach
 Xor all a[i] then continue to xor with 1 to n
 you have got a num = x-y where x is the missing no and y is repeating no .
 Now task is to separate the num , calculate its rightmost set bit 
 see this bit is set or not in whole array and if set put in first bucket (xor with x) and if not put in second bucket
 (xor with y) and do the same with 1 to n again
 you have got x and y , cheeck the array for distinguishing the missing and repeating
**/

vector<int> Solution::repeatedNumber(const vector<int> &a) {
    int n=a.size();
   long long simplesum= n*(n+1)/2;
   long long squaresum = n*(n+1)*(2*n+1)/6;
   long long sum=0;long long sqsum=0;
   for(int x:a) {
       sum+=x;
      sqsum+= (x*x);
   }
   int xminusy= (int)(simplesum - sum);
   int xsqminusysq = (int)(squaresum - sqsum);
   int xplusy = xsqminusysq/xminusy;
   int x = (xminusy + xplusy)/2;// it is the missing Number
   int y= xplusy - x;// it is the repeatedNumber

  return {y,x};
}
// XOR ONE

vector<int> Solution::repeatedNumber(const vector<int> &a) {
 int n=a.size();
 int xr= 0;
 for(int x: a) xr^=x;
 for(int i=1;i<=n;i++) xr^=i;
 int num = xr;
 // now we need to separate num
 // Getting the rightmost set bit
 int set_bit = num & ~(num-1);
int x=0,y=0;
for(int i=0;i<n;i++){
    if(a[i]&set_bit) x^=a[i];
    else y^=a[i];
}
for(int i=1;i<=n;i++){
    if(i&set_bit) x^=i;
    else y^=i;
}
int rep=0;
for(int i=0;i<n;i++){
    if(a[i]==x) rep++;
}
if(rep) return {x,y};
return {y,x};

}
