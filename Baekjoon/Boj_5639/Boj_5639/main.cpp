#include <iostream>
#include <algorithm>
using namespace std;

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode * new_node(int key){
    TreeNode *temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}
TreeNode * insert_node(TreeNode *root, int key){
    if(root == NULL)
        return new_node(key);
    
    if(key < root->data)
        root->left = insert_node(root->left, key);
    else if(key > root->data)
        root->right = insert_node(root->right, key);
    
    return root;
}

void postorder(TreeNode *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d\n", root->data);
    }
}
int main(){
    
    int n;
    TreeNode *root = NULL;
    while(cin >> n){
        if(n == -1)
            break;
        root = insert_node(root, n);
    }
    postorder(root);
    return 0;
    
}
