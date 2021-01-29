/*

Number of minimum picks to get 'k' pairs of socks from a drawer

A drawer contains socks of n different colours. The number of socks available of ith colour is given by a[i] where a is an array of n elements. Tony wants to take k pairs of socks out of the drawer. However, he cannot see the colour of the sock that he is picking. You have to tell what is the minimum number of socks Tony has to pick in one attempt from the drawer such that he can be absolutely sure, without seeing their colours, that he will have at least k matching pairs.

Example 1:

Input: N = 4, a[] = {3, 4, 5, 3}, K = 6
Output: 15
Explanation: The worst case scenario, after 
14 picks will be 3,3,3,3 or 3,1,5,3 where 
each number represents picks of socks of 
one colour. Hence, 15th pick will get the 
5th pair for sure.

Example 2:

Input: N = 2, a[] = {4, 6}, K = 3
Output: 7
Explanation: The Worst case scenario after 6 
picks can be 3,3 or 1,5 or 5,1 of each 
coloured socks. Hence 7th pick will ensure 
3rd pair. 

*/
// } Driver Code Ends
class Solution{
	public:
	int find_min(int a[], int n, int k) {
        // Your code geos here
        int pairs=0,sum=0;
        for(int i=0;i<n;i++){
            pairs+=a[i]/2;
            if(a[i]%2==0)
                sum+=a[i]/2-1;
            else
                sum+=a[i]/2;
        }   
        if(k>pairs)
            return -1;
        if(sum>=k)
            return (2*k+n-1);
        return (sum+n+k);
    }
};