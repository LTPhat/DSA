#include<iostream>
#include <bits/stdc++.h>
using namespace std;

stack <int> st;
void Push_Number(int number){
	while (number != 0){
		st.push(number % 10);
		number = number / 10;
	}
}

int Reverse_Number(int number){
	Push_Number(number);
	int i = 0;
	int reverse = 0;
	while (!st.empty()){
		reverse = reverse + (st.top() * pow (10,i));
		st.pop();
		i++;
	}
	return reverse;
}

int main(){
	int n;
	cout << "Enter the number: ";
	cin >> n ;
	cout << "The reverse number: " << Reverse_Number(n);;
	return 0;
}



