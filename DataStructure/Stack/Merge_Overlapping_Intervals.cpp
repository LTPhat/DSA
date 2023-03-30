// Given a set of time intervals in any order, 
// merge all overlapping intervals into one and output the result which should have only mutually exclusive intervals. 
// Let the intervals be represented as pairs of integers for simplicity. 
// For example, let the given set of intervals be {{1,3}, {2,4}, {5,7}, {6,8}}. 
// The intervals {1,3} and {2,4} overlap with each other, so they should be merged and become {1, 4}. 
// Similarly, {5, 7} and {6, 8} should be merged and become {5, 8}

//Method 1: Using 2D vecto 
#include<algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    vector <vector <int>> Merge(vector <vector <int>> &intervals){

        sort(intervals.begin(),intervals.end());
        vector <vector<int>> ans;
        int n = intervals.size();

        for (int i = 0; i < n; i++){
            if (ans.empty()){
                ans.push_back(intervals[i]);
            }else{
                vector <int>&v = ans.back();
                if (intervals[i][0] <= v[1]){ //Overlapping
                    v[1] = max(v[1],intervals[i][1]);
                }else{
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
};


//Method 2: Using stack

#include<algorithm>
#include <iostream>
#include <vector>
#include<stack>

using namespace std;

struct Intervals{
    int start, end; 
};
//Condition for sorting.
bool cmd (Intervals i1, Intervals i2){
    return (i1.start < i2.start);
}

void Merge_Intervals(Intervals arr[], int n){
    if (n <= 0){
        cout << "Intervals empty";
        return;
    }
    stack <Intervals> st;
    sort(arr,arr + n, cmd);
    for (int i = 0; i < n; i++){
        if (st.empty()){
            st.push(arr[i]);
        }else{
            Intervals top = st.top();
            if (top.end < arr[i].start){   //Non-overlapping.
                st.push(arr[i]);
            }else{   //Overlapping.
                top.end = max(top.end,arr[i].end);
                st.pop();
                st.push(top);
            }
        }
    }
    //Print merged stack.
    // Intervals Show;
    int i = 0;
    cout <<"The merged intervals are: ";
    while (!st.empty()){
        cout << "[" << st.top().start <<", " << st.top().end << "] ";
        st.pop();
    }
    // for (int i = 0; i < n; i++){
    //     cout << "[ " << Show[i].start << ", " << Show[i].end << "] ";
    // }
    return;
}

int main(){
    Intervals list_of_intervals[] = {{1,3}, {2,4}, {5,7}, {6,8}};
    int n = sizeof(list_of_intervals)/sizeof(list_of_intervals[0]);
    Merge_Intervals(list_of_intervals,n);
    return 0;
}


