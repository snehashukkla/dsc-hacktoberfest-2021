// Longest Substring Without Repeating Characters
// Ritesh Thakur (ritesh-dt)
//
// Approach:
// In this program, we keep track of the indices where we have seen each character using a map.
// When a repeated character 'ch' is found, we assume the following
//      start of the sequence = index of previous occurence of 'ch'
//      end of the sequence = index of current occurence of 'ch'
// using these indices we find the length of the current sequence and store the maximum length and return it.

// Time complexity: O(n)
// Space complexity: O(n)

// Import statements
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// Solution class
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> charMap;
        int startIdx = 0;
        int maxLength = 0;

        for (int idx = 0; idx < s.length(); idx++) {
            char c = s[idx];

            if (charMap.find(c) != charMap.end()) {
                int length = idx - startIdx;

                maxLength = max(maxLength, length);
                startIdx = max(startIdx, charMap[c] + 1);
            }
            charMap[c] = idx;

        }
        int length = s.length() - startIdx;

        maxLength = max(maxLength, length);
        return maxLength;
    }
};

// Driver code
int main() {
    Solution s;

    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;   // Expected: 3
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;   // Expected: 1
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;   // Expected: 3
}
