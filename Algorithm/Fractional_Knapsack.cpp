// Given the weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.

// In the 0-1 Knapsack problem, we are not allowed to break items. We either take the whole item or don’t take it. 

// Input: 
// Items as (value, weight) pairs 
// arr[] = {{60, 10}, {100, 20}, {120, 30}} 
// Knapsack Capacity, W = 50; 

// Output: 
// Maximum possible value = 240 
// by taking items of weight 10 and 20 kg and 2/3 fraction 
// of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240

//Using greedy algorithm
#include<bits/stdc++.h>

using namespace std;


struct Item{
    int value, weight;
    Item(){
        value = 0;
        weight = 0;
    }
    Item(int value, int weight){
        this->value = value;
        this->weight = weight;
    }
};

bool cmd (struct Item a, struct Item b){
    double r1 = double((a.value)/(a.weight));
    double r2 = double((b.value)/(b.weight));
    return (r1 > r2);
}

double Fractional_Knapsack(struct Item arr[], int W, int n){
    sort(arr, arr + n, cmd);
    for (int i = 0; i < n; i++)
    {
        cout <<"("<< arr[i].value << "," << arr[i].weight << ")--> "
             << ((double)arr[i].value / arr[i].weight) <<
    endl;
    }

    double finalvalue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= W){
            W -= arr[i].weight;
            finalvalue += arr[i].value;
        }else{
            double remain = double(W)/double(arr[i].weight);
            finalvalue += arr[i].value * remain;
        }
    }
    return finalvalue;
}

int main(){
    int size, W;
    cout << "Enter the number of items: "; cin>> size;
    Item item[size];
    for (int i = 0; i < size; i++){
        cin >> item[i].value >> item[i].weight;
    }
    cout << "\nEnter the capacity of knapsack: "; cin >> W;
    double ans = Fractional_Knapsack(item, W, size);
    cout <<"\nMax value: " <<ans;
    return 0; 
}