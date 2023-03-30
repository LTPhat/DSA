//The span Si of the stock�s price on a given day i is defined as the maximum number of consecutive days 
//just before the given day, for which the price of the stock on the current day is less than its price on the given day. 
//For example:
//
//Input: N = 7, price[] = [100 80 60 70 60 75 85]
//Output: 1 1 1 2 1 4 6
//Explanation: Traversing the given input span for 100 will be 1, 
//80 is smaller than 100 so the span is 1, 
//60 is smaller than 80 so the span is 1, 
//70 is greater than 60 so the span is 2 and so on. 
//Hence the output will be 1 1 1 2 1 4 6.

//Method 1: Traverse the input array price
//#include<iostream>
//#include <bits/stdc++.h>
//using namespace std;
//
//void Calculate_Span(int price[], int n, int S[]){
//	S[0] = 1;
//	for (int i = 1; i < n; i++){
//		
//		S[i] = 1;
//		for (int j = i - 1; (j >= 0) &&
//                (price[i] >= price[j]); j--)
//            	S[i]++;
//			}
//		}	
//
//void Print_Span(int n, int arr[]){
//	for (int i = 0; i < n; i++){
//		cout << arr[i] << " ";
//	}
//}
//int main(){
//	int price[] = { 10, 4, 5, 90, 120, 80 };
//	int n = sizeof(price)/sizeof(price[0]);
//	int S[n];
//	Calculate_Span(price,n,S);
//	Print_Span(n,S);
//	return 0;
//}

//Method 2: Using stack

#include <iostream>
#include<stack>

using namespace std;

void Calculate_Span(int price[], int n, int S[]){
	
	stack <int> st;
	S[0] = 1;
	st.push(0);
	
	for (int i = 1; i < n; i++){
		while (!st.empty() && price[st.top()] <= price[i]){
			st.pop();
		}
		if (st.empty()){
			S[i] = i + 1;
		}else{
			S[i] = i - st.top();
		}
		st.push(i);
	}
}

void Print_Span(int n, int arr[]){
	for (int i = 0; i < n; i++){
		cout << "The stock span of the element with the index of "<< i << ": "<< arr[i] <<endl;
	}
}
int main(){
	int price[] = { 10, 4, 5, 90, 120, 80 };
	int n = sizeof(price)/sizeof(price[0]);
	cout << "The stock information:" << endl;
	for (int i = 0; i < n; i++){
		cout << price[i];
		cout <<" ";
	}
	cout <<endl;
	int S[n];
	Calculate_Span(price,n,S);
	Print_Span(n,S);
	return 0;
}
