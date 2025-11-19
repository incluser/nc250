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

/*
The idea of the algorithm is to search target - nums[i], like in example [2,7] and target = 9

We store in map {9-2: 0} -> {7:0}
And on second iteration we check if we have key 7, and turns out there is. Return [i and map.get(nums[i])]

Remember, we store in map {target - element: his_index}

*/