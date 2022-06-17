// Write a function that searches a given key ‘x’ in a given singly linked list. The function should return true if x is present in linked list and false otherwise. 
 

//    bool search(Node *head, int x) 
// For example, if the key to be searched is 15 and linked list is 14->21->11->30->10, then function should return false. If key to be searched is 14, then the function should return true.
// Iterative Solution 

// 1) Initialize a node pointer, current = head.
// 2) Do following while current is not NULL
//     a) current->key is equal to the key being searched return true.
//     b) current = current->next
// 3) Return false 


#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(){
        data = 0;
        next = NULL;
    }
    Node (int data){
        this ->data = data;
        next = NULL;
    }
};

