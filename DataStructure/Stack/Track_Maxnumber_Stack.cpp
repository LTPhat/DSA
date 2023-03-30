// //Tracking current Maximum Element in a Stack
#include<iostream>
#include<stack>

using namespace std;

class Max_Of_Stack{
	stack <int> main_st;
	stack <int> track_st;
	
public:
	void Push(int x){
		main_st.push(x);
		if (main_st.size() == 1){
			track_st.push(x);
			return;
		}			
		if (x > track_st.top()){
			track_st.push(x);
		}else{
			track_st.push(track_st.top());
		}
	}
	int Getmax(){
		return track_st.top();
		}
	int Pop(){
		main_st.pop();
		track_st.pop();
	}
};

int main(){
	Max_Of_Stack s;
	for (int i = 0; i <= 100; i += 10){
		s.Push(i);
	}
	s.Push(120);
//	cout << s.Getmax() << endl;
//	s.Push(30);
//	cout << s.Getmax() << endl;
//	s.Push(40);
//	cout << s.Getmax() << endl;
	s.Pop();
	s.Pop();
	cout << s.Getmax() << endl;
	return 0;
}

