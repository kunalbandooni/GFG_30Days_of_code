/*

Corona Vaccine
Hard Accuracy: 100.0% Submissions: 35 Points: 8

Geek has developed an effective vaccine for Corona virus and he wants each of the N houses in Geek Land to 
have access to it. Given a binary tree where each node represents a house in Geek Land, find the minimum
number of houses that should be supplied with the vaccine kit if one vaccine kit is sufficient for that
house, its parent house and it's immediate child nodes.  

Example 1:
Input:
    1
   / \
  2   3 
        \
         4
          \
           5
            \
             6

Output:
2
Explanation:
The vaccine kits should be 
supplied to house numbers 1 and 5. 

Example 2:
Input:
    1
   / \
  2   3 
Output:
1
Explanation:
The vaccine kits should be 
supplied to house number 1.

Your Task:
You don't need to read input or print anything. Complete the function supplyVaccine() which takes the root of the housing tree as input parameter and returns the minimum number of houses that should be supplied with the vaccine kit.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/
class Solution{
  public:
    int vaccine;
    int supplyVaccine(Node* root){
      vaccine=0;
      pair<bool,bool> temp=tovaccine(root);
      if(!temp.second)
        vaccine++;
      return vaccine;
    }
    pair<bool,bool> tovaccine(Node* root){
      if(root==NULL)
         return {false,true};
      pair<bool,bool> left=tovaccine(root->left);
      pair<bool,bool> right=tovaccine(root->right);
      bool has_vaccine=false;
      bool vaccinated=true;
      if(Left.first || Right.first)
         vaccinated=true;
      if(!Left.second || !Right.second){
         has_vaccine=true;
         vaccinated=true;
         vaccine++;
      }
      return {has_vaccine,vaccinated};
    }
};
