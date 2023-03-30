// Given a string s and an integer k, the task is to reduce the string by applying the following operation:
// Choose a group of k consecutive identical characters and remove them.

// The operation can be performed any number of times until it is no longer possible.

// Input_1:

// k = 2
// s = "geeksforgeeks"

// Output_1:

// gksforgks
// Explanation:
// Modified String after each step: 
// "geeksforgeeks" -> "gksforgks"


// Input_2:
// k = 2
// s = "geegsforgeeeks" 
// Output_2:
// sforgeks
// Explanation:
// Modified String after each step:
// "geegsforgeeeks" -> "ggsforgeks" -> "sforgeks"

//Related knowledge: Pair and Stack with pair datatype:
    // Pair systax: pair (data_type1, data_type2) Pair_name 
    // #include <utility> to use pair

//Algorithm using stack:
// 1. Create an empty stack and put the first character of the string in pair with the systax: 
// {character, the number of appearances}
// 2. Traverse from string.begin() to string.end() by for loop:
// If s.top().first = s[i] --> Increase the number of appearances of s[i].
// If s.top().first != s[i] ---> Push the pair {s[i],1} to the top of stack.
// Continue...
// 3. If s.top().end = k ---> Pop the character with k appearance out of the stack.
// 4. Create the ans string and push all the remain elements of the stack 
// (with the number of apperances ranges from 1 to k-1) into it.
// 5. Reverse the ans string to find the final ans (LIFO of stack).

#include <bits/stdc++.h>
#include <utility>
#include <stack>
#include <algorithm>

using namespace std;

string Reduce_String(string s, int k){
    stack <pair<char,int>> contain;
    for (int i = 0; i < s.size(); i++){
        if (contain.empty()){
            contain.push({s[i],1});
        }else{
            if (contain.top().first == s[i]){
                int count = contain.top().second;
                count ++;
                contain.pop();
                contain.push({s[i], count});
            }else{
                contain.push({s[i],1});
            }
        }
        if (contain.top().second == k){
            contain.pop();
        }
    }
    string ans = "";
    while (!contain.empty()){
        char c = contain.top().first;
        int x = contain.top().second;
        contain.pop();
        for (int i = 0; i < x; i++){
            ans += c;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}



int main(){
    int k;
    string input;
    cout << "Enter the string: "; cin >> input;
    cout << "Enter k: "; cin >> k;
    string final = Reduce_String(input, k);
    cout <<"The reduced string: "<< final;
    return 0;
}
