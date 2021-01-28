/*

Question:-
Given a positive integer N, you have to find nth Natural Number after removing all the numbers containing 9.

Input:- 
9
Output:-
10

Explanation:-
After removing 9, the nymbers are: 1 2 3 4 5 6 7 8 19 

*/
class Solution{
    long long find(long long n){
        long ans=0,f=1;
        while(n!=0){
            long a=n%9;
            n=n/9;
            ans=ans+f*a;
            f=f*10;
        }
        return ans;
    }
};