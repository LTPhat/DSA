

//Method 1: Iterative Method:
// #include<bits/stdc++.h>
// #include<algorithm>
// #include<vector>
// using namespace std;


// int Binary_Search(vector <pair<int,int>> a, int left, int right, int k){
//     if (left > right){
//         return -1;
//     }
//     while (left <= right){
//         int mid = int((left + right)/2);
//         if (a[mid].first == k){
//             return a[mid].second;
//         }
//         if (a[mid].first < k){
//             left = mid + 1;
//         }else{
//             right = mid - 1;
//         }
//     }
//     return -1;
// }

// int main(){
//     vector <pair<int,int>> a;
//     int n; 
//     cout << "Enter the size of array: "; cin >> n;
//     int s[n];
//     for (int i = 0; i < n; i++){
//         cin >> s[i];
//         a.push_back({s[i],i});
//     }
//     sort(a.begin(),a.end());
//     int k;
//     cout <<"Enter the value to find: "; cin >> k;
//     int ans = Binary_Search(a, 0, n - 1,k);
//     if (ans == -1){
//         cout << "Not found ";
//     }else{
//         cout << "The value is at the index " << ans;
//     }
//     return 0;
// }

//#Method 2: Using recursive function
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;


int Binary_Search(vector <pair<int,int>> a, int left, int right, int k){
    if (left > right){
        return -1;
    }
    while (left <= right){
        int mid = int((left + right)/2);
        if (a[mid].first == k){
            return a[mid].second;
        }
        if (a[mid].first < k){
            return Binary_Search(a, mid + 1, right, k);
        }else{
            return Binary_Search(a, left, mid - 1, k);   
        }
    }
    return -1;
}

int main(){
    vector <pair<int,int>> a;
    int n; 
    cout << "Enter the size of array: "; cin >> n;
    int s[n];
    for (int i = 0; i < n; i++){
        cin >> s[i];
        a.push_back({s[i],i});
    }
    sort(a.begin(),a.end());
    int k;
    cout <<"Enter the value to find: "; cin >> k;
    int ans = Binary_Search(a, 0, n - 1,k);
    if (ans == -1){
        cout << "Not found ";
    }else{
        cout << "The value is at the index " << ans;
    }
    return 0;
}