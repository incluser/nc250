#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// prototypes

int main()
{
      cout << "Hello Leetcode" << '\n';
      return 0;
}

/*
27. Remove element

We asked to mutate incoming array by deleting given val inside nums.
Well we dont really have to delete an element, its enough to shift other values to the start, btw we have to save the relative order of other elements

–––––-------------------------------------

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100

–––––-------------------------------------

TC: O(N)
SC: O(1)


*/

int removeElement(vector<int> &nums, int val)
{
      int moves = 0;
      for (int i = 0; i < nums.size(); i++)
      {
            if (nums[i] != val)
            {
                  nums[moves++] = nums[i];
            }
      }

      return moves;
}