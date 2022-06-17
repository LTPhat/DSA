// Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

// Example 1:

// Input:
// N = 2
// LinkedList: 1->2->3->4->5->6->7->8->9
// Output: 8
// Explanation: In the first example, there
// are 9 nodes in linked list and we need
// to find 2nd node from end. 2nd node
// from end os 8.  


#include<iostream>

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


int Get_nth_node (Node* head, int n){
    if (head == NULL){
        return -1;
    }
    Node *temp = head;
    int count = 0;
    while ((temp != NULL)){
        temp = temp->next;
        count++;
    }
    if (n > count){
        return -1;
    }else{
        int x = count - n;
        int y = 0;
        while (y != x){
            head = head->next;
            y++;
        }
    }
    return head->data;
}


int main(){
    int size, n, l, firstdata;
    Node *head = NULL, *tail = NULL;

    cin >> size >> n; // n is the size of list, k is the kth element to find
    cin >> firstdata;
    head = new Node(firstdata);
    tail = head;
    for (int i = 1; i < size; i++){
        cin >> l;
        tail->next = new Node(l);
        tail = tail ->next;
        }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "--->";
        temp = temp->next;
    }
    cout <<"\n" << Get_nth_node(head,n);
    return 0;
}
