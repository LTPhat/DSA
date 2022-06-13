//Given an array, print the Next Greater Element (NGE) for every element. 
//The Next greater Element for an element x is the first greater element on the right side of x in the array. 
//Elements for which no greater element exist, consider the next greater element as -1. 

//Method 1: Simple with two for loop:

//#include<iostream>
//
//using namespace std;
//
//void Next_Greater_Element(int a[], int n){
//	int next;
//	int i,j;
//	for (int i = 0; i < n; i++){
//		next = -1;
//		for (int j = i + 1; j < n; j++){
//			if (a[j] > a[i]){
//				next = a[j];
//				break;
//			}
//		}
//		cout << "The next greater element of " << a[i] << " is " << next << endl;
//	}
//}
//
//int main(){
//	int a[100];
//	int n;
//	cout << "Enter the number of elements: "; cin >> n;
//	for (int i = 0; i < n; i++){
//		cin >> a[i];
//	}
//	for (int i = 0; i < n; i++){
//		cout << a[i] <<" ";
//	}
//	cout << endl;
//	Next_Greater_Element(a,n);
//	return 0;
//}

//Method 2: Using stack
#include<iostream>
#include <bits/stdc++.h>
#include<stack>
using namespace std;


void Next_Greater_Element(int a[], int n){
	stack <int> s;
	int res[n];
	for (int i = n - 1; i >= 0; i--){
		if (!s.empty()){
			while (!s.empty() && s.top() <= a[i]){
				s.pop();
			}
		}
		if (s.empty()){
			res[i] = -1;
		}else{
			res[i] = s.top();
		}
		s.push(a[i]);
	}
	for (int i = 0; i < n; i++){
		cout << "The next greater element of " << a[i] << " is " << res[i] << endl;
	}
}

int main(){
	int a[100];
	int n;
	cout << "Enter the number of elements: "; cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		cout << a[i] <<" ";
	}
	cout << endl; 
	Next_Greater_Element(a,n);
	return 0;
}

