
//Algorithm



// /* This function takes last element as pivot, places the pivot element at its correct position in sorted array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */

// partition (arr[], low, high)

// {

//     // pivot (Element to be placed at right position)
// pivot = arr[high];  

//  i = (low – 1)  // Index of smaller element and indicates the 
// // right position of pivot found so far

// for (j = low; j <= high- 1; j++){

//  // If current element is smaller than the pivot
// if (arr[j] < pivot){
// i++;    // increment index of smaller element
//  swap arr[i] and arr[j]
//      }
//  }

//     swap arr[i + 1] and arr[high])
// return (i + 1)
// }

// /* low  –> Starting index,  high  –> Ending index */

// quickSort(arr[], low, high) {

//     if (low < high) {

//         /* pi is partitioning index, arr[pi] is now at right place */

//         pi = partition(arr, low, high);

//         quickSort(arr, low, pi – 1);  // Before pi

//         quickSort(arr, pi + 1, high); // After pi

//     }

// }



#include <bits/stdc++.h>
using namespace std;

void Swap(int &a, int &b){
    int temp = a;
    a = b; 
    b = temp;
}


int Partition(int a[], int left, int right){
    int pivot = a[right];
    int l = left - 1;

    for (int j = left; j <= (right - 1); j++){
        if (a[j] < pivot){
            l++;
            Swap(a[l], a[j]);
        }
    }
    Swap(a[l + 1], a[right]);
    return (l + 1);
}

void Quick_sort(int a[], int left, int right){
    if (left >= right){
        return;
    }else if(left + 1 == right){
        if (a[left] > a[right]){
            Swap (a[left], a[right]);
        }
    }else{
        int pi = Partition (a, left, right);
        Quick_sort(a, left, pi - 1);
        Quick_sort(a, pi + 1, right);
    }
}


void Input_Array(int a[], int n){
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
}
void Output_Array(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

int main(){
    int n;
    cout <<"Enter the number of elements: "; cin >> n;
    int a[n];
    Input_Array(a,n);
    cout << "\nThe array entered: "; 
    Output_Array(a,n); 
    Quick_sort(a, 0, n -1);
    cout << "\nThe array sorted: "; 
    Output_Array(a,n); 
    return 0;
}