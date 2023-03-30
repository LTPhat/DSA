//Create a heap tree with these operation function:
// 1) Insert Key/Node
// 2) Search Key/Node
// 3) Delete Key/Node
// 4) Get Min
// 5) Extract Min
// 6) Get height of heap
// 7) Traversal of Heap values


#include <iostream>
#include<math.h>

using namespace std;

class Minheap{
    public:
    int *harr;
    int heap_size;
    int capacity;
    //Constructor by array
    Minheap(int cap){
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }
    void swap(int &x, int &y){
        int temp = x;
        x = y;
        y = temp;
    }
    // Determine parent node of element with index i in array
    int parent(int i){
        return (i-1)/2;
    }
    // Determine left child of element with index i in array
    int left(int i){
        return (2*i + 1);
    }
    // Determine right child of element with index i in array
    int right(int i){
        return (2*i + 2);
    }
    int getMin(){
        return harr[0];
    }
    //Function to insert key in heap

    void insertKey(int k){
        if (heap_size == capacity){
            cout << "Heap overflow ";
            return;
        }
        heap_size ++;
        int i = heap_size - 1;
        harr[i] = k;
        while (i != 0 && harr[parent(i)] > harr[i]){
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    //Extract Min function
    int extractMin(){
        if (heap_size < 0){
            return INT_MAX;
        }
        if (heap_size == 1){
            heap_size--;
            return harr[0];
        }
        int root = harr[0];
        harr[0]= harr[heap_size - 1];
        heap_size --;
        Min_heaptify(0); //Re-structure min heap after extract min value
        return root;
    }
    //Min_heaptify function
    void Min_heaptify(int i){
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[smallest]){
            smallest = l;
        }
        if (r < heap_size && harr[r] < harr[smallest]){
            smallest = r;
        }
        if (smallest != i){
            swap(harr[i], harr[smallest]);
            Min_heaptify(smallest); //Continue to process with the left or right child of node i
        }
    }
    //Delete key function
    //Algorithm
    //  1) If the key to be delete is the root: -->Extract Min
    //  2) If not
    // - Replace the key to be deleted with node which has negative value --> Violate the min heap.
    // - Move this key to the root.
    // - Extract this key. (Heaptify is included in extract min function).

    void decrease_key(int i, int val){
        harr[i] = val;
        while (i != 0 && harr[parent(i)] > harr[i]){
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    //Detele function
    void delete_key(int i){
        decrease_key(i,INT_MIN);
        extractMin();
    }
    //Print heap array
    void print(){
        for (int i = 0; i < heap_size; i++){
            cout << harr[i] << " ";
        }
    }
    // Search key function
    void linearSearch(int val) {
    for (int i = 0; i < heap_size; i++) {
      if (harr[i] == val) {
        cout << "Value Found!";
        return;
            } 
        }
    cout << "Value NOT Found!";
    }
    //Get height function
    int height() {
        return ceil(log2(heap_size + 1)) - 1;
    }
    
};

int main(){
    int s; 
    cout <<"Enter the size of min heap: "; cin>> s;
    Minheap obj(s);
    int option, val;
    do{
         cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Key/Node" << endl;
        cout << "2. Search Key/Node" << endl;
        cout << "3. Delete Key/Node" << endl;
        cout << "4. Get Min" << endl;
        cout << "5. Extract Min" << endl;
        cout << "6. Height of Heap" << endl;
        cout << "7. Print/Traversal Heap values" << endl;
        cout << "8. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;
        cin >> option;
    switch (option)
    {
    case 1:
        cout <<"---Search Key/Node Operation---"<<endl;
        cout <<"Enter VALUE to INSERT in HEAP ";
        cin >> val;
        obj.insertKey(val);
        cout<<endl;
        break;
    case 2:
        cout <<"---Insert Key/Node Operation---"<<endl;
        cout <<"Enter VALUE to SEARCH in HEAP ";
        cin >> val;
        obj.linearSearch(val);
        cout<<endl;
        break;
    case 3:
        cout <<"---Delete Key/Node Operation---"<<endl;
        cout <<"Enter INDEX of VALUE to DELETE in HEAP ";
        cin >> val;
        obj.delete_key(val);
        cout<<endl;
        break;
    case 4:
        cout <<"---Get Min Key/Node Operation---"<<endl;
        cout <<"Min value: "<<obj.getMin();
        cout<<endl;
        break;
    case 5:
        cout <<"---Extract Min Key/Node Operation---"<<endl;
        cout <<"Min value extracted: "<<obj.extractMin();
        cout<<endl;
        break;
    case 6:
        cout <<"---Get height of heap Operation---"<<endl;
        cout <<"Height of HEAP: "<<obj.height();
        cout<<endl;
        break;
    case 7:
        cout <<"---Heap traversal Operation---"<<endl;
        cout <<"Print heap: ";
        obj.print();
        cout<<endl;
        break;
    case 8:
        system("cls");
        break;
    default:
        break;
    }
    }while(option!= 0);

    return 0;
}