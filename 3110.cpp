#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int scoreOfString(string s);
int main()
{
      cout << "Hello Leetcode" << '\n';
      string s = "hello";
      int result = scoreOfString(s);
      cout << "Result: " << result << '\n';
      return 0;
}

/*
3110. Score of a String

Given a string consisting of lowercase english letters. Asked to find the sum of absolute difference of chars by taking their ascii positions

"hello" -> 13

|104 - 101| + |101 - 108| + ... = 13

*/

int scoreOfString(string s)
{

      int res = 0;
      for (int i = 1; i < s.size(); i++)
      {
            res += abs(s[i] - s[i - 1]);
      }
      return res;
}