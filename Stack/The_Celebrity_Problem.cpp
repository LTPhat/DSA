// // In a party of N people, only one person is known to everyone. 
// //Such a person may be present in the party.
// //if yes, (s)he doesn’t know anyone in the party. We can only ask questions like “does A know B? “. 
// //Find the stranger (celebrity) in minimum number of questions.

//Method 1: Using Stack:

#include<bits/stdc++.h>
#include<list>
#include<stack>

using namespace std;

#define N 8
//Matrix of information:
// i: row; j: columm
// i know j --> matrix[i][j] = 1 
// else matrix[i][j] = 0

bool Matrix[N][N] = {{0, 0, 0, 1},
                    {0, 0, 0, 1},
                    {0, 0, 0, 1},
                    {0, 0, 0, 0}};
//Function determine whether a knows b:

bool knows(int a, int b){
    return Matrix[a][b];
}
//Function to find celebrity with n people:

int Find_Celebrity(int n){
    stack <int> s;
    //Variable indicates celebrity:
    int C;
    //Push all the index of people into the stack:
    for (int i = 0; i < n; i++){
        s.push(i);
    }
    // Extract top 2 of the stack:
    while (s.size() > 1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (knows(a,b)){
            s.push(b);
        }else{
            s.push(a);
        }
    }
    //The rest elements of the stack are potential celebrities, which they don't know their next-to person
    //Pick the top of stack and check whether 
        //(s)he is known to everyone else and (s)he don't know anyone --> C is celebrity.
        //Anyone don't know (s)he or (s)he knows anyone --> C is not celebrity.
    C = s.top();
    s.pop();

    for (int i = 0; i < n; i++){
        if ((!knows(i,C) || knows(C,i)) && (i != C)){
            return -1;
        }
    }
    return C;
}

int main(){
    int n = 4;
    int id = Find_Celebrity(n);
    if (id == -1 ){
        cout << "No celebrity ";
    }else{
        cout << "Celebrity ID: "<< id;
    }
    return 0;
}




