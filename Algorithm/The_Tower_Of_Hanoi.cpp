#include <iostream>
using namespace std;

// A is the begin_place
// C is the end_place
// B is the helper_place

void move(int n,char A,char B,char C)
 {
      if(n==1){
        cout<<A<<" ==> "<<C<<"\n";// nếu n = 1 thì dịch chuyển từ A -> C
      }
      else {        
        //// Nếu n > 1 thì thực hiện lần lượt các bước
        move(n - 1, A, C, B); // 1. Dịch chuyển n-1 đĩa từ A -> B
        cout<<A<<" ==> "<<C<<"\n"; //2. Dịch chuyển đĩa thứ n từ A -> C
        move(n - 1, B, A, C); // 3. Dịch chuyển n-1 đĩa từ B -> C
      }
 }
 
int main() {
  int n;
  cout<<endl<<"Enter the number of disks: ";
  cin>>n;
  cout<<"Solution includes these following steps: \n";
  move(n, 'A', 'B', 'C');
  cout<<"\n------------------------------\n";
}