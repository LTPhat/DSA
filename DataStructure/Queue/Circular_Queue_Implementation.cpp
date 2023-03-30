// Operations on Circular Queue: 
 

// Front: Get the front item from queue.

// Rear: Get the last item from queue.

// enQueue(value) This function is used to insert an element into the circular queue. 
// In a circular queue, the new element is always inserted at Rear position. 
// Check whether queue is Full – Check ((rear == SIZE-1 && front == 0) || (rear == front-1)).
// If it is full then display Queue is full. 
// If queue is not full then, check if (rear == SIZE – 1 && front != 0) if it is true then set rear=0 and insert element.

// deQueue() This function is used to delete an element from the circular queue. In a circular queue, the element is always deleted from front position. 
// Check whether queue is Empty means check (front==-1).
// If it is empty then display Queue is empty. If queue is not empty then step 3
// Check if (front==rear) if it is true then set front=rear= -1 else check if (front==size-1), if it is true then set front=0 and return the element.

/// C++ implementation of De-queue using circular
// array

#include<bits/stdc++.h>

using namespace std;

class Queue{
    public:
    int front, rear; 
    int size; 
    int *arr;
    
    Queue(int s){
        front = rear = -1;
        size = s;
        arr = new int [s];
    }
    void Enqueue(int value);
    int  Dequeue();
    void DisplayQueue();

};

void Queue::Enqueue(int value){
    if ((front == 0 && rear == size-1) ||
            (rear == (front-1)%(size-1)))
    {
        cout<<"\nQueue is Full";
        return;
    }else if (front == -1){ // Queue is empty
        front = rear = 0;
        arr[rear] = value;
    }else if ((rear == size - 1) && (front != 0)) { // Rear reachs the end of queue size 
        rear = 0;
        arr[rear] = value;
    }else{  // Normal
        rear ++;
        arr[rear] = value;
    }
}

int Queue:: Dequeue() {
    int element;
    if (front == - 1) {
      cout << "Queue is empty" << endl;
      return (-1);
    } else {
      element = arr[front];
      if (front == rear) {
        front = -1;
        rear = -1;
      }
      // Q has only one element,
      // so we reset the queue after deleting it.
      else {
        front = (front + 1) % size;
      }
      return (element);
    }
  }

 void Queue:: DisplayQueue() {
    // Function to display status of Circular Queue
    int i;
    if (front == -1) {
      cout << "Empty Queue" << endl;
    } else {
        cout <<endl;
        for (i = front; i != rear; i = (i + 1) % size)
            cout << arr[i] << " ";
            cout << arr[i] << " ";
    }
}

// 
int main()
{
    Queue q(5);
 
    // Inserting elements in Circular Queue
    q.Enqueue(14);
    q.Enqueue(22);
    q.Enqueue(13);
    q.Enqueue(-6);
 
    // Display elements present in Circular Queue
    q.DisplayQueue();
 
    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.Dequeue());
    printf("\nDeleted value = %d", q.Dequeue());
 
    q.DisplayQueue();
 
    q.Enqueue(9);
    q.Enqueue(20);
    q.Enqueue(5);
 
    q.DisplayQueue();
 
    q.Enqueue(20);
    return 0;
}

