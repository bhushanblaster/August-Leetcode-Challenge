/*
A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.
 
If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
 
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin. 

Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 

Notes:

S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.
*/

class Solution {
public:
    string toGoatLatin(string S) {
        
        int len = S.size();
        int no = 1;
        string ans;
        int i=0;
        while(true)
        {
            bool vowel = false;
            if(S[i]=='a' || S[i]=='A' || S[i]=='e' || S[i]=='E'|| S[i]=='i'||S[i]=='I'||S[i]=='o'||S[i]=='O'||
               S[i]=='u'|| S[i]=='U')
                vowel = true;
            int j; 
            string append;
            if(vowel)
                 j=i;
            else
            {
                j=i+1;
                append=S[i];
            }
            append+="ma";
            int num = no;
            while(num--)
            {
                append+="a";
            }
                
            no++;
            if(j<len)
            {
                while(S[j]!=' ' && S[j] !='\0')
                {
                    ans+=S[j];
                    j++;
                }
                ans+=append;
                if(S[j]==' ')
                {
                    ans+=' ';
                    i = j+1;
                }
                    
                else
                    break;
            }
            else
            {
                ans+=append;
                break;
            }
        }
        return ans;
    }
};
