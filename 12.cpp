/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int>ans;
     
        if(rowIndex==0)
            return {1};
        ans.push_back(1);
        ans.push_back(1);
        if(rowIndex == 1)
            return ans;
        for(int i=2;i<=rowIndex;i++)
        {
            int temp=ans[0];
            int temp1 ;//= ans[1];
            for(int j=1;j<ans.size();j++)
            {
                temp1 = ans[j];
                ans[j] = ans[j]+temp;
                temp = temp1;
            }
            ans.push_back(1);
        }
        
        return ans;
    }
};
