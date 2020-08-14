/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        
        int ans=0;
        if(s.size()==0)
            return ans;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        
        bool oddSeen=false;
      
        for(auto it : mp)
        {
            if(it.second %2 == 0 )
                ans+=it.second;
            else 
            {
                if(!oddSeen)
                {
                    ans+=it.second;
                    oddSeen = true;
                }
                else
                {
                    ans+=it.second-1;
                }
            }
            
                
        }
        
        return ans;
    }
};
