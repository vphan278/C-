#include <iostream>
#include <queue>
using namespace std;


//Vinh Phan
//CIS-22C: C++ Data Structures and Algorithms
//CRN 33571


class TreeNode{

    public:
        char data;
        TreeNode *parent;
        TreeNode *left;
        TreeNode *right;

        TreeNode(char val): data(val), parent(nullptr), left(nullptr), right(nullptr){}

};

TreeNode *buildTree(){

    TreeNode *P = new TreeNode('P');
    TreeNode *X = new TreeNode('X');
    TreeNode *A = new TreeNode('A');
    TreeNode *Y = new TreeNode('Y');
    TreeNode *B = new TreeNode('B');
    TreeNode *C = new TreeNode('C');

    //Tree Structure
    P->left = X;     X->parent = P;
    X->left = A;     A->parent = X;
    X->right = Y;    Y->parent = X;
    Y->left = B;     B->parent = Y;
    Y->right = C;    C->parent = Y;

    return P;


}

void printTree(TreeNode* node, int indent = 0) {
    if (!node) return;
    printTree(node->right, indent + 4);
    cout << string(indent, ' ') << node->data << "\n";
    printTree(node->left, indent + 4);
}


//Rotate Left
void rotateLeftAtX(TreeNode *X){
    if(X == nullptr || X->right == nullptr) return;

    //Before Rotation
    TreeNode *Y = X->right;  //Y moves up
    TreeNode *B = Y->left; //B will move under X
    TreeNode *P = X->parent;
    TreeNode *C = Y->right;

    //Step 1: move B to X's right
    X->right = B;
    if (B) B->parent = X;

    //Step 2: move X under Y
    Y->left = X;    X->parent  = Y;

    //Step 3: connect Y to P
    Y->parent = P;
    if (P) {
        if (P->left == X)
            P->left = Y;
        else if (P->right == X)
            P->right = Y;
    }

}


//Rotate Right
void rotateRightatY(TreeNode *Y){
    if (Y == nullptr || Y->left == nullptr) return;

    //At end of left rotation
    TreeNode *X = Y->left;
    TreeNode *B = X->right;
    TreeNode *P = Y->parent;
    TreeNode *C = Y->right;

    

    //Step 1:move B to Y's left
    Y->left = B;
    if(B)B->parent = Y;

    //Step 2: move Y under X
    X->right = Y;
    Y->parent = X;

    //Step 3: connect X to P
    X->parent = P;
    if (P) {
        if(P->left ==Y)
            P->left = X;
        else if(P->right ==Y)
            P->right = X;
        
    }

}

int main(){

    //Build the tree
    TreeNode *root = buildTree();

    //Print tree sideways
    cout << "Tree structure: ";
    printTree(root);
    //-----------------------------------------------------------------------------------------/

    // Rotate LEFT at X (X is P->left)
    TreeNode* X = root->left;
    rotateLeftAtX(X);

    cout << "\nAfter LEFT rotation at X:\n";
    printTree(root);
    //------------------------------------------------------------------------------------------/


    //Checks -after the left rotation
    cout << "\nChecks after left rotation:\n";
    cout << "P->left = " << root->left->data << "\n";                 // Y
    cout << "Y->left = " << root->left->left->data << "\n";           // X
    cout << "Y->right = " << root->left->right->data << "\n";         // C
    cout << "X->left = " << root->left->left->left->data << "\n";     // A
    cout << "X->right = " << root->left->left->right->data << "\n";   // B

    //-----------------------------------------------------------------------------------------/
    //Rotate RIGHT at Y back to original before left rotation
    TreeNode* Y = root->left;
    rotateRightatY(Y);

    cout << "\nAfter RIGHT rotation at Y (restored):\n";
    printTree(root);

    //Checks-after the right rotation back to original
    cout << "\nChecks after right rotation:\n";
    cout << "P->left = " << root->left->data << "\n";                 // x
    cout << "X->left = " << root->left->left->data << "\n";           // A
    cout << "X->right = " << root->left->right->data << "\n";         // Y
    cout << "Y->left = " << root->left->right->left->data << "\n";     // B
    cout << "Y->right = " << root->left->right->right->data << "\n";   // C

    return 0;
}