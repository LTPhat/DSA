// Create a BST with these operation function
// 1) Check Empty
// 2) Insert Node (The value in left child is always lesser than their parent node,
// the value in right child is always greater than their parent node  )
// 3) DFS Traversal: Preorder, Inorder, Postorder 
//    BFS Traversal: Levelorder
// 4) Print BST tree
// 5) Find height of BST tree
// 6) Delete node
// 7) Minvalue Node 
// 8) Search value


#include<iostream>

using namespace std;
#define SPACE 5


class TreeNode{
    public:
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){
        left = NULL;
        right = NULL;
        value = 0;
    }
    TreeNode(int v){
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST{
    public: 
    TreeNode* root;
    BST(){
        root = NULL;
    }

    // 1) Function to check if tree is empty
    bool Is_empty(){
        if (root == NULL){
            return true;
        }else{
            return false;
        }
    }
    //2) Function to insert node 
    void Insert_node(TreeNode *new_node)
    {
        if (root == NULL)
        {  //Check if the root is empty, then root = new_node
            root = new_node;
            cout << "Insert succesfully as root"<<endl;
        }
        else
        {  // The root is not empty
            TreeNode *temp = root;
            while(temp != NULL)
            {    //Set condition 
                if (new_node->value == temp->value)
                { //Check if the value of new_node equal to the value of root
                    cout <<"Duplicate value error: "<<endl;
                    return;
                }
                else if ((new_node->value < temp->value) && (temp->left == NULL))
                {
                    //Check if the left pointer of root is empty, then link left pointer of root to new_node
                    temp->left = new_node;
                    cout << "Insert succesfully "<<endl;
                    break;
                }
                else if(new_node->value < temp->value)
                {
                    //Left pointer of root is not empty, then let root = left pointer for next while loop
                    temp = temp->left;
                }
                else if ((new_node->value > temp->value) && (temp->right == NULL))
                {
                    //Check if the right pointer of root is empty, then link right pointer of root to new_node
                    temp->right = new_node;
                    cout << "Insert succesfully "<<endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }

//  3) 

    //Function to traverse BST by DFS Pre_order (Root --> Left --> Right)
    void Print_Preoder(TreeNode *head){
        if(head == NULL){
            return;
        }
        cout << head->value <<" ";
        Print_Preoder(head->left);
        Print_Preoder(head->right);
    }

    //Function to traverse BST by DFS In_order (Left --> Root --> Right)
    void Print_Inoder(TreeNode *head){
        if(head == NULL){
            return;
        }
        Print_Inoder(head->left);
        cout << head->value<< " ";
        Print_Inoder(head->right);
    }
    //Function to traverse BST by DFS Post_order (Left --> Right --> Root)
    void Print_Postorder(TreeNode *head){
        if(head == NULL){
            return;
        }
        Print_Postorder(head->left);
        Print_Postorder(head->right);
        cout << head->value << " ";
    }
    //Function to traverse BST by BFS Level_order:
    void Print_Level(TreeNode *head, int level){
        if (head == NULL){
            return;
        }else if (level == 0){
            cout << head->value<< " ";
        }else{ //when level > 0
            Print_Level(head->left, level - 1);
            Print_Level(head->right, level - 1);
        }
    }

    void BFS_Traversal(TreeNode *head){
        int h = Height(head);
        for (int i = 0; i <= h; i++){
            Print_Level(head, i);
        }
    }

    //Function to print BST tree 2D

    void Print_2d(TreeNode *r, int space){
        if (r ==NULL){
            return;
        }
        space = space + SPACE;
        Print_2d(r->right, space);
        cout <<endl;
        for (int i = SPACE; i < space; i++){
            cout <<" ";
        }
        cout << r->value << "\n";
        Print_2d(r->left, space);
    }
    //4) Function to search value in BST tree

    TreeNode *Search_BST(int value){
        if (root == NULL){
            return root;
        }else{
            TreeNode *temp = root;
            while (temp != NULL){
                if (value < temp->value){
                    temp = temp->left;
                }else if (value > temp->value){
                    temp = temp->right;
                }else{
                    return temp;
                }
            }
            return NULL;
        }
        
        
    }
    //5) Function to find height of BST tree
    int Height(TreeNode *head){
        if (head == NULL){
            return -1;
        }
        int l_height = Height(head->left);
        int r_height = Height(head->right);
        if (l_height = r_height){
            return (l_height + 1);
        }else if (l_height < r_height){
            return (r_height + 1);
        }else{
            return (l_height + 1);
        }
    }
    // 6) Delete node:

    // Algorithm
    // +) For leaf node or node with one child
    //    - Traverse to the leaf node or node with single child to be deleted (let it be n)
    //    - Check if n has left child (n->left) 
    // --> If no, link the right child (n->right) with the parent node of n.
    // --> If yes, check if n has right child (n->right). If no, link the left child (n->left) with the parent node of n.
    // +) For node with 2 children
    //    - Traverse to the node with 2 children to be deleted.
    //    - Find the smallest node (nMin) in the right subtree of n (Find the largest node (nMax) in the left subtree of n)
    //    - Replace (nMin) (nMax) with the node to be deleted.
    //    - Delete nMin or nMax using delete process again.

    TreeNode *MinValue_Node(TreeNode *head){ //Function to find address of min value node of a subtree of node head
        TreeNode *temp = head;
        while (temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }

    TreeNode *Delete_Node(TreeNode *head, int val){
        if (head == NULL){
            return head;
        }
        if (val < head->value){ // If val smalller, go left subtree.
            head->left = Delete_Node(head->left, val);
        }else if (val > head->value){  //If val greater , go right subtree.
            head->right = Delete_Node(head->right, val);
        }else{ //Found match value to delete

            //Processing node with single child or no child

            if (head->left == NULL){        //Check if the node to be deleted has left child
                TreeNode *temp = head->right;
                delete head;
                return temp; // Return to finish the current recursion and move to the previous recursion.
            }else if(head->right == NULL){ //Check if the node to be deleted has right child
                TreeNode *temp = head->left;
                delete head;
                return temp; // Return to finish the current recursion and move to the previous recursion.
            }else{  //Processing node with two child
                TreeNode *temp = MinValue_Node(head->right); //Find minvalue of right subtree of the node to be deleted
                head->value = temp->value; //Replace the node to be deleted with the min value
                head->right = Delete_Node(head->right, temp->value); // Delete the min value
            }
        }
        return head;
    }

    // 7) Function to find the node has min value
    int Min_BST(TreeNode *head){
        TreeNode *temp = head;
        while (temp->left != NULL){
            temp = temp->left;
        }
        return temp->value;
    }

};


int main(){
    int space;
    int choice,val;
    BST obj;
    do{
        cout <<"\n------BINARY SEARCH TREE------ "<< endl;
        cout <<"Which choice do you want to choose? Select number choice. Press 0 to exit."<<endl;
        cout <<"1) Insert node" <<endl;
        cout <<"2) Search node" <<endl;
        cout <<"3) Delete node" <<endl;
        cout <<"4) Print BST" <<endl;
        cout <<"5) Find height" <<endl;
        cout <<"6) Clear screen" <<endl;
        cout <<"0) Exit" <<endl;
        cin >> choice;
        TreeNode *new_node = new TreeNode();
        switch (choice)
        {
        case 1: //Insert
            cout <<"---INSERT OPERATION---"<<endl;
            cout <<"Enter the VALUE of NODE to INSERT to BST tree: "; cin >>val;
            new_node->value = val;
            obj.Insert_node(new_node);
            break;
        case 2: //Search
            cout <<"---SEARCH OPERATION---"<<endl;
            cout <<"Enter the VALUE of NODE to SEARCH on BST tree: "; cin >>val;
            new_node  = obj.Search_BST(val);
            if (new_node != NULL){
                cout << "Value FOUND in BST tree";
            }else{
                cout << "Value NOT FOUND in BST tree";
            }
            break;
        case 3: //Delete 
             cout <<"---DELETE OPERATION---"<<endl;
             cout <<"Enter the VALUE of NODE to delete: "; cin >>val;
             new_node = obj.Search_BST(val);
             if (new_node == NULL){
                cout <<"Value NOT FOUND";
             }else{
                obj.Delete_Node(obj.root, val);
                cout <<"Delete succesffully";
             }
            break;
        case 4: //Print
            cout << "---Print BST Tree Operation---"<<endl;
            obj.Print_2d(obj.root,5);
            cout <<"TRAVERSAL BST TREE BY DFS"<<endl;
            cout <<"\nTravelsal tree by Pre-oder: ";
            obj.Print_Preoder(obj.root);
            cout <<"\nTravelsal tree by In-oder: ";
            obj.Print_Inoder(obj.root);
            cout <<"\nTravelsal tree by Post-oder: ";
            obj.Print_Postorder(obj.root);
            cout <<"\nTRAVERSAL BST TREE BY BFS ";
            obj.BFS_Traversal(obj.root);
            break;
        case 5: //Find height
            cout <<"---FIND HEIGHT---"<<endl;
            cout <<"BST tree has the height of "<< obj.Height(obj.root);
            break;
        case 6:
            system("cls");
            break;
        case 0:
            exit(0);
            break;
        default:
            break;
        }
    }while(choice != 0);
    return 0;
}