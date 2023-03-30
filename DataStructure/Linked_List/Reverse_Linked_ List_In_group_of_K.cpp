// Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).

// Example 1:

// Input:
// LinkedList: 1->2->2->4->5->6->7->8
// K = 4
// Output: 4 2 2 1 8 7 6 5 
// Explanation: 
// The first 4 elements 1,2,2,4 are reversed first 
// and then the next 4 elements 5,6,7,8. Hence, the 
// resultant linked list is 4->2->2->1->8->7->6->5.
// Example 2:

// Input:
// LinkedList: 1->2->3->4->5
// K = 3
// Output: 3 2 1 5 4 
// Explanation: 
// The first 3 elements are 1,2,3 are reversed 
// first and then elements 4,5 are reversed.Hence, 
// the resultant linked list is 3->2->1->5->4.

#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(){
        data = 0;
        next = NULL;
    }
    Node(int d){
        data = d;
        next = NULL;
    }
};

Node *Reverse(Node *head, int k){
    if (head == NULL || head->next == NULL){
        return head;
    }
    Node *currentptr = head;
    Node *previousptr = NULL;
    Node *front = NULL;
     int count = 0;
    while (currentptr != NULL && count < k){
        front = currentptr->next;
        currentptr->next = previousptr;
        previousptr = currentptr;
        currentptr = front;
        count++;
    }
    if (front != NULL){
        head->next = Reverse(front,k);
    }
    return previousptr;
}

void Print_list(Node *head){
    if (head == NULL){
        return;
    }
    while (head != NULL){
        cout << head->data << "--->";
        head = head->next;
    }
}
    


int main(){
    int  n;
    Node *temp = NULL;
    Node *head = NULL;
    cin >> n;
    for (int i = 0; i < n; i++){
        int value;
        cin >> value;
        if (i == 0){
            head = new Node(value);
            temp = head;
        }else{
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
    int k; cin >> k;
    Node *ans = Reverse(head,k);
    Print_list(ans);
    return 0;
}