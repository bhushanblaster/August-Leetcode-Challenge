/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        /*if(s.size()<=1)
            return true;
        int i=0;
        int j=s.size()-1;
        
        while(i<j)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
            {
                if((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z') || (s[j]>='0' && s[j]<='9'))
                {
                    if(((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) && 
                       ((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z'))
                      )
                    {
                        int x = s[i]>s[j]?(s[i]-s[j]):(s[j]-s[i]);
                        cout<<x;
                        if(x==0 || x==32)
                        {
                            i++;j--;
                        }
                        else
                            return false;    
                    }
                    else
                    {
                        if(s[i]==s[j])
                        {
                            i++;j--;
                        }
                        else
                            return false;
                    }
                }
                else
                {
                    j--;
                }
            }
            else
            {
                i++;
            }
        }
        return true;*/
        
        for(int i=0,j=s.size()-1;i<j;i++,j--)
        {
            while(!isalnum(s[i]) && i<j)
                i++;
            while(!isalnum(s[j]) && j>i)
                j--;
            if(tolower(s[i])!=tolower(s[j]))
                return false;
        }
        return true;
    }
};
