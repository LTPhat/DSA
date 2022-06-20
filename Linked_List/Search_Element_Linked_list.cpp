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
    }
    Node (int data){
        this ->data = data;
        next = NULL;
    }
};
void Append_node(Node *head, int value){
    Node *new_node = new Node();
    new_node->data = value;
    new_node ->next = NULL;
    if (head == NULL){
        head = new_node;
    }else{
        Node *ptr = head;
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}
bool Search (Node *head, int x){
    Node *current = head;
    while (current != NULL){
        if (current->data == x){
            return true;
        }
        current = current->next;
    }
    return false;
}

void Print_list(Node *head){
    while (head != NULL){
        cout << head->data << "--->";
        head = head->next;
    }
}

int main(){
    int size, value, k;
    cout <<"Enter the size of list: "; cin >> size;
    cin >> value;
    Node *head = new Node(value);
    Node *tail = head;
    for (int i = 1; i < size; i++){
        cin >> value;
        tail->next = new Node(value);
        tail = tail->next;
    }
    cout <<"List entered: ";
    Print_list(head);
    cout <<"\nEnter the value to find "; 
    cin >> k;
    bool ans = Search(head, k);
    if (ans == true){
        cout << "True";
    }else{
        cout << "False";
    }
   return 0;
}