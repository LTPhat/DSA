#include<iostream>

using namespace std;
#define MAX_SIZE 100

class Mystack{
public:
int current_size = -1;
int st[MAX_SIZE];
    bool IsEmpty(){
        if (current_size == -1){
            return true;
        }
        return false;
    }
    bool IsFull(){
        if (current_size == MAX_SIZE){
         return true;
        }
        return false;
    }
    void push (int data){
        if (!IsFull()){
            current_size ++;
            st[current_size] = data;
            cout << "Insertion is successful ";
        }else{
            cout << "The stack is overflow! Can not insert!"<<endl;
        }
    }

    int top(){
        int data;
        if (!IsEmpty()){
            data = st[current_size];
            return data;
        }else{
            cout << "Stack is empty! "<< endl;
        }

    }
    void pop(){
        int data;
        if (!IsEmpty()){
            data = st[current_size];
            current_size --;
        }else{
            cout << "Stack is empty! Can not delete! "<<endl;
        }
    }

    int size(){
        return (current_size + 1);
    }

    void display(){
        cout << "Stack current elements are: ";
        for (int i = current_size; i >= 0; i--){
            cout << st[i]<< " ";
        }
    }
};

int main(){
    Mystack stack;
    int n;
    int choice, data;
    while (1){
        cout <<"\n\n***** MENU *****\n";
        cout <<("1. Push\n2. Pop\n3. Display\n4. Exit");
        cout << ("\nEnter your choice: ");
        cin >> choice;
    switch (choice)
        {
    case 1:
        cout <<"Enter the number to push into the stack: ";
        cin >> data;
        stack.push(data);
        break;
    case 2:
        stack.pop();
        break;
    case 3:
        stack.display();
        break;
    case 4:
        exit(0);
    default:
        cout <<"Error selection ! Try again !";
        break;
        }
    }
    return 0;
}
