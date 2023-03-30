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
    // CHECK EMPTY TREE
    bool Tree_empty(){
        if (root == NULL){
            return true;
        }
        return false;
    }
    // FUNCTION TO GET HEIGHT OF AVL TREE
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
    // FUNCTION TO GET BALANCED FACTOR OF EACH NODE
    int Get_balanced_factor(Treenode *head){
        if (head == NULL){
            return -1;
        }
        return (Height(head->left) - Height(head->right));
    }

    // FUNCTION TO TRAVERSE AND PRINT AVL TREE
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
    // ROTATE FUNCTION
    Treenode *Right_Rotate(Treenode *head){
        Treenode *l = head->left;
        Treenode *r = head->right;
            //Rotate step
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
    //FUNCTION TO INSERT NODE USING RECURSION
    Treenode *Insert_node(Treenode *head, Treenode *new_node){
        if (head == NULL){ // Base case of recursion function
            head = new_node;
            return head;
        }
        if (new_node->value < head->value){ //Move to left child 
            head->left = Insert_node(head->left, new_node);
        }else if(new_node->value > head->value){
            head->right = Insert_node(head->right, new_node); //Move to right child
        }else{ //New_node->value = head->value
            cout <<"Duplicate node value is not allowed ";
            return head;
        }
        // Calculate the balanced factor and rotate if AVL tree is not balanced
        int bf = Get_balanced_factor(head);
        // Check left - left case (Right rotation)
        if (bf > 1 && new_node->value < head->left->value){
            return Right_Rotate(head);
        }
        // Check right - right case (Left rotation)
        if (bf < -1 && new_node->value > head->right->value){
            return Left_Rotate(head);
        }
        // Check left - right case (Right - Left rotation)
        if (bf > 1 && new_node->value > head->left->value){
            head->left = Left_Rotate(head->left);
            return Right_Rotate(head);
        }
        // Check right - left case (Left - Right rotation)
        if (bf < -1 && new_node->value < head->right->value){
            head->right = Right_Rotate(head->right);
            return Left_Rotate(head);
        }
        return head; //If there is no change, return head
    }
    //FUNCTION TO DELETE NODE 
    Treenode *Minvalue_node(Treenode *head){
        Treenode *current = head;
        while (current->left != NULL){ 
            current = current->left;   //Find the leftmost node in AVL tree 
        }
        return current;
    }
    Treenode *Delete_node(Treenode *head, int val){
        if (head == NULL){ // Base case of recursion function
            return head;
        }
        if (val < head->value){ //If value less than head, move to left sub tree
            head->left = Delete_node(head->left, val);
        }else if (val > head->value){//If value more than head, move to right sub tree
            head->right = Delete_node(head->right,val);
        }else{ // Head value = val
            //Processing with node (to be deleted) has one or no child

            if (head->left == NULL){ //Node has 1 right child
                Treenode *temp = head->right; //NULL
                delete head; // Detele node 
                return temp; // Return NULL to end current recursion and move back to previous recursion
            }else if (head->right == NULL){ //Node has 1 left child
                Treenode *temp = head->left; //NULL
                delete head;
                return temp;
            }else{ //Node has 2 children
                Treenode *temp = Minvalue_node(head->right);
                // Get the minvalue of the right subtree of the node to be deleted
                head->value = temp->value; // Delete the node and replace with that min minimun value
                head->right = Delete_node(head->right, temp->value);
                //Delete the minimum value 
            }   
        }
        //Check balanced factor and rotate if AVL tree is not balanced
            //Case 1: bf = 2
            //  After deleting:
                // a)-->left left imbalance(head->left has 1 left child) --> Right rotate
                // b)-->left left imbalance(head->left has 2 children) --> Right rotate
                // c)-->left right imbalance -->Right left rotate
            //Case 2: bf = -2
            //  After deleting:
                // a)-->right right imbalance(head->right has 1 left child) --> Left rotate
                // b)-->right right imbalance(head->right has 2 children) --> Left rotate
                // c)-->right left imbalance -->Left right rotate
        int bf = Get_balanced_factor(head);
        if (bf == 2 && Get_balanced_factor(head->left) >= 0){ //Case 1a and 1b
            return Right_Rotate(head);
        }else if(bf == 2 && Get_balanced_factor(head->left) == -1){//Case 1c
            head->left = Left_Rotate(head->left);
            return Right_Rotate(head);
        }else if (bf == -2 && Get_balanced_factor(head->right) <= 0){//Case 2a and 2b
            return Left_Rotate(head);
        }else if (bf == -2 && Get_balanced_factor(head->right) == 1){
            head->right = Right_Rotate(head->right);
            return Left_Rotate(head);
        }
        return head;
    }   
    //FUNCTION TO SEARCH VALUE IN AVL TREE
    Treenode *Search_node(int val){
        if (root == NULL){
            return root;
        }else{
            Treenode *temp = root;
            while (temp != NULL){
                if (temp->value == root->value){
                    return temp;
                }else if (temp->value < root->value){
                    temp = temp->left;
                }else{
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }
};
int main() {
  AVLTree obj;
  int option, val;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print/Traversal AVL Tree values" << endl;
    cout << "5. Height of Tree" << endl;
    cout << "6. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    //Node n1;
    Treenode * new_node = new Treenode();

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "\n---AVL INSERT OPERATION---" << endl;
      cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
      cin >> val;
      new_node -> value = val;
      obj.root = obj.Insert_node(obj.root, new_node);
      cout << endl;
      break;
    case 2:
      cout << "--SEARCH OPERATION---" << endl;
      cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
      cin >> val;
      new_node = obj.Search_node(val);
      if (new_node != NULL) {
        cout << "Value found" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
    case 3:
      cout << "DELETE" << endl;
      cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
      cin >> val;
      new_node = obj.Search_node(val);
      if (new_node != NULL) {
        obj.root = obj.Delete_node(obj.root, val);
        cout << "Value Deleted" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
    case 4:
      cout << "AVL TREE: " << endl;
      obj.Print_2d(obj.root, 5);
      cout << endl;
      cout <<"Print Level Order BFS: \n";
      obj.BFS_Traversal(obj.root);
      cout <<endl;
      	      cout <<"PRE-ORDER: ";
      	      obj.Print_Preorder(obj.root);
      	      cout<<endl;
      	      cout <<"IN-ORDER: ";
      	      obj.Print_Inorder(obj.root);
      	      cout<<endl;
      	      cout <<"POST-ORDER: ";
      	      obj.Print_Postorder(obj.root);
              cout<<endl;
      break;
    case 5:
      cout << "TREE HEIGHT" << endl;
      cout << "Height : " << obj.Height(obj.root) << endl;
      break;
    case 6:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}


