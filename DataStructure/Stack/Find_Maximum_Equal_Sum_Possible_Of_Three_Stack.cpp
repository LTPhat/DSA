//Given three stacks S1, S2, and S3 of the positive numbers.
//The task is to find the possible equal maximum sum of the stacks with the removal of top elements allowed. 
//Stacks are represented as an array, and the first index of the array represents the top element of the stack.

// Input:
// N1 = 3, N2 = 4, N3 = 2
// S1 = {4,2,3}
// S2 = {1,1,2,3}
// S3= {1,4}
// Output:
// 5
// Explanation:
// We can pop 1 element from the 1st stack, and 2
// elements from the 2nd stack. Now remaining elements
// yield the equal sum of the three stacks, that is 5.

//Algorithm

// Find the sum of all elements of in individual stacks.
// If the sum of all three stacks is the same, then this is the maximum sum.
// Else remove the top element of the stack having the maximum sum among three of stacks.  
// Repeat step 1 and step 2.

#include <bits/stdc++.h>

using namespace std;


int Find_Max_Possible(int s1[], int s2[],int s3[], int n1, int n2, int n3){
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < n1; i++){
        sum1 += s1[i];
    }
    for (int i = 0; i < n2; i++){
        sum2 += s2[i];
    }
    for (int i = 0; i < n3; i++){
        sum3 += s3[i];
    }
    int top1 = 0, top2 = 0, top3 = 0;

    while (true){
        // Any of three stacks is empty.
        if (top1 == n1 || top2 == n2  || top3 == n3 ){
            return 0;
        }
        // Three sums are equal.
        if (sum1 == sum2 && sum2 ==sum3){
            return sum1;
        }
        // Finding the stack with maximum sum and
        // removing its top element.
        if (max(max(sum1,sum2),sum3) == sum1){
            sum1 -= s1[top1++];
        }
        if (max(max(sum1,sum2),sum3) == sum2){
            sum2 -= s2[top2++];
        }
        if (max(max(sum1,sum2),sum3) == sum3){
            sum3 -= s3[top3++];
        }
    }
}

int main(){
    int s1[] = {4,7};
    int s2[] = {10};
    int s3[] = {1,2,3};
    // int s1[] = { 3, 2, 1, 1, 1 };
    // int s2[] = { 4, 3, 2 };
    // int s3[] = { 1, 1, 4, 1 };
    int n1 = sizeof(s1)/sizeof(s1[0]);
    int n2 = sizeof(s2)/sizeof(s2[0]);
    int n3 = sizeof(s3)/sizeof(s3[0]);
    int sum = Find_Max_Possible(s1,s2,s3,n1,n2,n3);
    cout <<"The maximum equal sum of three stack is: " << sum;
    return 0;
}

