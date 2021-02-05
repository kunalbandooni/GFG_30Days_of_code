/*
I was unable to do this code, so just tried by using hint, then saw the whole solution :(

Secret Cipher

Geek wants to send an encrypted message in the form of string S to his friend Keeg along with instructions on how to decipher the message. To decipher the message, his friend needs to iterate over the message string from left to right, if he finds a '*', he must remove it and add all the letters read so far to the string. He must keep on doing this till he gets rid of all the '*'.
Can you help Geek encrypt his message string S? 

Note: If the string can be encrypted in multiple ways, find the smallest encrypted string. 

Example 1:
Input: S = "ababcababcd"
Output: ab*c*d
Explanation: We can encrypt the string 
in following way : "ababcababcd" -> 
"ababc*d" -> "ab*c*d"

Example 2:
Input: S = "zzzzzzz"
Output: z*z*z
Explanation: The string can be encrypted 
in 2 ways: "z*z*z" and "z**zzz". Out of 
the two "z*z*z" is smaller in length.

Your Task: 
You don't need to read input or print anything. Complete the function secretCipher() which takes the message string S as input parameter and returns the shortest possible encrypted string.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/
class Solution{
    public:
    void fill_array(string s, int a[])
    {
        a[0] = 0;
        for(int i=1 ; i<s.size() ; i++)
        {
            int series = a[i-1];
            while(series)
            {
                if( s[series] == s[i] )
                {
                    a[i] = series+1;
                    break;
                }
                series = a[series-1];
            }
            if(!series)
                a[i] = ( s[i] == s[0] );
        }
    }
    
    string compress(string s){
        int a[(int)s.size()];
        // ith element of array a stores the length of longest
        // proper suffix which is also a proper prefix
        // for substr s[0] to s[i]
        fill_array( s, a );
        
        stack <char> shortened;
        
        for(int i=s.size()-1 ; i>0 ; i--)
        // we start checking string from last index
        {
            if(i%2==0) { shortened.push(s[i]); continue; }
            // for even index, string length is odd
            // hence it cannot be divided into two
            // so we simply push ith character in stack
            
            bool star_here=0;
            // star_here will be made TRUE if substring s[0] to s[i]
            // can be divided into identical halves
            int suffix = a[i];
            int substrlen = i+1;
            // suffix and substring length are also meant for
            // substring s[0] to s[i]
            
            if(suffix*2 >= substrlen)
                if( substrlen % (substrlen-suffix) == 0 )
                    if( ( substrlen / (substrlen-suffix) ) % 2 == 0 )
                    // these conditions, if true, imply that, substring
                    // can be divided into 2 identical halves
                        star_here = 1;
            
            if(star_here)
                { shortened.push('*'); i = i/2 + 1; }
                // adding * to stack and moving index as required
            else
                shortened.push(s[i]);
                // else, simply adding character to stack
        }
        
        string ret;
        ret.push_back( s[0] );
        
        while( !shortened.empty() )
        {
            // since we analysed input string from end to start
            // removing elements from stack and pushing back to
            // output string will reverse them back to required order
            ret.push_back( shortened.top() );
            shortened.pop();
        }
        
        return ret;
    }
};