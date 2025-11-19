#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// prototypes
bool isAnagram(string s, string t);
bool is_anagram_unicode(const string &s, const string &t);
uint32_t next_code_point(const string &s, int &i);
int main()
{
      cout << "Hello Leetcode" << '\n';
      return 0;
}

/*
242. Valid anagram

Given two strings, we asked to check them if they are anagrams

Example: s = 'anagram', t = 'nagaram'
Output: true

–––––-------------------------------------

1 <= s.length, t.length <= 5 * 10^4
s and t consist of lowercase English letters.

–––––-------------------------------------

TC: O(N)
SC: O(26) -> O(1)

*/
bool isAnagram(string s, string t)
{
      // anagram strings should have equal length
      if (s.size() != t.size())
      {
            return false;
      }

      // since all letters are lowercase and there are total 26 chars we can use array of 26 elements where each cell stores frequency of chars a-z (0-25), we can take indexes from ASCII table
      vector<int> frequency_counter(26, 0);
      for (int i = 0; i < s.size(); i++)
      {
            // incrementing the frequency of chars in s
            frequency_counter[s[i] - 'a']++;
            // decrementing the frequency of chars in t
            frequency_counter[t[i] - 'a']--;
      }

      // eventually if s and t are anagrams for real we should have only zeros in array
      for (int x : frequency_counter)
      {
            if (x != 0)
            {
                  return false;
            }
      }
      return true;
}

// next we asked follow up question - What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

// that means we might have symbols, emoji, flags and we have to handle this. Problem is unicode symbol != one char.

// Here is explanation of problem, you can skip it if you want

/*
1. ASCII - American Standard Code for Information Interchange

• Created in early 60s.
• Contains only 128 symbols (0-127)
• First in 1 byte
• Designed primarily for English

ASCII can not represent:
• Cyrillic (АБСВ)
• Arabic
• Chinese
• Emoji



Unicode - the solution. ASCII was to small, world has thousands of scripts and symbols, so unicode was created. It assigns each symbol a code point like:
• 'А' - U+0041
• 'Ж' → U+0416
• '你' → U+4F60
• '😂' → U+1F602
• '🏴󠁧󠁢󠁷󠁬󠁳󠁿' → U+1F1F0 U+1F1FF (2 code points!) (If you have press button delete 2 times)


Unicode code points are large and we need to store them in bytes -> UTF standarts

Most dominant UTF-8

ASCII
• 128 characters
• 1 byte
• English only

Unicode
• mathematical list of all human symbols
• each symbol = code point (U+XXXX)

UTF-8
• most popular encoding
• 1–4 bytes per symbol

UTF-16
• 2–4 bytes

UTF-32
• always 4 bytes


Character → Unicode code point → Encoding → Bytes
            (U+XXXX)            (UTF-8)


😀 → U+1F600 → F0 9F 98 80 → 4 bytes
*/

uint32_t next_code_point(const string &s, int &i)
{
      unsigned char c = s[i];
      uint32_t cp;

      if (c < 0x80)
      {
            cp = c;
            i += 1;
      }
      else if ((c >> 5) == 0x6)
      {
            cp = ((c & 0x1F) << 6) |
                 (s[i + 1] & 0x3F);
            i += 2;
      }
      else if ((c >> 4) == 0xE)
      {
            cp = ((c & 0x0F) << 12) |
                 ((s[i + 1] & 0x3F) << 6) |
                 (s[i + 2] & 0x3F);
            i += 3;
      }
      else
      {
            cp = ((c & 0x07) << 18) |
                 ((s[i + 1] & 0x3F) << 12) |
                 ((s[i + 2] & 0x3F) << 6) |
                 (s[i + 3] & 0x3F);
            i += 4;
      }

      return cp;
}

bool is_anagram_unicode(const string &s, const string &t)
{
      unordered_map<uint32_t, int> frequency;
      int i = 0;
      int j = 0;

      while (i < s.size())
      {
            uint32_t cp = next_code_point(s, i);
            frequency[cp]++;
      }

      while (j < t.size())
      {
            uint32_t cp = next_code_point(t, i);
            frequency[cp]--;
      }

      for (auto &p : frequency)
      {
            if (p.second != 0)
            {
                  return false;
            }
      }
      return true;
}
