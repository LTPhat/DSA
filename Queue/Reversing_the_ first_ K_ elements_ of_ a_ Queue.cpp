// Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.
// Only following standard operations are allowed on queue. 

// enqueue(x) : Add an item x to rear of queue
// dequeue() : Remove an item from front of queue
// size() : Returns number of elements in queue.
// front() : Finds front item.
// Examples: 

// Input : Q = [10, 20, 30, 40, 50, 60, 
//             70, 80, 90, 100]
//         k = 5
// Output : Q = [50, 40, 30, 20, 10, 60, 
//              70, 80, 90, 100]

// Input : Q = [10, 20, 30, 40, 50, 60, 
//             70, 80, 90, 100]
//         k = 4
// Output : Q = [40, 30, 20, 10, 50, 60, 
//              70, 80, 90, 100]

// Algorithm

// Create an empty stack.
// One by one dequeue first K items from given queue and push the dequeued items to stack.
// Enqueue the contents of stack at the back of the queue
// Dequeue (size-k) elements from the front and enqueue them one by one to the same queue.

#include<bits/stdc++.h>
#include<stack>
#include<queue>

using namespace std;


void Reverse_k_elements(int k, queue <int> &q){
    if (q.empty() || k > q.size()){
        return;
    }
    if (k <= 0){
        return;
    }
    stack <int> st;
    for(int i = 0; i < k; i++){
        st.push(q.front());
        q.pop();
    }
    
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    for (int i = 0; i < q.size() - k; i++){
        int front = q.front();
        q.pop();
        q.push(front);
    }
}

void Print_Queue(queue <int> q){
    while (!q.empty()){
        cout << q.front() <<" ";
        q.pop();
    }
}

int main(){
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    int k = 4;
    Print_Queue(q);
    Reverse_k_elements(k,q);
    cout <<endl;
    cout <<"After reverse: ";
    cout <<endl;
    Print_Queue(q);
}