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
