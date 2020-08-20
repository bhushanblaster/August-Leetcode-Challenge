/*
Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Note:

1 <= N <= 9
0 <= K <= 9
*/
class Solution {
public:
    void check(int num,int k,int n,vector<int>& ans)
    {
        if(n==1)
        {
            ans.push_back(num);
            return;
        }
        if(num%10-k >= 0)
        {
            check(num*10+(num%10-k),k,n-1,ans);
        }
        if(k)
        {
            if(num%10+k <=9)
            {
                check(num*10+(num%10 + k),k,n-1,ans);
            }
        }
       
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N==1)
            return {0,1,2,3,4,5,6,7,8,9};
        
        vector<int>ans;
        for(int i=1;i<10;i++)
        {
            check(i,K,N,ans);
        }
        return ans;
    }
};
