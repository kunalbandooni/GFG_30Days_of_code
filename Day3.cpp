/*
Given an array of size N, find the smallest positive integer value that cannot be represented as sum of some elements from the array.

Example 1:

Input: 
N = 6
array[] = {1, 10, 3, 11, 6, 15}
Output: 
2
Explanation:
2 is the smallest integer value that cannot 
be represented as sum of elements from the array.
*/
class Solution
{   
public:
    long long smallestpositive(vector<long long> arr, int n)
    { 
        long long res=1;
        sort(arr.begin(),arr.end());
        // code here 
        /*int c=1;
        
        int sum[n]={0};
        sum[0]=array[0];
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+array[i];
        }
        for(int i=0;i<n;i++){
            if(c==sum[i])
                c++;
            else if(sum[i]>c)
                return c;
        }
        return c;*/
        for (int i = 0; i < n && arr[i] <= res; i++)
            res = res + arr[i];
        return res; 
    } 
};