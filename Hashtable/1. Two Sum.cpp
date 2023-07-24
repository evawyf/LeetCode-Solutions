/*
1. Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

*/

#include <vector>
#include <unordered_map>
using namespace std; 

// time O(n) linear 
// space O(n) extra space depends on how many potential match num which store in hash table (most n elements)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; 
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.find(nums[i]) == mp.end()) {
                // doesn't find , so store potential match num 
                mp.insert( {target - nums[i], i} );
            } else {
                return {i, mp[nums[i]]};
            }
        }
        return {}; 
    }
};