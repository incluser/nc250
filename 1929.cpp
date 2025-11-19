#include <iostream>
#include <vector>
using namespace std;

// prototypes
vector<int> getConcatenation(vector<int> &nums);

int main()
{
      cout << "Hello Leetcode\n";
      return 0;
}

/*
1929. Concatenation of Array

Given array of integers, problem is to concatenate array with itself

[1,2,3] -> [1,2,3,1,2,3]

–––––-------------------------------------

1 <= n <= 1000
1 <= nums[i] <= 1000

–––––-------------------------------------

TC: O(2N) -> O(N)
SC: O(2N) -> O(N)

*/
vector<int> getConcatenation(vector<int> &nums)
{

      vector<int> res;
      int length = nums.size();
      for (int i = 0; i < length * 2; i++)
      {
            // % operator helps us remain in range 0:size() (included:not_included)
            res.push_back(nums[i % length]);
      }
      return res;
}
