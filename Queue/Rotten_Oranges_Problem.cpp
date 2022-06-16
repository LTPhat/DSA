// Given a matrix of dimension m*n where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:  

// 0: Empty cell
// 1: Cells have fresh oranges
// 2: Cells have rotten oranges
// Determine what is the minimum time required so that all the oranges become rotten.
// A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right). 
// If it is impossible to rot every orange then simply return -1.

// Input:  arr[][C] = { {2, 1, 0, 2, 1},
//                      {1, 0, 1, 2, 1},
//                      {1, 0, 0, 2, 1}};
// Output:
// All oranges can become rotten in 2-time frames.
// Explanation: 
// At 0th time frame:
//  {2, 1, 0, 2, 1}
//  {1, 0, 1, 2, 1}
//  {1, 0, 0, 2, 1}

// At 1st time frame:
//  {2, 2, 0, 2, 2}
//  {2, 0, 2, 2, 2}
//  {1, 0, 0, 2, 2}

// At 2nd time frame:
//  {2, 2, 0, 2, 2}
//  {2, 0, 2, 2, 2}
//  {2, 0, 0, 2, 2}

// Input:  arr[][C] = { {2, 1, 0, 2, 1},
//                      {0, 0, 1, 2, 1},
//                      {1, 0, 0, 2, 1}};
// Output:
// All oranges cannot be rotten.
// Explanation: 
// At 0th time frame:
// {2, 1, 0, 2, 1}
// {0, 0, 1, 2, 1}
// {1, 0, 0, 2, 1}

// At 1st time frame:
// {2, 2, 0, 2, 2}
// {0, 0, 2, 2, 2}
// {1, 0, 0, 2, 2}

// At 2nd time frame:
// {2, 2, 0, 2, 2}
// {0, 0, 2, 2, 2}
// {1, 0, 0, 2, 2}
// ...
// The 1 at the bottom left corner of the matrix is never rotten.


//Method 1: Traverse all the element of the matrix (Nested loop)

#include<bits/stdc++.h>

using namespace std; 

const int Row = 3;
const int Column = 3;


//Function to check if v[i][j] is in the matrix area.

bool Is_in(int i, int j){
    return (i >= 0 && i < Row && j >= 0 && j < Column);
}

int Min_Time(int a[Row][Column]){   
    int count = 0;
    int rot = 2;
    bool Changed = false;
    while (true)
    {
        for (int i = 0; i < Row; i++){
            for (int j = 0; j < Column; j ++){
                if (a[i][j] == rot){
                    if (Is_in(i,j-1) && a[i][j-1] == 1){  //Check left
                        a[i][j-1] = a[i][j] + 1;
                        Changed = true;
                    }
                    if (Is_in(i,j+1) && a[i][j+1] == 1){   //Check right
                        a[i][j+1] = a[i][j] + 1;
                        Changed = true;
                    }
                    if (Is_in(i-1,j) && a[i-1][j] == 1){    //Check up
                        a[i-1][j] = a[i][j] + 1;;
                        Changed = true;
                    }
                    if (Is_in(i+1,j) && a[i+1][j] == 1){    //Check down
                        a[i+1][j] = a[i][j] + 1;;
                        Changed = true;
                    }
                }
            }
        }
        if (!Changed){break;}
        Changed = false;
        rot ++;
    }
    for(int i = 0; i < Row; i++){
        for (int j = 0; j < Column; j++){
            if (a[i][j] == 1){
                return -1;
            }
        }
    }
    return (rot - 2);
}

int main(){
    int a[Row][Column] = {{2,1,1},{1,1,0},{0,1,1}};

    cout <<"Min time required so that all oranges are rotten is: " << Min_Time(a);
    return 0;
}


//Method 2: Using queue

#include <bits/stdc++.h>
#include<vector>
using namespace std;

//Algorithm

// 1) Create a queue to store all the rottened oranges (which have value of 2), if grid[i][j] = 1 --> Fresh++
// (Fresh is used to count how many oranges are not rottened).
// 2) While the queue is not empty:

//    Pop front element of queue (which is rottened).
//    Check if adjcent top, bottom, left, right element of a[i][j] is rottened or not. 
//    If rottened, push it into queue, fresh --


// 3) Check if queue is empty or not:
//    If queue is empty, return count if fresh == 0 (All are rottened), else return -1;
//    If queue is not empty, return to step 2

class Solution{
    public:
    const int r = 3;
    const int c = 5;
    vector <vector<int>> grid;

    void Enter_Grid(){
        cout<< "Enter the input matrix: " << endl;
        for(int i = 0;i < r;++i) { 
            //Create a vector  
            vector<int> row; 
            for(int j = 0;j < c;++j){ 
                int value; 
                cin >> value; 
                row.push_back(value); 
            } 
            //Push the row in matrix 
            grid.push_back(row); 
        }
        cout<<"The matrix input: "<<endl;

        for(int i = 0;i < r;++i) { 
		    for(int j = 0;j < c;++j){ 
			    cout << grid[i][j] << " "; 
		    } 
		        cout << "\n"; 
	    } 
    }

    bool In_Grid(int i, int j){
        return (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size());
    }

    int OrangeRotting(){
        int fresh = 0;
        queue <pair <int,int>> rotten;
        int row = grid.size(), column = grid[0].size();
        for(int i = 0; i < row; i++){
            for (int j = 0; j < column; j++){
                if (grid[i][j] == 2){
                    rotten.push({i,j});
                }else if(grid[i][j] == 1){
                    fresh ++;
                }
            }
        }
        int time = 0;
        while (!rotten.empty()){
            int num = rotten.size();
            for (int i = 0; i < num; i++){
                int x = rotten.front().first , y = rotten.front().second;
                rotten.pop();
                if (In_Grid((x-1),y) && grid[x-1][y] == 1){ //Check the adjcent top element:
                    grid[x-1][y] = 2; 
                    fresh --;
                    rotten.push({x-1,y});
                }
                if (In_Grid((x+1),y) && grid[x+1][y] == 1){ //Check the adjcent bottom element:
                    grid[x+1][y] = 2; 
                    fresh --;
                    rotten.push({x+1,y});
                }
                if (In_Grid(x,(y-1)) && grid[x][y-1] == 1){ //Check the adjcent left element:
                    grid[x][y-1] = 2; 
                    fresh --;
                    rotten.push({x,y-1});
                }
                if (In_Grid(x,(y+1)) && grid[x][y+1] == 1){ //Check the adjcent right element:
                    grid[x][y+1] = 2; 
                    fresh --;
                    rotten.push({x,y+1});
                }
            } 
            if (!rotten.empty()){time++;}
        }
        if(fresh == 0){
            return time;
        }
        return -1;
    }
};

int main(){
    Solution matrix;

    matrix.Enter_Grid();

    int ans = matrix.OrangeRotting();
    cout <<"The minimum time required to rotten all the orange is: " <<ans;
    return 0;
//Check:
// // Input:  arr[][C] = { {2, 1, 0, 2, 1},
//                      {1, 0, 1, 2, 1},
//                      {1, 0, 0, 2, 1}};
// Output: 2 (right)
}






    