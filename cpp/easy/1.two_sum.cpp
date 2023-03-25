#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    // Brute-force approach
    // Time: O(n^2)
    // Space: O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {

            for (int k = 0; k < nums.size(); ++k) {
                if (i == k) {
                    continue;
                }
                else if (target > 0 && nums[i] > target) {
                    continue;
                }
                else if (target < 0 && nums[i] < target) {
                    continue;
                }
                else if (nums[i] + nums[k] == target) {
                    return vector<int> {i, k};
                }
            }
        }

        return {0, 0};
    }

    // Smarter approach with a hash table. This is much faster.
    // Time: O(n)
    // Space: O(n)
    vector<int> twoSum_v2(vector<int>& nums, int target) {
        map<int, int> hashTable;

        for (int i = 0; i < nums.size(); ++i) {
            auto iter = hashTable.find(target - nums[i]);
            if (iter != hashTable.end()) {
                return {i, iter->second};
            }
            else {
                hashTable[nums[i]] = i;
            }
        }

        return {0, 0};
     }

};


/* main.cpp
#include "./easy/1.two_sum.cpp"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
   Solution s;

//    vector<int> v = {-1,-2,-3,-4,-5};
//    int t = -8;

   vector<int> v = {2,7,11,15};
   int t = 9;

   for (auto n : s.twoSum_v2(v, t)) {
       cout << n << " ";
   }

   cout << endl;
}
*/

/*
 https://leetcode.com/problems/two-sum/description/

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9

Only one valid answer exists.

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
 */
