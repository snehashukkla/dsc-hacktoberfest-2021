//Trapping Rain Water problem
//Approach:
/*An element of the array can store water if there are higher bars on the left and right.
The amount of water to be stored in every element can be found out by finding the heights of bars on the left and right sides.
The idea is to compute the amount of water that can be stored in every element of the array.
The idea is to traverse every array element and find the highest bars on the left and right sides by 
pre-compute the highest bar on the left and right of every bar in linear time.
for each index Take the smaller of two heights.
The difference between the smaller height and 
height of the current element is the amount of water that can be stored in this array element.*/
//TimeComplexity: O(n)
//SpaceComplexity:O(n)


//DriverCode Starts
#include <bits/stdc++.h>
using namespace std;
//DriverCode Ends

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i;
        if(n==0)
            return 0;
        if(n==1)
            return 0;
        int left[n];
        int right[n];
        left[0]=height[0];
        for(i=1;i<n;i++)
            left[i]=max(left[i-1],height[i]);
        right[n-1]=height[n-1];
        for(i=n-2;i>=0;i--)
            right[i]=max(height[i],right[i+1]);
        int watertrapp=0;
        for(i=1;i<=n-2;i++)
            watertrapp=watertrapp+min(left[i],right[i])-height[i];
        return watertrapp;
    }
};


// { Driver Code Starts.

int main(){
    
    int t;
    
   
        int n,x;
        
        cin >> n;
        
        vector<int>height;
        Solution ob;
        
        for(int i =0;i<n;i++){
            cin>>x;
            height.push_back(x);
        }
        
        cout << ob.trap(height) << endl;
        
    
    
    return 0;
}  // } Driver Code Ends