
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[10] = {1,2,3,4,5}; //n = 3 
    //a [i] = a[1] = 1 
    int sum = 0;
    for (int i = 0; i < 5; i++){
        sum += a[i];
    }
    int top = 0;
    sum -= a[top++];
    cout << sum <<endl;
    sum -= a[top++];
    cout << sum <<endl;
    sum -= a[top++];
    cout << sum <<endl;
    sum -= a[top++];
    cout << sum <<endl;
    return 0;
}