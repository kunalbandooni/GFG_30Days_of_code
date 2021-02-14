/*

Valentine Sum

Cupid wants to strike maximum houses in Geek Land on Valentine's Day. The houses in Geek Land are arranged in the form of a binary tree. Cupid is standing at target node initially. 
Find the sum of all nodes within a maximum distance k from target node. The target node should be included in the sum.

Example 1:
Input:
                   1
                 /    \
                2      9
               /      /  \
              4      5     7
            /   \         /  \
           8     19     20    11
          /     /  \
         30   40   50
target = 9, K = 1
Output:
22
Explanation:
Nodes within distance 1 from 9 are 9, 5, 7, 1  

Example 2:
Input:
                   1
                 /    \
                2      9
               /      /  \
              4      5     7
            /   \         /  \
           8     19     20    11
          /     /  \
         30   40   50
target = 40, K = 2
Output:
113
Explanation:
Nodes within distance 2 from 40 are 40, 19, 50, 4

Your Task:
You don't need to read input or print anything. Complete the function sum_at_distK() which takes the root of the tree, target, and K  as input parameter and returns the sum of all nodes within a max distance of k from the target

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/
//CODE:-
/*
// node structure:
struct Node{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution{
    
    private:
    void add_subtree(Node* n, int dist, int* sum)
    {
        if( !n || dist<0 ) return;
        *sum += n->data;
        add_subtree(n->left, dist-1, sum);
        add_subtree(n->right, dist-1, sum);
    }
    
    int traverse(Node* n, int target, int k, int* sum)
    {
        if(!n) return -1;
        if(n->data==target)
        {
            add_subtree(n, k, sum);
            // adding all nodes within range in the sub tree below
            return k-1;
        }
        
        int dist = traverse(n->left, target, k, sum);
        if(dist>-1)
        // dist>-1 indicates target was found in left subtree
        {
            *sum += n->data;
            add_subtree(n->right, dist-1, sum);
            // adding values from right sub tree
            return dist-1;
        }
        
        dist = traverse(n->right, target, k, sum);
        if(dist>-1)
        // dist>-1 indicates target was found in right subtree
        {
            *sum += n->data;
            add_subtree(n->left, dist-1, sum);
            // adding values from left sub tree
            return dist-1;
        }
        
        return -1;
    }
    
    public:
    int sum_at_distK(Node* root, int target, int k)
    {
        int sum = 0;
        traverse(root, target, k, &sum);
        return sum;
    }


};
