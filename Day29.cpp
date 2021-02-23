/*

Elixir of Life

Flamel is making the Elixir of Life but he is missing a secret ingredient, a 
set of contiguous plants (substring) from the Garden of Eden. The garden 
consists of various plants represented by string S where each letter represents
a different plant.  But the prophecy has predicted that the correct set of 
plants required to make the potion will appear in the same contiguous pattern 
(substring) at the beginning of the forest (prefix), the end of the forest
(suffix), and will also be the most frequent sequence present in the entire forest.

Identify the substring of plants required to make the elixir and find out the
number of times it appears in the forest. 

Example 1:
Input: S = "ababaaaab"
Output: 3
Explanation: substring "ab" is a prefix, 
a suffix and appears 3 times.


Example 2:
Input: S = "aaaa"
Output: 4
Explanation: substring "aaaa" occurs 1 time, 
substring "aaa" occurs 2 times, substring 
"aa" occurs 3 times, substring "a" occurs 
4 times. All of them are proper prefixes 
and suffixes. But, "a" has the maximum 
frequency.

Example 3:
Input: S = "abcdef"
Output: 1

Your Task: 
You don't need to read input or print anything. Complete the function
maxFrequency() which takes string S as input parameter and returns the answer

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)

*/
//     METHOD - 1 :
class Solution{
    public:
    int maxFrequency(string str){
        string lps;
        int ans=0;
        int n=str.length();
        for(int i=1;i<n;i++){ 
            if(str.substr(0,i)==str.substr(n-i,i)){
                lps=str.substr(0,i);
                break;
            }
        }
        for(int i=0;i<=n-lps.length();i++)
            if(str[i]==lps[0]){
                int j=0;
                for(j=0;j<lps.length();j++)
                    if(lps[j]!=str[i+j])
                        break;
                if(j==lps.length())
                    ans++;
            }
        return ans;	
    }
};

//       METHOD - 2 :
//       Z-FUNCTION ALGORITHM
class Solution
{
    public:
    vector<int> z_function(string s)
    {
    	int n = s.size();
    	vector<int> z(n);
    	for(int i = 1, l = 0, r = 0; i < n; i++)
    	{
    		if(i <= r)
    			z[i] = min(r - i + 1, z[i - l]);
    		
    		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
    			z[i]++;
    		
    		if(i + z[i] - 1 > r)
    			l = i, r = i + z[i] - 1;
    	}
    
    	return z;
    }
     
     
    void update(int idx, int val, vector<int> &bit, int n)
    {
    	if(idx == 0)
    		return;
    
    	while(idx <= n)
    	{
    		bit[idx] += val;
    		idx += (idx&-idx);
    	}
    }
     
    int pref(int idx, vector<int> &bit)
    {
    	int ans = 0;
    	while(idx > 0)
    	{
    		ans += bit[idx];
    		idx -= (idx&-idx);
    	}	
    
    	return ans;
    }
    
    int maxFrequency(string str)
    {
    	int n = str.size();
    	vector<int> z = z_function(str);
    
    	vector<int> bit(n+5, 0);
    
    	for(int i = 1; i < n; i++)
    		update(z[i], 1, bit, n);
    
    	map<int, int> m;
    
    	for(int i = n-1; i >= 1; i--)
    	{
    		if(z[i] != (n-i))
    			continue;
    		
    		m[z[i]] += (pref(n, bit) - pref(z[i]-1, bit) + 1);
    	}
    	int ans = 1;
    	for(auto it:m)
    		ans = max(ans, it.second);
    
    	return ans;
    }
};
