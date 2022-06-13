// Infix expression: 
// The expression of the form a op b. When an operator is in-between every pair of operands.

// Postfix expression: 
// The expression of the form a b op. When an operator is followed for every pair of operands.

#include <iostream>
#include <bits/stdc++.h>
#include <stack>

using namespace std;
//Set preference of operator.
int Preference(char c){
    if (c == '^'){
        return 3;
    }
    if (c == '*' || c == '/'){
        return 2;
    }
    if (c == '+' || c == '-'){
        return 1;
    }
    return -1;
}
//The main program to convert infix to postfix.

void Infix_to_Postfix(string s){
    stack <char> st;
    string result;
    for (int i = 0; i < s.length(); i++){
        char c = s[i];
        // If c is character or number:
        if ((c >= 'a' && c <= 'z') || (c >= 'A' &&c <= 'Z') || (c >= '0' && c <= '9')){
            result += c;
        // If c is the left parenthesis or right parenthsis:
        }else if (c == '('){
            st.push('(');
        }else if (c == ')'){
            while (st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        //If c is operator:
        else{
            while (!st.empty() && Preference(s[i]) <= Preference(st.top())){
                if (c == '^' && st.top() == '^'){
                    break;
                }else{
                    result += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }

    //Pop all the remain elements in the stack afterall.
    while (!st.empty()){
        result += st.top();
        st.pop();
    }
    cout << result << endl;
}

int main(){
    string s;
    cout << "Enter the infix expression: ";
    cin >> s;
    Infix_to_Postfix(s);
    return 0;
}
