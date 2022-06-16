// Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.


// Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3 
// Output: 3 3 4 5 5 5 6
// Explanation: 
// Maximum of 1, 2, 3 is 3
// Maximum of 2, 3, 1 is 3
// Maximum of 3, 1, 4 is 4
// Maximum of 1, 4, 5 is 5
// Maximum of 4, 5, 2 is 5 
// Maximum of 5, 2, 3 is 5
// Maximum of 2, 3, 6 is 6


// Input: arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}, K = 4 
// Output: 10 10 10 15 15 90 90
// Explanation:
// Maximum of first 4 elements is 10, similarly for next 4 
// elements (i.e from index 1 to 4) is 10, So the sequence 
// generated is 10 10 10 15 15 90 90

//Method 1: Using nested loop

#include<bits/stdc++.h>

using namespace std;


void Max_Subarray(int a[], int size, int k){
    int max; 
    for (int i = 0; i < size - k; i++){
        max = a[i];
        for (int j = 1; j < k; j++){
            if (a[i+j] > max){
                max = a[i+j];
            }
        }
        cout << max << " ";
    }
}

int main(){
    int a[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    int size = sizeof(a)/sizeof(a[0]);
    Max_Subarray(a,size,k);
    return 0;
}


//Method 2: Using deque

// Algorithm:  

// Create a deque to store k elements.
// Run a loop and insert first k elements in the deque. Before inserting the element, check if the element at the back of the queue is smaller than the current element, if it is so remove the element from the back of the deque, until all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque.
// Now, run a loop from k to end of the array.
// Print the front element of the deque.
// Remove the element from the front of the queue if they are out of the current window.
// Insert the next element in the deque. Before inserting the element, check if the element at the back of the queue is smaller than the current element, if it is so remove the element from the back of the deque, until all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque.
// Print the maximum element of the last window.


#include<iostream>
#include<deque>

using namespace std;

void Sliding_Window_Maximum(int a[], int n, int k){
    deque <int> Qi(k);
    int i;
    // Processing first k elements:
    for (int i = 0; i < k; i++){
        while (!Qi.empty() && a[i] >= a[Qi.back()]){
            Qi.pop_back();
        }
        Qi.push_back(i);
    }
    // Processing from a[k] to a[n-1]
    for (int i = k; i < n; i++){
        cout << a[Qi.front()] <<" "; //Output the max of each window

        while (!Qi.empty() && Qi.front() <= i - k){ // Remove useless elements which are not in the current window
        Qi.pop_front();
        }

        while (!Qi.empty() && a[i] >= a[Qi.back()]){
            Qi.pop_back();
        }
        Qi.push_back(i);
    }
    cout << a[Qi.front()]; //Print the maximum of the last window
}

int main(){
    int input[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int size = sizeof(input)/sizeof(input[0]);
    int k = 3;
    Sliding_Window_Maximum(input,size,k);
    return 0;
}