#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// prototypes
string longestCommonPrefix(vector<string> &strs);
int main()
{
      cout << "Hello Leetcode" << '\n';
      return 0;
}

/*
14. Longest common prefix

Given an array of strings. We asked to find the string prefix that is common in all strings

["flower","flow","flight"] -> "fl"

–––––-------------------------------------

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.

–––––-------------------------------------

TC: O(M*N) - M = the length of first string, N = list size
SC: O(1)

*/

string longestCommonPrefix(vector<string> &strs)
{
      int stopIndex = 0;
      bool shouldBreak = false;
      for (int i = 0; i < strs[0].size(); i++)
      {
            for (int j = 1; j < strs.size(); j++)
            {
                  if (strs[0][i] != strs[j][i])
                  {
                        shouldBreak = true;
                        break;
                  }
            }
            if (shouldBreak)
            {
                  break;
            }
            stopIndex++;
      }
      return strs[0].substr(0, stopIndex);
}

/*
Idea is simple, we iterate through first string and check his prefix with all other strings and stop when prefix char doesn't match
*/