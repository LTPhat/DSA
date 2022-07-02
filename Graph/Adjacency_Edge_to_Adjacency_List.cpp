// Danh sách cạnh sang danh sách kề

// Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy viết
// chương trình thực hiện chuyển đổi biểu diễn đồ thị dưới dạng danh sách kề.
// Input
// Dòng đầu tiên chứa 2 số n, m là số đỉnh và số cạnh của đồ thị. ( 1≤ n ≤1000, 1 ≤ m ≤
// n*(n-1)/2.)
// M dòng tiếp theo mỗi dòng là 2 số u, v biểu diễn cạnh u, v của đồ thị ( 1 ≤ u, v ≤ n). Các
// cạnh được liệt kê theo thứ tự tăng dần của các đỉnh đầu
// Output
// In ra danh sách kề tương ứng của đồ thị, liệt kê theo thứ tự tăng dần của các đỉnh
// Ví dụ

// Input 
// 5 9

// 1 2
// 1 3
// 1 4
// 2 3
// 2 4
// 2 5
// 3 4
// 3 5
// 4 5

// Output
// 1 : 2 3 4
// 2 : 1 3 4 5
// 3 : 1 2 4 5
// 4 : 1 2 3 5
// 5 : 2 3 4

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector <int> a[m];
    for (int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++){
        cout << i << ": ";
        for (int j: a[i]){
            cout << j <<" ";
        }
        cout<<endl;
    }
    return 0;
}