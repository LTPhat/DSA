#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next; 
    Node(){   //Default constructor
        data = 0;
        next = NULL;
    }
    Node(int d){
        data = d;
    }
};

class IntSLinkedList{
    public:
    Node *head;
    IntSLinkedList(){
        head = NULL;
    }
    IntSLinkedList(Node *n){
        head = n;
    }

    void empty(){
        if (head == NULL){
            cout<<"List is Empty";
        }else{
            cout<<"List is not Empty";
        }
    }
    int size(){
        if (head == NULL){
            return 0;
        }else{
            int count = 0;
            Node *temp = head;
            while (temp != NULL){
                count += 1;
                temp = temp->next;
            }
            return count;
        }
    }
    void add(int element){
        Node *new_node = new Node();
        new_node->data = element;
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
    void add(int index, int element){
        Node *new_node = new Node();
        new_node->data = element;
        if (index > size()){
            cout<<"Error! Out of range";
        }else{
            int count = 0;
            Node *ptr = head;
            while (count < index - 1){
                ptr = ptr->next;
                count +=1; 
            }
            Node *temp = ptr->next;
            ptr->next = new_node;
            new_node->next = temp;
        }
    }

    void print_list(){
    if (head == NULL){
        cout << "Singly linked list is empty " << endl;
    }else{
        Node *temp = head;
        while (temp != NULL){
            cout <<"(" << temp->data << ") --->";
            temp = temp->next;
            }
        }
    }
    void printarray(int *A,int n){
        for(int i = 0; i<n;i++){
            cout<<A[i]<<" ";
        }
    }
    void toString(){
        int len =size();
        int i=0;
        Node *temp = head;
        int *A = new int[len];
        while(temp!=NULL){
            A[i++]=temp->data;
            temp=temp->next;
        }
        printarray(A,len);
    }
};

int main(){
    IntSLinkedList List;
    int size = 10;
    for (int index = 0; index < size; index ++){
        List.add(index);
    }
    List.add(11);
    List.add(2,15);
    List.add(2,12);
    List.add(3,20);
    List.toString();
}
