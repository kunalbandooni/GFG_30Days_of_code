/*

Valid Pair Sum

Given an array of size N, find the number of distinct pairs {a[i], a[j]} (i != j) in the array with their sum greater than 0.

Example 1:

Input: N = 3, a[] = {3, -2, 1}
Output: 2
Explanation: {3, -2}, {3, 1} are two 
possible pairs.

Example 2:

Input: N = 4, a[] = {-1, -1, -1, 0}
Output: 0
Explanation: There are no possible pairs.

Your Task:  
You don't need to read input or print anything. Complete the function ValidPair() which takes the array a[ ] and size of array N as input parameters and returns the count of such pairs.

Expected Time Complexity: O(N * Log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 10^5 
-10^4  ≤ a[i] ≤ 10^4

*/
class Solution{
    public:
    /*int binary_search(int a[],int n){
        int l=0,r=n-1;
        if(a[0]>0)
            return 0;
        while(l<r){
            int mid=(l+r)/2;
            if(a[mid]>0&&a[mid-1]<=0)
                return mid;
            else if(a[mid]<0)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }*/
    long long ValidPair(int a[],int n){
        long ans=0;
        int p=0,q=n-1;
        sort(a,a+n);
        while(p<q){
            if(a[p]+a[q]>0){
                ans+=q-p;
                q--;
            }
            else
                p++;
        }
        return ans;
    }
    /*long long ValidPair(int a[], int n){ 
    	sort(a,a+n);
    	long long c=0,sum=0;
    	int k=binary_search(a,n);
    	if(k==-1)
    	    return 0;
    	for(int i=0;i<n;i++){
    	    if(i<k)
    	   	    for(int j=k;j<n;j++){
    	           if(i!=j){
    	                sum=a[i]+a[j];
    	                if(sum>0)
        	                c++;
    	            }
    	        }
    	}
    	return c;
    }*/
};