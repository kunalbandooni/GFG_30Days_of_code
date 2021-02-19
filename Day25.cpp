/*

Spidey Sense

Spiderman is stuck in a difficult situation. His arch-enemy the Green Goblin has 
planted several of his infamous Pumpkin Bombs in various locations in a building. 
Help Spiderman activate his Spidey Sense and identify the impact zones. 
He has a blueprint of the building which is a M x N matrix that is filled with 
the characters ‘O’, ‘B’, and ‘W’ where: 
‘O’ represents an open space.
‘B’ represents a bomb.
‘W’ represents a wall.
You have to replace all of the O’s (open spaces) in the matrix with their shortest
distance from a bomb without being able to go through any walls. Also, replace the
bombs with 0 and walls with -1 in the resultant matrix. If no path exists between a
bomb and an open space replace the corresponding 'O' with -1.

Example 1:
Input: N = 3, M = 3
A[] = {{O, O, O}, 
       {W, B, B}, 
       {W, O, O}}
Output: {{2, 1, 1}, 
         {-1, 0, 0},  
         {-1, 1, 1}}
Explanation: The walls at (1,0) and (2,0) 
are replaced by -1. The bombs at (1,1) and 
(1,2) are replaced by 0. The impact zone 
for the bomb at (1,1) includes open spaces 
at index (0,0), (0,1) and (2,1) with distance 
from bomb calculated as 2,1,1 respectively.
The impact zone for the bomb at (1,2) 
includes open spaces at index (0,3) and (2,2) 
with distance from bomb calculated as 1,1 
respectively.


Example 2:
Input: N = 2, M = 2
A[] = {{O, O},
       {O, O}} 
Output: {{-1, -1}
         {-1, -1}

Your Task:  
You don't need to read input or print anything. Complete the function findDistance()
which takes the matrix A[], M, and N as input parameters and the resultant matrix

Expected Time Complexity: O(M*N)
Expected Auxiliary Space: O(M*N)

*/
class Solution{
    private:
    
    struct queueNode{
    // i, j and distance stores x and y-coordinates
    // of a matrix cell and its distance from bomb
    // respectively
        int i, j, distance;
    };
 
    // These arrays are used to get row and column
    // numbers of 4 neighbors of a given cell 
    int row[4] = { -1, 0, 1, 0};
    int col[4] = { 0, 1, 0, -1 };
    
    // return true if row number and column number
    // is in range
    bool isValid(int i, int j,int m,int n){
        if ((i < 0 || i > m - 1) || (j < 0 || j >n - 1))
            return false;
        return true;
    }
    
   // return true if current cell is an open area and its
   // distance from bomb is not calculated yet
   // i.e true when we need to visit it else false
   bool isSafe(int i, int j, vector<vector<char>>& matrix,vector<vector<int>> &output){
        if (isValid(i,j,matrix.size(),matrix[0].size())==false)
            return false;
        
        // i.e W/B or if O then it has been visited
        if (matrix[i][j] != 'O' || output[i][j] != -1)
            return false;
        return true;
    }
    
    public:
    
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N){ 
        vector<vector<int>> output(M,vector<int>(N)); //making a 2D vector of MXN
        queue<queueNode> q;
    // finding bomb location and adding into queue
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++){
            // initialize each cell as -1
                output[i][j] = -1;
                if(matrix[i][j]=='B'){
                    queueNode pos = {i, j, 0};
                    q.push(pos);
                // guard has 0 distance
                    output[i][j] = 0;
                }
            }
    
    //BFS implementation
        // do till queue is empty
        while (!q.empty()){
            // get the front cell in the queue and update
            // its adjacent cells
            queueNode curr = q.front();
            q.pop();
            int x = curr.i, y = curr.j, dist = curr.distance;
            for (int i = 0; i < 4; i++)
                if (isSafe(x + row[i], y + col[i], matrix, output)){
                // i.e we need to visit this point (x+row[i],y+col[i])
                    //update distance in the output matrix
                    output[x + row[i]][y + col[i]] = dist + 1;
                    queueNode pos = {x + row[i], y + col[i], dist + 1};
                    // pushing ine the queue
                    q.push(pos);
                }
        }
        // return output matrix
        return output;
    }
};
