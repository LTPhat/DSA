// Create a AVL tree with these operation function
// 1) Check Empty
// 2) Insert Node (The value in left child is always lesser than their parent node,
// the value in right child is always greater than their parent node)
// 3) DFS Traversal: Preorder, Inorder, Postorder 
//    BFS Traversal: Levelorder
// 4) Print BST tree
// 5) Find height of BST tree
// 6) Delete node
// 7) Minvalue Node 
// 8) Search value
// More: Get Balanced Factor of each node, if not, balance AVL tree after inserting or deleting


#include <bits/stdc++.h>

using namespace std;
#define SPACE 5


//Create node
class Treenode{
    public:
    int value;
    Treenode *left;
    Treenode *right;
    Treenode(){
        value = 0;
        left = NULL;
        right = NULL;
    }
    Treenode(int data){
        value = data;
        left = NULL;
        right = NULL;
    }
};

class AVLTree{
    public:
    //Create root node
    Treenode *root;
    AVLTree(){
        root = NULL;
    }
    // Check empty function
    bool Tree_empty(){
        if (root == NULL){
            return true;
        }
        return false;
    }
    // Function to get height of AVL tree
    int Height(Treenode *head){
        if (head == NULL){
            return -1;
        }
        int lheight = Height(head->left);
        int rheight = Height(head->right);
        if (lheight > rheight){
            return (lheight + 1);
        }else{
            return (rheight + 1);
        }
    }
    // Function to get balanced factor of each node
    int Get_balanced_factor(Treenode *head){
        if (head == NULL){
            return -1;
        }
        return (Height(head->left) - Height(head->right));
    }

    // Function to print and traverse AVL tree in different way
        // Print 2d
    void Print_2d(Treenode *head, int space){
        if (head == NULL){
            return;
        }
        space = space + SPACE;
        Print_2d(head->right, space);
        for (int i = SPACE; i < space; i++){
            cout << " ";
        }
        cout << head->value << "\n";
        Print_2d(head->left, space);
    }
        //Traverse DFS Pre-order (Root--Left--Right)
        void Print_Preorder(Treenode *head){
            if (head == NULL){
                return;
            }
            cout << head->value<<" ";
            Print_Preorder(head->left);
            Print_Preorder(head->right);
        }

        //Traverse DFS In-order (Left--Root--Right)
        void Print_Inorder(Treenode *head){
            if (head == NULL){
                return;
            }
            Print_Inorder(head->left);
            cout << head->value<<" ";
            Print_Inorder(head->right);
        }
        
        //Traverse DFS Post-order (Left--Right--Root)
        void Print_Postorder(Treenode *head){
            if (head == NULL){
                return;
            }
            Print_Postorder(head->left);
            Print_Postorder(head->right);
            cout << head->value<<" ";
        }
        //Traverse BFS (Breath Deep First)
            // Print level function
        void Print_level(Treenode *head, int level){
            if (head == NULL){
                return;
            }else if(level == 0){
                cout << head->value << " ";
            }else{
                Print_level(head->left, level - 1);
                Print_level(head->right, level - 1);
            }
        }
            //Traver BFS 
        void BFS_Traversal(Treenode *head){
            int h = Height(head);
            for (int i = 0; i <= h; i++){
                Print_level(head,i);
            }
        }
        //Rotate function
        Treenode *Right_Rotate(Treenode *head){
            Treenode *l = head->left;
            Treenode *r = head->right;
            //Rotate
            l->right = head;
            head->left = r;
            return l;
        }
        Treenode *Left_Rotate(Treenode *head){
            Treenode *l = head->left;
            Treenode *r = head->right;
            //Rotate
            r->left = head;
            head->right = l;
            return r;
        }
        
};



