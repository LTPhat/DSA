//Singly Linked list operation function:
// 1) Append Node ()
// 2) Prepend Node ()
// 3) Insert node after () 
// 4) Delete node by key ()
// 5) Update node by key ()
// 6) Print ()


#include<iostream>

using namespace std;

class Node {
    public:
    int data, key;
    Node *next; 
    Node(){   //Default constructor
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d){
        key = k;
        data = d;
    }
};

class Singly_Linked_List{
    public:
    Node *head;
    Singly_Linked_List(){
        head = NULL;
    }
    Singly_Linked_List(Node *n){
        head = n;
    }
    Node *nodeExist(int k){ 
// Check if the node which has key k exist in the current linked list, return the pointer of the node has key k
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL){
            if (ptr->key == k){
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    void Append_node(Node* n);
    void Prepend_node(Node* n);
    void Insert_node_after(int k, Node* n);
    void Delete_note_by_key(int k);
    void Update_note_by_key(int k, int d);
    void Print_list();

};




void Singly_Linked_List::Append_node(Node *n){
        // Check if the node to append has the key which exist in the current list,
        // if yes, require other input with different key.
        if(nodeExist(n->key) != NULL){
            cout << "Node already exist, enter another node with different key! ";
        }else{
            if (head = NULL){
                head = n;
                cout <<"Append node successfully ";
            }else{
                Node* ptr = head;
                while (ptr->next != NULL){
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout <<"Append node successfully ";
            }
        }
    }
