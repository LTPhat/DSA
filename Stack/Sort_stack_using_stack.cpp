#include <bits/stdc++.h>

using namespace std;

//Write the function to sort stack using another temporary stack:

stack <int> Sort_stack(stack <int> &input){
    stack <int> tmpStack;

    while (!input.empty()){
        int tmp = input.top();
        input.pop();
        while (!tmpStack.empty() && tmpStack.top() > tmp){
            input.push(tmpStack.top());
            tmpStack.pop();
        }
        tmpStack.push(tmp);
    }
    return tmpStack;
}

int main(){
    int n;
    int a[100],b[100];
    stack <int> input;
    cout <<"Enter the size of the stack: "; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        input.push(a[i]);
    }
    cout <<"Stack entered: ";
    for (int i = 0; i < n; i++){
        cout << a[i];
        cout << " ";
    }
    // input.push(10);
    // input.push(7);
    // input.push(56);
    // input.push(15);
    // input.push(73);
    stack <int> tmpStack = Sort_stack(input);
    int size = tmpStack.size();
    for (int i = 0; i < size; i++){
        b[i] = tmpStack.top();
        tmpStack.pop();
    }
    cout <<endl <<"The stack incrementally sorted: ";
    for (int i = size - 1; i >= 0; i--){
        cout << b[i] << " ";
    }
}
