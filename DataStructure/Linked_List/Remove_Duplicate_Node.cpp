// Write a function that takes a list sorted in non-decreasing order 
//and deletes any duplicate nodes from the list. The list should only be traversed once. 



// For example if the linked list is 11->11->11->21->43->43->60 
//then removeDuplicates() should convert the list to 11->21->43->60. 

// Algorithm: Traverse the list from the head (or start) node. 
// While traversing, compare each node with its next node. 
// If the data of the next node is the same as the current node then delete the next node.
// Before we delete a node, we need to store the next pointer of the node 


#include <bits/stdc++.h>

using namespace std;
//Create node
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
//Print linked list
void Print_list(Node *n){
    while (n != NULL){
        cout << n->data << "--->";
        n = n->next;
    }
}
//Push new node at the end of list
// void Push (Node *head, Node *n){
//     Node *temp = head;
//     while (temp->next!= NULL){ 
//         temp = temp->next;
//     }
//     temp->next = new Node(n->data);
//     temp = temp->next;
// }


void Remove_duplicate(Node *head){
    Node *currentptr = head;
    Node *temp = NULL;
    if (currentptr == NULL){
        return;
    }

    while (currentptr->next != NULL){                   //Delete the adjcent node has the same data
        if (currentptr->data == currentptr->next->data){
            temp = currentptr->next->next;
            free(currentptr->next);
            currentptr->next = temp;
        }else{
            currentptr = currentptr->next;
        }
    }
}

int main(){
    int size, value;
    cout <<"Enter the size of list: "; cin >> size;
    cin >> value;
    Node *head = new Node(value);
    Node *tail = head;
    for (int i = 1; i < size; i++){
        cin >> value;
        tail->next = new Node(value);
        tail = tail->next;
    }
    cout <<"List before removal: ";
    Print_list(head);
    Remove_duplicate(head);
    cout <<"\nList before after: ";
    Print_list(head);
}

