# Longest Substring Without Repeating Characters
# Himanshu Bulani (HIMANSHU3107)
#
# Approach:
# We use the sliding window approach where the start of the window goes from '0' to 'n'
# and the end from 'start' to 'n'. We stop the current window when we find a repeating character.
#
# Time complexity: O(n^2)
# Space complexity: O(no. of distinct characters)

# Import statements
pass

# Solution class
class Solution:
    def length_of_longest_substring(self, s: str):
        max_length = 0

        for start in range(len(s)):
            characters = set()
            for end in range(start, len(s)):
                if s[end] in characters:
                    break
                characters.add(s[end])

                length = end - start + 1
                max_length = max(max_length, length)


        length = end - start + 1
        max_length = max(max_length, length)

        return max_length


# Driver code
def main():
    solution = Solution()

    print(solution.length_of_longest_substring("abcabcbb"))   # Expected: 3
    print(solution.length_of_longest_substring("bbbbb"))   # Expected: 1
    print(solution.length_of_longest_substring("pwwkew"))   # Expected: 3

if __name__ == "__main__":
    main()