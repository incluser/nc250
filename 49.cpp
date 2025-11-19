#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// prototypes
string key_builder(string s);
vector<vector<string>> groupAnagrams(vector<string> &strs);

int main()
{
      cout << "Hello Leetcode" << '\n';
      return 0;
}

/*
49. Group Anagrams

Given an 2D array with strings. We asked to group the anagrams

["abc","cba","key","eky"] -> [["abc","cba"], ["key","eky"]]

–––––-------------------------------------

1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.


–––––-------------------------------------

TC: O(N)
SC: O(N)

*/

string key_builder(string s)
{
      vector<int> frequency(26, 0);
      for (int i = 0; i < s.size(); i++)
      {
            frequency[s[i] - 'a']++;
      }
      string key;
      key.reserve(100);
      for (int f : frequency)
      {
            key += to_string(f);
            key += '|';
      }
      return key;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
      unordered_map<string, vector<string>> groups;
      for (string s : strs)
      {
            string key = key_builder(s);
            groups[key].push_back(s);
      }

      vector<vector<string>> ans;
      ans.reserve(groups.size());

      for (auto &p : groups)
      {
            ans.push_back(move(p.second));
      }
      return ans;
}