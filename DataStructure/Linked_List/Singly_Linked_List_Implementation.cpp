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
// Check if the node which has the key k exist in the current linked list, return the pointer of the node has key k
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
            if (head == NULL){
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

void Singly_Linked_List::Prepend_node(Node* n){
    // Check if the node to append has the key which exist in the current list,
    // if yes, require other input with different key.
        if(nodeExist(n->key) != NULL){
            cout << "Node already exist, enter another node with different key! ";
        }else{
            n->next = head;
            head = n;
            cout <<"Prepend node successfully ";
        }
}

void Singly_Linked_List::Insert_node_after(int k, Node* n){ // insert node n after the node which has has the key k in the current list
    Node *ptr = nodeExist(k);
    if (ptr == NULL){
        cout << "No node exists with key value " << k <<endl;
    }else{
        if(nodeExist(n->key) != NULL){
            cout << "Node already exist with the key "<< n->key << ", enter another node with different key! ";
        }else{
            n->next = ptr->next;
            ptr->next = n;
        }
    }
}
void Singly_Linked_List::Delete_note_by_key(int k){
    if (head == NULL){ //Check if linked list is empty
        cout <<"Singly linked list is empty, can not delete node";
    }else if (head != NULL){    //The linked list is not empty
        if (head->key == k){    //Check if the first node is the node to delete
            head = head->next;
            cout <<"Node unlinked with key value " << k;
        }else{
            Node *temp = NULL;
            Node *preptr = head;
            Node *currentptr = head->next;

            while (currentptr != NULL){
                if (currentptr->key == k){ //If the key value is find, let temp = node with value k, currentptr =NULL to end while loop.
                    temp = currentptr;
                    currentptr = NULL;
                }else{ //If the key value is find, move forward to next node
                    currentptr = currentptr->next;
                    preptr = preptr->next;
                }
            }
            if (temp != NULL){
                preptr->next = temp->next;
                cout <<"Node unlinked with key value " << k <<endl;
            }else{
                cout <<"No node with key "<< k <<" exists"<<endl;
            }
        }
    }
}

void Singly_Linked_List::Update_note_by_key(int k, int d){
    Node *ptr = nodeExist(k);
    if (ptr != NULL){
        ptr->data = d;
        cout << "Update data succesfully "<< endl;
    }else{
        cout <<"No node with key "<< k <<" exists"<<endl;
    }
}
void Singly_Linked_List::Print_list(){
    if (head == NULL){
        cout << "Singly linked list is empty " << endl;
    }else{
        cout << "Singly linked list value ";
        Node *temp = head;
        while (temp != NULL){
            cout <<"("<< temp->key << ", " << temp->data << ") --->";
            temp = temp->next;
        }
    }
}


int main(){
    Singly_Linked_List s;
    int choice;
    int key1, k1, data1;
    do{
        cout <<"\n------SINGLY LINKED LIST IMPLEMENTATION------ "<< endl;
        cout <<"Which choice do you want to choose? Select number choice. Press 0 to exit."<<endl;
        cout <<"1) Append node" <<endl;
        cout <<"2) Prepend node" <<endl;
        cout <<"3) Insert node after () " <<endl;
        cout <<"4) Delete node by key ()" <<endl;
        cout <<"5) Update node by key ()" <<endl;
        cout <<"6) Print linked list " <<endl;
        cout <<"7) Clear screan" <<endl;
        cin >> choice;
        Node * n1 = new Node();
        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout <<"---Append node operation---"<<endl;
            cout <<"Enter key and data to append: ";
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1; 
            s.Append_node(n1);
            break;
        case 2:
            cout <<"---Prepend node operation---"<<endl;
            cout <<"Enter key and data to append: ";
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1; 
            s.Prepend_node(n1);
            break;
        case 3: 
            cout <<"---Insert node operation---"<<endl;
            cout <<"Enter the key of the node after which you want to insert the new node: ";
            cin >> k1;
            cout <<"Enter key and data of the node to insert: ";
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.Insert_node_after(k1,n1);
            break;
        case 4: 
            cout <<"---Delete node operation---"<<endl;
            cout <<"Enter the key of the node you want to delete: ";
            cin >> k1;
            s.Delete_note_by_key(k1);
            break;
        case 5:
            cout <<"---Update node operation---"<<endl;
            cout <<"Enter key and new data: ";
            cin >> key1;
            cin >> data1;
            s.Update_note_by_key(k1,data1);
            break;
        case 6:
            cout <<"---Print linked list operation---"<<endl;
            s.Print_list();
            break;
        case 7: 
            system("cls");
            break;
        default:
            break;
        }
    }while(choice != 0);
    return 0;
}