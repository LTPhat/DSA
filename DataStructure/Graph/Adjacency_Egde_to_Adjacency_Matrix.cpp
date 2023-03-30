// Bài 1. Danh sách cạnh sang ma trận kề
// Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy viết
// chương trình thực hiện chuyển đổi biểu diễn đồ thị dưới dạng ma trận kề.
// Input
// Dòng đầu tiên chứa 2 số n, m là số đỉnh và số cạnh của đồ thị. ( 1≤ n ≤1000, 1 ≤ m ≤
// n*(n-1)/2.)
// M dòng tiếp theo mỗi dòng là 2 số u, v biểu diễn cạnh u, v của đồ thị ( 1 ≤ u, v ≤ n). Các
// cạnh được liệt kê theo thứ tự tăng dần của các đỉnh đầu
// Output
// In ra ma trận kề tương ứng của đồ thị

// Ví dụ
// Input                Output
// 5 9                  0 1 1 1 0
//                      1 0 1 1 1
//                      1 1 0 1 1
//                      1 1 1 0 1
//                      0 1 1 1 0
// 1 2
// 1 3
// 1 4
// 2 3
// 2 4
// 2 5
// 3 4
// 3 5
// 4 5


#include<iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n][n];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            a[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout <<a[i][j];
        }
        cout <<endl;
    }
    return 0;
}


