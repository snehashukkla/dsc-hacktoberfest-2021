// Rotate Array
// Vishal Khandate (vkinsane)
//
// Approach:
// In this program, we perform three reverse operations on the array to rotate it.
//      1. We first reverse the entire array (1 to n)
//      2. Then, we reverse the first 'k' elements (1 to k)
//      3. Finally, we reverse the remaining 'n-k' elements (k+1 to n)
//
// Time complexity: O(n)
// Space complexity: O(1)

// Import statements
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Solution class
class Solution {
public:
    void reverse(vector<int>&arr, int start, int end) {
        int temp = -1;
        while (start < end) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        if (k == 0 || k % nums.size() == 0)
            return;
        k = k % nums.size();

        int n = nums.size();

        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);

        return;
    }
};

void printVector(vector<int> arr) {
    cout << "[ ";
    for (int idx = 0; idx < arr.size(); ++idx) {
        cout << arr[idx] << ", ";
    }
    cout << "] " << endl;
    return;
}

// Driver code
int main() {
    Solution s;

    int case1[] = {1, 2, 3, 4, 5, 6, 7};
    vector<int> v1(case1, case1+7);

    printVector(v1);    // Expected: [1, 2, 3, 4, 5, 6, 7]
    s.rotate(v1, 3);
    printVector(v1);    // Expected: [5, 6, 7, 1, 2, 3, 4]

    cout << endl;

    int case2[] = {-1, -100, 3, 99};
    v1 = vector<int>(case2, case2+4);
    printVector(v1);    // Expected: [-1, -100, 3, 99]
    s.rotate(v1, 2);
    printVector(v1);    // Expected: [3, 99, -1, -100]

}
