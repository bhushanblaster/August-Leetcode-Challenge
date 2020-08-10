/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int>ans;
        for(auto n : nums)
        {
            mp[n]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second == 2)
                ans.push_back(it->first);
        }
        return ans;
    }
};
