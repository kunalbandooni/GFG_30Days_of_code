/*

Count Triplets

Given a sorted linked list of distinct nodes (no two nodes have the same data) and an integer X. Count distinct triplets in the list that sum up to given integer X.

Example 1:
Input: LinkedList: 1->2->4->5->6->8->9, X = 17
Output: 2
Explanation: Distinct triplets are (2, 6, 9) 
and (4, 5, 8) which have sum equal to X i.e 17.


Example 2:
Input: LinkedList: 1->2->4->5->6->8->9, X = 15
Output: 5
Explanation: (1, 5, 9), (1, 6, 8), (2, 4, 9), 
(2, 5, 8), (4, 5, 6) are the distinct triplets

Your Task:  
You don't need to read input or print anything. Complete the function countTriplets() which takes a head reference and X as input parameters and returns the triplet count

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

*/
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}// } Driver Code Ends
int countTriplets(struct Node* head,int x){ 
    unordered_map<int,int> m;
    int res=0;
    Node *t1=head,*t2;
    while(t1){
        m[t1->data]++;
        t1=t1->next;
    }
    for(t1=head;t1->next!=NULL;t1=t1->next)
        for(t2=t1->next;t2!=NULL;t2=t2->next){
            int c=x-(t1->data + t2->data);
            if(m[c]!=0 && c>t2->data)
                res++;
        }
    return res;
}