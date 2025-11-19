#include <iostream>
#include <vector>
using namespace std;

// prototypes

int main()
{
      cout << "Hello Leetcode\n";
      return 0;
}

/*
169. Majority element

Given array of integers and some element appears more than n / 2 times. Need to find this element

[3,2,3] -> 3

–––––-------------------------------------

n == nums.length
1 <= n <= 5 * 10^4
-10^9 <= nums[i] <= 10^9
The input is generated such that a majority element will exist in the array.

–––––-------------------------------------

TC: O(n)
SC: O(1)

*/

int majorityElement(vector<int> &nums)
{
      int potentialCandidate = nums[0];
      int frequency = 1;

      for (int i = 1; i < nums.size(); i++)
      {
            if (nums[i] == potentialCandidate)
            {
                  frequency++;
            }
            else
            {
                  frequency--;
            }

            // starting new candidate
            if (frequency == 0)
            {
                  potentialCandidate = nums[i];
                  frequency = 1;
            }
      }
      return potentialCandidate;
}