#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// prototypes
bool containsDuplicate(vector<int> &nums);

int main()
{
      cout << "Hello Leetcode" << '\n';
      vector<int> nums = {1, 2, 3, 1};
      bool result = containsDuplicate(nums);
      cout << result << '\n';
      return 0;
}

/*
217. Contains duplicate

Given array of integers, problem is to find if there is duplicate number

[1,2,3,1] -> true

–––––-------------------------------------

1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9

–––––-------------------------------------

TC: O(N) - in worse case we will iterate all unique elements
SC: O(N) - in worse case where all elements are unique

*/
bool containsDuplicate(vector<int> &nums)
{
      // i am using set which contains unique elements
      unordered_set<int> unique;
      for (int i = 0; i < nums.size(); i++)
      {
            if (unique.count(nums[i]))
            {
                  return true;
            }
            unique.insert(nums[i]);
      }
      return false;
}
