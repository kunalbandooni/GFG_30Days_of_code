/*

Given a matrix of size N x M. You have to find the Kth element which will obtain while traversing the matrix spirally starting from the top-left corner of the matrix.

Example 1:

Input: 
N = 3, M = 3, K = 4
A[] = {{1, 2, 3}, 
       {4, 5, 6}, 
       {7, 8, 9}}
Output: 
6
Explanation: Spiral traversal of matrix: 
{1, 2, 3, 6, 9, 8, 7, 4, 5}. Fourth element
is 6.

Example 2:

Input: 
N = 2, M = 2, K = 2 
A[] = {{1, 2},
       {3, 4}} 
Output: 
2
Explanation: Spiral traversal of matrix: 
{1, 2, 4, 3}. Second element is 2.

*/
class Solution{
	public:
	int findK(vector<vector<int>> &a, int r, int c, int k)
    {
        // Your code goes here
        vector<int> v;
        int i=0,x=0,y=0,count=0;
        while(x<r && y<c){
            for(i=y;i<c;i++)
                v.push_back(a[x][i]);
            x++;
            for(i=x;i<r;i++)
                v.push_back(a[i][c-1]);
            c--;
            if(y<c){
                for(i=c-1;i>=y;i--)
                    v.push_back(a[r-1][i]);
                r--;
            }
            if(x<r){
                for(i=r-1;i>=x;i--)
                    v.push_back(a[i][y]);
                y++;
            }
        }
        return v[k-1];
    }
};