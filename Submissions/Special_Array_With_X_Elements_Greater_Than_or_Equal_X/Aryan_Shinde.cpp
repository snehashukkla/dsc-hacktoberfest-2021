// Special Array With X Elements Greater Than or Equal X
// Aryan Shinde
//
// Approach:
// In this problem, my approach was to sort the given array first and then apllied binary search,
// which compares the numbers with the iteration count and decreases untill their difference doesnt
// get equal to the ierating element, if found, return that or simply return -1 if not found

// Time complexity: O(nlogn)
// Space complexity: O(1)

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); i++)
        {
            int start = 0;
            int end = nums.size() - 1;
            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                if (nums[mid] >= i)
                {
                    end = mid - 1;
                }
                else if (nums[mid] < i)
                {
                    start = mid + 1;
                }
            }
            if (nums.size() - start == i)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {0, 4, 3, 0, 4};
    if (s.specialArray(nums) != -1)
        cout << s.specialArray(nums) << endl;
    else
    {
        cout << "element not found";
    }
    return -1;
}
