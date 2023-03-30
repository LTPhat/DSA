// // Array implementation Of Queue 

// // For implementing queue, we need to keep track of two indices, front and rear. 
// // We enqueue an item at the rear and dequeue an item from the front. If we simply increment front and rear indices, then there may be problems, the front may reach the end of the array. 
// // The solution to this problem is to increase front and rear in circular manner.

// // Steps for ENQUEUE

// // Check the queue is full or not
// // If full, print overflow and exit
// // If queue is not full, increment tail and add the element
// // Steps for DEQUEUE

// // Check queue is empty or not
// // if empty, print underflow and exit
// // if not empty, print element at the head and increment head

// //Method 1: Simple version:

#include <bits/stdc++.h> 


using namespace std;

struct Queue{
    int front, rear, capacity;
    int *queue;
    Queue(int c){
        front = rear = 0;
        capacity = c;
        queue = new int;
    }
    ~Queue(){
        delete [] queue;
    }
    bool Full(){
        if (capacity == rear){
            return true;
        }
        return false;
    }
    bool Empty(){
        if (front == rear){
            return true;
        }
        return false;
    } 
    void Enqueue(int data){
        if (Full()){
            cout <<"\nQueue is full. ";
        }else{
            queue[rear++] = data;
            cout <<"\nEnqueue successfully. ";
        }
    }
    void Dequeue(){
        if (Empty()){
            cout << "\nQueue is empty, can not dequeue. ";
        }else{
            for (int i = 0; i < rear - 1; i++){
                queue[i] = queue[i + 1];
            }
            rear --;
            cout <<"Dequeue successfully. ";
        }
    }
    void Display(){ 
        int i;
        if (Empty()){
            cout << "\nQueue is empty, can not dequeue. ";
        }else{
        cout << "The current queue is: ";
        for (int i = front; i < rear; i ++){
            cout << queue[i] <<" ";
        }
    }
}
    int Size(){
        return (rear + 1);
    }
    void Front()
    {
        if (front == rear) {
            cout<<"\nQueue is Empty\n";
        }
        cout <<"\nFront Element is: "<< queue[front];
    }
};


int main(void){
    Queue q(5);
    int n;
    int choice, data;
while (1){
        cout <<"\n\n***** MENU *****\n";
        cout <<("1. Enqueue\n2. Dequeue\n3. Display\n4. Front\n5. Exit");
        cout << ("\nEnter your choice: ");
        cin >> choice;
    switch (choice)
        {
    case 1:
        cout <<"Enter the number to push into the stack: ";
        cin >> data;
        q.Enqueue(data);
        break;
    case 2:
        q.Dequeue();
        break;
    case 3:
        q.Display();
        break;
    case 4:
        q.Front();
    case 5:
        exit(0); 
    default:
        cout <<"Error selection ! Try again !";
        break;
        }
    }
    return 0;
}
