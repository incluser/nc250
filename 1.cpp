#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// prototypes
vector<int> twoSum(vector<int> &nums, int target);
int main()
{
      cout << "Hello Leetcode" << '\n';
      return 0;
}

/*
1. Two sum

Given array of integers and target k, need to find pairs of number with sum equals to k and return indices

[2,4,7,3]  k = 9 -> [0,2] - (2,7)

–––––-------------------------------------

2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
Only one valid answer exists.

–––––-------------------------------------

TC: O(N)
SC: O(N)

*/

vector<int> twoSum(vector<int> &nums, int target)
{

      // idea is to save {target - element : index} and if we took an examlpe [2,7] with target = 9 it will be clear
      unordered_map<int, int> pairs;
      vector<int> result = {-1, -1};
      for (int i = 0; i < nums.size(); i++)
      {
            if (pairs.count(nums[i]))
            {
                  result[0] = i;
                  result[1] = pairs[nums[i]];
                  break;
            }
            else
            {
                  pairs[target - nums[i]] = i;
            }
      }
      return result;
}
