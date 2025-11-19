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

–––––-------------------------------------


–––––-------------------------------------


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