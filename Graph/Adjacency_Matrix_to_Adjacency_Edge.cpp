// Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng ma trận kề. Hãy viết chương
// trình thực hiện chuyển đổi biểu diễn đồ thị dưới dạng danh sách cạnh.
// Input
// Dòng đầu tiên chứa 2 số n là số đỉnh của đồ thị. ( 1≤ n ≤1000)
// N dòng tiếp theo, mỗi dòng N số biểu diễn ma trận kề của đồ thị
// Output
// In ra danh sách cạnh tương ứng theo thứ tự đỉnh đầu tăng dần.
// Ví dụ
// Input Output

// 5
// 0 1 1 1 0
// 1 0 1 1 1
// 1 1 0 1 1
// 1 1 1 0 1
// 0 1 1 1 0

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
#include<vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    int matrix [n][n];
    vector <pair<int,int>> a;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> matrix[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (matrix[i][j] == 1 & i < j){
                a.push_back({i,j});
            }
        }
    }
    for (auto it: a){
        cout << it.first << " " << it.second <<endl;
    }
    return 0;
}
