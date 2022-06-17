// Given a singly linked list of size N. The task is to left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

// Example 1:

// Input:
// N = 5
// value[] = {2, 4, 7, 8, 9}
// k = 3
// Output: 8 9 2 4 7
// Explanation:
// Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
// Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
// Rotate 3: 8 -> 9 -> 2 -> 4 -> 7
// Example 2:

// Input:
// N = 8
// value[] = {1, 2, 3, 4, 5, 6, 7, 8}
// k = 4
// Output: 5 6 7 8 1 2 3 4


#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

Node *Rotate_List(Node *head, int k){  // Rotate list from left to right by k elements
    Node *tail = head;
    Node *current = head;
    if (head == NULL || head->next == NULL){
        return head;
    }
    // Set tail pointer at the end of list
    while (tail->next != NULL){
        tail = tail->next;
    }
    int count = 0;
    while (count < k){
        head = head->next;
        current->next = NULL;
        tail->next = current;
        tail = current;
        current = head;
        count ++;
    }
    return head;
}
void Print_list(Node *n){
    while (n != NULL){
        cout << n->data << "--->";
        n = n->next;
    }
}


int main(){
    int n, value, k;
    cin >> n;

    cin >> value;
    Node *head = new Node(value);
    Node *tail = head;
    for (int i = 1; i < n; i++){
        cin >> value;
        tail->next = new Node(value);
        tail = tail->next;
    }
    cin >> k;
    Node *ans = Rotate_List(head,k);
    Print_list(ans);
    return 0;
}

