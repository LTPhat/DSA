// Begin
// Input set of items each with a weight and a value
// Set knapsack capacity
// Create a function that returns maximum of two integers.
// Create a function which returns the maximum value that can be put in a knapsack of capacity W



// int knapSack(int W, int w[], int v[], int n)
// int i, wt;
// int K[n + 1][W + 1]
// for i = 0 to n
// for wt = 0 to W
// if (i == 0 or wt == 0)
// Do K[i][wt] = 0
// else if (w[i - 1] <= wt)
// Compute: K[i][wt] = max(v[i - 1] + K[i - 1][wt - w[i - 1]], K[i -1][wt])
// else
// K[i][wt] = K[i - 1][wt]
// return K[n][W]
// Call the function and print.
// End


//Example:
// Let weight elements = {1, 2, 3}
// Let weight values = {10, 15, 40}
// Capacity=6

//    0   1   2   3   4   5   6

// 0  0   0   0   0   0   0   0

// 1  0  10  10  10  10  10  10

// 2  0  10  15  25  25  25  25

// 3  0  10  15  40  50  55  65


//Method: Using dynamic programming

#include<iostream>


using namespace std;

int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int Knap_sack(int value[], int weight[], int W, int n){
    int K[n + 1][W + 1];
    for (int i = 0; i <= n; i++){
        for (int w = 0; w <= W; w++){
            if (i == 0 || w == 0){
                K[i][w] = 0;
            }else if (weight[i - 1] <= w){
                K[i][w] = max(value[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
            }else{
                K[i][w] = K[i - 1][w];
            }
        }
    }
            
    return K[n][W];
}
int main(){
    int weight[] = {1, 2, 3};
    int value[] ={10, 15, 40};
    int W = 6;
    int n = sizeof(value)/sizeof(value[0]);
    int ans = Knap_sack(value,weight,W,n);
    cout << ans;
}