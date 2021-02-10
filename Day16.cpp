/*

Restrictive Candy Crush
Medium Accuracy: 90.37% Submissions: 901 Points: 4

Given a string S and an integer K, the task is to reduce the string by applying the following operation:
Choose a group of K consecutive identical characters and remove them. The operation can be performed any number of times until it is no longer possible.

Example 1:

Input:
K = 2
S = "geeksforgeeks"
Output:
gksforgks
Explanation:
Modified String after each step: 
"geegsforgeeks" -> "gksforgks"

Example 2:

Input:
K = 2
S = "geegsforgeeeks" 
Output:
sforgeks
Explanation:
Modified String after each step:
"geegsforgeeeks" -> "ggsforgeks" -> "sforgeks"

Your Task:  
You don't need to read input or print anything. Complete the function Reduced_String() which takes integer K and string S as input parameters and returns the reduced string.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)

*/
class Solution{
    public:
    string Reduced_String(int k,string s){
        vector< char > res ;
        stack< pair< char , int > > st;
        st.push(make_pair((char)s[0],1));
        for(int i=1;i<s.length();i++){
            if(!st.empty() && s[i]== st.top().first)
                st.top().second++;
            else
                st.push(make_pair((char)s[i],1));
            if(!st.empty() && st.top().second== k)
                st.pop();
        }
        while(!st.empty()){
            for(int i=0;i<st.top().second;i++)
                res.push_back(st.top().first);
            st.pop();
        }
        string result;
        for(int i=res.size()-1;i>=0;i--)
            result += (char)res[i];
        string none = "";
        if(k == 1)
            return none;
        return result;
    }   
};
/*
GFG's Solutino:-

    string Reduced_String(int k,string s){
        if(k == 1){
            string ans = "";
            return ans;
        }
        
        stack<pair<char,int>> st;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                st.push({s[i],1});
            }
            else if(st.top().first==s[i]){
                st.push({s[i],st.top().second+1});
                if(st.top().second==k){
                    int x=k;
                    while(x){
                        st.pop();
                        x--;
                    }
                }
            }
            else if(st.top().first!=s[i]){
                st.push({s[i],1});
            }
        }
        
        while(!st.empty()){
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

*/