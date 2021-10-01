// Finding middle element in a linked list
//
// Approach:
// In this program, we find the middle of a given linked list
//      1. We assign two pointers to head , a slow and a fast
//      2. Fast pointer moves twice the speed compared to slow
//      3. when fast reaches end of linked list slow reaches middle
//
// Time complexity: O(n)
// Space complexity: O(1)

// Import statements
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 
// Solution class
class Solution{
    public:
    int getMiddle(Node *head)
    {
        Node *slow = head, *fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next; 
            fast = fast->next->next; //fast moves twice the speed as slow, when fast reaches end of linked list slow reaches middle
        }
        
        return slow->data;        // return value of slow
    }
};
int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}
  // } Driver Code Ends