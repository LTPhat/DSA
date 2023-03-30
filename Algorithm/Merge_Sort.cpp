// Algorithm 


// step 1: start
// step 2: declare array and left, right, mid variable 
// step 3: perform merge function.
//         mergesort(array,left,right)
//         if left > right
//         return
//         mid= (left+right)/2
//         mergesort(array, left, mid)
//         mergesort(array, mid+1, right)
//         merge(array, left, mid, right)
// step 4: Stop
#include <bits/stdc++.h>

using namespace std;

void Merge(int a[], int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int k = left;
    int temp[100];
    while (i <= mid && j <= right){
        if (a[i] <= a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }
    while (i <= mid){
        temp[k++] = a[i++];
    }
    while(j <= right){
        temp[k++] = a[j++];
    }
    for (int s = left; s <= right; s++){
        a[s] = temp[s];
    }
}

void Merge_Sort(int a[], int left, int right){
    if (left >= right){
        return; 
    }

    if (left < right){
    int mid = (left + right)/2;
    Merge_Sort(a, left, mid);
    Merge_Sort(a, mid + 1, right);
    Merge(a,left, mid, right);
    }
}
void Print_array(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

int main(){
    int n; 
    cout << "Enter the size of array: "; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout <<"The array entered: ";
    Print_array(a, n);
    Merge_Sort(a, 0, n - 1);
    cout <<"\nThe array sorted: ";
    Print_array(a, n);
    return 0;
}