/*

Escape the Forbidden Forest

Penelope and her classmates are lost in the Forbidden Forest and the Devil is out
to get them. But Penelope has magical powers that can build bridges across the 
dangerous river and take her friends to safety. The only bridges that can withstand 
the Devil's wrath are the ones built between two similar trees in the forest. 
Given str1 and str2 denoting the order of trees on either side of the river, find
the maximum number of bridges that Penelope can build and save everyone from the Devil. 
Note: Each tree in the forest belongs to one of the 3 categories represented by * or # or @

Example 1:

Input:
str1 = "*@#*" 
str2 = "*#"
Output:
2
Explanation:
str1 = "*@#*" and str2 = "*#" 
Two bridges can be built between the banks 
of the river in the following manner. 
* @ # *
|      |
*     #

Example 2:

Input:
str1 = "***"
str2 = "##"
Output:
0

Your Task:
You don't need to read input or print anything. Complete the function build_bridges() that takes str1 and str2 as input parameters and returns the maximum number of bridges that can be built. 

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(N*M)

*/
class Solution{
    public:
    int build_bridges(string str1,string str2){
        int ans=0;
        int m=str1.length();
        int n=str2.length();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
            dp[i][0]=0;
        for(int i=0;i<=n;i++)
            dp[0][i]=0;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                if(str1[i-1]==str2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        return dp[m][n];
        /*
        int a[3]={0},b[3]={0};
        for(int i=0;i<str1.length();i++)
            if('*'==str1[i])
                a[0]++;
            else if('#'==str1[i])
                a[1]++;
            else
                a[2]++;
        for(int i=0;i<str2.length();i++)
            if('*'==str2[i])
                b[0]++;
            else if('#'==str2[i])
                b[1]++;
            else
                b[2]++;
        for(int i=0;i<3;i++)
            ans+=min(a[i],b[i]);
        return ans;*/
    }
};
